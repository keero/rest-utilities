#ifndef READY4AIR_GENERICPAGE_H
#define READY4AIR_GENERICPAGE_H

#include "abstract/JsonDeserializable.h"
#include "hypermedia/Link.h"

namespace ready4air
{
    template<class T>
    class GenericPage : public JsonDeserializable
    {
    public:
        GenericPage()
        {
        }

        virtual ~GenericPage()
        {
        }

        const Link &GetPrev() const
        {
            return mPrev;
        }

        void SetPrev(const Link &prev)
        {
            mPrev = prev;
        }

        const Link &GetNext() const
        {
            return mNext;
        }

        void SetNext(const Link &next)
        {
            mNext = next;
        }

        const std::vector<T> &GetItems() const
        {
            return mItems;
        }

        void SetItems(const std::vector<T> &items)
        {
            mItems = items;
        }

    private:
        Link mPrev;
        Link mNext;
        std::vector<T> mItems;
    };
}

#endif //READY4AIR_GENERICPAGE_H
