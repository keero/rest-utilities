#ifndef READY4AIR_WMVFILE_H
#define READY4AIR_WMVFILE_H

#include "../common/Maybe.h"
#include "FileBase.h"
#include "hypermedia/Link.h"

namespace ready4air
{
    namespace dto
    {
        class WmvFile : public FileBase
        {
        public:
            WmvFile() : TAG("ready4air::dto::WmvFile")
            {
            }

            virtual ~WmvFile()
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

            virtual BOOL_T InitFromJsonValue(const rapidjson::Value &value, ParseErrors &parseErrors)
            {
                INT32_T location;
                Link mmsLink;

                // Initialize parent properties
                FileBase::InitFromJsonValue(value, parseErrors);

                if (ParseInt(value, "Location", true, location, parseErrors))
                    SetLocation(location);

                if (ParseObject(value, "MmsLink", false, mmsLink, parseErrors))
                    SetMmsLink(mmsLink);

                return !parseErrors;
            }

        private:
            Maybe<int> mLocation;
            Maybe <Link> mMmsLink;
            const STRING_T TAG;
        };
    }
}

#endif //READY4AIR_WMVFILE_H
