#ifndef READY4AIR_PAYMENTDATA_H
#define READY4AIR_PAYMENTDATA_H

#include "../common/Maybe.h"
#include "abstract/JsonDeserializable.h"
#include "abstract/JsonSerializable.h"

namespace ready4air
{
    namespace dto
    {
        class PaymentData : public JsonDeserializable, public IJsonSerializable
        {
        public:
            PaymentData() : TAG("ready4air::dto::PaymentData")
            {
            }

            virtual ~PaymentData()
            {
            }

            const Maybe<STRING_T> &GetPhoneNumber() const
            {
                return mPhoneNumber;
            }

            void SetPhoneNumber(const STRING_T &phoneNumber)
            {
                mPhoneNumber = phoneNumber;
            }

            const Maybe<STRING_T> &GetReservationNumber() const
            {
                return mReservationNumber;
            }

            void SetReservationNumber(const STRING_T &reservationNumber)
            {
                mReservationNumber = reservationNumber;
            }

            const Maybe<int> &GetPin() const
            {
                return mPin;
            }

            void SetPin(int pin)
            {
                mPin = pin;
            }

            virtual BOOL_T InitFromJsonValue(const rapidjson::Value &value, ParseErrors &parseErrors,
                                             VECTOR_T<STRING_T> &context)
            {
                STRING_T phoneNumber;
                STRING_T reservationNumber;
                INT32_T pin;

                context.push_back(TAG);

                if (ParseString(value, "PhoneNumber", false, phoneNumber, parseErrors, context))
                    SetPhoneNumber(phoneNumber);

                if (ParseString(value, "ReservationNumber", false, reservationNumber, parseErrors, context))
                    SetReservationNumber(reservationNumber);

                if (ParseInt(value, "Pin", false, pin, parseErrors, context))
                    SetPin(pin);

                context.pop_back();
                return !parseErrors;
            }

            virtual const STRING_T ToJsonString(void) const
            {
                STRING_T result;
                rapidjson::StringBuffer s;
                rapidjson::Writer<rapidjson::StringBuffer> writer(s);

                writer.StartObject();
                if (GetPhoneNumber())
                {
                    writer.String("PhoneNumber");
                    writer.String(GetPhoneNumber().Just.c_str());
                }
                if (GetReservationNumber())
                {
                    writer.String("ReservationNumber");
                    writer.String(GetReservationNumber().Just.c_str());
                }
                if (GetPin())
                {
                    writer.String("Pin");
                    writer.Int(GetPin().Just);
                }
                writer.EndObject();
                result = s.GetString();
                return result;
            }

        private:
            Maybe<STRING_T> mPhoneNumber;
            Maybe<STRING_T> mReservationNumber;
            Maybe<int> mPin;
            STRING_T TAG;
        };

    }
}

#endif //READY4AIR_PAYMENTDATA_H
