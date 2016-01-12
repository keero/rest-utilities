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

        const Maybe <double> &GetAverageValue() const
        {
            return mAverageValue;
        }

        void SetAverageValue(double averageValue)
        {
            mAverageValue = averageValue;
        }

        virtual bool InitFromJsonValue(const rapidjson::Value &value, ParseErrors &parseErrors)
        {
            int numberOfVotes;
            int val;
            double averageValue;

            if (ParseInt(value, "NumberOfVotes", true, numberOfVotes, parseErrors))
                SetNumberOfVotes(numberOfVotes);

            if (ParseInt(value, "Value", true, val, parseErrors))
                SetValue(val);

            if (ParseDouble(value, "AverageValue", true, averageValue, parseErrors))
                SetAverageValue(averageValue);

            return !parseErrors;
        }

    private:
        Maybe <int> mNumberOfVotes;
        Maybe <int> mValue;
        Maybe <double> mAverageValue;
    };
}

#endif //READY4AIR_USERRATING_H
