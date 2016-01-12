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

        virtual bool InitFromJsonValue(const rapidjson::Value &value, ParseErrors &parseErrors)
        {
            Link link;
            ProtectionData protectionData;

            if (ParseObject(value, "Link", true, link, parseErrors))
                SetLink(link);

            if (ParseObject(value, "ProtectionData", false, protectionData, parseErrors))
                SetProtectionData(protectionData);

            return !parseErrors;
        }

    private:
        Maybe <Link> mLink;
        Maybe <ProtectionData> mProtectionData;
    };
}

#endif //READY4AIR_MANIFEST_H
