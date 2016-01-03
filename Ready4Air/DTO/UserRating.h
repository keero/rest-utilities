#ifndef READY4AIR_USERRATING_H
#define READY4AIR_USERRATING_H

#include "abstract/JsonDeserializable.h"

namespace ready4air
{
    class UserRating : public JsonDeserializable
    {
    public:
        UserRating()
        {
        }

        virtual ~UserRating()
        {
        }

        int GetNumberOfVotes() const
        {
            return mNumberOfVotes;
        }

        void SetNumberOfVotes(int numberOfVotes)
        {
            mNumberOfVotes = numberOfVotes;
        }

        int GetValue() const
        {
            return mValue;
        }

        void SetValue(int value)
        {
            mValue = value;
        }

        float GetAverageValue() const
        {
            return mAverageValue;
        }

        void SetAverageValue(float averageValue)
        {
            mAverageValue = averageValue;
        }

    private:
        int mNumberOfVotes;
        int mValue;
        float mAverageValue;
    };
}

#endif //READY4AIR_USERRATING_H
