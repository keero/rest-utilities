#ifndef READY4AIR_GENERICPAGE_H
#define READY4AIR_GENERICPAGE_H

#include <exception>
#include "../common/Maybe.h"
#include "abstract/JsonDeserializable.h"
#include "hypermedia/Link.h"

namespace ready4air
{
    namespace dto
    {
        template<class T>
        class GenericPage : public JsonDeserializable
        {
        private:
            class BadType : public std::exception
            {
                virtual const char *what() const throw()
                {
                    return "Template class T must inherit ready4air::JsonDeserializable";
                }
            } mBadType;

        public:
            GenericPage()
            {
                if (!std::is_base_of<IJsonDeserializable, T>::value) throw mBadType;
            }

            virtual ~GenericPage()
            {
            }

            const Maybe <Link> &GetPrev() const
            {
                return mPrev;
            }

            void SetPrev(const Link &prev)
            {
                mPrev = prev;
            }

            const Maybe <Link> &GetNext() const
            {
                return mNext;
            }

            void SetNext(const Link &next)
            {
                mNext = next;
            }

            const Maybe <std::vector<T> > &GetItems() const
            {
                return mItems;
            }

            void SetItems(const std::vector<T> &items)
            {
                mItems = items;
            }

            virtual bool InitFromJsonValue(const rapidjson::Value &value, ParseErrors &parseErrors)
            {
                Link prev;
                Link next;
                std::vector<T> items;

                if (ParseObject(value, "Prev", false, prev, parseErrors))
                    SetPrev(prev);

                if (ParseObject(value, "Next", false, next, parseErrors))
                    SetNext(next);

                if (VerifyArray(value, "Items", true, parseErrors))
                {
                    for (rapidjson::SizeType i = 0; i < value["Items"].Size(); i += 1)
                    {
                        T item;
                        IJsonDeserializable *abstractItem = &item;
                        if (abstractItem->InitFromJsonValue(value["Items"][i], parseErrors))
//                        if (ParseObject(value["Items"][i], "", false, item, parseErrors))
                            items.push_back(item);
                    }
                    SetItems(items);
                }

                return !parseErrors;
            }

        private:
            Maybe <Link> mPrev;
            Maybe <Link> mNext;
            Maybe <std::vector<T> > mItems;
        };
    }
}

#endif //READY4AIR_GENERICPAGE_H
