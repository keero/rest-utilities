#ifndef READY4AIR_PAYMENTDATA_H
#define READY4AIR_PAYMENTDATA_H

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

        const std::string &GetPhoneNumber() const
        {
            return mPhoneNumber;
        }

        void SetPhoneNumber(const std::string &phoneNumber)
        {
            mPhoneNumber = phoneNumber;
        }

        const std::string &GetReservationNumber() const
        {
            return mReservationNumber;
        }

        void SetReservationNumber(const std::string &reservationNumber)
        {
            mReservationNumber = reservationNumber;
        }

        int GetPin() const
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
        std::string mPhoneNumber;
        std::string mReservationNumber;
        int mPin;
    };
}

#endif //READY4AIR_PAYMENTDATA_H
