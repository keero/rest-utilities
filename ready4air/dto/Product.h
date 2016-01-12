//
// Created by Martin Kero on 12/01/16.
//

#ifndef READY4AIR_PRODUCT_H
#define READY4AIR_PRODUCT_H

#include "../maybe/Maybe.h"
#include "abstract/JsonDeserializable.h"
#include "hypermedia/Link.h"
#include "Entitlement.h"
#include "PurchaseItem.h"

namespace ready4air
{
    class Product : public JsonDeserializable
    {
    public:
        Product()
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

        const Maybe<bool> &GetHD() const
        {
            return mHD;
        }

        void SetHD(bool HD)
        {
            mHD = HD;
        }

        const Maybe<bool> &GetDubbed() const
        {
            return mDubbed;
        }

        void SetDubbed( bool dubbed)
        {
            mDubbed = dubbed;
        }

        const Maybe<Link> &GetFullPLay() const
        {
            return mFullPLay;
        }

        void SetFullPLay(const Link &fullPLay)
        {
            mFullPLay = fullPLay;
        }

        const Maybe<Entitlement> &GetEntitlements() const
        {
            return mEntitlements;
        }

        void SetEntitlements(const Entitlement &entitlements)
        {
            mEntitlements = entitlements;
        }

        const Maybe<std::vector<PurchaseItem>> &GetPurchaseItems() const
        {
            return mPurchaseItems;
        }

        void SetPurchaseItems(const std::vector<PurchaseItem> &purchaseItems)
        {
            mPurchaseItems = purchaseItems;
        }

        virtual bool InitFromJsonValue(const rapidjson::Value &value, ParseErrors &parseErrors)
        {
            return false;
        }


    private:
        Maybe <int> mProductId;
        Maybe <bool> mHD;
        Maybe <bool> mDubbed;
        Maybe <Link> mFullPLay;
        Maybe <Entitlement> mEntitlements;
        Maybe <std::vector<PurchaseItem> > mPurchaseItems;
    };
}

#endif //READY4AIR_PRODUCT_H
