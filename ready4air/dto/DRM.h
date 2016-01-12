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

        virtual bool InitFromJsonValue(const rapidjson::Value &value, ParseErrors &parseErrors)
        {
            Link cookie;
            std::string customData;
            std::string customerToken;
            std::string deviceToken;
            std::string contentId;

            if (ParseObject(value, "Cookie", true, cookie, parseErrors))
                SetCookie(cookie);

            if (ParseString(value, "CustomData", true, customData, parseErrors))
                SetCustomData(customData);

            if (ParseString(value, "CustomerToken", true, customerToken, parseErrors))
                SetCustomerToken(customerToken);

            if (ParseString(value, "DeviceToken", true, deviceToken, parseErrors))
                SetDeviceToken(deviceToken);

            if (ParseString(value, "ContentId", true, contentId, parseErrors))
                SetContentId(contentId);

            return !parseErrors;
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
