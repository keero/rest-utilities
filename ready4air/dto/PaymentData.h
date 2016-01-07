#ifndef READY4AIR_PAYMENTDATA_H
#define READY4AIR_PAYMENTDATA_H

#include "../maybe/Maybe.h"
#include "abstract/JsonDeserializable.h"

namespace ready4air
{
    class PaymentData : public JsonDeserializable
    {
    public:
        PaymentData()
        {
        }

        virtual ~PaymentData()
        {
        }

        const Maybe <std::string> &GetPhoneNumber() const
        {
            return mPhoneNumber;
        }

        void SetPhoneNumber(const std::string &phoneNumber)
        {
            mPhoneNumber = phoneNumber;
        }

        const Maybe <std::string> &GetReservationNumber() const
        {
            return mReservationNumber;
        }

        void SetReservationNumber(const std::string &reservationNumber)
        {
            mReservationNumber = reservationNumber;
        }

        const Maybe <int> &GetPin() const
        {
            return mPin;
        }

        void SetPin(int pin)
        {
            mPin = pin;
        }

        virtual bool InitFromJsonValue(const rapidjson::Value &value)
        {
            return false;
        }

    private:
        Maybe <std::string> mPhoneNumber;
        Maybe <std::string> mReservationNumber;
        Maybe <int> mPin;
    };
}

#endif //READY4AIR_PAYMENTDATA_H
