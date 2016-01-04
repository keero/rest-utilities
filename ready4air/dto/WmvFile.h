#ifndef READY4AIR_WMVFILE_H
#define READY4AIR_WMVFILE_H

#include "FileBase.h"
#include "hypermedia/Link.h"

namespace ready4air
{
    class WmvFile : public FileBase
    {
    public:
        WmvFile()
        {
        }

        virtual ~WmvFile()
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

        virtual bool InitFromJsonValue(const rapidjson::Value &value)
        {
            return false;
        }

    private:
        int mLocation;
        Link mMmsLink;
    };
}

#endif //READY4AIR_WMVFILE_H
