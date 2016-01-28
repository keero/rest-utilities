#ifndef READY4AIR_HLSMANIFEST_H
#define READY4AIR_HLSMANIFEST_H

#include "../common/Maybe.h"
#include "FileBase.h"
#include "hypermedia/Link.h"

namespace ready4air
{
    namespace dto
    {
        class HlsManifest : public FileBase
        {
        public:
            HlsManifest()
            {
            }

            const Maybe <STRING_T> &GetLanguage() const
            {
                return mLanguage;
            }

            void SetLanguage(const STRING_T &language)
            {
                mLanguage = language;
            }

            const Maybe<INT16_T> &GetBandwidth() const
            {
                return mBandwidth;
            }

            void SetBandwidth(INT16_T bandwidth)
            {
                mBandwidth = bandwidth;
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

            const Maybe <Link> &GetMmsLink() const
            {
                return mMmsLink;
            }

            void SetMmsLink(const Link &mmsLink)
            {
                mMmsLink = mmsLink;
            }

            virtual BOOL_T InitFromJsonValue(const rapidjson::Value &value, ParseErrors &parseErrors)
            {
                STRING_T language;
                INT32_T bandwidth;
                INT32_T manifestTypeId;
                STRING_T manifestTypeName;
                INT32_T location;
                Link mmsLink;

                // Initialize parent properties
                FileBase::InitFromJsonValue(value, parseErrors);

                if (ParseString(value, "Language", false, language, parseErrors))
                    SetLanguage(language);

                if (ParseInt(value, "Bandwidth", true, bandwidth, parseErrors))
                    SetBandwidth((INT16_T) bandwidth);

                if (ParseInt(value, "ManifestTypeId", false, manifestTypeId, parseErrors))
                    SetManifestTypeId(manifestTypeId);

                if (ParseString(value, "ManifestTypeName", false, manifestTypeName, parseErrors))
                    SetManifestTypeName(manifestTypeName);

                if (ParseInt(value, "Location", true, location, parseErrors))
                    SetLocation(location);

                if (ParseObject(value, "MmsLink", false, mmsLink, parseErrors))
                    SetMmsLink(mmsLink);

                return !parseErrors;
            }

        private:
            Maybe <STRING_T> mLanguage;
            Maybe<INT16_T> mBandwidth;
            Maybe<int> mManifestTypeId;
            Maybe <STRING_T> mManifestTypeName;
            Maybe<int> mLocation;
            Maybe <Link> mMmsLink;
        };
    }
}

#endif //READY4AIR_HLSMANIFEST_H
