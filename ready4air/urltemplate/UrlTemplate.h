#ifndef READY4AIR_URLTEMPLATE_URLTEMPLATE_H
#define READY4AIR_URLTEMPLATE_URLTEMPLATE_H

#include <map>
#include <sstream>
#include <iterator>
#include <algorithm>
#include <cctype>
#include <iomanip>
#include "../common/Maybe.h"
#include "../common/Regex.h"

typedef std::map<std::string, std::string> UrlContext;

const char operators[7] = {'+', '#', '.', '/', ';', '?', '&'};

namespace ready4air
{
    class UrlTemplate
    {
    public:

        UrlTemplate()
        {
        }

        virtual ~UrlTemplate()
        {
        }

        void SetUrl(const std::string &value)
        {
            mUrl = value;
        }

        const Maybe <std::string> &GetUrl() const
        {
            return mUrl;
        }

        void SetParam(const std::string &key, const std::string &value)
        {
            mUrlContext[key] = value;
        }

        const std::string &GetParam(const std::string &key) const
        {
            return mUrlContext.find(key)->second;
        }

        void UnsetParam(const std::string &key)
        {
            mUrlContext.erase(key);
        }

        void ClearParams()
        {
            mUrlContext.clear();
        }

        std::string Expand() const
        {
            if (!mUrl) return "";
            std::string url = mUrl.Just();

            std::ostringstream expanded;

            std::string exprRegex = "^\\{([^\\{\\}]+)\\}";
            std::string literalRegex = "([^\\{\\}]+)";
            std::string subject = url;
            std::string match;
            std::string rest;

            bool lastIsOp = false;
            while (subject.length() > 0)
            {
                if (ready4air::Regex::MatchSingle(exprRegex, subject, match, rest))
                {
                    std::vector<std::string> values;
                    char op = '\0';
                    const char *end = operators + 7;
                    const char *result = std::find(operators, end, match[0]);
                    if (result != end)
                    {
                        op = *result;
                        match = match.substr(1, std::string::npos);
                    }

                    std::stringstream ss(match);
                    std::string item;
                    while (getline(ss, item, ','))
                    {
                        values.push_back(getValues(op, item));
                    }

                    std::stringstream ss2;
                    char separator = ',';

                    if (op && op != '+')
                    {
                        if (op == '?')
                        {
                            separator = '&';
                        }
                        else if (op != '#')
                        {
                            separator = op;
                        }



                        if (values.size() && !lastIsOp)
                        {
                            ss2 << op;
                            lastIsOp = true;
                        }

                    }
                    for (size_t j = 0; j < values.size(); ++j)
                    {
                        if (j > 0 && values[j-1].length() > 0)
                        {
                            ss2 << separator;
                            lastIsOp = true;
                        }
                        if (values[j].length() > 0)
                        {
                            ss2 << values[j];
                            lastIsOp = false;
                        }
                    }
                    expanded << ss2.str();
                }
                else if (ready4air::Regex::MatchSingle(literalRegex, subject, match, rest))
                {
                    if (match[0] == '&' && lastIsOp) match = match.substr(1);
                    expanded << encodeReserved(match);
                }
                else
                    break;
                subject = rest;
            }
            return expanded.str();
        }

    private:
        std::string getValues(char op, const std::string &key) const
        {
            std::ostringstream result;
            UrlContext::const_iterator search = mUrlContext.find(key);

            if (search != mUrlContext.end() && isDefined(search->second))
            {
                result << encodeValue(op, search->second, isKeyOperator(op) ? key : "");
            }
            else
            {
                if (op == ';')
                {
                    result << encodeURI(key, true);
                }
                else if (search != mUrlContext.end() && search->second.length() == 0)
                {
                    if (op == '&' || op == '?')
                        result << encodeURI(key, true) << '=';
                    else
                        result << "";
                }
            }
            return result.str();
        }

        static std::string encodeReserved(const std::string &value)
        {
            std::ostringstream result;

            std::vector<std::string> tokens;
            Regex::Split("(%[[:xdigit:]]{2})", value, tokens);

            for (size_t i = 0; i < tokens.size(); i += 1)
            {
                std::string item = tokens[i];
                if (!Regex::Match("(%[[:xdigit:]])", item))
                {
                    item = encodeURI(item, false);
                }
                result << item;
            }
            return result.str();
        }

        static std::string encodeURI(const std::string &value, bool isComponent)
        {
            std::ostringstream escaped;
            escaped.fill('0');
            escaped << std::hex;

            for (std::string::const_iterator i = value.begin(), n = value.end(); i != n; ++i)
            {
                std::string::value_type c = (*i);

                if (isalnum(c) || c == '-' || c == '_' || c == '.' || c == '!' || c == '~' || c == '*' || c == '\'' ||
                    c == '(' || c == ')'
                    || (!isComponent &&
                        (c == ';' || c == ',' || c == '/' || c == '?' || c == ':' || c == '@' || c == '&' || c == '=' ||
                         c == '+' || c == '$'
                         || c == '#')))
                {
                    escaped << c;
                    continue;
                }

                escaped << std::uppercase;
                escaped << '%' << std::setw(2) << int((unsigned char) c);
                escaped << std::nouppercase;
            }

            return escaped.str();
        }

        static std::string encodeValue(char op, const std::string &value, const std::string &key)
        {
            std::ostringstream result;
            std::string v(op == '+' || op == '#' ? encodeReserved(value) : encodeURI(value, true));

            if (key.length())
            {
                result << encodeURI(key, true) << '=' << v;
            } else
            {
                result << v;
            }
            return result.str();
        }

        static bool isDefined(const std::string &value)
        {
            return value.length() > 0;
        }

        static bool isKeyOperator(char op)
        {
            return op == ';' || op == '&' || op == '?';
        }

    private:
        Maybe <std::string> mUrl;
        UrlContext mUrlContext;
    };
}
#endif //READY4AIR_URLTEMPLATE_URLTEMPLATE_H
