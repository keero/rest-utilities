#ifndef READY4AIR_HYPERMEDIA_LINK_H
#define READY4AIR_HYPERMEDIA_LINK_H

#include "../../maybe/Maybe.h"
#include "../abstract/JsonDeserializable.h"
#include "../../urltemplate/UrlTemplate.h"

namespace ready4air
{
    class Link : public JsonDeserializable
    {
    public:
        Link()
        {
        }

        virtual ~Link()
        {
        }

        void SetHref(const std::string &value)
        {
            mUrlTemplate.SetUrl(value);
        }

        const Maybe<std::string> &GetHref() const
        {
            return mUrlTemplate.GetUrl();
        }

        void SetTemplated(bool value)
        {
            mTemplated.Set(value);
        }

        Maybe<bool> GetTemplated() const
        {
            return mTemplated;
        }

        void SetWithCredentials(bool value)
        {
            mWithCredentials.Set(value);
        }

        Maybe<bool> GetWithCredentials() const
        {
            return mWithCredentials;
        }

        void SetParam(const std::string &key, const std::string &value)
        {
            mUrlTemplate.SetParam(key, value);
        }

        const std::string &GetParam(const std::string &key) const
        {
            return mUrlTemplate.GetParam(key);
        }

        void UnsetParam(const std::string &key)
        {
            mUrlTemplate.UnsetParam(key);
        }

        void ClearParams()
        {
            mUrlTemplate.ClearParams();
        }

        const std::string GetExpandedUrl()
        {
            return mUrlTemplate.Expand();
        }

        virtual bool InitFromJsonValue(const rapidjson::Value &value)
        {
            {
                // Mandatory property
                if (!value.HasMember("Href") || !value["Href"].IsString()) return false;
                SetHref(value["Href"].GetString());
            }
            {
                // Non-mandatory property
                if (value.HasMember("Templated"))
                {
                    if (!value["Templated"].IsBool()) return false;
                    SetTemplated(value["Templated"].GetBool());
                }
            }
            {
                // Non-mandatory property
                if (value.HasMember("WithCredentials"))
                {
                    if (!value["WithCredentials"].IsBool()) return false;
                    SetWithCredentials(value["WithCredentials"].GetBool());
                }
            }

            return true;
        }

    private:
        Maybe<bool> mTemplated;
        Maybe<bool> mWithCredentials;
        UrlTemplate mUrlTemplate;
    };
}

#endif //READY4AIR_HYPERMEDIA_LINK_H
