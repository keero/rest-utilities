#ifndef READY4AIR_USERLISTITEM_H
#define READY4AIR_USERLISTITEM_H

#include "../maybe/Maybe.h"
#include "abstract/JsonDeserializable.h"

namespace ready4air
{
    class UserListItem : public JsonDeserializable
    {
    public:
        UserListItem()
        {
        }

        virtual ~UserListItem()
        {
        }

        const Maybe <int> &GetPosition() const
        {
            return mPosition;
        }

        void SetPosition(int position)
        {
            mPosition = position;
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
            return false;
        }

    private:
        Maybe <int> mPosition;
        Maybe <std::string> mContentId;
    };
}

#endif //READY4AIR_USERLISTITEM_H
