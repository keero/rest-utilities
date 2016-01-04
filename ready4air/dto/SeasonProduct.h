#ifndef READY4AIR_SEASONPRODUCT_H
#define READY4AIR_SEASONPRODUCT_H

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

        int GetProductId() const
        {
            return mProductId;
        }

        void SetProductId(int productId)
        {
            mProductId = productId;
        }

        const ProductType &GetProductType() const
        {
            return mProductType;
        }

        void SetProductType(const ProductType &productType)
        {
            mProductType = productType;
        }

        float GetPrice() const
        {
            return mPrice;
        }

        void SetPrice(float price)
        {
            mPrice = price;
        }

        const std::string &GetCurrency() const
        {
            return mCurrency;
        }

        void SetCurrency(const std::string &currency)
        {
            mCurrency = currency;
        }

        const std::string &GetStrPrice() const
        {
            return mStrPrice;
        }

        void SetStrPrice(const std::string &strPrice)
        {
            mStrPrice = strPrice;
        }

        bool IsHD() const
        {
            return mHD;
        }

        void SetHD(bool HD)
        {
            mHD = HD;
        }

        bool IsDubbed() const
        {
            return mDubbed;
        }

        void SetDubbed(bool dubbed)
        {
            mDubbed = dubbed;
        }

        const std::vector<Entitlement> &GetEntitlements() const
        {
            return mEntitlements;
        }

        void SetEntitlements(const std::vector<Entitlement> &entitlements)
        {
            mEntitlements = entitlements;
        }

        const Form &GetPurchase() const
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
        int mProductId;
        ProductType mProductType;
        float mPrice;
        std::string mCurrency;
        std::string mStrPrice;
        bool mHD;
        bool mDubbed;
        std::vector<Entitlement> mEntitlements;
        Form mPurchase;
    };
}

#endif //READY4AIR_SEASONPRODUCT_H
