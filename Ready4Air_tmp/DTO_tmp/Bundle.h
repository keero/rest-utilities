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
            return JsonDeserializable::InitFromJsonValue(value);
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
