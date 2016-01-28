#ifndef READY4AIR_TEASER_H
#define READY4AIR_TEASER_H

#include "../common/Maybe.h"
#include "abstract/JsonDeserializable.h"
#include "MediaProduct.h"

namespace ready4air
{
    namespace dto
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

            const Maybe <VECTOR_T<MediaProduct> > &GetMedias() const
            {
                return mMedias;
            }

            void SetMedias(const VECTOR_T<MediaProduct> &medias)
            {
                mMedias = medias;
            }

            virtual BOOL_T InitFromJsonValue(const rapidjson::Value &value, ParseErrors &parseErrors)
            {
                VECTOR_T<MediaProduct> medias;

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
            Maybe <VECTOR_T<MediaProduct> > mMedias;
        };
    }
}

#endif //READY4AIR_TEASER_H
