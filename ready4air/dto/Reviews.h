#ifndef READY4AIR_REVIEWS_H
#define READY4AIR_REVIEWS_H

#include "../maybe/Maybe.h"
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

        const Maybe <UserRating> &GetUserRating() const
        {
            return mUserRating;
        }

        void SetUserRating(const UserRating &userRating)
        {
            mUserRating = userRating;
        }

        const Maybe <std::string> &GetFormattedAverageCriticsScore() const
        {
            return mFormattedAverageCriticsScore;
        }

        void SetFormattedAverageCriticsScore(const std::string &formattedAverageCriticsScore)
        {
            mFormattedAverageCriticsScore = formattedAverageCriticsScore;
        }

        const Maybe <std::vector<CriticsQuote> > &GetCriticsQuotes() const
        {
            return mCriticsQuotes;
        }

        void SetCriticsQuotes(const std::vector<CriticsQuote> &criticsQuotes)
        {
            mCriticsQuotes = criticsQuotes;
        }

        virtual bool InitFromJsonValue(const rapidjson::Value &value, ParseErrors &parseErrors)
        {
            UserRating userRating;
            std::string formattedAverageCriticsScore;
            std::vector<CriticsQuote> criticsQuotes;

            if (ParseObject(value, "UserRating", false, userRating, parseErrors))
                SetUserRating(userRating);

            if (ParseString(value, "FormattedAverageCriticsScore", false, formattedAverageCriticsScore, parseErrors))
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
        Maybe <UserRating> mUserRating;
        Maybe <std::string> mFormattedAverageCriticsScore;
        Maybe <std::vector<CriticsQuote> > mCriticsQuotes;
    };
}

#endif //READY4AIR_REVIEWS_H
