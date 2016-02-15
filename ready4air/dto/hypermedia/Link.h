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
            Link() : TAG("ready4air::dto::Link")
            {
            }

            virtual ~Link()
            {
            }

            void SetHref(const STRING_T &value)
            {
                mUrlTemplate.SetUrl(value);
            }

            const Maybe<STRING_T> &GetHref() const
            {
                return mUrlTemplate.GetUrl();
            }

            void SetTemplated(BOOL_T value)
            {
                mTemplated = value;
            }

            Maybe<BOOL_T> GetTemplated() const
            {
                return mTemplated;
            }

            void SetWithCredentials(BOOL_T value)
            {
                mWithCredentials = value;
            }

            Maybe<BOOL_T> GetWithCredentials() const
            {
                return mWithCredentials;
            }

            void SetParam(const STRING_T &key, const STRING_T &value)
            {
                mUrlTemplate.SetParam(key, value);
            }

            const STRING_T &GetParam(const STRING_T &key) const
            {
                return mUrlTemplate.GetParam(key);
            }

            void UnsetParam(const STRING_T &key)
            {
                mUrlTemplate.UnsetParam(key);
            }

            void ClearParams()
            {
                mUrlTemplate.ClearParams();
            }

            const STRING_T GetExpandedUrl() const
            {
                return mUrlTemplate.Expand();
            }

            virtual BOOL_T InitFromJsonValue(const rapidjson::Value &value, ParseErrors &parseErrors,
                                             VECTOR_T<STRING_T> &context)
            {
                STRING_T href;
                BOOL_T templated;
                BOOL_T withCredentials;

                context.push_back(TAG);

                if (ParseString(value, "Href", true, href, parseErrors, context))
                    SetHref(href);

                if (ParseBool(value, "Templated", false, templated, parseErrors, context))
                    SetTemplated(templated);

                if (ParseBool(value, "WithCredentials", false, withCredentials, parseErrors, context))
                    SetWithCredentials(withCredentials);

                context.pop_back();
                return !parseErrors;
            }

        private:
            Maybe <BOOL_T> mTemplated;
            Maybe <BOOL_T> mWithCredentials;
            UrlTemplate mUrlTemplate;
            STRING_T TAG;
        };
    }
}

#endif //READY4AIR_HYPERMEDIA_LINK_H
