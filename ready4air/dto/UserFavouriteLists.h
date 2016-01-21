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

            virtual bool InitFromJsonValue(const rapidjson::Value &value, ParseErrors &parseErrors)
            {
                Form addLists;
                Form listPosition;
                Form removeLists;
                Link lists;
                std::vector<std::string> exposedItems;

                if (ParseObject(value, "AddLists", true, addLists, parseErrors))
                    SetAddLists(addLists);

                if (ParseObject(value, "ListPosition", true, listPosition, parseErrors))
                    SetListPosition(listPosition);

                if (ParseObject(value, "RemoveLists", true, removeLists, parseErrors))
                    SetRemoveLists(removeLists);

                if (ParseObject(value, "Lists", false, lists, parseErrors))
                    SetLists(lists);

                if (VerifyArray(value, "ExposedItems", false, parseErrors))
                {
                    for (rapidjson::SizeType i = 0; i < value["ExposedItems"].Size(); i += 1)
                    {
                        std::string exposedItem;
                        if (ParseString(value["ExposedItems"][i], "", false, exposedItem, parseErrors))
                            exposedItems.push_back(exposedItem);
                    }
                    SetExposedItems(exposedItems);
                }

                return !parseErrors;
            }

        private:
            Maybe <Form> mAddLists;
            Maybe <Form> mListPosition;
            Maybe <Form> mRemoveLists;
            Maybe <Link> mLists;
            Maybe <std::vector<std::string> > mExposedItems;
        };
    }
}

#endif //READY4AIR_USERFAVOURITELISTS_H
