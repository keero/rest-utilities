#ifndef READY4AIR_URLTEMPLATE_URLTEMPLATE_H
#define READY4AIR_URLTEMPLATE_URLTEMPLATE_H

#include <map>
#include <sstream>
#include <iterator>
#include <regex>
#include <algorithm>
#include <cctype>
#include <iomanip>
#include "../maybe/Maybe.h"

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

        std::string Expand()
        {
            if (mUrl.Nothing()) return "";
            std::string url = mUrl.Just();

            std::ostringstream expanded;

            std::regex expr_regex("\\{([^\\{\\}]+)\\}|([^\\{\\}]+)");

            std::sregex_iterator exprs_begin = std::sregex_iterator(url.begin(), url.end(), expr_regex);
            std::sregex_iterator exprs_end = std::sregex_iterator();

            for (std::sregex_iterator i = exprs_begin; i != exprs_end; ++i)
            {
                std::smatch expr_match = *i;

                if (expr_match.size() == 3)
                {
                    std::string expression = expr_match[1];
                    std::string literal = expr_match[2];

                    if (expression.length())
                    {
                        std::vector<std::string> values;
                        char op = '\0';
                        const char *end = operators + 7;
                        const char *result = std::find(operators, end, expression[0]);
                        if (result != end)
                        {
                            op = *result;
                            expression = expression.substr(1, std::string::npos);
                        }

                        std::stringstream ss(expression);
                        std::string item;
                        while (getline(ss, item, ','))
                        {
                            std::regex var_regex("([^:\\*]*)(?::(\\d+)|(\\*))?");
                            std::smatch var_match;
                            if (regex_match(item, var_match, var_regex) && var_match.size() == 4)
                            {
                                std::string key = var_match[1];
                                std::string modifier = var_match[2].length() ? var_match[2] : var_match[3];
                                values.push_back(getValues(op, key, modifier));
                            }
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


                            if (values.size()) ss2 << op;

                        }
                        for (size_t j = 0; j < values.size(); ++j)
                        {
                            if (j != 0)
                                ss2 << separator;
                            ss2 << values[j];
                        }
                        expanded << ss2.str();
                    }

                    if (literal.length())
                    {
                        expanded << encodeReserved(literal);
                    }
                }
            }
            return expanded.str();
        }

    private:
        std::string getValues(char op, const std::string &key, const std::string &modifier)
        {
            if (modifier.length()) throw "Support for modifier syntax is not yet supported";

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
            std::regex rgx("%[0-9A-Fa-f]{2}");
            std::sregex_token_iterator iter(value.begin(),
                                            value.end(),
                                            rgx,
                                            -1);
            std::sregex_token_iterator end;
            for (; iter != end; ++iter)
            {
                std::string item(*iter);
                std::regex rgx2("%[0-9A-Fa-f]");
                std::smatch m;
                if (regex_match(item, m, rgx2))
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
