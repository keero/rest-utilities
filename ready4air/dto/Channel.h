#ifndef READY4AIR_CHANNEL_H
#define READY4AIR_CHANNEL_H

#include "../common/Maybe.h"
#include "abstract/JsonDeserializable.h"
#include "Image.h"
#include "EpgInfo.h"
#include "hypermedia/Link.h"

namespace ready4air
{
    namespace dto
    {
        class Channel : public JsonDeserializable
        {
        public:
            Channel() : TAG("ready4air::dto::Channel")
            {
            }

            virtual ~Channel()
            {
            }

            const Maybe<STRING_T> &GetId() const
            {
                return mId;
            }

            void SetId(const STRING_T &id)
            {
                mId = id;
            }

            const Maybe<STRING_T> &GetOriginalTitle() const
            {
                return mOriginalTitle;
            }

            void SetOriginalTitle(const STRING_T &originalTitle)
            {
                mOriginalTitle = originalTitle;
            }

            const Maybe<STRING_T> &GetDescription() const
            {
                return mDescription;
            }

            void SetDescription(const STRING_T &description)
            {
                mDescription = description;
            }

            const Maybe<STRING_T> &GetLocalTitle() const
            {
                return mLocalTitle;
            }

            void SetLocalTitle(const STRING_T &localTitle)
            {
                mLocalTitle = localTitle;
            }

            const Maybe<STRING_T> &GetShortTitle() const
            {
                return mShortTitle;
            }

            void SetShortTitle(const STRING_T &shortTitle)
            {
                mShortTitle = shortTitle;
            }

            const Maybe<STRING_T> &GetLongSummary() const
            {
                return mLongSummary;
            }

            void SetLongSummary(const STRING_T &longSummary)
            {
                mLongSummary = longSummary;
            }

            const Maybe<STRING_T> &GetShortSummary() const
            {
                return mShortSummary;
            }

            void SetShortSummary(const STRING_T &shortSummary)
            {
                mShortSummary = shortSummary;
            }

            const Maybe<STRING_T> &GetSortTitle() const
            {
                return mSortTitle;
            }

            void SetSortTitle(const STRING_T &sortTitle)
            {
                mSortTitle = sortTitle;
            }

            const Maybe<VECTOR_T<Image> > &GetImages() const
            {
                return mImages;
            }

            void SetImages(const VECTOR_T<Image> &images)
            {
                mImages = images;
            }

            const Maybe<EpgInfo> &GetEpgInfo() const
            {
                return mEpgInfo;
            }

            void SetEpgInfo(const EpgInfo &epgInfo)
            {
                mEpgInfo = epgInfo;
            }

            const Maybe<Link> &GetSelf() const
            {
                return mSelf;
            }

            void SetSelf(const Link &self)
            {
                mSelf = self;
            }

            virtual BOOL_T InitFromJsonValue(const rapidjson::Value &value, ParseErrors &parseErrors)
            {
                STRING_T id;
                STRING_T originalTitle;
                STRING_T description;
                STRING_T localTitle;
                STRING_T shortTitle;
                STRING_T longSummary;
                STRING_T shortSummary;
                STRING_T sortTitle;
                VECTOR_T<Image> images;
                EpgInfo epgInfo;
                Link self;

                if (ParseString(value, "Id", true, id, parseErrors))
                    SetId(id);

                if (ParseString(value, "OriginalTitle", false, originalTitle, parseErrors))
                    SetOriginalTitle(originalTitle);

                if (ParseString(value, "Description", false, description, parseErrors))
                    SetDescription(description);

                if (ParseString(value, "LocalTitle", false, localTitle, parseErrors))
                    SetLocalTitle(localTitle);

                if (ParseString(value, "ShortTitle", false, shortTitle, parseErrors))
                    SetShortTitle(shortTitle);

                if (ParseString(value, "LongSummary", false, longSummary, parseErrors))
                    SetLongSummary(longSummary);

                if (ParseString(value, "ShortSummary", false, shortSummary, parseErrors))
                    SetShortSummary(shortSummary);

                if (ParseString(value, "SortTitle", false, sortTitle, parseErrors))
                    SetSortTitle(sortTitle);

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

                if (ParseObject(value, "EpgInfo", true, epgInfo, parseErrors))
                    SetEpgInfo(epgInfo);

                if (ParseObject(value, "Self", false, self, parseErrors))
                    SetSelf(self);

                return !parseErrors;
            }

        private:
            Maybe<STRING_T> mId;
            Maybe<STRING_T> mOriginalTitle;
            Maybe<STRING_T> mDescription;
            Maybe<STRING_T> mLocalTitle;
            Maybe<STRING_T> mShortTitle;
            Maybe<STRING_T> mLongSummary;
            Maybe<STRING_T> mShortSummary;
            Maybe<STRING_T> mSortTitle;
            Maybe<VECTOR_T<Image> > mImages;
            Maybe<EpgInfo> mEpgInfo;
            Maybe<Link> mSelf;
            const STRING_T TAG;
        };
    }
}

#endif //READY4AIR_CHANNEL_H
