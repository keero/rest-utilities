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
            HlsManifest() : TAG("ready4air::dto::HlsManifest")
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

            virtual BOOL_T InitFromJsonValue(const rapidjson::Value &value, ParseErrors &parseErrors,
                                             VECTOR_T<STRING_T> &context)
            {
                STRING_T language;
                INT32_T bandwidth;
                INT32_T manifestTypeId;
                STRING_T manifestTypeName;
                INT32_T location;
                Link mmsLink;

                context.push_back(TAG);

                // Initialize parent properties
                FileBase::InitFromJsonValue(value, parseErrors, context);

                if (ParseString(value, "Language", false, language, parseErrors, context))
                    SetLanguage(language);

                if (ParseInt(value, "Bandwidth", true, bandwidth, parseErrors, context))
                    SetBandwidth((INT16_T) bandwidth);

                if (ParseInt(value, "ManifestTypeId", false, manifestTypeId, parseErrors, context))
                    SetManifestTypeId(manifestTypeId);

                if (ParseString(value, "ManifestTypeName", false, manifestTypeName, parseErrors, context))
                    SetManifestTypeName(manifestTypeName);

                if (ParseInt(value, "Location", true, location, parseErrors, context))
                    SetLocation(location);

                if (ParseObject(value, "MmsLink", false, mmsLink, parseErrors, context))
                    SetMmsLink(mmsLink);

                context.pop_back();
                return !parseErrors;
            }

        private:
            Maybe <STRING_T> mLanguage;
            Maybe<INT16_T> mBandwidth;
            Maybe<int> mManifestTypeId;
            Maybe <STRING_T> mManifestTypeName;
            Maybe<int> mLocation;
            Maybe <Link> mMmsLink;
            STRING_T TAG;
        };
    }
}

#endif //READY4AIR_HLSMANIFEST_H
