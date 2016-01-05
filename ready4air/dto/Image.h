#ifndef READY4AIR_IMAGE_H
#define READY4AIR_IMAGE_H

#include "FileBase.h"
#include "hypermedia/Link.h"

namespace ready4air
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

        const Link &GetSecureLink() const
        {
            return mSecureLink;
        }

        void SetSecureLink(const Link &secureLink)
        {
            mSecureLink = secureLink;
        }

        virtual bool InitFromJsonValue(const rapidjson::Value &value)
        {
            // Initialize parent properties
            if (!FileBase::InitFromJsonValue(value)) return false;

            {
                // Non-mandatory property
                if (value.HasMember("SecureLink"))
                {
                    Link secureLink;
                    if (!value["SecureLink"].IsObject() || !secureLink.InitFromJsonValue(value["SecureLink"])) return false;
                    SetSecureLink(secureLink);
                }
            }
            return true;
        }

    private:
        Link mSecureLink;
    };
}

#endif //READY4AIR_IMAGE_H
