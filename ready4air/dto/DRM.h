#ifndef READY4AIR_DRM_H
#define READY4AIR_DRM_H

#include "../common/Maybe.h"
#include "abstract/JsonDeserializable.h"
#include "hypermedia/Link.h"

namespace ready4air
{
    namespace dto
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

            const Maybe <STRING_T> &GetCustomData() const
            {
                return mCustomData;
            }

            void SetCustomData(const STRING_T &customData)
            {
                mCustomData = customData;
            }

            const Maybe <STRING_T> &GetCustomerToken() const
            {
                return mCustomerToken;
            }

            void SetCustomerToken(const STRING_T &customerToken)
            {
                mCustomerToken = customerToken;
            }

            const Maybe <STRING_T> &GetDeviceToken() const
            {
                return mDeviceToken;
            }

            void SetDeviceToken(const STRING_T &deviceToken)
            {
                mDeviceToken = deviceToken;
            }

            const Maybe <STRING_T> &GetContentId() const
            {
                return mContentId;
            }

            void SetContentId(const STRING_T &contentId)
            {
                mContentId = contentId;
            }

            virtual BOOL_T InitFromJsonValue(const rapidjson::Value &value, ParseErrors &parseErrors)
            {
                Link cookie;
                STRING_T customData;
                STRING_T customerToken;
                STRING_T deviceToken;
                STRING_T contentId;

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
            Maybe <STRING_T> mCustomData;
            Maybe <STRING_T> mCustomerToken;
            Maybe <STRING_T> mDeviceToken;
            Maybe <STRING_T> mContentId;
        };
    }
}

#endif //READY4AIR_DRM_H
