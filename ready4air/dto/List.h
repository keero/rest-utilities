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
            return false;
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
