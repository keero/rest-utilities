#ifndef READY4AIR_HLSMANIFEST_H
#define READY4AIR_HLSMANIFEST_H

#include "FileBase.h"
#include "hypermedia/Link.h"

namespace ready4air
{
    class HlsManifest : public FileBase
    {
    public:
        HlsManifest()
        {
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

        const Link &GetMmsLink() const
        {
            return mMmsLink;
        }

        void SetMmsLink(const Link &mmsLink)
        {
            mMmsLink = mmsLink;
        }

        virtual bool InitFromJsonValue(const rapidjson::Value &value)
        {
            return false;
        }

    private:
        std::string mLanguage;
        short mBandwidth;
        int mManifestTypeId;
        std::string mManifestTypeName;
        int mLocation;
        Link mMmsLink;
    };
}

#endif //READY4AIR_HLSMANIFEST_H
