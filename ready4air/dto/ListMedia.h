#ifndef READY4AIR_LISTMEDIA_H
#define READY4AIR_LISTMEDIA_H

#include "../maybe/Maybe.h"
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

        const Maybe <int> &GetDeviceVersion() const
        {
            return mDeviceVersion;
        }

        void SetDeviceVersion(int deviceVersion)
        {
            mDeviceVersion = deviceVersion;
        }

        const Maybe <std::string> &GetCountryCode() const
        {
            return mCountryCode;
        }

        void SetCountryCode(const std::string &countryCode)
        {
            mCountryCode = countryCode;
        }

        const Maybe <int> &GetMediaId() const
        {
            return mMediaId;
        }

        void SetMediaId(int mediaId)
        {
            mMediaId = mediaId;
        }

        const Maybe <std::string> &GetCurrencyCode() const
        {
            return mCurrencyCode;
        }

        void SetCurrencyCode(const std::string &currencyCode)
        {
            mCurrencyCode = currencyCode;
        }

        const Maybe <bool> &IsMainList() const
        {
            return mIsMainList;
        }

        void SetIsMainList(bool isMainList)
        {
            mIsMainList = isMainList;
        }

        const Maybe <double> &GetPrice() const
        {
            return mPrice;
        }

        void SetPrice(double price)
        {
            mPrice = price;
        }

        const Maybe <int> &GetListOrder() const
        {
            return mListOrder;
        }

        void SetListOrder(int listOrder)
        {
            mListOrder = listOrder;
        }

        virtual bool InitFromJsonValue(const rapidjson::Value &value, ParseErrors &parseErrors)
        {
            int deviceVersion;
            std::string countryCode;
            int mediaId;
            std::string currencyCode;
            bool isMainList;
            double price;
            int listOrder;

            if (ParseInt(value, "DeviceVersion", true, deviceVersion, parseErrors))
                SetDeviceVersion(deviceVersion);

            if (ParseString(value, "CountryCode", true, countryCode, parseErrors))
                SetCountryCode(countryCode);

            if (ParseInt(value, "MediaId", true, mediaId, parseErrors))
                SetDeviceVersion(mediaId);

            if (ParseString(value, "CurrencyCode", true, currencyCode, parseErrors))
                SetCurrencyCode(currencyCode);

            if (ParseBool(value, "IsMainList", true, isMainList, parseErrors))
                SetIsMainList(isMainList);

            if (ParseDouble(value, "Price", true, price, parseErrors))
                SetPrice(price);

            if (ParseInt(value, "ListOrder", true, listOrder, parseErrors))
                SetListOrder(listOrder);

            return !parseErrors;
        }

    private:
        Maybe <int> mDeviceVersion;
        Maybe <std::string> mCountryCode;
        Maybe <int> mMediaId;
        Maybe <std::string> mCurrencyCode;
        Maybe <bool> mIsMainList;
        Maybe <double> mPrice;
        Maybe <int> mListOrder;
    };
}

#endif //READY4AIR_LISTMEDIA_H
