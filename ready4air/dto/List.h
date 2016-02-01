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
            List() : TAG("ready4air::dto::List")
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

            const Maybe<STRING_T> &GetName() const
            {
                return mName;
            }

            void SetName(const STRING_T &name)
            {
                mName = name;
            }

            const Maybe<BOOL_T> &IsGenre() const
            {
                return mIsGenre;
            }

            void SetIsGenre(BOOL_T isGenre)
            {
                mIsGenre = isGenre;
            }

            const Maybe<STRING_T> &GetDescription() const
            {
                return mDescription;
            }

            void SetDescription(const STRING_T &description)
            {
                mDescription = description;
            }

            const Maybe<VECTOR_T<Image> > &GetImages() const
            {
                return mImages;
            }

            void SetImages(const VECTOR_T<Image> &images)
            {
                mImages = images;
            }

            const Maybe<MAP_T<STRING_T, STRING_T> > &GetCustom() const
            {
                return mCustom;
            }

            void SetCustom(const MAP_T<STRING_T, STRING_T> &custom)
            {
                mCustom = custom;
            }

            const Maybe<VECTOR_T<LanguageList> > &GetLanguageLists() const
            {
                return mLanguageLists;
            }

            void SetLanguageLists(const VECTOR_T<LanguageList> &languageLists)
            {
                mLanguageLists = languageLists;
            }

            const Maybe<VECTOR_T<ListMedia> > &GetListMedias() const
            {
                return mListMedias;
            }

            void SetListMedias(const VECTOR_T<ListMedia> &listMedias)
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

            virtual BOOL_T InitFromJsonValue(const rapidjson::Value &value, ParseErrors &parseErrors)
            {
                INT32_T listId;
                INT32_T listType;
                STRING_T name;
                BOOL_T isGenre;
                STRING_T description;
                VECTOR_T<Image> images;
                MAP_T<STRING_T, STRING_T> custom;
                VECTOR_T<LanguageList> languageLists;
                VECTOR_T<ListMedia> listMedias;
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
                        STRING_T customValue;
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
            Maybe<STRING_T> mName;
            Maybe<BOOL_T> mIsGenre;
            Maybe<STRING_T> mDescription;
            Maybe<VECTOR_T<Image> > mImages;
            Maybe<MAP_T<STRING_T, STRING_T> > mCustom;
            Maybe<VECTOR_T<LanguageList> > mLanguageLists;
            Maybe<VECTOR_T<ListMedia> > mListMedias;
            Maybe<Link> mItems;
            STRING_T TAG;
        };
    }
}

#endif //READY4AIR_LIST_H
