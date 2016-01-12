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

        virtual bool InitFromJsonValue(const rapidjson::Value &value, ParseErrors &parseErrors)
        {
            int manifestTypeId;
            std::string manifestTypeName;
            int location;

            // Initialize parent properties
            FileBase::InitFromJsonValue(value, parseErrors);

            if (ParseInt(value, "ManifestTypeId", true, manifestTypeId, parseErrors))
                SetManifestTypeId(manifestTypeId);

            if (ParseString(value, "ManifestTypeName", true, manifestTypeName, parseErrors))
                SetManifestTypeName(manifestTypeName);

            if (ParseInt(value, "Location", true, location, parseErrors))
                SetLocation(location);

            return !parseErrors;
        }

    private:
        Maybe <int> mManifestTypeId;
        Maybe <std::string> mManifestTypeName;
        Maybe <int> mLocation;
    };
}

#endif //READY4AIR_SMOOTHMANIFEST_H
