#ifndef READY4AIR_DEVICEAUTHDATA_H
#define READY4AIR_DEVICEAUTHDATA_H

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

        int GetDeviceVersion() const
        {
            return mDeviceVersion;
        }

        void SetDeviceVersion(int deviceVersion)
        {
            mDeviceVersion = deviceVersion;
        }

        const std::string &GetCountry() const
        {
            return mCountry;
        }

        void SetCountry(const std::string &country)
        {
            mCountry = country;
        }

        const std::string &GetLanguage() const
        {
            return mLanguage;
        }

        void SetLanguage(const std::string &language)
        {
            mLanguage = language;
        }

        const std::string &GetDeviceId() const
        {
            return mDeviceId;
        }

        void SetDeviceId(const std::string &deviceId)
        {
            mDeviceId = deviceId;
        }

        const std::string &GetToken() const
        {
            return mToken;
        }

        void SetToken(const std::string &token)
        {
            mToken = token;
        }

        const std::string &GetExpirationDateTime() const
        {
            return mExpirationDateTime;
        }

        void SetExpirationDateTime(const std::string &expirationDateTime)
        {
            mExpirationDateTime = expirationDateTime;
        }

        const std::string &GetIpAddress() const
        {
            return mIpAddress;
        }

        void SetIpAddress(const std::string &ipAddress)
        {
            mIpAddress = ipAddress;
        }

    private:
        int mDeviceVersion;
        std::string mCountry;
        std::string mLanguage;
        std::string mDeviceId;
        std::string mToken;
        std::string mExpirationDateTime;
        std::string mIpAddress;
    };
}

#endif //READY4AIR_DEVICEAUTHDATA_H
