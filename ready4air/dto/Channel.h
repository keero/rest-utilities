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
            Channel()
            {
            }

            virtual ~Channel()
            {
            }

            const Maybe<std::string> &GetId() const
            {
                return mId;
            }

            void SetId(const std::string &id)
            {
                mId = id;
            }

            const Maybe<std::string> &GetOriginalTitle() const
            {
                return mOriginalTitle;
            }

            void SetOriginalTitle(const std::string &originalTitle)
            {
                mOriginalTitle = originalTitle;
            }

            const Maybe<std::string> &GetDescription() const
            {
                return mDescription;
            }

            void SetDescription(const std::string &description)
            {
                mDescription = description;
            }

            const Maybe<std::string> &GetLocalTitle() const
            {
                return mLocalTitle;
            }

            void SetLocalTitle(const std::string &localTitle)
            {
                mLocalTitle = localTitle;
            }

            const Maybe<std::string> &GetShortTitle() const
            {
                return mShortTitle;
            }

            void SetShortTitle(const std::string &shortTitle)
            {
                mShortTitle = shortTitle;
            }

            const Maybe<std::string> &GetLongSummary() const
            {
                return mLongSummary;
            }

            void SetLongSummary(const std::string &longSummary)
            {
                mLongSummary = longSummary;
            }

            const Maybe<std::string> &GetShortSummary() const
            {
                return mShortSummary;
            }

            void SetShortSummary(const std::string &shortSummary)
            {
                mShortSummary = shortSummary;
            }

            const Maybe<std::string> &GetSortTitle() const
            {
                return mSortTitle;
            }

            void SetSortTitle(const std::string &sortTitle)
            {
                mSortTitle = sortTitle;
            }

            const Maybe<std::vector<Image> > &GetImages() const
            {
                return mImages;
            }

            void SetImages(const std::vector<Image> &images)
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

            virtual bool InitFromJsonValue(const rapidjson::Value &value, ParseErrors &parseErrors)
            {
                std::string id;
                std::string originalTitle;
                std::string description;
                std::string localTitle;
                std::string shortTitle;
                std::string longSummary;
                std::string shortSummary;
                std::string sortTitle;
                std::vector<Image> images;
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
            Maybe<std::string> mId;
            Maybe<std::string> mOriginalTitle;
            Maybe<std::string> mDescription;
            Maybe<std::string> mLocalTitle;
            Maybe<std::string> mShortTitle;
            Maybe<std::string> mLongSummary;
            Maybe<std::string> mShortSummary;
            Maybe<std::string> mSortTitle;
            Maybe<std::vector<Image> > mImages;
            Maybe<EpgInfo> mEpgInfo;
            Maybe<Link> mSelf;
        };
    }
}

#endif //READY4AIR_CHANNEL_H
