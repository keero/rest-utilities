#ifndef READY4AIR_MANIFEST_H
#define READY4AIR_MANIFEST_H

#include "../common/Maybe.h"
#include "abstract/JsonDeserializable.h"
#include "hypermedia/Link.h"
#include "ProtectionData.h"

namespace ready4air
{
    namespace dto
    {
        class Manifest : public JsonDeserializable
        {
        public:
            Manifest() : TAG("ready4air::dto::Manifest")
            {
            }

            virtual ~Manifest()
            {
            }

            const Maybe<Link> &GetLink() const
            {
                return mLink;
            }

            void SetLink(const Link &link)
            {
                mLink = link;
            }

            const Maybe<ProtectionData> &GetProtectionData() const
            {
                return mProtectionData;
            }

            void SetProtectionData(const ProtectionData &protectionData)
            {
                mProtectionData = protectionData;
            }

            virtual BOOL_T InitFromJsonValue(const rapidjson::Value &value, ParseErrors &parseErrors,
                                             VECTOR_T<STRING_T> &context)
            {
                Link link;
                ProtectionData protectionData;

                context.push_back(TAG);

                if (ParseObject(value, "Link", true, link, parseErrors, context))
                    SetLink(link);

                if (ParseObject(value, "ProtectionData", false, protectionData, parseErrors, context))
                    SetProtectionData(protectionData);

                context.pop_back();
                return !parseErrors;
            }

        private:
            Maybe<Link> mLink;
            Maybe<ProtectionData> mProtectionData;
            STRING_T TAG;
        };
    }
}

#endif //READY4AIR_MANIFEST_H
