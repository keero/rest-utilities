#ifndef READY4AIR_USERRATING_H
#define READY4AIR_USERRATING_H

#include "../maybe/Maybe.h"
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

        const Maybe <int> &GetNumberOfVotes() const
        {
            return mNumberOfVotes;
        }

        void SetNumberOfVotes(int numberOfVotes)
        {
            mNumberOfVotes = numberOfVotes;
        }

        const Maybe <int> &GetValue() const
        {
            return mValue;
        }

        void SetValue(int value)
        {
            mValue = value;
        }

        const Maybe <float> &GetAverageValue() const
        {
            return mAverageValue;
        }

        void SetAverageValue(float averageValue)
        {
            mAverageValue = averageValue;
        }

        virtual bool InitFromJsonValue(const rapidjson::Value &value)
        {
            return false;
        }

    private:
        Maybe <int> mNumberOfVotes;
        Maybe <int> mValue;
        Maybe <float> mAverageValue;
    };
}

#endif //READY4AIR_USERRATING_H
