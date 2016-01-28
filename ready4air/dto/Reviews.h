#ifndef READY4AIR_REVIEWS_H
#define READY4AIR_REVIEWS_H

#include "../common/Maybe.h"
#include "abstract/JsonDeserializable.h"
#include "UserRating.h"
#include "CriticsQuote.h"

namespace ready4air
{
    namespace dto
    {
        class Reviews : public JsonDeserializable
        {
        public:
            Reviews() : TAG("ready4air::dto::Reviews")
            {
            }

            virtual ~Reviews()
            {
            }

            const Maybe<UserRating> &GetUserRating() const
            {
                return mUserRating;
            }

            void SetUserRating(const UserRating &userRating)
            {
                mUserRating = userRating;
            }

            const Maybe<STRING_T> &GetFormattedAverageCriticsScore() const
            {
                return mFormattedAverageCriticsScore;
            }

            void SetFormattedAverageCriticsScore(const STRING_T &formattedAverageCriticsScore)
            {
                mFormattedAverageCriticsScore = formattedAverageCriticsScore;
            }

            const Maybe<VECTOR_T<CriticsQuote> > &GetCriticsQuotes() const
            {
                return mCriticsQuotes;
            }

            void SetCriticsQuotes(const VECTOR_T<CriticsQuote> &criticsQuotes)
            {
                mCriticsQuotes = criticsQuotes;
            }

            virtual BOOL_T InitFromJsonValue(const rapidjson::Value &value, ParseErrors &parseErrors)
            {
                UserRating userRating;
                STRING_T formattedAverageCriticsScore;
                VECTOR_T<CriticsQuote> criticsQuotes;

                if (ParseObject(value, "UserRating", false, userRating, parseErrors))
                    SetUserRating(userRating);

                if (ParseString(value, "FormattedAverageCriticsScore", false, formattedAverageCriticsScore,
                                parseErrors))
                    SetFormattedAverageCriticsScore(formattedAverageCriticsScore);

                if (VerifyArray(value, "CriticsQuotes", false, parseErrors))
                {
                    for (rapidjson::SizeType i = 0; i < value["CriticsQuotes"].Size(); i += 1)
                    {
                        CriticsQuote criticsQuote;
                        if (ParseObject(value["CriticsQuotes"][i], "", false, criticsQuote, parseErrors))
                            criticsQuotes.push_back(criticsQuote);
                    }
                    SetCriticsQuotes(criticsQuotes);
                }

                return !parseErrors;
            }

        private:
            Maybe<UserRating> mUserRating;
            Maybe<STRING_T> mFormattedAverageCriticsScore;
            Maybe<VECTOR_T<CriticsQuote> > mCriticsQuotes;
            const STRING_T TAG;
        };
    }
}

#endif //READY4AIR_REVIEWS_H
