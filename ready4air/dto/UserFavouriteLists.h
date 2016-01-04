#ifndef READY4AIR_USERFAVOURITELISTS_H
#define READY4AIR_USERFAVOURITELISTS_H

#include "abstract/JsonDeserializable.h"
#include "hypermedia/Form.h"
#include "hypermedia/Link.h"

namespace ready4air
{
    class UserFavouriteLists : public JsonDeserializable
    {
    public:
        UserFavouriteLists()
        {
        }

        virtual ~UserFavouriteLists()
        {
        }

        const Form &GetAddLists() const
        {
            return mAddLists;
        }

        void SetAddLists(const Form &addLists)
        {
            mAddLists = addLists;
        }

        const Form &GetListPosition() const
        {
            return mListPosition;
        }

        void SetListPosition(const Form &listPosition)
        {
            mListPosition = listPosition;
        }

        const Form &GetRemoveLists() const
        {
            return mRemoveLists;
        }

        void SetRemoveLists(const Form &removeLists)
        {
            mRemoveLists = removeLists;
        }

        const Link &GetLists() const
        {
            return mLists;
        }

        void SetLists(const Link &lists)
        {
            mLists = lists;
        }

        const std::vector<std::string> &GetExposedItems() const
        {
            return mExposedItems;
        }

        void SetExposedItems(const std::vector<std::string> &exposedItems)
        {
            mExposedItems = exposedItems;
        }

        virtual bool InitFromJsonValue(const rapidjson::Value &value)
        {
            return false;
        }

    private:
        Form mAddLists;
        Form mListPosition;
        Form mRemoveLists;
        Link mLists;
        std::vector<std::string> mExposedItems;
    };
}

#endif //READY4AIR_USERFAVOURITELISTS_H
