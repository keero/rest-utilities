#ifndef READY4AIR_LIST_H
#define READY4AIR_LIST_H

#include "abstract/JsonDeserializable.h"
#include "Image.h"
#include "LanguageList.h"
#include "ListMedia.h"
#include "hypermedia/Link.h"

namespace ready4air
{
    class List : public JsonDeserializable
    {
    public:
        List()
        {
        }

        virtual ~List()
        {
        }

        int GetListId() const
        {
            return mListId;
        }

        void SetListId(int listId)
        {
            mListId = listId;
        }

        int GetListType() const
        {
            return mListType;
        }

        void SetListType(int listType)
        {
            mListType = listType;
        }

        const std::string &GetName() const
        {
            return mName;
        }

        void SetName(const std::string &name)
        {
            mName = name;
        }

        bool IsGenre() const
        {
            return mIsGenre;
        }

        void SetIsGenre(bool isGenre)
        {
            mIsGenre = isGenre;
        }

        const std::string &GetDescription() const
        {
            return mDescription;
        }

        void SetDescription(const std::string &description)
        {
            mDescription = description;
        }

        const std::vector<Image> &GetImages() const
        {
            return mImages;
        }

        void SetImages(const std::vector<Image> &images)
        {
            mImages = images;
        }

        const std::map<std::string, std::string> &GetCustom() const
        {
            return mCustom;
        }

        void SetCustom(const std::map<std::string, std::string> &custom)
        {
            mCustom = custom;
        }

        const std::vector<LanguageList> &GetLanguageLists() const
        {
            return mLanguageLists;
        }

        void SetLanguageLists(const std::vector<LanguageList> &languageLists)
        {
            mLanguageLists = languageLists;
        }

        const std::vector<ListMedia> &GetListMedias() const
        {
            return mListMedias;
        }

        void SetListMedias(const std::vector<ListMedia> &listMedias)
        {
            mListMedias = listMedias;
        }

        const Link &GetItems() const
        {
            return mItems;
        }

        void SetItems(const Link &items)
        {
            mItems = items;
        }

        virtual bool InitFromJsonValue(const rapidjson::Value &value)
        {
            {
                // Mandatory property
                if (!value.HasMember("ListId") || !value["ListId"].IsInt()) return false;
                SetListId(value["ListId"].GetInt());
            }
            {
                // Mandatory property
                if (!value.HasMember("ListType") || !value["ListType"].IsInt()) return false;
                SetListType(value["ListType"].GetInt());
            }
            {
                // Mandatory property
                if (!value.HasMember("Name") || !value["Name"].IsString()) return false;
                SetName(value["Name"].GetString());
            }
            {
                // Mandatory property
                if (!value.HasMember("IsGenre") || !value["IsGenre"].IsBool()) return false;
                SetIsGenre(value["IsGenre"].GetBool());
            }
            {
                // Non-mandatory property
                if (value.HasMember("Description"))
                {
                    if (!value["Description"].IsString()) return false;
                    SetDescription(value["Description"].GetString());
                }
            }
            {
                // Non-mandatory property
                if (value.HasMember("Images"))
                {
                    if (!value["Images"].IsArray()) return false;
                    std::vector<Image> images;
                    for (rapidjson::SizeType i = 0; i < value["Images"].Size(); i += 1)
                    {
                        Image image;
                        if (!value["Images"][i].IsObject() || !image.InitFromJsonValue(value["Images"][i])) return false;
                        images.push_back(image);
                    }
                    SetImages(images);
                }
            }
            {
                // Non-mandatory property
                if (value.HasMember("Custom"))
                {
                    if (!value["Custom"].IsObject()) return false;
                    std::map<std::string, std::string> custom;
                    for (rapidjson::Value::ConstMemberIterator itr = value.MemberBegin(); itr != value.MemberEnd(); ++itr)
                    {
                        if (itr->value.GetType() != rapidjson::kStringType) return false;
                        custom[itr->name.GetString()] = itr->value.GetString();
                    }
                    SetCustom(custom);
                }
            }
            {
                // Non-mandatory property
                if (value.HasMember("LanguageLists"))
                {
                    if (!value["LanguageLists"].IsArray()) return false;
                    std::vector<LanguageList> languageLists;
                    for (rapidjson::SizeType i = 0; i < value["LanguageLists"].Size(); i += 1)
                    {
                        LanguageList languageList;
                        if (!value["LanguageLists"][i].IsObject() || !languageList.InitFromJsonValue(value["LanguageLists"][i])) return false;
                        languageLists.push_back(languageList);
                    }
                    SetLanguageLists(languageLists);
                }
            }
            {
                // Non-mandatory property
                if (value.HasMember("ListMedias"))
                {
                    if (!value["ListMedias"].IsArray()) return false;
                    std::vector<ListMedia> listMedias;
                    for (rapidjson::SizeType i = 0; i < value["ListMedias"].Size(); i += 1)
                    {
                        ListMedia listMedia;
                        if (!value["ListMedias"][i].IsObject() || !listMedia.InitFromJsonValue(value["ListMedias"][i])) return false;
                        listMedias.push_back(listMedia);
                    }
                    SetListMedias(listMedias);
                }
            }
            {
                // Mandatory property
                Link items;
                if (!value.HasMember("Items") || !value["Items"].IsObject() || !items.InitFromJsonValue(value["Items"])) return false;
                SetItems(items);
            }

            return true;
        }

    private:
        int mListId;
        int mListType;
        std::string mName;
        bool mIsGenre;
        std::string mDescription;
        std::vector<Image> mImages;
        std::map<std::string, std::string> mCustom;
        std::vector<LanguageList> mLanguageLists;
        std::vector<ListMedia> mListMedias;
        Link mItems;
    };
}

#endif //READY4AIR_LIST_H
