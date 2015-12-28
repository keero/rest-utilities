#ifndef _LINK_H_
#define _LINK_H_

#include <string>
#include "rapidjson/document.h"

#include "UrlTemplate/UrlTemplate.h"

class Link
{
public:

    Link();
    virtual ~Link();
    
    void SetHref(const string& value) { m_oUrlTemplate.SetUrl(value); }
    const string& GetHref() const { return m_oUrlTemplate.GetUrl(); }
    
    void SetTemplated(bool value) { m_bTemplated = value; }
    bool GetTemplated() const { return m_bTemplated; }
    
    void SetWithCredentials(bool value) { m_bWithCredentials = value; }
    bool GetWithCredentials() const { return m_bWithCredentials; }
    
    void SetParam(const string& key, const string& value) { m_oUrlTemplate.SetParam(key, value); }
    const string& GetParam(const string& key) const { return m_oUrlTemplate.GetParam(key); }
    void UnsetParam(const string& key) { m_oUrlTemplate.UnsetParam(key); }
    void ClearParams() { m_oUrlTemplate.ClearParams(); }
    
    const string GetExpandedUrl() { return m_oUrlTemplate.Expand(); }
    
    static bool CreateFromJsonString(const string& json, Link& link); // @TODO: Add ref obj for parse errors
    static bool CreateFromJson(const rapidjson::Value& value, Link& link); // @TODO: Add ref obj for parse errors
    
private:
    bool            m_bTemplated;
    bool            m_bWithCredentials;
    UrlTemplate     m_oUrlTemplate;
};

#endif /* _LINK_H_ */
