#ifndef READY4AIR_SEASONPRODUCT_H
#define READY4AIR_SEASONPRODUCT_H

#include "../common/Maybe.h"
#include "abstract/JsonDeserializable.h"
#include "MediaProduct.h"
#include "Entitlement.h"
#include "hypermedia/Form.h"

namespace ready4air
{
    namespace dto
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

            const Maybe<int> &GetProductId() const
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

            const Maybe<DOUBLE_T> &GetPrice() const
            {
                return mPrice;
            }

            void SetPrice(DOUBLE_T price)
            {
                mPrice = price;
            }

            const Maybe <STRING_T> &GetCurrency() const
            {
                return mCurrency;
            }

            void SetCurrency(const STRING_T &currency)
            {
                mCurrency = currency;
            }

            const Maybe <STRING_T> &GetStrPrice() const
            {
                return mStrPrice;
            }

            void SetStrPrice(const STRING_T &strPrice)
            {
                mStrPrice = strPrice;
            }

            const Maybe<BOOL_T> &IsHD() const
            {
                return mHD;
            }

            void SetHD(BOOL_T HD)
            {
                mHD = HD;
            }

            const Maybe<BOOL_T> &IsDubbed() const
            {
                return mDubbed;
            }

            void SetDubbed(BOOL_T dubbed)
            {
                mDubbed = dubbed;
            }

            const Maybe <VECTOR_T<Entitlement> > &GetEntitlements() const
            {
                return mEntitlements;
            }

            void SetEntitlements(const VECTOR_T<Entitlement> &entitlements)
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

            const Maybe <VECTOR_T<PurchaseItem> > &GetPurchaseItems() const
            {
                return mPurchaseItems;
            }

            void SetPurchaseItems(const VECTOR_T<PurchaseItem> &purchaseItems)
            {
                mPurchaseItems = purchaseItems;
            }

            virtual BOOL_T InitFromJsonValue(const rapidjson::Value &value, ParseErrors &parseErrors)
            {
                INT32_T productId;
                DOUBLE_T price;
                STRING_T currency;
                STRING_T strPrice;
                BOOL_T hd;
                BOOL_T dubbed;
                VECTOR_T<Entitlement> entitlements;
                Form purchase;
                VECTOR_T<PurchaseItem> purchaseItems;

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
            Maybe<int> mProductId;
            Maybe <ProductType> mProductType;
            Maybe<DOUBLE_T> mPrice;
            Maybe <STRING_T> mCurrency;
            Maybe <STRING_T> mStrPrice;
            Maybe<BOOL_T> mHD;
            Maybe<BOOL_T> mDubbed;
            Maybe <VECTOR_T<Entitlement> > mEntitlements;
            Maybe <Form> mPurchase;
            Maybe <VECTOR_T<PurchaseItem> > mPurchaseItems;
        };
    }
}

#endif //READY4AIR_SEASONPRODUCT_H
