#ifndef READY4AIR_PURCHASE_H
#define READY4AIR_PURCHASE_H

#include "../common/Maybe.h"
#include "abstract/JsonDeserializable.h"
#include "hypermedia/Link.h"
#include "hypermedia/Form.h"
#include "DRM.h"

namespace ready4air
{
    namespace dto
    {
        class Purchase : public JsonDeserializable
        {
        public:
            Purchase()
            {
            }

            virtual ~Purchase()
            {
            }

            const Maybe <std::string> &GetId() const
            {
                return mId;
            }

            void SetId(const std::string &id)
            {
                mId = id;
            }

            const Maybe <std::string> &GetCpurchaseId() const
            {
                return mCpurchaseId;
            }

            void SetCpurchaseId(const std::string &cpurchaseId)
            {
                mCpurchaseId = cpurchaseId;
            }

            const Maybe <std::string> &GetCrentalId() const
            {
                return mCrentalId;
            }

            void SetCrentalId(const std::string &crentalId)
            {
                mCrentalId = crentalId;
            }

            const Maybe <std::vector<std::string> > &GetCValueCodes() const
            {
                return mCValueCodes;
            }

            void SetCValueCodes(const std::vector<std::string> &CValueCodes)
            {
                mCValueCodes = CValueCodes;
            }

            const Maybe <std::string> &GetCurrency() const
            {
                return mCurrency;
            }

            void SetCurrency(const std::string &currency)
            {
                mCurrency = currency;
            }

            const Maybe <std::string> &GetIPAddress() const
            {
                return mIPAddress;
            }

            void SetIPAddress(const std::string &IPAddress)
            {
                mIPAddress = IPAddress;
            }

            const Maybe <std::string> &GetIPCountry() const
            {
                return mIPCountry;
            }

            void SetIPCountry(const std::string &IPCountry)
            {
                mIPCountry = IPCountry;
            }

            const Maybe <std::string> &GetProductId() const
            {
                return mProductId;
            }

            void SetProductId(const std::string &productId)
            {
                mProductId = productId;
            }

            const Maybe<double> &GetOriginalPrice() const
            {
                return mOriginalPrice;
            }

            void SetOriginalPrice(double originalPrice)
            {
                mOriginalPrice = originalPrice;
            }

            const Maybe <std::string> &GetPaymentMethod() const
            {
                return mPaymentMethod;
            }

            void SetPaymentMethod(const std::string &paymentMethod)
            {
                mPaymentMethod = paymentMethod;
            }

            const Maybe <std::string> &GetPaymentReference() const
            {
                return mPaymentReference;
            }

            void SetPaymentReference(const std::string &paymentReference)
            {
                mPaymentReference = paymentReference;
            }

            const Maybe<double> &GetPaidPrice() const
            {
                return mPaidPrice;
            }

            void SetPaidPrice(double paidPrice)
            {
                mPaidPrice = paidPrice;
            }

            const Maybe<double> &GetRemainingAmount() const
            {
                return mRemainingAmount;
            }

            void SetRemainingAmount(double remainingAmount)
            {
                mRemainingAmount = remainingAmount;
            }

            const Maybe <std::string> &GetTitle() const
            {
                return mTitle;
            }

            void SetTitle(const std::string &title)
            {
                mTitle = title;
            }

            const Maybe <std::string> &GetTransactionTime() const
            {
                return mTransactionTime;
            }

            void SetTransactionTime(const std::string &transactionTime)
            {
                mTransactionTime = transactionTime;
            }

            const Maybe <Link> &GetSelf() const
            {
                return mSelf;
            }

            void SetSelf(const Link &self)
            {
                mSelf = self;
            }

            const Maybe <Form> &GetCommit() const
            {
                return mCommit;
            }

            void SetCommit(const Form &commit)
            {
                mCommit = commit;
            }

            const Maybe <Form> &GetCancel() const
            {
                return mCancel;
            }

            void SetCancel(const Form &cancel)
            {
                mCancel = cancel;
            }

            const Maybe <Form> &GetUpdate() const
            {
                return mUpdate;
            }

            void SetUpdate(const Form &update)
            {
                mUpdate = update;
            }

            const Maybe <DRM> &GetDRM() const
            {
                return mDRM;
            }

            void SetDRM(const DRM &DRM)
            {
                mDRM = DRM;
            }

            const Maybe <std::string> &GetSignature() const
            {
                return mSignature;
            }

            void SetSignature(const std::string &signature)
            {
                mSignature = signature;
            }

            virtual bool InitFromJsonValue(const rapidjson::Value &value, ParseErrors &parseErrors)
            {
                std::string id;
                std::string cpurchaseId;
                std::string crentalId;
                std::vector<std::string> cValueCodes;
                std::string currency;
                std::string ipAddress;
                std::string ipCountry;
                std::string productId;
                double originalPrice;
                std::string paymentMethod;
                std::string paymentReference;
                double paidPrice;
                double remainingAmount;
                std::string title;
                std::string transactionTime;
                Link self;
                Form commit;
                Form cancel;
                Form update;
                DRM drm;
                std::string signature;

                if (ParseString(value, "Id", true, id, parseErrors))
                    SetId(id);

                if (ParseString(value, "CpurchaseId", false, cpurchaseId, parseErrors))
                    SetCpurchaseId(cpurchaseId);

                if (ParseString(value, "CrentalId", false, crentalId, parseErrors))
                    SetCrentalId(crentalId);

                if (VerifyArray(value, "CValueCodes", false, parseErrors))
                {
                    for (rapidjson::SizeType i = 0; i < value["CValueCodes"].Size(); i += 1)
                    {
                        std::string cValueCode;
                        if (ParseString(value["CValueCodes"][i], "", false, cValueCode, parseErrors))
                            cValueCodes.push_back(cValueCode);
                    }
                    SetCValueCodes(cValueCodes);
                }

                if (ParseString(value, "Currency", true, currency, parseErrors))
                    SetCurrency(currency);

                if (ParseString(value, "IPAddress", true, ipAddress, parseErrors))
                    SetIPAddress(ipAddress);

                if (ParseString(value, "IPCountry", true, ipCountry, parseErrors))
                    SetIPCountry(ipCountry);

                if (ParseString(value, "ProductId", true, productId, parseErrors))
                    SetProductId(productId);

                if (ParseDouble(value, "OriginalPrice", true, originalPrice, parseErrors))
                    SetOriginalPrice(originalPrice);

                if (ParseString(value, "PaymentMethod", false, paymentMethod, parseErrors))
                    SetPaymentMethod(paymentMethod);

                if (ParseString(value, "PaymentReference", false, paymentReference, parseErrors))
                    SetPaymentReference(paymentReference);

                if (ParseDouble(value, "PaidPrice", true, paidPrice, parseErrors))
                    SetPaidPrice(paidPrice);

                if (ParseDouble(value, "RemainingAmount", true, remainingAmount, parseErrors))
                    SetRemainingAmount(remainingAmount);

                if (ParseString(value, "Title", false, title, parseErrors))
                    SetTitle(title);

                if (ParseString(value, "TransactionTime", false, transactionTime, parseErrors))
                    SetTransactionTime(transactionTime);

                if (ParseObject(value, "Self", true, self, parseErrors))
                    SetSelf(self);

                if (ParseObject(value, "Commit", false, commit, parseErrors))
                    SetCommit(commit);

                if (ParseObject(value, "Cancel", false, cancel, parseErrors))
                    SetCancel(cancel);

                if (ParseObject(value, "Update", false, update, parseErrors))
                    SetUpdate(update);

                if (ParseObject(value, "DRM", false, drm, parseErrors))
                    SetDRM(drm);

                if (ParseString(value, "Signature", true, signature, parseErrors))
                    SetSignature(signature);

                return !parseErrors;
            }

        private:
            Maybe <std::string> mId;
            Maybe <std::string> mCpurchaseId;
            Maybe <std::string> mCrentalId;
            Maybe <std::vector<std::string> > mCValueCodes;
            Maybe <std::string> mCurrency;
            Maybe <std::string> mIPAddress;
            Maybe <std::string> mIPCountry;
            Maybe <std::string> mProductId;
            Maybe<double> mOriginalPrice;
            Maybe <std::string> mPaymentMethod;
            Maybe <std::string> mPaymentReference;
            Maybe<double> mPaidPrice;
            Maybe<double> mRemainingAmount;
            Maybe <std::string> mTitle;
            Maybe <std::string> mTransactionTime;
            Maybe <Link> mSelf;
            Maybe <Form> mCommit;
            Maybe <Form> mCancel;
            Maybe <Form> mUpdate;
            Maybe <DRM> mDRM;
            Maybe <std::string> mSignature;
        };
    }
}

#endif //READY4AIR_PURCHASE_H
