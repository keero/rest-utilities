#ifndef READY4AIR_MANIFEST_H
#define READY4AIR_MANIFEST_H

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

        const Link &GetLink() const
        {
            return mLink;
        }

        void SetLink(const Link &link)
        {
            mLink = link;
        }

        const ProtectionData &GetProtectionData() const
        {
            return mProtectionData;
        }

        void SetProtectionData(const ProtectionData &protectionData)
        {
            mProtectionData = protectionData;
        }

    private:
        Link mLink;
        ProtectionData mProtectionData;
    };
}

#endif //READY4AIR_MANIFEST_H
