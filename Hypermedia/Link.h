#ifndef REST_UTILITIES_HYPERMEDIA_LINK_H
#define REST_UTILITIES_HYPERMEDIA_LINK_H

#include <string>
#include "rapidjson/document.h"

#include "UrlTemplate/UrlTemplate.h"

class Link
{
public:

    Link()
    {
    }

    virtual ~Link()
    {
    }

    void SetHref(const string &value)
    {
        mUrlTemplate.SetUrl(value);
    }

    const string &GetHref() const
    {
        return mUrlTemplate.GetUrl();
    }

    void SetTemplated(bool value)
    {
        mTemplated = value;
    }

    bool GetTemplated() const
    {
        return mTemplated;
    }

    void SetWithCredentials(bool value)
    {
        mWithCredentials = value;
    }

    bool GetWithCredentials() const
    {
        return mWithCredentials;
    }

    void SetParam(const string &key, const string &value)
    {
        mUrlTemplate.SetParam(key, value);
    }

    const string &GetParam(const string &key) const
    {
        return mUrlTemplate.GetParam(key);
    }

    void UnsetParam(const string &key)
    {
        mUrlTemplate.UnsetParam(key);
    }

    void ClearParams()
    {
        mUrlTemplate.ClearParams();
    }

    const string GetExpandedUrl()
    {
        return mUrlTemplate.Expand();
    }

    static bool CreateFromJsonString(const string &json, Link &link); // @TODO: Add ref obj for parse errors
    static bool CreateFromJson(const rapidjson::Value &value, Link &link); // @TODO: Add ref obj for parse errors

private:
    bool mTemplated;
    bool mWithCredentials;
    UrlTemplate mUrlTemplate;
};

#endif //REST_UTILITIES_HYPERMEDIA_LINK_H
