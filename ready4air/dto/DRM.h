#ifndef READY4AIR_DRM_H
#define READY4AIR_DRM_H

#include "../maybe/Maybe.h"
#include "abstract/JsonDeserializable.h"
#include "hypermedia/Link.h"

namespace ready4air
{
    class DRM : public JsonDeserializable
    {
    public:
        DRM()
        {
        }

        virtual ~DRM()
        {
        }

        const Maybe <Link> &GetCookie() const
        {
            return mCookie;
        }

        void SetCookie(const Link &cookie)
        {
            mCookie = cookie;
        }

        const Maybe <std::string> &GetCustomData() const
        {
            return mCustomData;
        }

        void SetCustomData(const std::string &customData)
        {
            mCustomData = customData;
        }

        const Maybe <std::string> &GetCustomerToken() const
        {
            return mCustomerToken;
        }

        void SetCustomerToken(const std::string &customerToken)
        {
            mCustomerToken = customerToken;
        }

        const Maybe <std::string> &GetDeviceToken() const
        {
            return mDeviceToken;
        }

        void SetDeviceToken(const std::string &deviceToken)
        {
            mDeviceToken = deviceToken;
        }

        const Maybe <std::string> &GetContentId() const
        {
            return mContentId;
        }

        void SetContentId(const std::string &contentId)
        {
            mContentId = contentId;
        }

        virtual bool InitFromJsonValue(const rapidjson::Value &value)
        {
            {
                // Mandatory property
                Link cookie;
                if (!value.HasMember("Cookie") || !value["Cookie"].IsObject() || !cookie.InitFromJsonValue(value["Cookie"])) return false;
                SetCookie(cookie);
            }
            {
                // Mandatory property
                if (!value.HasMember("CustomData") || !value["CustomData"].IsString()) return false;
                SetCustomData(value["CustomData"].GetString());
            }
            {
                // Mandatory property
                if (!value.HasMember("CustomerToken") || !value["CustomerToken"].IsString()) return false;
                SetCustomerToken(value["CustomerToken"].GetString());
            }
            {
                // Mandatory property
                if (!value.HasMember("DeviceToken") || !value["DeviceToken"].IsString()) return false;
                SetDeviceToken(value["DeviceToken"].GetString());
            }
            {
                // Mandatory property
                if (!value.HasMember("ContentId") || !value["ContentId"].IsString()) return false;
                SetContentId(value["ContentId"].GetString());
            }

            return true;
        }

    private:
        Maybe <Link> mCookie;
        Maybe <std::string> mCustomData;
        Maybe <std::string> mCustomerToken;
        Maybe <std::string> mDeviceToken;
        Maybe <std::string> mContentId;
    };
}

#endif //READY4AIR_DRM_H
