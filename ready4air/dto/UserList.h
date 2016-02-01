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
            UserList() : TAG("ready4air::dto::UserList")
            {
            }

            virtual ~UserList()
            {
            }

            const Maybe<STRING_T> &GetId() const
            {
                return mId;
            }

            void SetId(const STRING_T &id)
            {
                mId = id;
            }

            const Maybe<STRING_T> &GetName() const
            {
                return mName;
            }

            void SetName(const STRING_T &name)
            {
                mName = name;
            }

            const Maybe<BOOL_T> &IsPublic() const
            {
                return mPublic;
            }

            void SetPublic(BOOL_T aPublic)
            {
                mPublic = aPublic;
            }

            const Maybe<STRING_T> &GetOwner() const
            {
                return mOwner;
            }

            void SetOwner(const STRING_T &owner)
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

            const Maybe<STRING_T> &GetListType() const
            {
                return mListType;
            }

            void SetListType(const STRING_T &listType)
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

            const Maybe<VECTOR_T<UserListItem> > &GetExposedItems() const
            {
                return mExposedItems;
            }

            void SetExposedItems(const VECTOR_T<UserListItem> &exposedItems)
            {
                mExposedItems = exposedItems;
            }

            const Maybe<STRING_T> &GetUserId() const
            {
                return mUserId;
            }

            void SetUserId(const STRING_T &userId)
            {
                mUserId = userId;
            }

            const Maybe<STRING_T> &GetDeviceId() const
            {
                return mDeviceId;
            }

            void SetDeviceId(const STRING_T &deviceId)
            {
                mDeviceId = deviceId;
            }

            virtual BOOL_T InitFromJsonValue(const rapidjson::Value &value, ParseErrors &parseErrors)
            {
                STRING_T id;
                STRING_T name;
                BOOL_T aPublic;
                STRING_T owner;
                INT32_T type;
                STRING_T listType;
                Form addItems;
                Form itemPosition;
                Form removeItems;
                Link items;
                VECTOR_T<UserListItem> exposedItems;
                STRING_T userId;
                STRING_T deviceId;

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
            Maybe<STRING_T> mId;
            Maybe<STRING_T> mName;
            Maybe<BOOL_T> mPublic;
            Maybe<STRING_T> mOwner;
            Maybe<int> mType;
            Maybe<STRING_T> mListType;
            Maybe<Form> mAddItems;
            Maybe<Form> mItemPosition;
            Maybe<Form> mRemoveItems;
            Maybe<Link> mItems;
            Maybe<VECTOR_T<UserListItem> > mExposedItems;
            Maybe<STRING_T> mUserId;
            Maybe<STRING_T> mDeviceId;
            STRING_T TAG;
        };
    }
}

#endif //READY4AIR_USERLIST_H
