#ifndef READY4AIR_BUNDLE_H
#define READY4AIR_BUNDLE_H

#include "../maybe/Maybe.h"
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

        Maybe<std::string> GetId() const
        {
            return mId;
        }

        void SetId(const std::string &id)
        {
            mId = id;
        }

        const Maybe<std::string> &GetExternalId() const
        {
            return mExternalId;
        }

        void SetExternalId(const std::string &externalId)
        {
            mExternalId = externalId;
        }

        const Maybe<std::string> &GetOriginalTitle() const
        {
            return mOriginalTitle;
        }

        void SetOriginalTitle(const std::string &originalTitle)
        {
            mOriginalTitle = originalTitle;
        }

        const Maybe<std::string> &GetOriginalSummary() const
        {
            return mOriginalSummary;
        }

        void SetOriginalSummary(const std::string &originalSummary)
        {
            mOriginalSummary = originalSummary;
        }

        const Maybe<std::string> &GetLocalTitle() const
        {
            return mLocalTitle;
        }

        void SetLocalTitle(const std::string &localTitle)
        {
            mLocalTitle = localTitle;
        }

        const Maybe<std::string> &GetLocalSummary() const
        {
            return mLocalSummary;
        }

        void SetLocalSummary(const std::string &localSummary)
        {
            mLocalSummary = localSummary;
        }

        const Maybe<std::vector<Image> > &GetImages() const
        {
            return mImages;
        }

        void SetImages(const std::vector<Image> &images)
        {
            mImages = images;
        }

        const Maybe<std::vector<Link> > &GetMediaProductLinks() const
        {
            return mMediaProductLinks;
        }

        void SetMediaProductLinks(const std::vector<Link> &mediaProductLinks)
        {
            mMediaProductLinks = mediaProductLinks;
        }

        const Maybe<std::vector<WmvFile> > &GetWmvFiles() const
        {
            return mWmvFiles;
        }

        void SetWmvFiles(const std::vector<WmvFile> &wmvFiles)
        {
            mWmvFiles = wmvFiles;
        }

        const Maybe<std::vector<SmoothManifest> > &GetSmoothManifests() const
        {
            return mSmoothManifests;
        }

        void SetSmoothManifests(const std::vector<SmoothManifest> &smoothManifests)
        {
            mSmoothManifests = smoothManifests;
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
            std::string externalId;
            std::string originalTitle;
            std::string originalSummary;
            std::string localTitle;
            std::string localSummary;
            std::vector<Image> images;
            std::vector<Link> mediaProductLinks;
            std::vector<WmvFile> wmvFiles;
            std::vector<SmoothManifest> smoothManifests;
            Link self;

            if (ParseString(value, "Id", true, id, parseErrors))
                SetId(id);

            if (ParseString(value, "ExternalId", true, externalId, parseErrors))
                SetExternalId(externalId);

            if (ParseString(value, "OriginalTitle", false, originalTitle, parseErrors))
                SetOriginalTitle(originalTitle);

            if (ParseString(value, "OriginalSummary", false, originalSummary, parseErrors))
                SetOriginalSummary(originalSummary);

            if (ParseString(value, "LocalTitle", false, localTitle, parseErrors))
                SetLocalTitle(localTitle);

            if (ParseString(value, "LocalSummary", false, localSummary, parseErrors))
                SetLocalSummary(localSummary);

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

            if (VerifyArray(value, "MediaProductLinks", false, parseErrors))
            {
                for (rapidjson::SizeType i = 0; i < value["MediaProductLinks"].Size(); i += 1)
                {
                    Link mediaProductLink;
                    if (ParseObject(value["MediaProductLinks"][i], "", false, mediaProductLink, parseErrors))
                        mediaProductLinks.push_back(mediaProductLink);
                }
                SetMediaProductLinks(mediaProductLinks);
            }

            if (VerifyArray(value, "WmvFiles", false, parseErrors))
            {
                for (rapidjson::SizeType i = 0; i < value["WmvFiles"].Size(); i += 1)
                {
                    WmvFile wmvFile;
                    if (ParseObject(value["WmvFiles"][i], "", false, wmvFile, parseErrors))
                        wmvFiles.push_back(wmvFile);
                }
                SetWmvFiles(wmvFiles);
            }

            if (VerifyArray(value, "SmoothManifests", false, parseErrors))
            {
                for (rapidjson::SizeType i = 0; i < value["SmoothManifests"].Size(); i += 1)
                {
                    SmoothManifest smoothManifest;
                    if (ParseObject(value["SmoothManifests"][i], "", false, smoothManifest, parseErrors))
                        smoothManifests.push_back(smoothManifest);
                }
                SetSmoothManifests(smoothManifests);
            }

            if (ParseObject(value, "Self", false, self, parseErrors))
                SetSelf(self);

            return !parseErrors;
        }


    private:
        Maybe <std::string> mId;
        Maybe <std::string> mExternalId;
        Maybe <std::string> mOriginalTitle;
        Maybe <std::string> mOriginalSummary;
        Maybe <std::string> mLocalTitle;
        Maybe <std::string> mLocalSummary;
        Maybe <std::vector<Image> > mImages;
        Maybe <std::vector<Link> > mMediaProductLinks;
        Maybe <std::vector<WmvFile> > mWmvFiles;
        Maybe <std::vector<SmoothManifest> > mSmoothManifests;
        Maybe <Link> mSelf;
    };
}

#endif //READY4AIR_BUNDLE_H
