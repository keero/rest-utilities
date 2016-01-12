#ifndef READY4AIR_DEVICEAUTHDATA_H
#define READY4AIR_DEVICEAUTHDATA_H

#include "../maybe/Maybe.h"
#include "abstract/JsonDeserializable.h"

namespace ready4air
{
    class DeviceAuthData : public JsonDeserializable
    {
    public:
        DeviceAuthData()
        {
        }

        virtual ~DeviceAuthData()
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

        const Maybe <std::string> &GetCountry() const
        {
            return mCountry;
        }

        void SetCountry(const std::string &country)
        {
            mCountry = country;
        }

        const Maybe <std::string> &GetLanguage() const
        {
            return mLanguage;
        }

        void SetLanguage(const std::string &language)
        {
            mLanguage = language;
        }

        const Maybe <std::string> &GetDeviceId() const
        {
            return mDeviceId;
        }

        void SetDeviceId(const std::string &deviceId)
        {
            mDeviceId = deviceId;
        }

        const Maybe <std::string> &GetToken() const
        {
            return mToken;
        }

        void SetToken(const std::string &token)
        {
            mToken = token;
        }

        const Maybe <std::string> &GetExpirationDateTime() const
        {
            return mExpirationDateTime;
        }

        void SetExpirationDateTime(const std::string &expirationDateTime)
        {
            mExpirationDateTime = expirationDateTime;
        }

        const Maybe <std::string> &GetIpAddress() const
        {
            return mIpAddress;
        }

        void SetIpAddress(const std::string &ipAddress)
        {
            mIpAddress = ipAddress;
        }

        virtual bool InitFromJsonValue(const rapidjson::Value &value, ParseErrors &parseErrors)
        {
            int deviceVersion;
            std::string country;
            std::string language;
            std::string deviceId;
            std::string token;
            std::string expirationDateTime;
            std::string ipAddress;

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
        Maybe <int> mDeviceVersion;
        Maybe <std::string> mCountry;
        Maybe <std::string> mLanguage;
        Maybe <std::string> mDeviceId;
        Maybe <std::string> mToken;
        Maybe <std::string> mExpirationDateTime;
        Maybe <std::string> mIpAddress;
    };
}

#endif //READY4AIR_DEVICEAUTHDATA_H
