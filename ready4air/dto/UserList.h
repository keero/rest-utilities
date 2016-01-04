#ifndef READY4AIR_USERLIST_H
#define READY4AIR_USERLIST_H

#include "abstract/JsonDeserializable.h"
#include "hypermedia/Form.h"
#include "hypermedia/Link.h"
#include "UserListItem.h"

namespace ready4air
{
    class UserList : public JsonDeserializable
    {
    public:
        UserList()
        {
        }

        virtual ~UserList()
        {
        }

        const std::string &GetId() const
        {
            return mId;
        }

        void SetId(const std::string &id)
        {
            mId = id;
        }

        const std::string &GetName() const
        {
            return mName;
        }

        void SetName(const std::string &name)
        {
            mName = name;
        }

        bool IsAPublic() const
        {
            return mPublic;
        }

        void SetAPublic(bool aPublic)
        {
            mPublic = aPublic;
        }

        const std::string &GetOwner() const
        {
            return mOwner;
        }

        void SetOwner(const std::string &owner)
        {
            mOwner = owner;
        }

        int GetType() const
        {
            return mType;
        }

        void SetType(int type)
        {
            mType = type;
        }

        const std::string &GetListType() const
        {
            return mListType;
        }

        void SetListType(const std::string &listType)
        {
            mListType = listType;
        }

        const Form &GetAddItems() const
        {
            return mAddItems;
        }

        void SetAddItems(const Form &addItems)
        {
            mAddItems = addItems;
        }

        const Form &GetItemPosition() const
        {
            return mItemPosition;
        }

        void SetItemPosition(const Form &itemPosition)
        {
            mItemPosition = itemPosition;
        }

        const Form &GetRemoveItems() const
        {
            return mRemoveItems;
        }

        void SetRemoveItems(const Form &removeItems)
        {
            mRemoveItems = removeItems;
        }

        const Link &GetItems() const
        {
            return mItems;
        }

        void SetItems(const Link &items)
        {
            mItems = items;
        }

        const std::vector<UserListItem> &GetExposedItems() const
        {
            return mExposedItems;
        }

        void SetExposedItems(const std::vector<UserListItem> &exposedItems)
        {
            mExposedItems = exposedItems;
        }

        const std::string &GetUserId() const
        {
            return mUserId;
        }

        void SetUserId(const std::string &userId)
        {
            mUserId = userId;
        }

        const std::string &GetDeviceId() const
        {
            return mDeviceId;
        }

        void SetDeviceId(const std::string &deviceId)
        {
            mDeviceId = deviceId;
        }

        virtual bool InitFromJsonValue(const rapidjson::Value &value)
        {
            return false;
        }

    private:
        std::string mId;
        std::string mName;
        bool mPublic;
        std::string mOwner;
        int mType;
        std::string mListType;
        Form mAddItems;
        Form mItemPosition;
        Form mRemoveItems;
        Link mItems;
        std::vector<UserListItem> mExposedItems;
        std::string mUserId;
        std::string mDeviceId;

    };
}

#endif //READY4AIR_USERLIST_H
