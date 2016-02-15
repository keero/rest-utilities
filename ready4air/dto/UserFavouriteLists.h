#ifndef READY4AIR_USERFAVOURITELISTS_H
#define READY4AIR_USERFAVOURITELISTS_H

#include "../common/Maybe.h"
#include "abstract/JsonDeserializable.h"
#include "hypermedia/Form.h"
#include "hypermedia/Link.h"

namespace ready4air
{
    namespace dto
    {
        class UserFavouriteLists : public JsonDeserializable
        {
        public:
            UserFavouriteLists() : TAG("ready4air::dto::UserFavouriteLists")
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

            const Maybe <VECTOR_T<STRING_T>> &GetExposedItems() const
            {
                return mExposedItems;
            }

            void SetExposedItems(const VECTOR_T<STRING_T> &exposedItems)
            {
                mExposedItems = exposedItems;
            }

            virtual BOOL_T InitFromJsonValue(const rapidjson::Value &value, ParseErrors &parseErrors,
                                             VECTOR_T<STRING_T> &context)
            {
                Form addLists;
                Form listPosition;
                Form removeLists;
                Link lists;
                VECTOR_T<STRING_T> exposedItems;

                context.push_back(TAG);

                if (ParseObject(value, "AddLists", true, addLists, parseErrors, context))
                    SetAddLists(addLists);

                if (ParseObject(value, "ListPosition", true, listPosition, parseErrors, context))
                    SetListPosition(listPosition);

                if (ParseObject(value, "RemoveLists", true, removeLists, parseErrors, context))
                    SetRemoveLists(removeLists);

                if (ParseObject(value, "Lists", false, lists, parseErrors, context))
                    SetLists(lists);

                if (VerifyArray(value, "ExposedItems", false, parseErrors, context))
                {
                    for (rapidjson::SizeType i = 0; i < value["ExposedItems"].Size(); i += 1)
                    {
                        STRING_T exposedItem;
                        if (ParseString(value["ExposedItems"][i], "", false, exposedItem, parseErrors, context))
                            exposedItems.push_back(exposedItem);
                    }
                    SetExposedItems(exposedItems);
                }

                context.pop_back();
                return !parseErrors;
            }

        private:
            Maybe <Form> mAddLists;
            Maybe <Form> mListPosition;
            Maybe <Form> mRemoveLists;
            Maybe <Link> mLists;
            Maybe <VECTOR_T<STRING_T>> mExposedItems;
            STRING_T TAG;
        };
    }
}

#endif //READY4AIR_USERFAVOURITELISTS_H
