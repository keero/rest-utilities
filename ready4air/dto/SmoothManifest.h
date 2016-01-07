#ifndef READY4AIR_SMOOTHMANIFEST_H
#define READY4AIR_SMOOTHMANIFEST_H

#include "../maybe/Maybe.h"
#include "FileBase.h"

namespace ready4air
{
    class SmoothManifest : public FileBase
    {
    public:
        SmoothManifest()
        {
        }

        virtual ~SmoothManifest()
        {
        }

        const Maybe <int> &GetManifestTypeId() const
        {
            return mManifestTypeId;
        }

        void SetManifestTypeId(int manifestTypeId)
        {
            mManifestTypeId = manifestTypeId;
        }

        const Maybe <std::string> &GetManifestTypeName() const
        {
            return mManifestTypeName;
        }

        void SetManifestTypeName(const std::string &manifestTypeName)
        {
            mManifestTypeName = manifestTypeName;
        }

        const Maybe <int> &GetLocation() const
        {
            return mLocation;
        }

        void SetLocation(int location)
        {
            mLocation = location;
        }

        virtual bool InitFromJsonValue(const rapidjson::Value &value)
        {
            return false;
        }

    private:
        Maybe <int> mManifestTypeId;
        Maybe <std::string> mManifestTypeName;
        Maybe <int> mLocation;
    };
}

#endif //READY4AIR_SMOOTHMANIFEST_H
