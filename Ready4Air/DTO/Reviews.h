#ifndef READY4AIR_REVIEWS_H
#define READY4AIR_REVIEWS_H

#include "abstract/JsonDeserializable.h"
#include "UserRating.h"
#include "CriticsQuote.h"

namespace ready4air
{
    class Reviews : public JsonDeserializable
    {
    public:
        Reviews()
        {
        }

        virtual ~Reviews()
        {
        }

        const UserRating &GetUserRating() const
        {
            return mUserRating;
        }

        void SetUserRating(const UserRating &userRating)
        {
            mUserRating = userRating;
        }

        const std::string &GetFormattedAverageCriticsScore() const
        {
            return mFormattedAverageCriticsScore;
        }

        void SetFormattedAverageCriticsScore(const std::string &formattedAverageCriticsScore)
        {
            mFormattedAverageCriticsScore = formattedAverageCriticsScore;
        }

        const std::vector<CriticsQuote> &GetCriticsQuotes() const
        {
            return mCriticsQuotes;
        }

        void SetCriticsQuotes(const std::vector<CriticsQuote> &criticsQuotes)
        {
            mCriticsQuotes = criticsQuotes;
        }

    private:
        UserRating mUserRating;
        std::string mFormattedAverageCriticsScore;
        std::vector<CriticsQuote> mCriticsQuotes;
    };
}

#endif //READY4AIR_REVIEWS_H
