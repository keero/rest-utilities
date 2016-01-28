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

typedef MAP_T<STRING_T, STRING_T> UrlContext;

const INT8_T operators[7] = {'+', '#', '.', '/', ';', '?', '&'};

namespace ready4air
{
    class UrlTemplate
    {
    public:

        UrlTemplate() : TAG("ready4air::UrlTemplate")
        {
        }

        virtual ~UrlTemplate()
        {
        }

        void SetUrl(const STRING_T &value)
        {
            mUrl = value;
        }

        const Maybe <STRING_T> &GetUrl() const
        {
            return mUrl;
        }

        void SetParam(const STRING_T &key, const STRING_T &value)
        {
            mUrlContext[key] = value;
        }

        const STRING_T &GetParam(const STRING_T &key) const
        {
            return mUrlContext.find(key)->second;
        }

        void UnsetParam(const STRING_T &key)
        {
            mUrlContext.erase(key);
        }

        void ClearParams()
        {
            mUrlContext.clear();
        }

        STRING_T Expand() const
        {
            if (!mUrl) return "";
            STRING_T url = mUrl.Just();

            std::ostringstream expanded;

            STRING_T exprRegex = "^\\{([^\\{\\}]+)\\}";
            STRING_T literalRegex = "([^\\{\\}]+)";
            STRING_T subject = url;
            STRING_T match;
            STRING_T rest;

            BOOL_T lastIsOp = false;
            while (subject.length() > 0)
            {
                if (ready4air::Regex::MatchSingle(exprRegex, subject, match, rest))
                {
                    VECTOR_T<STRING_T> values;
                    INT8_T op = '\0';
                    const INT8_T *end = operators + 7;
                    const INT8_T *result = std::find(operators, end, match[0]);
                    if (result != end)
                    {
                        op = *result;
                        match = match.substr(1, STRING_T::npos);
                    }

                    std::stringstream ss(match);
                    STRING_T item;
                    while (getline(ss, item, ','))
                    {
                        values.push_back(getValues(op, item));
                    }

                    std::stringstream ss2;
                    INT8_T separator = ',';

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
            STRING_T expandedStr = expanded.str();
            if (isKeyOperator(expandedStr.back())) expandedStr.pop_back();
            return expandedStr;
        }

    private:
        STRING_T getValues(INT8_T op, const STRING_T &key) const
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

        static STRING_T encodeReserved(const STRING_T &value)
        {
            std::ostringstream result;

            VECTOR_T<STRING_T> tokens;
            Regex::Split("(%[[:xdigit:]]{2})", value, tokens);

            for (size_t i = 0; i < tokens.size(); i += 1)
            {
                STRING_T item = tokens[i];
                if (!Regex::Match("(%[[:xdigit:]])", item))
                {
                    item = encodeURI(item, false);
                }
                result << item;
            }
            return result.str();
        }

        static STRING_T encodeURI(const STRING_T &value, BOOL_T isComponent)
        {
            std::ostringstream escaped;
            escaped.fill('0');
            escaped << std::hex;

            for (STRING_T::const_iterator i = value.begin(), n = value.end(); i != n; ++i)
            {
                STRING_T::value_type c = (*i);

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
                escaped << '%' << std::setw(2) << INT32_T((UINT8_T) c);
                escaped << std::nouppercase;
            }

            return escaped.str();
        }

        static STRING_T encodeValue(INT8_T op, const STRING_T &value, const STRING_T &key)
        {
            std::ostringstream result;
            STRING_T v(op == '+' || op == '#' ? encodeReserved(value) : encodeURI(value, true));

            if (key.length())
            {
                result << encodeURI(key, true) << '=' << v;
            } else
            {
                result << v;
            }
            return result.str();
        }

        static BOOL_T isDefined(const STRING_T &value)
        {
            return value.length() > 0;
        }

        static BOOL_T isKeyOperator(INT8_T op)
        {
            return op == ';' || op == '&' || op == '?';
        }

    private:
        Maybe <STRING_T> mUrl;
        UrlContext mUrlContext;
        const STRING_T TAG;
    };
}
#endif //READY4AIR_URLTEMPLATE_URLTEMPLATE_H
