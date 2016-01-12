#ifndef READY4AIR_BOOKMARK_H
#define READY4AIR_BOOKMARK_H

#include "../maybe/Maybe.h"
#include "abstract/JsonDeserializable.h"

namespace ready4air
{
    class Bookmark : public JsonDeserializable
    {
    public:
        Bookmark()
        {
        }

        virtual ~Bookmark()
        {
        }

        const Maybe <std::string> &GetId() const
        {
            return mId;
        }

        void SetId(const std::string &id)
        {
            mId = id;
        }

        const Maybe <std::string> &GetValue() const
        {
            return mValue;
        }

        void SetValue(const std::string &value)
        {
            mValue = value;
        }

        const Maybe <std::string> &GetCreated() const
        {
            return mCreated;
        }

        void SetCreated(const std::string &created)
        {
            mCreated = created;
        }

        const Maybe <std::string> &GetContentId() const
        {
            return mContentId;
        }

        void SetContentId(const std::string &contentId)
        {
            mContentId = contentId;
        }

        const Maybe <std::string> &GetDeviceId() const
        {
            return mDeviceId;
        }

        void SetDeviceId(const std::string &deviceId)
        {
            mDeviceId = deviceId;
        }

        const Maybe <std::string> &GetUserId() const
        {
            return mUserId;
        }

        void SetUserId(const std::string &userId)
        {
            mUserId = userId;
        }

        const Maybe <std::string> &GetModified() const
        {
            return mModified;
        }

        void SetModified(const std::string &modified)
        {
            mModified = modified;
        }

        virtual bool InitFromJsonValue(const rapidjson::Value &value, ParseErrors &parseErrors)
        {
            std::string id;
            std::string val;
            std::string created;
            std::string contentId;
            std::string deviceId;
            std::string userId;
            std::string modified;

            if (ParseString(value, "Id", true, id, parseErrors))
                SetId(id);

            if (ParseString(value, "Value", true, val, parseErrors))
                SetValue(val);

            if (ParseString(value, "Created", true, created, parseErrors))
                SetCreated(created);

            if (ParseString(value, "ContentId", true, contentId, parseErrors))
                SetContentId(contentId);

            if (ParseString(value, "DeviceId", false, deviceId, parseErrors))
                SetDeviceId(deviceId);

            if (ParseString(value, "UserId", false, userId, parseErrors))
                SetUserId(userId);

            if (ParseString(value, "Modified", false, modified, parseErrors))
                SetModified(modified);

            return !parseErrors;
        }

    private:
        Maybe <std::string> mId;
        Maybe <std::string> mValue;
        Maybe <std::string> mCreated;
        Maybe <std::string> mContentId;
        Maybe <std::string> mDeviceId;
        Maybe <std::string> mUserId;
        Maybe <std::string> mModified;
    };
}

#endif //READY4AIR_BOOKMARK_H
