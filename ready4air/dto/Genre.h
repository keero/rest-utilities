#ifndef READY4AIR_GENRE_H
#define READY4AIR_GENRE_H

#include "abstract/JsonDeserializable.h"
#include "hypermedia/Link.h"

namespace ready4air
{
    class Genre : public JsonDeserializable
    {
    public:
        Genre()
        {
        }

        virtual ~Genre()
        {
        }

        const std::string &GetName() const
        {
            return mName;
        }

        void SetName(const std::string &name)
        {
            mName = name;
        }

        const Link &GetLink() const
        {
            return mLink;
        }

        void SetLink(const Link &link)
        {
            mLink = link;
        }

        bool IsMain() const
        {
            return mIsMain;
        }

        void SetIsMain(bool isMain)
        {
            mIsMain = isMain;
        }

        int GetListId() const
        {
            return mListId;
        }

        void SetListId(int listId)
        {
            mListId = listId;
        }

    private:
        std::string mName;
        Link mLink;
        bool mIsMain;
        int mListId;
    };
}

#endif //READY4AIR_GENRE_H
