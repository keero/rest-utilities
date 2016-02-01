#ifndef READY4AIR_PLAY_H
#define READY4AIR_PLAY_H

#include "../common/Maybe.h"
#include "abstract/JsonDeserializable.h"
#include "Manifests.h"

namespace ready4air
{
    namespace dto
    {
        class Play : public JsonDeserializable
        {
        public:
            Play() : TAG("ready4air::dto::Play")
            {
            }

            virtual ~Play()
            {
            }

            const Maybe<int> &GetProductId() const
            {
                return mProductId;
            }

            void SetProductId(int productId)
            {
                mProductId = productId;
            }

            const Maybe<Manifests> &GetTrailers() const
            {
                return mTrailers;
            }

            void SetTrailers(const Manifests &trailers)
            {
                mTrailers = trailers;
            }

            const Maybe<Manifests> &GetFeatures() const
            {
                return mFeatures;
            }

            void SetFeatures(const Manifests &features)
            {
                mFeatures = features;
            }

            virtual BOOL_T InitFromJsonValue(const rapidjson::Value &value, ParseErrors &parseErrors)
            {
                INT32_T productId;
                Manifests trailers;
                Manifests features;

                if (ParseInt(value, "ProductId", true, productId, parseErrors))
                    SetProductId(productId);

                if (ParseObject(value, "Trailers", false, trailers, parseErrors))
                    SetTrailers(trailers);

                if (ParseObject(value, "Features", false, features, parseErrors))
                    SetFeatures(features);

                return !parseErrors;
            }

        private:
            Maybe<int> mProductId;
            Maybe<Manifests> mTrailers;
            Maybe<Manifests> mFeatures;
            STRING_T TAG;
        };
    }
}

#endif //READY4AIR_PLAY_H
