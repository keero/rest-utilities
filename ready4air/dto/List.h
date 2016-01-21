#ifndef READY4AIR_LIST_H
#define READY4AIR_LIST_H

#include "../common/Maybe.h"
#include "abstract/JsonDeserializable.h"
#include "Image.h"
#include "LanguageList.h"
#include "ListMedia.h"
#include "hypermedia/Link.h"

namespace ready4air
{
    namespace dto
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

            const Maybe<int> &GetListId() const
            {
                return mListId;
            }

            void SetListId(int listId)
            {
                mListId = listId;
            }

            const Maybe<int> &GetListType() const
            {
                return mListType;
            }

            void SetListType(int listType)
            {
                mListType = listType;
            }

            const Maybe<std::string> &GetName() const
            {
                return mName;
            }

            void SetName(const std::string &name)
            {
                mName = name;
            }

            const Maybe<bool> &IsGenre() const
            {
                return mIsGenre;
            }

            void SetIsGenre(bool isGenre)
            {
                mIsGenre = isGenre;
            }

            const Maybe<std::string> &GetDescription() const
            {
                return mDescription;
            }

            void SetDescription(const std::string &description)
            {
                mDescription = description;
            }

            const Maybe<std::vector<Image> > &GetImages() const
            {
                return mImages;
            }

            void SetImages(const std::vector<Image> &images)
            {
                mImages = images;
            }

            const Maybe<std::map<std::string, std::string> > &GetCustom() const
            {
                return mCustom;
            }

            void SetCustom(const std::map<std::string, std::string> &custom)
            {
                mCustom = custom;
            }

            const Maybe<std::vector<LanguageList> > &GetLanguageLists() const
            {
                return mLanguageLists;
            }

            void SetLanguageLists(const std::vector<LanguageList> &languageLists)
            {
                mLanguageLists = languageLists;
            }

            const Maybe<std::vector<ListMedia> > &GetListMedias() const
            {
                return mListMedias;
            }

            void SetListMedias(const std::vector<ListMedia> &listMedias)
            {
                mListMedias = listMedias;
            }

            const Maybe<Link> &GetItems() const
            {
                return mItems;
            }

            void SetItems(const Link &items)
            {
                mItems = items;
            }

            virtual bool InitFromJsonValue(const rapidjson::Value &value, ParseErrors &parseErrors)
            {
                int listId;
                int listType;
                std::string name;
                bool isGenre;
                std::string description;
                std::vector<Image> images;
                std::map<std::string, std::string> custom;
                std::vector<LanguageList> languageLists;
                std::vector<ListMedia> listMedias;
                Link items;

                if (ParseInt(value, "ListId", true, listId, parseErrors))
                    SetListId(listId);

                if (ParseInt(value, "ListType", true, listType, parseErrors))
                    SetListType(listType);

                if (ParseString(value, "Name", true, name, parseErrors))
                    SetName(name);

                if (ParseBool(value, "IsGenre", true, isGenre, parseErrors))
                    SetIsGenre(isGenre);

                if (ParseString(value, "Description", false, description, parseErrors))
                    SetDescription(description);

                if (VerifyArray(value, "Images", false, parseErrors))
                {
                    for (rapidjson::SizeType i = 0; i < value["Images"].Size(); i += 1)
                    {
                        Image image;
                        if (ParseObject(value["Images"][i], "", false, image, parseErrors))
                            images.push_back(image);
                    }
                    SetImages(images);
                }

                if (VerifyObject(value, "Custom", false, parseErrors))
                {
                    for (rapidjson::Value::ConstMemberIterator itr = value["Custom"].MemberBegin();
                         itr != value["Custom"].MemberEnd(); ++itr)
                    {
                        std::string customValue;
                        if (ParseString(itr->value, "", false, customValue, parseErrors))
                            custom[itr->name.GetString()] = customValue;
                    }
                    SetCustom(custom);
                }

                if (VerifyArray(value, "LanguageLists", false, parseErrors))
                {
                    for (rapidjson::SizeType i = 0; i < value["LanguageLists"].Size(); i += 1)
                    {
                        LanguageList languageList;
                        if (ParseObject(value["LanguageLists"][i], "", false, languageList, parseErrors))
                            languageLists.push_back(languageList);
                    }
                    SetLanguageLists(languageLists);
                }

                if (VerifyArray(value, "ListMedias", false, parseErrors))
                {
                    for (rapidjson::SizeType i = 0; i < value["ListMedias"].Size(); i += 1)
                    {
                        ListMedia listMedia;
                        if (ParseObject(value["ListMedias"][i], "", false, listMedia, parseErrors))
                            listMedias.push_back(listMedia);
                    }
                    SetListMedias(listMedias);
                }

                if (ParseObject(value, "Items", true, items, parseErrors))
                    SetItems(items);

                return !parseErrors;
            }

        private:
            Maybe<int> mListId;
            Maybe<int> mListType;
            Maybe<std::string> mName;
            Maybe<bool> mIsGenre;
            Maybe<std::string> mDescription;
            Maybe<std::vector<Image> > mImages;
            Maybe<std::map<std::string, std::string> > mCustom;
            Maybe<std::vector<LanguageList> > mLanguageLists;
            Maybe<std::vector<ListMedia> > mListMedias;
            Maybe<Link> mItems;
        };
    }
}

#endif //READY4AIR_LIST_H
