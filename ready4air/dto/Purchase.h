#ifndef READY4AIR_PURCHASE_H
#define READY4AIR_PURCHASE_H

#include "../common/Maybe.h"
#include "abstract/JsonDeserializable.h"
#include "hypermedia/Link.h"
#include "hypermedia/Form.h"
#include "DRM.h"
#include "abstract/JsonSerializable.h"

namespace ready4air
{
    namespace dto
    {
        class Purchase : public JsonDeserializable, public IJsonSerializable
        {
        public:
            Purchase() : TAG("ready4air::dto::Purchase")
            {
            }

            virtual ~Purchase()
            {
            }

            const Maybe<STRING_T> &GetId() const
            {
                return mId;
            }

            void SetId(const STRING_T &id)
            {
                mId = id;
            }

            const Maybe<STRING_T> &GetCpurchaseId() const
            {
                return mCpurchaseId;
            }

            void SetCpurchaseId(const STRING_T &cpurchaseId)
            {
                mCpurchaseId = cpurchaseId;
            }

            const Maybe<STRING_T> &GetCrentalId() const
            {
                return mCrentalId;
            }

            void SetCrentalId(const STRING_T &crentalId)
            {
                mCrentalId = crentalId;
            }

            const Maybe<VECTOR_T<STRING_T> > &GetCValueCodes() const
            {
                return mCValueCodes;
            }

            void SetCValueCodes(const VECTOR_T<STRING_T> &CValueCodes)
            {
                mCValueCodes = CValueCodes;
            }

            const Maybe<STRING_T> &GetCurrency() const
            {
                return mCurrency;
            }

            void SetCurrency(const STRING_T &currency)
            {
                mCurrency = currency;
            }

            const Maybe<STRING_T> &GetIPAddress() const
            {
                return mIPAddress;
            }

            void SetIPAddress(const STRING_T &IPAddress)
            {
                mIPAddress = IPAddress;
            }

            const Maybe<STRING_T> &GetIPCountry() const
            {
                return mIPCountry;
            }

            void SetIPCountry(const STRING_T &IPCountry)
            {
                mIPCountry = IPCountry;
            }

            const Maybe<STRING_T> &GetProductId() const
            {
                return mProductId;
            }

            void SetProductId(const STRING_T &productId)
            {
                mProductId = productId;
            }

            const Maybe<DOUBLE_T> &GetOriginalPrice() const
            {
                return mOriginalPrice;
            }

            void SetOriginalPrice(DOUBLE_T originalPrice)
            {
                mOriginalPrice = originalPrice;
            }

            const Maybe<STRING_T> &GetPaymentMethod() const
            {
                return mPaymentMethod;
            }

            void SetPaymentMethod(const STRING_T &paymentMethod)
            {
                mPaymentMethod = paymentMethod;
            }

            const Maybe<STRING_T> &GetPaymentReference() const
            {
                return mPaymentReference;
            }

            void SetPaymentReference(const STRING_T &paymentReference)
            {
                mPaymentReference = paymentReference;
            }

            const Maybe<DOUBLE_T> &GetPaidPrice() const
            {
                return mPaidPrice;
            }

            void SetPaidPrice(DOUBLE_T paidPrice)
            {
                mPaidPrice = paidPrice;
            }

            const Maybe<DOUBLE_T> &GetRemainingAmount() const
            {
                return mRemainingAmount;
            }

            void SetRemainingAmount(DOUBLE_T remainingAmount)
            {
                mRemainingAmount = remainingAmount;
            }

            const Maybe<STRING_T> &GetTitle() const
            {
                return mTitle;
            }

            void SetTitle(const STRING_T &title)
            {
                mTitle = title;
            }

            const Maybe<STRING_T> &GetTransactionTime() const
            {
                return mTransactionTime;
            }

            void SetTransactionTime(const STRING_T &transactionTime)
            {
                mTransactionTime = transactionTime;
            }

            const Maybe<Link> &GetSelf() const
            {
                return mSelf;
            }

            void SetSelf(const Link &self)
            {
                mSelf = self;
            }

            const Maybe<Form> &GetCommit() const
            {
                return mCommit;
            }

            void SetCommit(const Form &commit)
            {
                mCommit = commit;
            }

            const Maybe<Form> &GetCancel() const
            {
                return mCancel;
            }

            void SetCancel(const Form &cancel)
            {
                mCancel = cancel;
            }

            const Maybe<Form> &GetUpdate() const
            {
                return mUpdate;
            }

            void SetUpdate(const Form &update)
            {
                mUpdate = update;
            }

            const Maybe<DRM> &GetDRM() const
            {
                return mDRM;
            }

            void SetDRM(const DRM &DRM)
            {
                mDRM = DRM;
            }

            const Maybe<STRING_T> &GetSignature() const
            {
                return mSignature;
            }

            void SetSignature(const STRING_T &signature)
            {
                mSignature = signature;
            }

            virtual BOOL_T InitFromJsonValue(const rapidjson::Value &value, ParseErrors &parseErrors,
                                             VECTOR_T<STRING_T> &context)
            {
                STRING_T id;
                STRING_T cpurchaseId;
                STRING_T crentalId;
                VECTOR_T<STRING_T> cValueCodes;
                STRING_T currency;
                STRING_T ipAddress;
                STRING_T ipCountry;
                STRING_T productId;
                DOUBLE_T originalPrice;
                STRING_T paymentMethod;
                STRING_T paymentReference;
                DOUBLE_T paidPrice;
                DOUBLE_T remainingAmount;
                STRING_T title;
                STRING_T transactionTime;
                Link self;
                Form commit;
                Form cancel;
                Form update;
                DRM drm;
                STRING_T signature;

                context.push_back(TAG);

                if (ParseString(value, "Id", true, id, parseErrors, context))
                    SetId(id);

                if (ParseString(value, "CpurchaseId", false, cpurchaseId, parseErrors, context))
                    SetCpurchaseId(cpurchaseId);

                if (ParseString(value, "CrentalId", false, crentalId, parseErrors, context))
                    SetCrentalId(crentalId);

                if (VerifyArray(value, "CValueCodes", false, parseErrors, context))
                {
                    for (rapidjson::SizeType i = 0; i < value["CValueCodes"].Size(); i += 1)
                    {
                        STRING_T cValueCode;
                        if (ParseString(value["CValueCodes"][i], "", false, cValueCode, parseErrors, context))
                            cValueCodes.push_back(cValueCode);
                    }
                    SetCValueCodes(cValueCodes);
                }

                if (ParseString(value, "Currency", true, currency, parseErrors, context))
                    SetCurrency(currency);

                if (ParseString(value, "IPAddress", true, ipAddress, parseErrors, context))
                    SetIPAddress(ipAddress);

                if (ParseString(value, "IPCountry", true, ipCountry, parseErrors, context))
                    SetIPCountry(ipCountry);

                if (ParseString(value, "ProductId", true, productId, parseErrors, context))
                    SetProductId(productId);

                if (ParseDouble(value, "OriginalPrice", true, originalPrice, parseErrors, context))
                    SetOriginalPrice(originalPrice);

                if (ParseString(value, "PaymentMethod", false, paymentMethod, parseErrors, context))
                    SetPaymentMethod(paymentMethod);

                if (ParseString(value, "PaymentReference", false, paymentReference, parseErrors, context))
                    SetPaymentReference(paymentReference);

                if (ParseDouble(value, "PaidPrice", true, paidPrice, parseErrors, context))
                    SetPaidPrice(paidPrice);

                if (ParseDouble(value, "RemainingAmount", true, remainingAmount, parseErrors, context))
                    SetRemainingAmount(remainingAmount);

                if (ParseString(value, "Title", false, title, parseErrors, context))
                    SetTitle(title);

                if (ParseString(value, "TransactionTime", false, transactionTime, parseErrors, context))
                    SetTransactionTime(transactionTime);

                if (ParseObject(value, "Self", true, self, parseErrors, context))
                    SetSelf(self);

                if (ParseObject(value, "Commit", false, commit, parseErrors, context))
                    SetCommit(commit);

                if (ParseObject(value, "Cancel", false, cancel, parseErrors, context))
                    SetCancel(cancel);

                if (ParseObject(value, "Update", false, update, parseErrors, context))
                    SetUpdate(update);

                if (ParseObject(value, "DRM", false, drm, parseErrors, context))
                    SetDRM(drm);

                if (ParseString(value, "Signature", true, signature, parseErrors, context))
                    SetSignature(signature);

                context.pop_back();
                return !parseErrors;
            }

            virtual const STRING_T ToJsonString(void) const
            {
                if (OriginalJsonString)
                    return OriginalJsonString.Just;
                else
                    return "";
            }

        private:
            Maybe<STRING_T> mId;
            Maybe<STRING_T> mCpurchaseId;
            Maybe<STRING_T> mCrentalId;
            Maybe<VECTOR_T<STRING_T> > mCValueCodes;
            Maybe<STRING_T> mCurrency;
            Maybe<STRING_T> mIPAddress;
            Maybe<STRING_T> mIPCountry;
            Maybe<STRING_T> mProductId;
            Maybe<DOUBLE_T> mOriginalPrice;
            Maybe<STRING_T> mPaymentMethod;
            Maybe<STRING_T> mPaymentReference;
            Maybe<DOUBLE_T> mPaidPrice;
            Maybe<DOUBLE_T> mRemainingAmount;
            Maybe<STRING_T> mTitle;
            Maybe<STRING_T> mTransactionTime;
            Maybe<Link> mSelf;
            Maybe<Form> mCommit;
            Maybe<Form> mCancel;
            Maybe<Form> mUpdate;
            Maybe<DRM> mDRM;
            Maybe<STRING_T> mSignature;
            STRING_T TAG;
        };
    }
}

#endif //READY4AIR_PURCHASE_H
