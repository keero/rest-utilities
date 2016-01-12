#ifndef READY4AIR_TEASER_H
#define READY4AIR_TEASER_H

#include "../maybe/Maybe.h"
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

        const Maybe <std::vector<MediaProduct> > &GetMedias() const
        {
            return mMedias;
        }

        void SetMedias(const std::vector<MediaProduct> &medias)
        {
            mMedias = medias;
        }

        virtual bool InitFromJsonValue(const rapidjson::Value &value, ParseErrors &parseErrors)
        {
            std::vector<MediaProduct> medias;

            if (VerifyArray(value, "Medias", true, parseErrors))
            {
                for (rapidjson::SizeType i = 0; i < value["Medias"].Size(); i += 1)
                {
                    MediaProduct mediaProduct;
                    if (ParseObject(value["Medias"][i], "", false, mediaProduct, parseErrors))
                        medias.push_back(mediaProduct);
                }
                SetMedias(medias);
            }

            return !parseErrors;
        }

    private:
        Maybe <std::vector<MediaProduct> > mMedias;
    };
}

#endif //READY4AIR_TEASER_H
