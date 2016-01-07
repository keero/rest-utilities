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

        virtual bool InitFromJsonValue(const rapidjson::Value &value)
        {
            {
                // Mandatory property
                if (!value.HasMember("Id") || !value["Id"].IsString()) return false;
                SetId(value["Id"].GetString());
            }
            {
                // Mandatory property
                if (!value.HasMember("ExternalId") || !value["ExternalId"].IsString()) return false;
                SetExternalId(value["ExternalId"].GetString());
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
                if (value.HasMember("OriginalSummary"))
                {
                    if (!value["OriginalSummary"].IsString()) return false;
                    SetOriginalSummary(value["OriginalSummary"].GetString());
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
                if (value.HasMember("LocalSummary"))
                {
                    if (!value["LocalSummary"].IsString()) return false;
                    SetLocalSummary(value["LocalSummary"].GetString());
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
                        if (!value["Images"][i].IsObject() || !image.InitFromJsonValue(value["Images"][i]))
                            return false;
                        images.push_back(image);
                    }
                    SetImages(images);
                }
            }
            {
                // Non-mandatory property
                if (value.HasMember("MediaProductLinks"))
                {
                    if (!value["MediaProductLinks"].IsArray()) return false;
                    std::vector<Link> mediaProductLinks;
                    for (rapidjson::SizeType i = 0; i < value["MediaProductLinks"].Size(); i += 1)
                    {
                        Link mediaProductLink;
                        if (!value["MediaProductLinks"][i].IsObject() ||
                            !mediaProductLink.InitFromJsonValue(value["MediaProductLinks"][i]))
                            return false;
                        mediaProductLinks.push_back(mediaProductLink);
                    }
                    SetMediaProductLinks(mediaProductLinks);
                }
            }
            {
                // Non-mandatory property
                if (value.HasMember("WmvFiles"))
                {
                    if (!value["WmvFiles"].IsArray()) return false;
                    std::vector<WmvFile> wmvFiles;
                    for (rapidjson::SizeType i = 0; i < value["WmvFiles"].Size(); i += 1)
                    {
                        WmvFile wmvFile;
                        if (!value["WmvFiles"][i].IsObject() || !wmvFile.InitFromJsonValue(value["WmvFiles"][i]))
                            return false;
                        wmvFiles.push_back(wmvFile);
                    }
                    SetWmvFiles(wmvFiles);
                }
            }
            {
                // Non-mandatory property
                if (value.HasMember("SmoothManifests"))
                {
                    if (!value["SmoothManifests"].IsArray()) return false;
                    std::vector<SmoothManifest> smoothManifests;
                    for (rapidjson::SizeType i = 0; i < value["SmoothManifests"].Size(); i += 1)
                    {
                        SmoothManifest smoothManifest;
                        if (!value["SmoothManifests"][i].IsObject() ||
                            !smoothManifest.InitFromJsonValue(value["SmoothManifests"][i]))
                            return false;
                        smoothManifests.push_back(smoothManifest);
                    }
                    SetSmoothManifests(smoothManifests);
                }
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
