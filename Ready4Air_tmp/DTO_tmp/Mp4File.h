#ifndef READY4AIR_MP4FILE_H
#define READY4AIR_MP4FILE_H

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

        int GetLocation() const
        {
            return mLocation;
        }

        void SetLocation(int location)
        {
            mLocation = location;
        }

        const Link &GetMmsLink() const
        {
            return mMmsLink;
        }

        void SetMmsLink(const Link &mmsLink)
        {
            mMmsLink = mmsLink;
        }

        const std::string &GetLanguage() const
        {
            return mLanguage;
        }

        void SetLanguage(const std::string &language)
        {
            mLanguage = language;
        }

        short GetBandwidth() const
        {
            return mBandwidth;
        }

        void SetBandwidth(short bandwidth)
        {
            mBandwidth = bandwidth;
        }

    private:
        int mLocation;
        Link mMmsLink;
        std::string mLanguage;
        short mBandwidth;
    };
}

#endif //READY4AIR_MP4FILE_H
