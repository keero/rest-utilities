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

        virtual bool InitFromJsonValue(const rapidjson::Value &value)
        {
            {
                // Mandatory property
                if (!value.HasMember("Id") || !value["Id"].IsString()) return false;
                SetId(value["Id"].GetString());
            }
            {
                // Mandatory property
                if (!value.HasMember("Value") || !value["Value"].IsString()) return false;
                SetValue(value["Value"].GetString());
            }
            {
                // Mandatory property
                if (!value.HasMember("Created") || !value["Created"].IsString()) return false;
                SetCreated(value["Created"].GetString());
            }
            {
                // Mandatory property
                if (!value.HasMember("ContentId") || !value["ContentId"].IsString()) return false;
                SetContentId(value["ContentId"].GetString());
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
                if (value.HasMember("UserId"))
                {
                    if (!value["UserId"].IsString()) return false;
                    SetUserId(value["UserId"].GetString());
                }
            }
            {
                // Non-mandatory property
                if (value.HasMember("Modified"))
                {
                    if (!value["Modified"].IsString()) return false;
                    SetModified(value["Modified"].GetString());
                }
            }

            return true;
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
