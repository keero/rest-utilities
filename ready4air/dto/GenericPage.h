#ifndef READY4AIR_GENERICPAGE_H
#define READY4AIR_GENERICPAGE_H

#include <exception>
#include "../maybe/Maybe.h"
#include "abstract/JsonDeserializable.h"
#include "hypermedia/Link.h"

namespace ready4air
{
    template<class T>
    class GenericPage : public JsonDeserializable
    {
    private:
        class BadType : public std::exception
        {
            virtual const char* what() const throw()
            {
                return "Template class T must inherit ready4air::JsonDeserializable";
            }
        } mBadType;

    public:
        GenericPage()
        {
            if (!std::is_base_of<JsonDeserializable, T>::value) throw mBadType;
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

        virtual bool InitFromJsonValue(const rapidjson::Value &value)
        {
            {
                // Non-mandatory property
                if (value.HasMember("Prev"))
                {
                    Link prev;
                    if (!value["Prev"].IsObject() || !prev.InitFromJsonValue(value["Prev"])) return false;
                    SetPrev(prev);
                }
            }
            {
                // Non-mandatory property
                if (value.HasMember("Next"))
                {
                    Link next;
                    if (!value["Next"].IsObject() || !next.InitFromJsonValue(value["Next"])) return false;
                    SetNext(next);
                }
            }
            {
                // Mandatory property
                if (!value.HasMember("Items") || !value["Items"].IsArray()) return false;
                std::vector<T> items;
                for (rapidjson::SizeType i = 0; i < value["Items"].Size(); i += 1)
                {
                    T item;
                    if (!value["Items"][i].IsObject() || !item.InitFromJsonValue(value["Items"][i])) return false;
                    items.push_back(item);
                }
                SetItems(items);
            }

            return true;
        }

    private:
        Maybe <Link> mPrev;
        Maybe <Link> mNext;
        Maybe <std::vector<T> > mItems;
    };
}

#endif //READY4AIR_GENERICPAGE_H
