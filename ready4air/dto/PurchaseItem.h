#ifndef READY4AIR_PURCHASEITEM_H
#define READY4AIR_PURCHASEITEM_H

#include "../common/Maybe.h"
#include "abstract/JsonDeserializable.h"
#include "hypermedia/Form.h"

namespace ready4air
{
    namespace dto
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

            const Maybe <STRING_T> &GetBusinessType() const
            {
                return mBusinessType;
            }

            void SetBusinessType(const STRING_T &businessType)
            {
                mBusinessType = businessType;
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

            const Maybe <Form> &GetForm() const
            {
                return mForm;
            }

            void SetForm(const Form &form)
            {
                mForm = form;
            }

            virtual BOOL_T InitFromJsonValue(const rapidjson::Value &value, ParseErrors &parseErrors)
            {
                STRING_T businessType;
                DOUBLE_T price;
                STRING_T currency;
                STRING_T strPrice;
                Form form;

                if (ParseString(value, "BusinessType", true, businessType, parseErrors))
                    SetBusinessType(businessType);

                if (ParseDouble(value, "Price", false, price, parseErrors))
                    SetPrice(price);

                if (ParseString(value, "Currency", false, currency, parseErrors))
                    SetCurrency(currency);

                if (ParseString(value, "StrPrice", false, strPrice, parseErrors))
                    SetStrPrice(strPrice);

                if (ParseObject(value, "Form", false, form, parseErrors))
                    SetForm(form);

                return !parseErrors;
            }

        private:
            Maybe <STRING_T> mBusinessType;
            Maybe<DOUBLE_T> mPrice;
            Maybe <STRING_T> mCurrency;
            Maybe <STRING_T> mStrPrice;
            Maybe <Form> mForm;
        };
    }
}

#endif //READY4AIR_PURCHASEITEM_H
