#ifndef READY4AIR_QUOTEIMAGES_H
#define READY4AIR_QUOTEIMAGES_H


#include "../common/Maybe.h"
#include "abstract/JsonDeserializable.h"
#include "QuoteImage.h"

namespace ready4air
{
    namespace dto
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

            const Maybe<QuoteImage> &GetSmallLogo() const
            {
                return mSmallLogo;
            }

            void SetSmallLogo(const QuoteImage &smallLogo)
            {
                mSmallLogo = smallLogo;
            }

            const Maybe<QuoteImage> &GetLargeLogo() const
            {
                return mLargeLogo;
            }

            void SetLargeLogo(const QuoteImage &largeLogo)
            {
                mLargeLogo = largeLogo;
            }

            const Maybe<QuoteImage> &GetScore() const
            {
                return mScore;
            }

            void SetScore(const QuoteImage &score)
            {
                mScore = score;
            }

            virtual bool InitFromJsonValue(const rapidjson::Value &value, ParseErrors &parseErrors)
            {
                QuoteImage smallLogo;
                QuoteImage largeLogo;
                QuoteImage score;

                if (ParseObject(value, "SmallLogo", false, smallLogo, parseErrors))
                    SetSmallLogo(smallLogo);

                if (ParseObject(value, "LargeLogo", false, largeLogo, parseErrors))
                    SetLargeLogo(largeLogo);

                if (ParseObject(value, "Score", false, score, parseErrors))
                    SetScore(score);

                return !parseErrors;
            }

        private:
            Maybe<QuoteImage> mSmallLogo;
            Maybe<QuoteImage> mLargeLogo;
            Maybe<QuoteImage> mScore;
        };
    }
}

#endif //READY4AIR_QUOTEIMAGES_H
