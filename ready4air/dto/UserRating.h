#ifndef READY4AIR_USERRATING_H
#define READY4AIR_USERRATING_H

#include "../common/Maybe.h"
#include "abstract/JsonDeserializable.h"

namespace ready4air
{
    namespace dto
    {
        class UserRating : public JsonDeserializable
        {
        public:
            UserRating() : TAG("ready4air::dto::UserRating")
            {
            }

            virtual ~UserRating()
            {
            }

            const Maybe<int> &GetNumberOfVotes() const
            {
                return mNumberOfVotes;
            }

            void SetNumberOfVotes(int numberOfVotes)
            {
                mNumberOfVotes = numberOfVotes;
            }

            const Maybe<int> &GetValue() const
            {
                return mValue;
            }

            void SetValue(int value)
            {
                mValue = value;
            }

            const Maybe<DOUBLE_T> &GetAverageValue() const
            {
                return mAverageValue;
            }

            void SetAverageValue(DOUBLE_T averageValue)
            {
                mAverageValue = averageValue;
            }

            virtual BOOL_T InitFromJsonValue(const rapidjson::Value &value, ParseErrors &parseErrors,
                                             VECTOR_T<STRING_T> &context)
            {
                INT32_T numberOfVotes;
                INT32_T val;
                DOUBLE_T averageValue;

                context.push_back(TAG);

                if (ParseInt(value, "NumberOfVotes", true, numberOfVotes, parseErrors, context))
                    SetNumberOfVotes(numberOfVotes);

                if (ParseInt(value, "Value", true, val, parseErrors, context))
                    SetValue(val);

                if (ParseDouble(value, "AverageValue", true, averageValue, parseErrors, context))
                    SetAverageValue(averageValue);

                context.pop_back();
                return !parseErrors;
            }

        private:
            Maybe<int> mNumberOfVotes;
            Maybe<int> mValue;
            Maybe<DOUBLE_T> mAverageValue;
            STRING_T TAG;
        };
    }
}

#endif //READY4AIR_USERRATING_H
