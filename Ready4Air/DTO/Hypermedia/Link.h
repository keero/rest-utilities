#ifndef REST_UTILITIES_HYPERMEDIA_LINK_H
#define REST_UTILITIES_HYPERMEDIA_LINK_H

#include <string>
#include <include/rapidjson/document.h>
#include <Ready4Air/DTO/Abstract/JsonDeserializable.h>

#include "UrlTemplate/UrlTemplate.h"

class Link : public JsonDeserializable
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

    virtual bool InitFromJsonValue(const rapidjson::Value &value);

private:
    bool mTemplated;
    bool mWithCredentials;
    UrlTemplate mUrlTemplate;
};

#endif //REST_UTILITIES_HYPERMEDIA_LINK_H
