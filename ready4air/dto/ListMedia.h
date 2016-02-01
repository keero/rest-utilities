#ifndef READY4AIR_LISTMEDIA_H
#define READY4AIR_LISTMEDIA_H

#include "../common/Maybe.h"
#include "abstract/JsonDeserializable.h"

namespace ready4air
{
    namespace dto
    {
        class ListMedia : public JsonDeserializable
        {
        public:
            ListMedia() : TAG("ready4air::dto::ListMedia")
            {
            }

            virtual ~ListMedia()
            {
            }

            const Maybe<int> &GetDeviceVersion() const
            {
                return mDeviceVersion;
            }

            void SetDeviceVersion(int deviceVersion)
            {
                mDeviceVersion = deviceVersion;
            }

            const Maybe <STRING_T> &GetCountryCode() const
            {
                return mCountryCode;
            }

            void SetCountryCode(const STRING_T &countryCode)
            {
                mCountryCode = countryCode;
            }

            const Maybe<int> &GetMediaId() const
            {
                return mMediaId;
            }

            void SetMediaId(int mediaId)
            {
                mMediaId = mediaId;
            }

            const Maybe <STRING_T> &GetCurrencyCode() const
            {
                return mCurrencyCode;
            }

            void SetCurrencyCode(const STRING_T &currencyCode)
            {
                mCurrencyCode = currencyCode;
            }

            const Maybe<BOOL_T> &IsMainList() const
            {
                return mIsMainList;
            }

            void SetIsMainList(BOOL_T isMainList)
            {
                mIsMainList = isMainList;
            }

            const Maybe<DOUBLE_T> &GetPrice() const
            {
                return mPrice;
            }

            void SetPrice(DOUBLE_T price)
            {
                mPrice = price;
            }

            const Maybe<int> &GetListOrder() const
            {
                return mListOrder;
            }

            void SetListOrder(int listOrder)
            {
                mListOrder = listOrder;
            }

            virtual BOOL_T InitFromJsonValue(const rapidjson::Value &value, ParseErrors &parseErrors)
            {
                INT32_T deviceVersion;
                STRING_T countryCode;
                INT32_T mediaId;
                STRING_T currencyCode;
                BOOL_T isMainList;
                DOUBLE_T price;
                INT32_T listOrder;

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
            Maybe<int> mDeviceVersion;
            Maybe <STRING_T> mCountryCode;
            Maybe<int> mMediaId;
            Maybe <STRING_T> mCurrencyCode;
            Maybe<BOOL_T> mIsMainList;
            Maybe<DOUBLE_T> mPrice;
            Maybe<int> mListOrder;
            STRING_T TAG;
        };
    }
}

#endif //READY4AIR_LISTMEDIA_H
