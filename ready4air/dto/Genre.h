#ifndef READY4AIR_GENRE_H
#define READY4AIR_GENRE_H

#include "../maybe/Maybe.h"
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

        const Maybe <std::string> &GetName() const
        {
            return mName;
        }

        void SetName(const std::string &name)
        {
            mName = name;
        }

        const Maybe <Link> &GetLink() const
        {
            return mLink;
        }

        void SetLink(const Link &link)
        {
            mLink = link;
        }

        const Maybe <bool> &IsMain() const
        {
            return mIsMain;
        }

        void SetIsMain(bool isMain)
        {
            mIsMain = isMain;
        }

        const Maybe <int> &GetListId() const
        {
            return mListId;
        }

        void SetListId(int listId)
        {
            mListId = listId;
        }

        virtual bool InitFromJsonValue(const rapidjson::Value &value, ParseErrors &parseErrors)
        {
            std::string name;
            Link link;
            bool isMain;
            int listId;

            if (ParseString(value, "Name", false, name, parseErrors))
                SetName(name);

            if (ParseObject(value, "Link", false, link, parseErrors))
                SetLink(link);

            if (ParseBool(value, "IsMain", true, isMain, parseErrors))
                SetIsMain(isMain);

            if (ParseInt(value, "ListId", true, listId, parseErrors))
                SetListId(listId);

            return !parseErrors;
        }

    private:
        Maybe <std::string> mName;
        Maybe <Link> mLink;
        Maybe <bool> mIsMain;
        Maybe <int> mListId;
    };
}

#endif //READY4AIR_GENRE_H
