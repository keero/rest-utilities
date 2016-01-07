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

        virtual bool InitFromJsonValue(const rapidjson::Value &value)
        {
            {
                // Mandatory property
                if (!value.HasMember("DeviceVersion") || !value["DeviceVersion"].IsInt()) return false;
                SetDeviceVersion(value["DeviceVersion"].GetInt());
            }
            {
                // Mandatory property
                if (!value.HasMember("Country") || !value["Country"].IsString()) return false;
                SetCountry(value["Country"].GetString());
            }
            {
                // Non-mandatory property
                if (value.HasMember("Language"))
                {
                    if (!value["Language"].IsString()) return false;
                    SetLanguage(value["Language"].GetString());
                }
            }
            {
                // Non-mandatory property
                if (value.HasMember("DeviceId"))
                {
                    if (!value["DeviceId"].IsString()) return false;
                    SetDeviceId(value["DeviceId"].GetString());
                }
            }
            {
                // Non-mandatory property
                if (value.HasMember("Token"))
                {
                    if (!value["Token"].IsString()) return false;
                    SetToken(value["Token"].GetString());
                }
            }
            {
                // Non-mandatory property
                if (value.HasMember("ExpirationDateTime"))
                {
                    if (!value["ExpirationDateTime"].IsString()) return false;
                    SetExpirationDateTime(value["ExpirationDateTime"].GetString());
                }
            }
            {
                // Non-mandatory property
                if (value.HasMember("IpAddress"))
                {
                    if (!value["IpAddress"].IsString()) return false;
                    SetIpAddress(value["IpAddress"].GetString());
                }
            }

            return true;
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
