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

            const Maybe <std::string> &GetBusinessType() const
            {
                return mBusinessType;
            }

            void SetBusinessType(const std::string &businessType)
            {
                mBusinessType = businessType;
            }

            const Maybe<double> &GetPrice() const
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

            const Maybe <Form> &GetForm() const
            {
                return mForm;
            }

            void SetForm(const Form &form)
            {
                mForm = form;
            }

            virtual bool InitFromJsonValue(const rapidjson::Value &value, ParseErrors &parseErrors)
            {
                std::string businessType;
                double price;
                std::string currency;
                std::string strPrice;
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
            Maybe <std::string> mBusinessType;
            Maybe<double> mPrice;
            Maybe <std::string> mCurrency;
            Maybe <std::string> mStrPrice;
            Maybe <Form> mForm;
        };
    }
}

#endif //READY4AIR_PURCHASEITEM_H
