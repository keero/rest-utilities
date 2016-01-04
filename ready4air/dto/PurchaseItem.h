#ifndef READY4AIR_PURCHASEITEM_H
#define READY4AIR_PURCHASEITEM_H

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

        const std::string &GetBusinessType() const
        {
            return mBusinessType;
        }

        void SetBusinessType(const std::string &businessType)
        {
            mBusinessType = businessType;
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

        const Form &GetForm() const
        {
            return mForm;
        }

        void SetForm(const Form &form)
        {
            mForm = form;
        }

    private:
        std::string mBusinessType;
        float mPrice;
        std::string mCurrency;
        std::string mStrPrice;
        Form mForm;
    };
}

#endif //READY4AIR_PURCHASEITEM_H
