#ifndef READY4AIR_PLAY_H
#define READY4AIR_PLAY_H

#include "abstract/JsonDeserializable.h"
#include "Manifests.h"

namespace ready4air
{
    class Play : public JsonDeserializable
    {
    public:
        Play()
        {
        }

        virtual ~Play()
        {
        }

        int GetProductId() const
        {
            return mProductId;
        }

        void SetProductId(int productId)
        {
            mProductId = productId;
        }

        const Manifests &GetTrailers() const
        {
            return mTrailers;
        }

        void SetTrailers(const Manifests &trailers)
        {
            mTrailers = trailers;
        }

        const Manifests &GetFeatures() const
        {
            return mFeatures;
        }

        void SetFeatures(const Manifests &features)
        {
            mFeatures = features;
        }

    private:
        int mProductId;
        Manifests mTrailers;
        Manifests mFeatures;
    };
}

#endif //READY4AIR_PLAY_H
