#ifndef READY4AIR_SMOOTHMANIFEST_H
#define READY4AIR_SMOOTHMANIFEST_H

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

        int GetManifestTypeId() const
        {
            return mManifestTypeId;
        }

        void SetManifestTypeId(int manifestTypeId)
        {
            mManifestTypeId = manifestTypeId;
        }

        const std::string &GetManifestTypeName() const
        {
            return mManifestTypeName;
        }

        void SetManifestTypeName(const std::string &manifestTypeName)
        {
            mManifestTypeName = manifestTypeName;
        }

        int GetLocation() const
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
        int mManifestTypeId;
        std::string mManifestTypeName;
        int mLocation;
    };
}

#endif //READY4AIR_SMOOTHMANIFEST_H
