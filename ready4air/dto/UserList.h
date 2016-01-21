#ifndef READY4AIR_USERLIST_H
#define READY4AIR_USERLIST_H

#include "../common/Maybe.h"
#include "abstract/JsonDeserializable.h"
#include "hypermedia/Form.h"
#include "hypermedia/Link.h"
#include "UserListItem.h"

namespace ready4air
{
    namespace dto
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

            const Maybe<std::string> &GetId() const
            {
                return mId;
            }

            void SetId(const std::string &id)
            {
                mId = id;
            }

            const Maybe<std::string> &GetName() const
            {
                return mName;
            }

            void SetName(const std::string &name)
            {
                mName = name;
            }

            const Maybe<bool> &IsPublic() const
            {
                return mPublic;
            }

            void SetPublic(bool aPublic)
            {
                mPublic = aPublic;
            }

            const Maybe<std::string> &GetOwner() const
            {
                return mOwner;
            }

            void SetOwner(const std::string &owner)
            {
                mOwner = owner;
            }

            const Maybe<int> &GetType() const
            {
                return mType;
            }

            void SetType(int type)
            {
                mType = type;
            }

            const Maybe<std::string> &GetListType() const
            {
                return mListType;
            }

            void SetListType(const std::string &listType)
            {
                mListType = listType;
            }

            const Maybe<Form> &GetAddItems() const
            {
                return mAddItems;
            }

            void SetAddItems(const Form &addItems)
            {
                mAddItems = addItems;
            }

            const Maybe<Form> &GetItemPosition() const
            {
                return mItemPosition;
            }

            void SetItemPosition(const Form &itemPosition)
            {
                mItemPosition = itemPosition;
            }

            const Maybe<Form> &GetRemoveItems() const
            {
                return mRemoveItems;
            }

            void SetRemoveItems(const Form &removeItems)
            {
                mRemoveItems = removeItems;
            }

            const Maybe<Link> &GetItems() const
            {
                return mItems;
            }

            void SetItems(const Link &items)
            {
                mItems = items;
            }

            const Maybe<std::vector<UserListItem> > &GetExposedItems() const
            {
                return mExposedItems;
            }

            void SetExposedItems(const std::vector<UserListItem> &exposedItems)
            {
                mExposedItems = exposedItems;
            }

            const Maybe<std::string> &GetUserId() const
            {
                return mUserId;
            }

            void SetUserId(const std::string &userId)
            {
                mUserId = userId;
            }

            const Maybe<std::string> &GetDeviceId() const
            {
                return mDeviceId;
            }

            void SetDeviceId(const std::string &deviceId)
            {
                mDeviceId = deviceId;
            }

            virtual bool InitFromJsonValue(const rapidjson::Value &value, ParseErrors &parseErrors)
            {
                std::string id;
                std::string name;
                bool aPublic;
                std::string owner;
                int type;
                std::string listType;
                Form addItems;
                Form itemPosition;
                Form removeItems;
                Link items;
                std::vector<UserListItem> exposedItems;
                std::string userId;
                std::string deviceId;

                if (ParseString(value, "Id", true, id, parseErrors))
                    SetId(id);

                if (ParseString(value, "Name", true, name, parseErrors))
                    SetName(name);

                if (ParseBool(value, "Public", true, aPublic, parseErrors))
                    SetPublic(aPublic);

                if (ParseString(value, "Owner", true, owner, parseErrors))
                    SetOwner(owner);

                if (ParseInt(value, "Type", true, type, parseErrors))
                    SetType(type);

                if (ParseString(value, "ListType", true, listType, parseErrors))
                    SetListType(listType);

                if (ParseObject(value, "AddItems", false, addItems, parseErrors))
                    SetAddItems(addItems);

                if (ParseObject(value, "ItemPosition", false, itemPosition, parseErrors))
                    SetItemPosition(itemPosition);

                if (ParseObject(value, "RemoveItems", false, removeItems, parseErrors))
                    SetRemoveItems(removeItems);

                if (ParseObject(value, "Items", false, items, parseErrors))
                    SetItems(items);

                if (VerifyArray(value, "ExposedItems", false, parseErrors))
                {
                    for (rapidjson::SizeType i = 0; i < value["ExposedItems"].Size(); i += 1)
                    {
                        UserListItem userListItem;
                        if (ParseObject(value["ExposedItems"][i], "", false, userListItem, parseErrors))
                            exposedItems.push_back(userListItem);
                    }
                    SetExposedItems(exposedItems);
                }

                if (ParseString(value, "UserId", false, userId, parseErrors))
                    SetUserId(userId);

                if (ParseString(value, "DeviceId", false, deviceId, parseErrors))
                    SetDeviceId(deviceId);

                return !parseErrors;
            }

        private:
            Maybe<std::string> mId;
            Maybe<std::string> mName;
            Maybe<bool> mPublic;
            Maybe<std::string> mOwner;
            Maybe<int> mType;
            Maybe<std::string> mListType;
            Maybe<Form> mAddItems;
            Maybe<Form> mItemPosition;
            Maybe<Form> mRemoveItems;
            Maybe<Link> mItems;
            Maybe<std::vector<UserListItem> > mExposedItems;
            Maybe<std::string> mUserId;
            Maybe<std::string> mDeviceId;
        };
    }
}

#endif //READY4AIR_USERLIST_H
