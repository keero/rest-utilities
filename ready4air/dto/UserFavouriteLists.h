#ifndef READY4AIR_USERFAVOURITELISTS_H
#define READY4AIR_USERFAVOURITELISTS_H

#include "../maybe/Maybe.h"
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

        const Maybe <Form> &GetAddLists() const
        {
            return mAddLists;
        }

        void SetAddLists(const Form &addLists)
        {
            mAddLists = addLists;
        }

        const Maybe <Form> &GetListPosition() const
        {
            return mListPosition;
        }

        void SetListPosition(const Form &listPosition)
        {
            mListPosition = listPosition;
        }

        const Maybe <Form> &GetRemoveLists() const
        {
            return mRemoveLists;
        }

        void SetRemoveLists(const Form &removeLists)
        {
            mRemoveLists = removeLists;
        }

        const Maybe <Link> &GetLists() const
        {
            return mLists;
        }

        void SetLists(const Link &lists)
        {
            mLists = lists;
        }

        const Maybe <std::vector<std::string> > &GetExposedItems() const
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
        Maybe <Form> mAddLists;
        Maybe <Form> mListPosition;
        Maybe <Form> mRemoveLists;
        Maybe <Link> mLists;
        Maybe <std::vector<std::string> > mExposedItems;
    };
}

#endif //READY4AIR_USERFAVOURITELISTS_H
