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

    private:
        Link mSecureLink;
    };
}

#endif //READY4AIR_IMAGE_H
