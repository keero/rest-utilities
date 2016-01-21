#ifndef READY4AIR_PURCHASEINFO_H
#define READY4AIR_PURCHASEINFO_H

#include "../common/Maybe.h"
#include "abstract/JsonDeserializable.h"
#include "Purchase.h"
#include "PaymentData.h"

namespace ready4air
{
    namespace dto
    {
        class PurchaseInfo : public JsonDeserializable
        {
        public:
            PurchaseInfo()
            {
            }

            virtual ~PurchaseInfo()
            {
            }

            const Maybe<Purchase> &GetPurchase() const
            {
                return mPurchase;
            }

            void SetPurchase(const Purchase &purchase)
            {
                mPurchase = purchase;
            }

            const Maybe<std::string> &GetPurchaseType() const
            {
                return mPurchaseType;
            }

            void SetPurchaseType(const std::string &purchaseType)
            {
                mPurchaseType = purchaseType;
            }

            const Maybe<PaymentData> &GetPaymentData() const
            {
                return mPaymentData;
            }

            void SetPaymentData(const PaymentData &paymentData)
            {
                mPaymentData = paymentData;
            }

            virtual bool InitFromJsonValue(const rapidjson::Value &value, ParseErrors &parseErrors)
            {
                Purchase purchase;
                std::string purchaseType;
                PaymentData paymentData;

                if (ParseObject(value, "Purchase", true, purchase, parseErrors))
                    SetPurchase(purchase);

                if (ParseString(value, "PurchaseType", true, purchaseType, parseErrors))
                    SetPurchaseType(purchaseType);

                if (ParseObject(value, "PaymentData", false, paymentData, parseErrors))
                    SetPaymentData(paymentData);

                return !parseErrors;
            }

        private:
            Maybe<Purchase> mPurchase;
            Maybe<std::string> mPurchaseType;
            Maybe<PaymentData> mPaymentData;
        };
    }
}

#endif //READY4AIR_PURCHASEINFO_H
