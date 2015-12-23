#include <sstream>
#include <iterator>
#include <regex>
#include <algorithm>
#include <cctype>
#include <iomanip>

#include "UrlTemplate.h"

const char operators[7] = {'+', '#', '.', '/', ';', '?', '&'};

UrlTemplate::UrlTemplate() { }
UrlTemplate::~UrlTemplate() { }

string UrlTemplate::Expand()
{
    ostringstream expanded;
    
    regex expr_regex("\\{([^\\{\\}]+)\\}|([^\\{\\}]+)");
    
    sregex_iterator exprs_begin = sregex_iterator(m_sUrl.begin(), m_sUrl.end(), expr_regex);
    sregex_iterator exprs_end = sregex_iterator();
    
    for (sregex_iterator i = exprs_begin; i != exprs_end; ++i)
    {
        smatch expr_match = *i;
        
        if (expr_match.size() == 3)
        {
            string expression = expr_match[1];
            string literal = expr_match[2];
            
            if (expression.length())
            {
                vector<string> values;
                char op;
                const char* end = operators + 7;
                const char* result = find(operators, end, expression[0]);
                if (result != end) {
                    op = *result;
                    expression = expression.substr(1,string::npos);
                }
                
                stringstream ss(expression);
                string item;
                while (getline(ss, item, ','))
                {
                    regex var_regex("([^:\\*]*)(?::(\\d+)|(\\*))?");
                    smatch var_match;
                    if (regex_match(item, var_match, var_regex) && var_match.size() == 4)
                    {
                        string key = var_match[1];
                        string modifier = var_match[2].length() ? var_match[2] : var_match[3];
                        values.push_back(getValues(op, key, modifier));
                    }
                }
                
                stringstream ss2;
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
                for(size_t j = 0; j < values.size(); ++j)
                {
                    if(j != 0)
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

string UrlTemplate::getValues(char op, const string& key, const string& modifier)
{
    if (modifier.length()) throw "Support for modifier syntax is not yet supported";
    
    ostringstream result;
    UrlContext::const_iterator search = m_oUrlContext.find(key);
    
    if (search != m_oUrlContext.end() && isDefined(search->second))
    {
        result << encodeValue(op, search->second, isKeyOperator(op) ? key : "");
    }
    else
    {
        if (op == ';')
        {
            result << encodeURI(key, true);
        }
        else if (search != m_oUrlContext.end() && search->second.length() == 0)
        {
            if (op == '&' || op == '?')
                result << encodeURI(key, true) << '=';
            else
                result << "";
        }
    }
    return result.str();
}

string UrlTemplate::encodeURI(const string &value, bool isComponent) {
    ostringstream escaped;
    escaped.fill('0');
    escaped << hex;

    for (string::const_iterator i = value.begin(), n = value.end(); i != n; ++i) {
        string::value_type c = (*i);

        if (isalnum(c) || c == '-' || c == '_' || c == '.' || c == '!' || c == '~' || c == '*' || c == '\'' || c == '(' || c == ')'
            || (!isComponent && (c == ';' || c == ',' || c == '/' || c == '?' || c == ':' || c == '@' || c == '&' || c == '=' || c == '+' || c == '$'
            || c == '#'))) {
            escaped << c;
            continue;
        }

        escaped << uppercase;
        escaped << '%' << setw(2) << int((unsigned char) c);
        escaped << nouppercase;
    }

    return escaped.str();
}

string UrlTemplate::encodeReserved(const string& value)
{
    ostringstream result;
    regex rgx("%[0-9A-Fa-f]{2}");
    sregex_token_iterator iter(value.begin(),
        value.end(),
        rgx,
        -1);
    sregex_token_iterator end;
    for ( ; iter != end; ++iter)
    {
        string item(*iter);
        regex rgx2("%[0-9A-Fa-f]");
        smatch m;
        if (regex_match(item, m, rgx2))
        {
            item = encodeURI(item, false);
        } 
        result << item;
    }
    
    return result.str();
}

string UrlTemplate::encodeValue(char op, const string& value, const string& key)
{
    ostringstream result;
    string v(op == '+' || op == '#' ? encodeReserved(value) : encodeURI(value, true));

    if (key.length()) {
        result << encodeURI(key, true) << '=' << value;
    } else {
        result << value;
    }
    return result.str();
}

bool UrlTemplate::isDefined(const string& value)
{
    return value.length() > 0;
}

bool UrlTemplate::isKeyOperator(char op)
{
    return op == ';' || op == '&' || op == '?';
}
