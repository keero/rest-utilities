#ifndef READY4AIR_SMOOTHMANIFEST_H
#define READY4AIR_SMOOTHMANIFEST_H

#include "../common/Maybe.h"
#include "FileBase.h"

namespace ready4air
{
    namespace dto
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

            const Maybe<int> &GetManifestTypeId() const
            {
                return mManifestTypeId;
            }

            void SetManifestTypeId(int manifestTypeId)
            {
                mManifestTypeId = manifestTypeId;
            }

            const Maybe <STRING_T> &GetManifestTypeName() const
            {
                return mManifestTypeName;
            }

            void SetManifestTypeName(const STRING_T &manifestTypeName)
            {
                mManifestTypeName = manifestTypeName;
            }

            const Maybe<int> &GetLocation() const
            {
                return mLocation;
            }

            void SetLocation(int location)
            {
                mLocation = location;
            }

            virtual BOOL_T InitFromJsonValue(const rapidjson::Value &value, ParseErrors &parseErrors)
            {
                INT32_T manifestTypeId;
                STRING_T manifestTypeName;
                INT32_T location;

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
            Maybe<int> mManifestTypeId;
            Maybe <STRING_T> mManifestTypeName;
            Maybe<int> mLocation;
        };
    }
}

#endif //READY4AIR_SMOOTHMANIFEST_H
