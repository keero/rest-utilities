#ifndef READY4AIR_MP4FILE_H
#define READY4AIR_MP4FILE_H

#include "../common/Maybe.h"
#include "FileBase.h"
#include "hypermedia/Link.h"

namespace ready4air
{
    namespace dto
    {
        class Mp4File : public FileBase
        {
        public:
            Mp4File()
            {
            }

            virtual ~Mp4File()
            {
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

            virtual BOOL_T InitFromJsonValue(const rapidjson::Value &value, ParseErrors &parseErrors)
            {
                INT32_T location;
                Link mmsLink;
                STRING_T language;
                INT32_T bandwidth;

                // Initialize parent properties
                FileBase::InitFromJsonValue(value, parseErrors);

                if (ParseInt(value, "Location", true, location, parseErrors))
                    SetLocation(location);

                if (ParseObject(value, "MmsLink", false, mmsLink, parseErrors))
                    SetMmsLink(mmsLink);

                if (ParseString(value, "Language", false, language, parseErrors))
                    SetLanguage(language);

                if (ParseInt(value, "Bandwidth", true, bandwidth, parseErrors))
                    SetBandwidth((INT16_T) bandwidth);

                return !parseErrors;
            }

        private:
            Maybe<int> mLocation;
            Maybe <Link> mMmsLink;
            Maybe <STRING_T> mLanguage;
            Maybe<INT16_T> mBandwidth;
        };
    }
}

#endif //READY4AIR_MP4FILE_H
