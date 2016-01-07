#ifndef READY4AIR_SEASONPRODUCT_H
#define READY4AIR_SEASONPRODUCT_H

#include "../maybe/Maybe.h"
#include "abstract/JsonDeserializable.h"
#include "MediaProduct.h"
#include "Entitlement.h"
#include "hypermedia/Form.h"

namespace ready4air
{
    class SeasonProduct : public JsonDeserializable
    {
    public:
        SeasonProduct()
        {
            mProductType = SeasonProductType;
        }

        virtual ~SeasonProduct()
        {
        }

        const Maybe <int> &GetProductId() const
        {
            return mProductId;
        }

        void SetProductId(int productId)
        {
            mProductId = productId;
        }

        const Maybe <ProductType> &GetProductType() const
        {
            return mProductType;
        }

        void SetProductType(const ProductType &productType)
        {
            mProductType = productType;
        }

        const Maybe <float> &GetPrice() const
        {
            return mPrice;
        }

        void SetPrice(float price)
        {
            mPrice = price;
        }

        const Maybe <std::string> &GetCurrency() const
        {
            return mCurrency;
        }

        void SetCurrency(const std::string &currency)
        {
            mCurrency = currency;
        }

        const Maybe <std::string> &GetStrPrice() const
        {
            return mStrPrice;
        }

        void SetStrPrice(const std::string &strPrice)
        {
            mStrPrice = strPrice;
        }

        const Maybe <bool> &IsHD() const
        {
            return mHD;
        }

        void SetHD(bool HD)
        {
            mHD = HD;
        }

        const Maybe <bool> &IsDubbed() const
        {
            return mDubbed;
        }

        void SetDubbed(bool dubbed)
        {
            mDubbed = dubbed;
        }

        const Maybe <std::vector<Entitlement> > &GetEntitlements() const
        {
            return mEntitlements;
        }

        void SetEntitlements(const std::vector<Entitlement> &entitlements)
        {
            mEntitlements = entitlements;
        }

        const Maybe <Form> &GetPurchase() const
        {
            return mPurchase;
        }

        void SetPurchase(const Form &purchase)
        {
            mPurchase = purchase;
        }

        virtual bool InitFromJsonValue(const rapidjson::Value &value)
        {
            return false;
        }

    private:
        Maybe <int> mProductId;
        Maybe <ProductType> mProductType;
        Maybe <float> mPrice;
        Maybe <std::string> mCurrency;
        Maybe <std::string> mStrPrice;
        Maybe <bool> mHD;
        Maybe <bool> mDubbed;
        Maybe <std::vector<Entitlement> > mEntitlements;
        Maybe <Form> mPurchase;
    };
}

#endif //READY4AIR_SEASONPRODUCT_H
