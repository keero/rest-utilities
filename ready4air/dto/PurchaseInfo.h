#ifndef READY4AIR_PURCHASEINFO_H
#define READY4AIR_PURCHASEINFO_H

#include "abstract/JsonDeserializable.h"
#include "Purchase.h"
#include "PaymentData.h"

namespace ready4air
{
    enum PurchaseType
    {
        None = 0,
        Tvod = 1,
        SeasonPass = 2,
        BundlePurchase = 3,
        Est = 4
    };

    class PurchaseInfo : public JsonDeserializable
    {
    public:
        PurchaseInfo()
        {
        }

        virtual ~PurchaseInfo()
        {
        }

        const Purchase &GetPurchase() const
        {
            return mPurchase;
        }

        void SetPurchase(const Purchase &purchase)
        {
            mPurchase = purchase;
        }

        const PurchaseType &GetPurchaseType() const
        {
            return mPurchaseType;
        }

        void SetPurchaseType(const PurchaseType &purchaseType)
        {
            mPurchaseType = purchaseType;
        }

        const PaymentData &GetPaymentData() const
        {
            return mPaymentData;
        }

        void SetPaymentData(const PaymentData &paymentData)
        {
            mPaymentData = paymentData;
        }

        virtual bool InitFromJsonValue(const rapidjson::Value &value)
        {
            return false;
        }

    private:
        Purchase mPurchase;
        PurchaseType mPurchaseType;
        PaymentData mPaymentData;
    };
}

#endif //READY4AIR_PURCHASEINFO_H
