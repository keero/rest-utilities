#ifndef READY4AIR_GENRE_H
#define READY4AIR_GENRE_H

#include "../common/Maybe.h"
#include "abstract/JsonDeserializable.h"
#include "hypermedia/Link.h"

namespace ready4air
{
    namespace dto
    {
        class Genre : public JsonDeserializable
        {
        public:
            Genre() : TAG("ready4air::dto::Genre")
            {
            }

            virtual ~Genre()
            {
            }

            const Maybe <STRING_T> &GetName() const
            {
                return mName;
            }

            void SetName(const STRING_T &name)
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

            const Maybe<BOOL_T> &IsMain() const
            {
                return mIsMain;
            }

            void SetIsMain(BOOL_T isMain)
            {
                mIsMain = isMain;
            }

            const Maybe<int> &GetListId() const
            {
                return mListId;
            }

            void SetListId(int listId)
            {
                mListId = listId;
            }

            virtual BOOL_T InitFromJsonValue(const rapidjson::Value &value, ParseErrors &parseErrors)
            {
                STRING_T name;
                Link link;
                BOOL_T isMain;
                INT32_T listId;

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
            Maybe <STRING_T> mName;
            Maybe <Link> mLink;
            Maybe<BOOL_T> mIsMain;
            Maybe<int> mListId;
            STRING_T TAG;
        };
    }
}

#endif //READY4AIR_GENRE_H
