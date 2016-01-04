#ifndef READY4AIR_BUNDLE_H
#define READY4AIR_BUNDLE_H

#include "abstract/JsonDeserializable.h"
#include "Image.h"
#include "hypermedia/Link.h"
#include "WmvFile.h"
#include "SmoothManifest.h"

namespace ready4air
{
    class Bundle : public JsonDeserializable
    {

    public:
        Bundle()
        {
        }

        virtual ~Bundle()
        {
        }

        const std::string &GetId() const
        {
            return mId;
        }

        void SetId(const std::string &id)
        {
            mId = id;
        }

        const std::string &GetExternalId() const
        {
            return mExternalId;
        }

        void SetExternalId(const std::string &externalId)
        {
            mExternalId = externalId;
        }

        const std::string &GetOriginalTitle() const
        {
            return mOriginalTitle;
        }

        void SetOriginalTitle(const std::string &originalTitle)
        {
            mOriginalTitle = originalTitle;
        }

        const std::string &GetOriginalSummary() const
        {
            return mOriginalSummary;
        }

        void SetOriginalSummary(const std::string &originalSummary)
        {
            mOriginalSummary = originalSummary;
        }

        const std::string &GetLocalTitle() const
        {
            return mLocalTitle;
        }

        void SetLocalTitle(const std::string &localTitle)
        {
            mLocalTitle = localTitle;
        }

        const std::string &GetLocalSummary() const
        {
            return mLocalSummary;
        }

        void SetLocalSummary(const std::string &localSummary)
        {
            mLocalSummary = localSummary;
        }

        const std::vector<Image> &GetImages() const
        {
            return mImages;
        }

        void SetImages(const std::vector<Image> &images)
        {
            mImages = images;
        }

        const std::vector<Link> &GetMediaProductLinks() const
        {
            return mMediaProductLinks;
        }

        void SetMediaProductLinks(const std::vector<Link> &mediaProductLinks)
        {
            mMediaProductLinks = mediaProductLinks;
        }

        const std::vector<WmvFile> &GetWmvFiles() const
        {
            return mWmvFiles;
        }

        void SetWmvFiles(const std::vector<WmvFile> &wmvFiles)
        {
            mWmvFiles = wmvFiles;
        }

        const std::vector<SmoothManifest> &GetSmoothManifests() const
        {
            return mSmoothManifests;
        }

        void SetSmoothManifests(const std::vector<SmoothManifest> &smoothManifests)
        {
            mSmoothManifests = smoothManifests;
        }

        const Link &GetSelf() const
        {
            return mSelf;
        }

        void SetSelf(const Link &self)
        {
            mSelf = self;
        }

        virtual bool InitFromJsonValue(const rapidjson::Value &value)
        {
            // Mandatory property
            if (!value.HasMember("Id") || !value["Id"].IsString()) return false;
            SetId(value["Id"].GetString());

            // Mandatory property
            if (!value.HasMember("ExternalId") || !value["ExternalId"].IsString()) return false;
            SetExternalId(value["ExternalId"].GetString());

            // Non-mandatory property
            if (value.HasMember("OriginalTitle"))
            {
                if (!value["OriginalTitle"].IsString()) return false;
                SetOriginalTitle(value["OriginalTitle"].GetString());
            }

            // Non-mandatory property
            if (value.HasMember("OriginalSummary"))
            {
                if (!value["OriginalSummary"].IsString()) return false;
                SetOriginalSummary(value["OriginalSummary"].GetString());
            }

            // Non-mandatory property
            if (value.HasMember("LocalTitle"))
            {
                if (!value["LocalTitle"].IsString()) return false;
                SetLocalTitle(value["LocalTitle"].GetString());
            }

            // Non-mandatory property
            if (value.HasMember("LocalSummary"))
            {
                if (!value["LocalSummary"].IsString()) return false;
                SetLocalSummary(value["LocalSummary"].GetString());
            }

            // Non-mandatory property
            if (value.HasMember("Images"))
            {
                if (!value["Images"].IsArray()) return false;
                std::vector<Image> images;
                for (rapidjson::SizeType i = 0; i < value["Images"].Size(); i += 1)
                {
                    Image image;
                    image.InitFromJsonValue(value["Images"][i]);
                    images.push_back(image);
                }
                SetImages(images);
            }

            // Non-mandatory property
            if (value.HasMember("MediaProductLinks"))
            {
                if (!value["MediaProductLinks"].IsArray()) return false;
                std::vector<Link> mediaProductLinks;
                for (rapidjson::SizeType i = 0; i < value["MediaProductLinks"].Size(); i += 1)
                {
                    Link mediaProductLink;
                    mediaProductLink.InitFromJsonValue(value["MediaProductLinks"][i]);
                    mediaProductLinks.push_back(mediaProductLink);
                }
                SetMediaProductLinks(mediaProductLinks);
            }

            // Non-mandatory property
            if (value.HasMember("WmvFiles"))
            {
                if (!value["WmvFiles"].IsArray()) return false;
                std::vector<WmvFile> wmvFiles;
                for (rapidjson::SizeType i = 0; i < value["WmvFiles"].Size(); i += 1)
                {
                    WmvFile wmvFile;
                    wmvFile.InitFromJsonValue(value["WmvFiles"][i]);
                    wmvFiles.push_back(wmvFile);
                }
                SetWmvFiles(wmvFiles);
            }

            // Non-mandatory property
            if (value.HasMember("SmoothManifests"))
            {
                if (!value["SmoothManifests"].IsArray()) return false;
                std::vector<SmoothManifest> smoothManifests;
                for (rapidjson::SizeType i = 0; i < value["SmoothManifests"].Size(); i += 1)
                {
                    SmoothManifest smoothManifest;
                    smoothManifest.InitFromJsonValue(value["SmoothManifests"][i]);
                    smoothManifests.push_back(smoothManifest);
                }
                SetSmoothManifests(smoothManifests);
            }

            // Non-mandatory property
            if (value.HasMember("Self"))
            {
                if (!value["Self"].IsObject()) return false;
                Link self;
                self.InitFromJsonValue(value["Self"]);
                SetSelf(self);
            }

            return true;
        }

    private:
        std::string mId;
        std::string mExternalId;
        std::string mOriginalTitle;
        std::string mOriginalSummary;
        std::string mLocalTitle;
        std::string mLocalSummary;
        std::vector<Image> mImages;
        std::vector<Link> mMediaProductLinks;
        std::vector<WmvFile> mWmvFiles;
        std::vector<SmoothManifest> mSmoothManifests;
        Link mSelf;
    };
}

#endif //READY4AIR_BUNDLE_H
