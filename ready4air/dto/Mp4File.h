#ifndef READY4AIR_MP4FILE_H
#define READY4AIR_MP4FILE_H

#include "../maybe/Maybe.h"
#include "FileBase.h"
#include "hypermedia/Link.h"

namespace ready4air
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

        const Maybe <int> &GetLocation() const
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

        const Maybe <short> &GetBandwidth() const
        {
            return mBandwidth;
        }

        void SetBandwidth(short bandwidth)
        {
            mBandwidth = bandwidth;
        }

        virtual bool InitFromJsonValue(const rapidjson::Value &value)
        {
            return false;
        }

    private:
        Maybe <int> mLocation;
        Maybe <Link> mMmsLink;
        Maybe <std::string> mLanguage;
        Maybe <short> mBandwidth;
    };
}

#endif //READY4AIR_MP4FILE_H
