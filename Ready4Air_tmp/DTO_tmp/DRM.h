#ifndef READY4AIR_DRM_H
#define READY4AIR_DRM_H

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

        const Link &GetCookie() const
        {
            return mCookie;
        }

        void SetCookie(const Link &cookie)
        {
            mCookie = cookie;
        }

        const std::string &GetCustomData() const
        {
            return mCustomData;
        }

        void SetCustomData(const std::string &customData)
        {
            mCustomData = customData;
        }

        const std::string &GetCustomerToken() const
        {
            return mCustomerToken;
        }

        void SetCustomerToken(const std::string &customerToken)
        {
            mCustomerToken = customerToken;
        }

        const std::string &GetDeviceToken() const
        {
            return mDeviceToken;
        }

        void SetDeviceToken(const std::string &deviceToken)
        {
            mDeviceToken = deviceToken;
        }

        const std::string &GetContentId() const
        {
            return mContentId;
        }

        void SetContentId(const std::string &contentId)
        {
            mContentId = contentId;
        }

    private:
        Link mCookie;
        std::string mCustomData;
        std::string mCustomerToken;
        std::string mDeviceToken;
        std::string mContentId;
    };
}

#endif //READY4AIR_DRM_H
