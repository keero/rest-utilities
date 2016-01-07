#ifndef READY4AIR_PURCHASEITEM_H
#define READY4AIR_PURCHASEITEM_H

#include "../maybe/Maybe.h"
#include "abstract/JsonDeserializable.h"
#include "hypermedia/Form.h"

namespace ready4air
{
    class PurchaseItem : public JsonDeserializable
    {
    public:
        PurchaseItem()
        {
        }

        virtual ~PurchaseItem()
        {
        }

        const Maybe <std::string> &GetBusinessType() const
        {
            return mBusinessType;
        }

        void SetBusinessType(const std::string &businessType)
        {
            mBusinessType = businessType;
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

        const Maybe <Form> &GetForm() const
        {
            return mForm;
        }

        void SetForm(const Form &form)
        {
            mForm = form;
        }

        virtual bool InitFromJsonValue(const rapidjson::Value &value)
        {
            return false;
        }

    private:
        Maybe <std::string> mBusinessType;
        Maybe <float> mPrice;
        Maybe <std::string> mCurrency;
        Maybe <std::string> mStrPrice;
        Maybe <Form> mForm;
    };
}

#endif //READY4AIR_PURCHASEITEM_H
