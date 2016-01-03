#ifndef READY4AIR_LISTMEDIA_H
#define READY4AIR_LISTMEDIA_H

#include "abstract/JsonDeserializable.h"

namespace ready4air
{
    class ListMedia : public JsonDeserializable
    {
    public:
        ListMedia()
        {
        }

        virtual ~ListMedia()
        {
        }

        int GetDeviceVersion() const
        {
            return mDeviceVersion;
        }

        void SetDeviceVersion(int deviceVersion)
        {
            mDeviceVersion = deviceVersion;
        }

        const std::string &GetCountryCode() const
        {
            return mCountryCode;
        }

        void SetCountryCode(const std::string &countryCode)
        {
            mCountryCode = countryCode;
        }

        int GetMediaId() const
        {
            return mMediaId;
        }

        void SetMediaId(int mediaId)
        {
            mMediaId = mediaId;
        }

        const std::string &GetCurrencyCode() const
        {
            return mCurrencyCode;
        }

        void SetCurrencyCode(const std::string &currencyCode)
        {
            mCurrencyCode = currencyCode;
        }

        bool IsMainList() const
        {
            return mIsMainList;
        }

        void SetIsMainList(bool isMainList)
        {
            mIsMainList = isMainList;
        }

        float GetPrice() const
        {
            return mPrice;
        }

        void SetPrice(float price)
        {
            mPrice = price;
        }

        int GetListOrder() const
        {
            return mListOrder;
        }

        void SetListOrder(int listOrder)
        {
            mListOrder = listOrder;
        }

    private:
        int mDeviceVersion;
        std::string mCountryCode;
        int mMediaId;
        std::string mCurrencyCode;
        bool mIsMainList;
        float mPrice;
        int mListOrder;
    };
}

#endif //READY4AIR_LISTMEDIA_H
