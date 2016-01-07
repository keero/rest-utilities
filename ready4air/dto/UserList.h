#ifndef READY4AIR_USERLIST_H
#define READY4AIR_USERLIST_H

#include "../maybe/Maybe.h"
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

        const Maybe <std::string> &GetId() const
        {
            return mId;
        }

        void SetId(const std::string &id)
        {
            mId = id;
        }

        const Maybe <std::string> &GetName() const
        {
            return mName;
        }

        void SetName(const std::string &name)
        {
            mName = name;
        }

        const Maybe <bool> &IsAPublic() const
        {
            return mPublic;
        }

        void SetAPublic(bool aPublic)
        {
            mPublic = aPublic;
        }

        const Maybe <std::string> &GetOwner() const
        {
            return mOwner;
        }

        void SetOwner(const std::string &owner)
        {
            mOwner = owner;
        }

        const Maybe <int> &GetType() const
        {
            return mType;
        }

        void SetType(int type)
        {
            mType = type;
        }

        const Maybe <std::string> &GetListType() const
        {
            return mListType;
        }

        void SetListType(const std::string &listType)
        {
            mListType = listType;
        }

        const Maybe <Form> &GetAddItems() const
        {
            return mAddItems;
        }

        void SetAddItems(const Form &addItems)
        {
            mAddItems = addItems;
        }

        const Maybe <Form> &GetItemPosition() const
        {
            return mItemPosition;
        }

        void SetItemPosition(const Form &itemPosition)
        {
            mItemPosition = itemPosition;
        }

        const Maybe <Form> &GetRemoveItems() const
        {
            return mRemoveItems;
        }

        void SetRemoveItems(const Form &removeItems)
        {
            mRemoveItems = removeItems;
        }

        const Maybe <Link> &GetItems() const
        {
            return mItems;
        }

        void SetItems(const Link &items)
        {
            mItems = items;
        }

        const Maybe <std::vector<UserListItem> > &GetExposedItems() const
        {
            return mExposedItems;
        }

        void SetExposedItems(const std::vector<UserListItem> &exposedItems)
        {
            mExposedItems = exposedItems;
        }

        const Maybe <std::string> &GetUserId() const
        {
            return mUserId;
        }

        void SetUserId(const std::string &userId)
        {
            mUserId = userId;
        }

        const Maybe <std::string> &GetDeviceId() const
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
        Maybe <std::string> mId;
        Maybe <std::string> mName;
        Maybe <bool> mPublic;
        Maybe <std::string> mOwner;
        Maybe <int> mType;
        Maybe <std::string> mListType;
        Maybe <Form> mAddItems;
        Maybe <Form> mItemPosition;
        Maybe <Form> mRemoveItems;
        Maybe <Link> mItems;
        Maybe <std::vector<UserListItem> > mExposedItems;
        Maybe <std::string> mUserId;
        Maybe <std::string> mDeviceId;
    };
}

#endif //READY4AIR_USERLIST_H
