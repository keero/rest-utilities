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

        virtual bool InitFromJsonValue(const rapidjson::Value &value)
        {
            {
                // Non-mandatory property
                if (value.HasMember("Name"))
                {
                    if (!value["Name"].IsString()) return false;
                    SetName(value["Name"].GetString());
                }
            }
            {
                // Non-mandatory property
                if (value.HasMember("Link"))
                {
                    Link link;
                    if (!value["Link"].IsObject() || !link.InitFromJsonValue(value["Link"])) return false;
                    SetLink(link);
                }
            }
            {
                // Mandatory property
                if (!value.HasMember("IsMain") || !value["IsMain"].IsBool()) return false;
                SetIsMain(value["IsMain"].GetBool());
            }
            {
                // Mandatory property
                if (!value.HasMember("ListId") || !value["ListId"].IsInt()) return false;
                SetListId(value["ListId"].GetInt());
            }

            return true;
        }

    private:
        Maybe <std::string> mName;
        Maybe <Link> mLink;
        Maybe <bool> mIsMain;
        Maybe <int> mListId;
    };
}

#endif //READY4AIR_GENRE_H
