#ifndef READY4AIR_MANIFEST_H
#define READY4AIR_MANIFEST_H

#include "../maybe/Maybe.h"
#include "abstract/JsonDeserializable.h"
#include "hypermedia/Link.h"
#include "ProtectionData.h"

namespace ready4air
{
    class Manifest : public JsonDeserializable
    {
    public:
        Manifest()
        {
        }

        virtual ~Manifest()
        {
        }

        const Maybe <Link> &GetLink() const
        {
            return mLink;
        }

        void SetLink(const Link &link)
        {
            mLink = link;
        }

        const Maybe <ProtectionData> &GetProtectionData() const
        {
            return mProtectionData;
        }

        void SetProtectionData(const ProtectionData &protectionData)
        {
            mProtectionData = protectionData;
        }

        virtual bool InitFromJsonValue(const rapidjson::Value &value)
        {
            {
                // Mandatory property
                Link link;
                if (!value.HasMember("Link") || !value["Link"].IsObject() || !link.InitFromJsonValue(value["Link"])) return false;
                SetLink(link);
            }
            {
                // Non-mandatory property
                if (value.HasMember("ProtectionData"))
                {
                    ProtectionData protectionData;
                    if (!value["ProtectionData"].IsObject() || !protectionData.InitFromJsonValue(value["ProtectionData"])) return false;
                    SetProtectionData(protectionData);
                }
            }

            return true;
        }

    private:
        Maybe <Link> mLink;
        Maybe <ProtectionData> mProtectionData;
    };
}

#endif //READY4AIR_MANIFEST_H
