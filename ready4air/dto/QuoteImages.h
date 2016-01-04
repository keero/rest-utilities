#ifndef READY4AIR_QUOTEIMAGES_H
#define READY4AIR_QUOTEIMAGES_H


#include "abstract/JsonDeserializable.h"
#include "QuoteImage.h"

namespace ready4air
{
    class QuoteImages : public JsonDeserializable
    {
    public:
        QuoteImages()
        {
        }

        virtual ~QuoteImages()
        {
        }

        const QuoteImage &GetSmallLogo() const
        {
            return mSmallLogo;
        }

        void SetSmallLogo(const QuoteImage &smallLogo)
        {
            mSmallLogo = smallLogo;
        }

        const QuoteImage &GetLargeLogo() const
        {
            return mLargeLogo;
        }

        void SetLargeLogo(const QuoteImage &largeLogo)
        {
            mLargeLogo = largeLogo;
        }

        const QuoteImage &GetScore() const
        {
            return mScore;
        }

        void SetScore(const QuoteImage &score)
        {
            mScore = score;
        }

        virtual bool InitFromJsonValue(const rapidjson::Value &value)
        {
            return false;
        }

    private:
        QuoteImage mSmallLogo;
        QuoteImage mLargeLogo;
        QuoteImage mScore;
    };
}

#endif //READY4AIR_QUOTEIMAGES_H
