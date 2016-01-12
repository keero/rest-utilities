#ifndef READY4AIR_WMVFILE_H
#define READY4AIR_WMVFILE_H

#include "../maybe/Maybe.h"
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

        virtual bool InitFromJsonValue(const rapidjson::Value &value, ParseErrors &parseErrors)
        {
            int location;
            Link mmsLink;

            // Initialize parent properties
            FileBase::InitFromJsonValue(value, parseErrors));

            if (ParseInt(value, "Location", true, location, parseErrors))
                SetLocation(location);

            if (ParseObject(value, "MmsLink", false, mmsLink, parseErrors))
                SetMmsLink(mmsLink);

            return !parseErrors;
        }

    private:
        Maybe <int> mLocation;
        Maybe <Link> mMmsLink;
    };
}

#endif //READY4AIR_WMVFILE_H
