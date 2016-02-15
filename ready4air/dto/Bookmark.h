#ifndef READY4AIR_BOOKMARK_H
#define READY4AIR_BOOKMARK_H

#include "../common/Maybe.h"
#include "abstract/JsonDeserializable.h"

namespace ready4air
{
    namespace dto
    {
        class Bookmark : public JsonDeserializable
        {
        public:
            Bookmark() : TAG("ready4air::dto::Bookmark")
            {
            }

            virtual ~Bookmark()
            {
            }

            const Maybe <STRING_T> &GetId() const
            {
                return mId;
            }

            void SetId(const STRING_T &id)
            {
                mId = id;
            }

            const Maybe <STRING_T> &GetValue() const
            {
                return mValue;
            }

            void SetValue(const STRING_T &value)
            {
                mValue = value;
            }

            const Maybe <STRING_T> &GetCreated() const
            {
                return mCreated;
            }

            void SetCreated(const STRING_T &created)
            {
                mCreated = created;
            }

            const Maybe <STRING_T> &GetContentId() const
            {
                return mContentId;
            }

            void SetContentId(const STRING_T &contentId)
            {
                mContentId = contentId;
            }

            const Maybe <STRING_T> &GetDeviceId() const
            {
                return mDeviceId;
            }

            void SetDeviceId(const STRING_T &deviceId)
            {
                mDeviceId = deviceId;
            }

            const Maybe <STRING_T> &GetUserId() const
            {
                return mUserId;
            }

            void SetUserId(const STRING_T &userId)
            {
                mUserId = userId;
            }

            const Maybe <STRING_T> &GetModified() const
            {
                return mModified;
            }

            void SetModified(const STRING_T &modified)
            {
                mModified = modified;
            }

            virtual BOOL_T InitFromJsonValue(const rapidjson::Value &value, ParseErrors &parseErrors,
                                             VECTOR_T<STRING_T> &context)
            {
                STRING_T id;
                STRING_T val;
                STRING_T created;
                STRING_T contentId;
                STRING_T deviceId;
                STRING_T userId;
                STRING_T modified;

                context.push_back(TAG);

                if (ParseString(value, "Id", true, id, parseErrors, context))
                    SetId(id);

                if (ParseString(value, "Value", true, val, parseErrors, context))
                    SetValue(val);

                if (ParseString(value, "Created", true, created, parseErrors, context))
                    SetCreated(created);

                if (ParseString(value, "ContentId", true, contentId, parseErrors, context))
                    SetContentId(contentId);

                if (ParseString(value, "DeviceId", false, deviceId, parseErrors, context))
                    SetDeviceId(deviceId);

                if (ParseString(value, "UserId", false, userId, parseErrors, context))
                    SetUserId(userId);

                if (ParseString(value, "Modified", false, modified, parseErrors, context))
                    SetModified(modified);

                context.pop_back();
                return !parseErrors;
            }

        private:
            Maybe <STRING_T> mId;
            Maybe <STRING_T> mValue;
            Maybe <STRING_T> mCreated;
            Maybe <STRING_T> mContentId;
            Maybe <STRING_T> mDeviceId;
            Maybe <STRING_T> mUserId;
            Maybe <STRING_T> mModified;
            STRING_T TAG;
        };
    }
}

#endif //READY4AIR_BOOKMARK_H
