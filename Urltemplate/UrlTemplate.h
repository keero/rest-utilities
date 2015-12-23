#ifndef _URLTEMPLATE_H_
#define _URLTEMPLATE_H_

using namespace std;

#include <string>
#include <map>

typedef map<string,string> UrlContext;

class UrlTemplate
{
public:
    UrlTemplate();
    virtual ~UrlTemplate();
    
    void SetUrl(const string& value) { m_sUrl = value; }
    const string& GetUrl() const { return m_sUrl; }
    
    void SetParam(const string& key, const string& value) { m_oUrlContext[key] = value; }
    const string& GetParam(const string& key) const { return m_oUrlContext.find(key)->second; }
    void UnsetParam(const string& key) { m_oUrlContext.erase(key); }
    void ClearParams() { m_oUrlContext.clear(); }
    
    string Expand();

private:
    string getValues(char op, const string& key, const string& modifier);
    
    static string encodeReserved(const string &value);
    static string encodeURI(const string &value, bool isComponent);
    static string encodeValue(char op, const string& value, const string& key);
    static bool isDefined(const string& value);
    static bool isKeyOperator(char op);
    
private:
    string      m_sUrl;
    UrlContext  m_oUrlContext;
    
};

#endif
