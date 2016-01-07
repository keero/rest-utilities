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

        virtual bool InitFromJsonValue(const rapidjson::Value &value)
        {
            {
                // Mandatory property
                if (!value.HasMember("DeviceVersion") || !value["DeviceVersion"].IsInt()) return false;
                SetDeviceVersion(value["DeviceVersion"].GetInt());
            }
            {
                // Mandatory property
                if (!value.HasMember("CountryCode") || !value["CountryCode"].IsString()) return false;
                SetCountryCode(value["CountryCode"].GetString());
            }
            {
                // Mandatory property
                if (!value.HasMember("MediaId") || !value["MediaId"].IsInt()) return false;
                SetMediaId(value["MediaId"].GetInt());
            }
            {
                // Mandatory property
                if (!value.HasMember("CurrencyCode") || !value["CurrencyCode"].IsString()) return false;
                SetCurrencyCode(value["CurrencyCode"].GetString());
            }
            {
                // Mandatory property
                if (!value.HasMember("IsMainList") || !value["IsMainList"].IsBool()) return false;
                SetIsMainList(value["IsMainList"].GetBool());
            }
            {
                // Mandatory property
                if (!value.HasMember("Price") || !value["Price"].IsDouble()) return false;
                SetPrice(value["Price"].GetDouble());
            }
            {
                // Mandatory property
                if (!value.HasMember("ListOrder") || !value["ListOrder"].IsInt()) return false;
                SetListOrder(value["ListOrder"].GetInt());
            }

            return true;
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
