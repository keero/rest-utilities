#ifndef READY4AIR_USERLISTITEM_H
#define READY4AIR_USERLISTITEM_H

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

        int GetPosition() const
        {
            return mPosition;
        }

        void SetPosition(int position)
        {
            mPosition = position;
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
        int mPosition;
        std::string mContentId;
    };
}

#endif //READY4AIR_USERLISTITEM_H
