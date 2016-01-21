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

            const Maybe <std::string> &GetLanguage() const
            {
                return mLanguage;
            }

            void SetLanguage(const std::string &language)
            {
                mLanguage = language;
            }

            const Maybe<short> &GetBandwidth() const
            {
                return mBandwidth;
            }

            void SetBandwidth(short bandwidth)
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

            const Maybe <std::string> &GetManifestTypeName() const
            {
                return mManifestTypeName;
            }

            void SetManifestTypeName(const std::string &manifestTypeName)
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

            virtual bool InitFromJsonValue(const rapidjson::Value &value, ParseErrors &parseErrors)
            {
                std::string language;
                int bandwidth;
                int manifestTypeId;
                std::string manifestTypeName;
                int location;
                Link mmsLink;

                // Initialize parent properties
                FileBase::InitFromJsonValue(value, parseErrors);

                if (ParseString(value, "Language", false, language, parseErrors))
                    SetLanguage(language);

                if (ParseInt(value, "Bandwidth", true, bandwidth, parseErrors))
                    SetBandwidth((short) bandwidth);

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
            Maybe <std::string> mLanguage;
            Maybe<short> mBandwidth;
            Maybe<int> mManifestTypeId;
            Maybe <std::string> mManifestTypeName;
            Maybe<int> mLocation;
            Maybe <Link> mMmsLink;
        };
    }
}

#endif //READY4AIR_HLSMANIFEST_H
