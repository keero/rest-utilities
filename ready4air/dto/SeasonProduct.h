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

        const Maybe <double> &GetPrice() const
        {
            return mPrice;
        }

        void SetPrice(double price)
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

        const Maybe <std::vector<PurchaseItem> > &GetPurchaseItems() const
        {
            return mPurchaseItems;
        }

        void SetPurchaseItems(const std::vector<PurchaseItem> &purchaseItems)
        {
            mPurchaseItems = purchaseItems;
        }

        virtual bool InitFromJsonValue(const rapidjson::Value &value, ParseErrors &parseErrors)
        {
            int productId;
            double price;
            std::string currency;
            std::string strPrice;
            bool hd;
            bool dubbed;
            std::vector<Entitlement> entitlements;
            Form purchase;
            std::vector<PurchaseItem> purchaseItems;

            if (ParseInt(value, "ProductId", false, productId, parseErrors))
                SetProductId(productId);

            if (ParseDouble(value, "Price", false, price, parseErrors))
                SetPrice(price);

            if (ParseString(value, "Currency", false, currency, parseErrors))
                SetCurrency(currency);

            if (ParseString(value, "StrPrice", false, strPrice, parseErrors))
                SetStrPrice(strPrice);

            if (ParseBool(value, "HD", false, hd, parseErrors))
                SetHD(hd);

            if (ParseBool(value, "Dubbed", false, dubbed, parseErrors))
                SetDubbed(dubbed);

            if (VerifyArray(value, "Entitlements", false, parseErrors))
            {
                for (rapidjson::SizeType i = 0; i < value["Entitlements"].Size(); i += 1)
                {
                    Entitlement entitlement;
                    if (ParseObject(value["Entitlements"][i], "", false, entitlement, parseErrors))
                        entitlements.push_back(entitlement);
                }
                SetEntitlements(entitlements);
            }

            if (ParseObject(value, "Purchase", false, purchase, parseErrors))
                SetPurchase(purchase);

            if (VerifyArray(value, "PurchaseItems", false, parseErrors))
            {
                for (rapidjson::SizeType i = 0; i < value["PurchaseItems"].Size(); i += 1)
                {
                    PurchaseItem purchaseItem;
                    if (ParseObject(value["PurchaseItems"][i], "", false, purchaseItem, parseErrors))
                        purchaseItems.push_back(purchaseItem);
                }
                SetPurchaseItems(purchaseItems);
            }

            return !parseErrors;
        }

    private:
        Maybe <int> mProductId;
        Maybe <ProductType> mProductType;
        Maybe <double> mPrice;
        Maybe <std::string> mCurrency;
        Maybe <std::string> mStrPrice;
        Maybe <bool> mHD;
        Maybe <bool> mDubbed;
        Maybe <std::vector<Entitlement> > mEntitlements;
        Maybe <Form> mPurchase;
        Maybe <std::vector<PurchaseItem> > mPurchaseItems;
    };
}

#endif //READY4AIR_SEASONPRODUCT_H
