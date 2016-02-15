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
            PurchaseInfo() : TAG("ready4air::dto::PurchaseInfo")
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

            const Maybe<STRING_T> &GetPurchaseType() const
            {
                return mPurchaseType;
            }

            void SetPurchaseType(const STRING_T &purchaseType)
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

            virtual BOOL_T InitFromJsonValue(const rapidjson::Value &value, ParseErrors &parseErrors,
                                             VECTOR_T<STRING_T> &context)
            {
                Purchase purchase;
                STRING_T purchaseType;
                PaymentData paymentData;

                context.push_back(TAG);

                if (ParseObject(value, "Purchase", true, purchase, parseErrors, context))
                    SetPurchase(purchase);

                if (ParseString(value, "PurchaseType", true, purchaseType, parseErrors, context))
                    SetPurchaseType(purchaseType);

                if (ParseObject(value, "PaymentData", false, paymentData, parseErrors, context))
                    SetPaymentData(paymentData);

                context.pop_back();
                return !parseErrors;
            }

        private:
            Maybe<Purchase> mPurchase;
            Maybe<STRING_T> mPurchaseType;
            Maybe<PaymentData> mPaymentData;
            STRING_T TAG;
        };
    }
}

#endif //READY4AIR_PURCHASEINFO_H
