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
            QuoteImages() : TAG("ready4air::dto::QuoteImages")
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

            virtual BOOL_T InitFromJsonValue(const rapidjson::Value &value, ParseErrors &parseErrors,
                                             VECTOR_T<STRING_T> &context)
            {
                QuoteImage smallLogo;
                QuoteImage largeLogo;
                QuoteImage score;

                context.push_back(TAG);

                if (ParseObject(value, "SmallLogo", false, smallLogo, parseErrors, context))
                    SetSmallLogo(smallLogo);

                if (ParseObject(value, "LargeLogo", false, largeLogo, parseErrors, context))
                    SetLargeLogo(largeLogo);

                if (ParseObject(value, "Score", false, score, parseErrors, context))
                    SetScore(score);

                context.pop_back();
                return !parseErrors;
            }

        private:
            Maybe<QuoteImage> mSmallLogo;
            Maybe<QuoteImage> mLargeLogo;
            Maybe<QuoteImage> mScore;
            STRING_T TAG;
        };
    }
}

#endif //READY4AIR_QUOTEIMAGES_H
