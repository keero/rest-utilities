#ifndef READY4AIR_PAYMENTDATA_H
#define READY4AIR_PAYMENTDATA_H

#include "../common/Maybe.h"
#include "abstract/JsonDeserializable.h"

namespace ready4air
{
    namespace dto
    {
        class PaymentData : public JsonDeserializable
        {
        public:
            PaymentData() : TAG("ready4air::dto::PaymentData")
            {
            }

            virtual ~PaymentData()
            {
            }

            const Maybe <STRING_T> &GetPhoneNumber() const
            {
                return mPhoneNumber;
            }

            void SetPhoneNumber(const STRING_T &phoneNumber)
            {
                mPhoneNumber = phoneNumber;
            }

            const Maybe <STRING_T> &GetReservationNumber() const
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

            virtual BOOL_T InitFromJsonValue(const rapidjson::Value &value, ParseErrors &parseErrors)
            {
                STRING_T phoneNumber;
                STRING_T reservationNumber;
                INT32_T pin;

                if (ParseString(value, "PhoneNumber", false, phoneNumber, parseErrors))
                    SetPhoneNumber(phoneNumber);

                if (ParseString(value, "ReservationNumber", false, reservationNumber, parseErrors))
                    SetReservationNumber(reservationNumber);

                if (ParseInt(value, "Pin", false, pin, parseErrors))
                    SetPin(pin);

                return !parseErrors;
            }

        private:
            Maybe <STRING_T> mPhoneNumber;
            Maybe <STRING_T> mReservationNumber;
            Maybe<int> mPin;
            STRING_T TAG;
        };
    }
}

#endif //READY4AIR_PAYMENTDATA_H
