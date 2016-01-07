#ifndef READY4AIR_PURCHASE_H
#define READY4AIR_PURCHASE_H

#include "../maybe/Maybe.h"
#include "abstract/JsonDeserializable.h"
#include "hypermedia/Link.h"
#include "hypermedia/Form.h"
#include "DRM.h"

namespace ready4air
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

        const Maybe <float> &GetOriginalPrice() const
        {
            return mOriginalPrice;
        }

        void SetOriginalPrice(float originalPrice)
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

        const Maybe <float> &GetPaidPrice() const
        {
            return mPaidPrice;
        }

        void SetPaidPrice(float paidPrice)
        {
            mPaidPrice = paidPrice;
        }

        const Maybe <float> &GetRemainingAmount() const
        {
            return mRemainingAmount;
        }

        void SetRemainingAmount(float remainingAmount)
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

        virtual bool InitFromJsonValue(const rapidjson::Value &value)
        {
            return false;
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
        Maybe <float> mOriginalPrice;
        Maybe <std::string> mPaymentMethod;
        Maybe <std::string> mPaymentReference;
        Maybe <float> mPaidPrice;
        Maybe <float> mRemainingAmount;
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

#endif //READY4AIR_PURCHASE_H
