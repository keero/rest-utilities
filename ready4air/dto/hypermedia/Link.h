#ifndef READY4AIR_HYPERMEDIA_LINK_H
#define READY4AIR_HYPERMEDIA_LINK_H

#include "../../common/Maybe.h"
#include "../abstract/JsonDeserializable.h"
#include "../../urltemplate/UrlTemplate.h"

namespace ready4air
{
    namespace dto
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
                mTemplated = value;
            }

            Maybe<bool> GetTemplated() const
            {
                return mTemplated;
            }

            void SetWithCredentials(bool value)
            {
                mWithCredentials = value;
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

            const std::string GetExpandedUrl() const
            {
                return mUrlTemplate.Expand();
            }

            virtual bool InitFromJsonValue(const rapidjson::Value &value, ParseErrors &parseErrors)
            {
                std::string href;
                bool templated;
                bool withCredentials;

                if (ParseString(value, "Href", true, href, parseErrors))
                    SetHref(href);

                if (ParseBool(value, "Templated", false, templated, parseErrors))
                    SetTemplated(templated);

                if (ParseBool(value, "WithCredentials", false, withCredentials, parseErrors))
                    SetWithCredentials(withCredentials);

                return !parseErrors;
            }

        private:
            Maybe<bool> mTemplated;
            Maybe<bool> mWithCredentials;
            UrlTemplate mUrlTemplate;
        };
    }
}

#endif //READY4AIR_HYPERMEDIA_LINK_H
