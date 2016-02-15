//
// Created by Martin Kero on 12/01/16.
//

#ifndef READY4AIR_PRODUCT_H
#define READY4AIR_PRODUCT_H

#include "../common/Maybe.h"
#include "abstract/JsonDeserializable.h"
#include "hypermedia/Link.h"
#include "Entitlement.h"
#include "PurchaseItem.h"

namespace ready4air
{
    namespace dto
    {
        class Product : public JsonDeserializable
        {
        public:
            Product() : TAG("ready4air::dto::Product")
            {
            }

            virtual ~Product()
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

            const Maybe<BOOL_T> &GetHD() const
            {
                return mHD;
            }

            void SetHD(BOOL_T HD)
            {
                mHD = HD;
            }

            const Maybe<BOOL_T> &GetDubbed() const
            {
                return mDubbed;
            }

            void SetDubbed(BOOL_T dubbed)
            {
                mDubbed = dubbed;
            }

            const Maybe <Link> &GetFullPLay() const
            {
                return mFullPLay;
            }

            void SetFullPLay(const Link &fullPLay)
            {
                mFullPLay = fullPLay;
            }

            const Maybe <Entitlement> &GetEntitlements() const
            {
                return mEntitlements;
            }

            void SetEntitlements(const Entitlement &entitlements)
            {
                mEntitlements = entitlements;
            }

            const Maybe <VECTOR_T<PurchaseItem>> &GetPurchaseItems() const
            {
                return mPurchaseItems;
            }

            void SetPurchaseItems(const VECTOR_T<PurchaseItem> &purchaseItems)
            {
                mPurchaseItems = purchaseItems;
            }

            virtual BOOL_T InitFromJsonValue(const rapidjson::Value &value, ParseErrors &parseErrors,
                                             VECTOR_T<STRING_T> &context)
            {
                INT32_T productId;
                BOOL_T hd;
                BOOL_T dubbed;
                Link fullPLay;
                Entitlement entitlements;
                VECTOR_T<PurchaseItem> purchaseItems;

                context.push_back(TAG);

                if (ParseInt(value, "ProductId", true, productId, parseErrors, context))
                    SetProductId(productId);

                if (ParseBool(value, "HD", true, hd, parseErrors, context))
                    SetHD(hd);

                if (ParseBool(value, "Dubbed", true, dubbed, parseErrors, context))
                    SetDubbed(dubbed);

                if (ParseObject(value, "FullPLay", false, fullPLay, parseErrors, context))
                    SetFullPLay(fullPLay);

                if (ParseObject(value, "Entitlements", true, entitlements, parseErrors, context))
                    SetEntitlements(entitlements);

                if (VerifyArray(value, "PurchaseItems", false, parseErrors, context))
                {
                    for (rapidjson::SizeType i = 0; i < value["PurchaseItems"].Size(); i += 1)
                    {
                        PurchaseItem purchaseItem;
                        if (ParseObject(value["PurchaseItems"][i], "", false, purchaseItem, parseErrors,
                                        context))
                            purchaseItems.push_back(purchaseItem);
                    }
                    SetPurchaseItems(purchaseItems);
                }

                context.pop_back();
                return !parseErrors;
            }


        private:
            Maybe<int> mProductId;
            Maybe<BOOL_T> mHD;
            Maybe<BOOL_T> mDubbed;
            Maybe <Link> mFullPLay;
            Maybe <Entitlement> mEntitlements;
            Maybe <VECTOR_T<PurchaseItem>> mPurchaseItems;
            STRING_T TAG;
        };
    }
}

#endif //READY4AIR_PRODUCT_H
