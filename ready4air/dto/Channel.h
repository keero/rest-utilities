#ifndef READY4AIR_CHANNEL_H
#define READY4AIR_CHANNEL_H

#include "../maybe/Maybe.h"
#include "abstract/JsonDeserializable.h"
#include "Image.h"
#include "EpgInfo.h"
#include "hypermedia/Link.h"

namespace ready4air
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

        const Maybe <std::string> &GetId() const
        {
            return mId;
        }

        void SetId(const std::string &id)
        {
            mId = id;
        }

        const Maybe <std::string> &GetOriginalTitle() const
        {
            return mOriginalTitle;
        }

        void SetOriginalTitle(const std::string &originalTitle)
        {
            mOriginalTitle = originalTitle;
        }

        const Maybe <std::string> &GetDescription() const
        {
            return mDescription;
        }

        void SetDescription(const std::string &description)
        {
            mDescription = description;
        }

        const Maybe <std::string> &GetLocalTitle() const
        {
            return mLocalTitle;
        }

        void SetLocalTitle(const std::string &localTitle)
        {
            mLocalTitle = localTitle;
        }

        const Maybe <std::string> &GetShortTitle() const
        {
            return mShortTitle;
        }

        void SetShortTitle(const std::string &shortTitle)
        {
            mShortTitle = shortTitle;
        }

        const Maybe <std::string> &GetLongSummary() const
        {
            return mLongSummary;
        }

        void SetLongSummary(const std::string &longSummary)
        {
            mLongSummary = longSummary;
        }

        const Maybe <std::string> &GetShortSummary() const
        {
            return mShortSummary;
        }

        void SetShortSummary(const std::string &shortSummary)
        {
            mShortSummary = shortSummary;
        }

        const Maybe <std::string> &GetSortTitle() const
        {
            return mSortTitle;
        }

        void SetSortTitle(const std::string &sortTitle)
        {
            mSortTitle = sortTitle;
        }

        const Maybe <std::vector<Image> > &GetImages() const
        {
            return mImages;
        }

        void SetImages(const std::vector<Image> &images)
        {
            mImages = images;
        }

        const Maybe <EpgInfo> &GetEpgInfo() const
        {
            return mEpgInfo;
        }

        void SetEpgInfo(const EpgInfo &epgInfo)
        {
            mEpgInfo = epgInfo;
        }

        const Maybe <Link> &GetSelf() const
        {
            return mSelf;
        }

        void SetSelf(const Link &self)
        {
            mSelf = self;
        }

        virtual bool InitFromJsonValue(const rapidjson::Value &value)
        {
            {
                // Mandatory property
                if (!value.HasMember("Id") || !value["Id"].IsString()) return false;
                SetId(value["Id"].GetString());
            }
            {
                // Non-mandatory property
                if (value.HasMember("OriginalTitle"))
                {
                    if (!value["OriginalTitle"].IsString()) return false;
                    SetOriginalTitle(value["OriginalTitle"].GetString());
                }
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
                if (value.HasMember("LocalTitle"))
                {
                    if (!value["LocalTitle"].IsString()) return false;
                    SetLocalTitle(value["LocalTitle"].GetString());
                }
            }
            {
                // Non-mandatory property
                if (value.HasMember("ShortTitle"))
                {
                    if (!value["ShortTitle"].IsString()) return false;
                    SetShortTitle(value["ShortTitle"].GetString());
                }
            }
            {
                // Non-mandatory property
                if (value.HasMember("LongSummary"))
                {
                    if (!value["LongSummary"].IsString()) return false;
                    SetLongSummary(value["LongSummary"].GetString());
                }
            }
            {
                // Non-mandatory property
                if (value.HasMember("ShortSummary"))
                {
                    if (!value["ShortSummary"].IsString()) return false;
                    SetShortSummary(value["ShortSummary"].GetString());
                }
            }
            {
                // Non-mandatory property
                if (value.HasMember("SortTitle"))
                {
                    if (!value["SortTitle"].IsString()) return false;
                    SetSortTitle(value["SortTitle"].GetString());
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
                // Mandatory property
                EpgInfo epgInfo;
                if (!value.HasMember("EpgInfo") || !value["EpgInfo"].IsObject() || !epgInfo.InitFromJsonValue(value["EpgInfo"])) return false;
                SetEpgInfo(epgInfo);
            }
            {
                // Non-mandatory property
                if (value.HasMember("Self"))
                {
                    Link self;
                    if (!value["Self"].IsObject() || !self.InitFromJsonValue(value["Self"])) return false;
                    SetSelf(self);
                }
            }

            return true;
        }

    private:
        Maybe <std::string> mId;
        Maybe <std::string> mOriginalTitle;
        Maybe <std::string> mDescription;
        Maybe <std::string> mLocalTitle;
        Maybe <std::string> mShortTitle;
        Maybe <std::string> mLongSummary;
        Maybe <std::string> mShortSummary;
        Maybe <std::string> mSortTitle;
        Maybe <std::vector<Image> > mImages;
        Maybe <EpgInfo> mEpgInfo;
        Maybe <Link> mSelf;
    };
}

#endif //READY4AIR_CHANNEL_H
