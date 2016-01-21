#ifndef READY4AIR_IMAGE_H
#define READY4AIR_IMAGE_H

#include "../common/Maybe.h"
#include "FileBase.h"
#include "hypermedia/Link.h"

namespace ready4air
{
    namespace dto
    {
        class Image : public FileBase
        {
        public:
            Image()
            {
            }

            virtual ~Image()
            {
            }

            const Maybe<Link> &GetSecureLink() const
            {
                return mSecureLink;
            }

            void SetSecureLink(const Link &secureLink)
            {
                mSecureLink = secureLink;
            }

            virtual bool InitFromJsonValue(const rapidjson::Value &value, ParseErrors &parseErrors)
            {
                Link secureLink;

                // Initialize parent properties
                FileBase::InitFromJsonValue(value, parseErrors);

                if (ParseObject(value, "SecureLink", false, secureLink, parseErrors))
                    SetSecureLink(secureLink);

                return !parseErrors;
            }

        private:
            Maybe<Link> mSecureLink;
        };
    }
}

#endif //READY4AIR_IMAGE_H
