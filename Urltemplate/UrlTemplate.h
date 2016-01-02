#ifndef REST_UTILITIES_URLTEMPLATE_URLTEMPLATE_H
#define REST_UTILITIES_URLTEMPLATE_URLTEMPLATE_H


#include <string>
#include <map>

using namespace std;

typedef map<string, string> UrlContext;

class UrlTemplate
{
public:

    UrlTemplate()
    {
    }

    virtual ~UrlTemplate()
    {
    }

    void SetUrl(const string &value)
    {
        mUrl = value;
    }

    const string &GetUrl() const
    {
        return mUrl;
    }

    void SetParam(const string &key, const string &value)
    {
        mUrlContext[key] = value;
    }

    const string &GetParam(const string &key) const
    {
        return mUrlContext.find(key)->second;
    }

    void UnsetParam(const string &key)
    {
        mUrlContext.erase(key);
    }

    void ClearParams()
    {
        mUrlContext.clear();
    }

    string Expand();

private:
    string getValues(char op, const string &key, const string &modifier);

    static string encodeReserved(const string &value);

    static string encodeURI(const string &value, bool isComponent);

    static string encodeValue(char op, const string &value, const string &key);

    static bool isDefined(const string &value);

    static bool isKeyOperator(char op);

private:
    string      mUrl;
    UrlContext  mUrlContext;
};

#endif //REST_UTILITIES_URLTEMPLATE_URLTEMPLATE_H
