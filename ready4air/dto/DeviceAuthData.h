#ifndef READY4AIR_DEVICEAUTHDATA_H
#define READY4AIR_DEVICEAUTHDATA_H

#include "../common/Maybe.h"
#include "abstract/JsonDeserializable.h"

namespace ready4air
{
    namespace dto
    {
        class DeviceAuthData : public JsonDeserializable
        {
        public:
            DeviceAuthData() : TAG("ready4air::dto::DeviceAuthData")
            {
            }

            virtual ~DeviceAuthData()
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

            const Maybe <STRING_T> &GetCountry() const
            {
                return mCountry;
            }

            void SetCountry(const STRING_T &country)
            {
                mCountry = country;
            }

            const Maybe <STRING_T> &GetLanguage() const
            {
                return mLanguage;
            }

            void SetLanguage(const STRING_T &language)
            {
                mLanguage = language;
            }

            const Maybe <STRING_T> &GetDeviceId() const
            {
                return mDeviceId;
            }

            void SetDeviceId(const STRING_T &deviceId)
            {
                mDeviceId = deviceId;
            }

            const Maybe <STRING_T> &GetToken() const
            {
                return mToken;
            }

            void SetToken(const STRING_T &token)
            {
                mToken = token;
            }

            const Maybe <STRING_T> &GetExpirationDateTime() const
            {
                return mExpirationDateTime;
            }

            void SetExpirationDateTime(const STRING_T &expirationDateTime)
            {
                mExpirationDateTime = expirationDateTime;
            }

            const Maybe <STRING_T> &GetIpAddress() const
            {
                return mIpAddress;
            }

            void SetIpAddress(const STRING_T &ipAddress)
            {
                mIpAddress = ipAddress;
            }

            virtual BOOL_T InitFromJsonValue(const rapidjson::Value &value, ParseErrors &parseErrors)
            {
                INT32_T deviceVersion;
                STRING_T country;
                STRING_T language;
                STRING_T deviceId;
                STRING_T token;
                STRING_T expirationDateTime;
                STRING_T ipAddress;

                if (ParseInt(value, "DeviceVersion", true, deviceVersion, parseErrors))
                    SetDeviceVersion(deviceVersion);

                if (ParseString(value, "Country", true, country, parseErrors))
                    SetCountry(country);

                if (ParseString(value, "Language", false, language, parseErrors))
                    SetLanguage(language);

                if (ParseString(value, "DeviceId", false, deviceId, parseErrors))
                    SetDeviceId(deviceId);

                if (ParseString(value, "Token", false, token, parseErrors))
                    SetToken(token);

                if (ParseString(value, "ExpirationDateTime", false, expirationDateTime, parseErrors))
                    SetExpirationDateTime(expirationDateTime);

                if (ParseString(value, "IpAddress", false, ipAddress, parseErrors))
                    SetIpAddress(ipAddress);

                return !parseErrors;
            }

        private:
            Maybe<int> mDeviceVersion;
            Maybe <STRING_T> mCountry;
            Maybe <STRING_T> mLanguage;
            Maybe <STRING_T> mDeviceId;
            Maybe <STRING_T> mToken;
            Maybe <STRING_T> mExpirationDateTime;
            Maybe <STRING_T> mIpAddress;
            const STRING_T TAG;
        };
    }
}

#endif //READY4AIR_DEVICEAUTHDATA_H
