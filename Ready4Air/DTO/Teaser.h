#ifndef READY4AIR_TEASER_H
#define READY4AIR_TEASER_H

#include "abstract/JsonDeserializable.h"
#include "MediaProduct.h"

namespace ready4air
{
    class Teaser : public JsonDeserializable
    {
    public:
        Teaser()
        {
        }

        virtual ~Teaser()
        {
        }

        const std::vector<MediaProduct> &GetMedias() const
        {
            return mMedias;
        }

        void SetMedias(const std::vector<MediaProduct> &medias)
        {
            mMedias = medias;
        }

    private:
        std::vector<MediaProduct> mMedias;
    };
}

#endif //READY4AIR_TEASER_H
