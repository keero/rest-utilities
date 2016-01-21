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

            virtual bool InitFromJsonValue(const rapidjson::Value &value, ParseErrors &parseErrors)
            {
                int location;
                Link mmsLink;
                std::string language;
                int bandwidth;

                // Initialize parent properties
                FileBase::InitFromJsonValue(value, parseErrors);

                if (ParseInt(value, "Location", true, location, parseErrors))
                    SetLocation(location);

                if (ParseObject(value, "MmsLink", false, mmsLink, parseErrors))
                    SetMmsLink(mmsLink);

                if (ParseString(value, "Language", false, language, parseErrors))
                    SetLanguage(language);

                if (ParseInt(value, "Bandwidth", true, bandwidth, parseErrors))
                    SetBandwidth((short) bandwidth);

                return !parseErrors;
            }

        private:
            Maybe<int> mLocation;
            Maybe <Link> mMmsLink;
            Maybe <std::string> mLanguage;
            Maybe<short> mBandwidth;
        };
    }
}

#endif //READY4AIR_MP4FILE_H
