#ifndef READY4AIR_PURCHASE_H
#define READY4AIR_PURCHASE_H

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

        const std::string &GetId() const
        {
            return mId;
        }

        void SetId(const std::string &id)
        {
            mId = id;
        }

        const std::string &GetCpurchaseId() const
        {
            return mCpurchaseId;
        }

        void SetCpurchaseId(const std::string &cpurchaseId)
        {
            mCpurchaseId = cpurchaseId;
        }

        const std::string &GetCrentalId() const
        {
            return mCrentalId;
        }

        void SetCrentalId(const std::string &crentalId)
        {
            mCrentalId = crentalId;
        }

        const std::vector<std::string> &GetCValueCodes() const
        {
            return mCValueCodes;
        }

        void SetCValueCodes(const std::vector<std::string> &CValueCodes)
        {
            mCValueCodes = CValueCodes;
        }

        const std::string &GetCurrency() const
        {
            return mCurrency;
        }

        void SetCurrency(const std::string &currency)
        {
            mCurrency = currency;
        }

        const std::string &GetIPAddress() const
        {
            return mIPAddress;
        }

        void SetIPAddress(const std::string &IPAddress)
        {
            mIPAddress = IPAddress;
        }

        const std::string &GetIPCountry() const
        {
            return mIPCountry;
        }

        void SetIPCountry(const std::string &IPCountry)
        {
            mIPCountry = IPCountry;
        }

        const std::string &GetProductId() const
        {
            return mProductId;
        }

        void SetProductId(const std::string &productId)
        {
            mProductId = productId;
        }

        float GetOriginalPrice() const
        {
            return mOriginalPrice;
        }

        void SetOriginalPrice(float originalPrice)
        {
            mOriginalPrice = originalPrice;
        }

        const std::string &GetPaymentMethod() const
        {
            return mPaymentMethod;
        }

        void SetPaymentMethod(const std::string &paymentMethod)
        {
            mPaymentMethod = paymentMethod;
        }

        const std::string &GetPaymentReference() const
        {
            return mPaymentReference;
        }

        void SetPaymentReference(const std::string &paymentReference)
        {
            mPaymentReference = paymentReference;
        }

        float GetPaidPrice() const
        {
            return mPaidPrice;
        }

        void SetPaidPrice(float paidPrice)
        {
            mPaidPrice = paidPrice;
        }

        float GetRemainingAmount() const
        {
            return mRemainingAmount;
        }

        void SetRemainingAmount(float remainingAmount)
        {
            mRemainingAmount = remainingAmount;
        }

        const std::string &GetTitle() const
        {
            return mTitle;
        }

        void SetTitle(const std::string &title)
        {
            mTitle = title;
        }

        const std::string &GetTransactionTime() const
        {
            return mTransactionTime;
        }

        void SetTransactionTime(const std::string &transactionTime)
        {
            mTransactionTime = transactionTime;
        }

        const Link &GetSelf() const
        {
            return mSelf;
        }

        void SetSelf(const Link &self)
        {
            mSelf = self;
        }

        const Form &GetCommit() const
        {
            return mCommit;
        }

        void SetCommit(const Form &commit)
        {
            mCommit = commit;
        }

        const Form &GetCancel() const
        {
            return mCancel;
        }

        void SetCancel(const Form &cancel)
        {
            mCancel = cancel;
        }

        const Form &GetUpdate() const
        {
            return mUpdate;
        }

        void SetUpdate(const Form &update)
        {
            mUpdate = update;
        }

        const DRM &GetDRM() const
        {
            return mDRM;
        }

        void SetDRM(const DRM &DRM)
        {
            mDRM = DRM;
        }

        const std::string &GetSignature() const
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
        std::string mId;
        std::string mCpurchaseId;
        std::string mCrentalId;
        std::vector<std::string> mCValueCodes;
        std::string mCurrency;
        std::string mIPAddress;
        std::string mIPCountry;
        std::string mProductId;
        float mOriginalPrice;
        std::string mPaymentMethod;
        std::string mPaymentReference;
        float mPaidPrice;
        float mRemainingAmount;
        std::string mTitle;
        std::string mTransactionTime;
        Link mSelf;
        Form mCommit;
        Form mCancel;
        Form mUpdate;
        DRM mDRM;
        std::string mSignature;
    };
}

#endif //READY4AIR_PURCHASE_H
