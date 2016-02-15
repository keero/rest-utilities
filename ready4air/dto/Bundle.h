#ifndef READY4AIR_BUNDLE_H
#define READY4AIR_BUNDLE_H

#include "../common/Maybe.h"
#include "abstract/JsonDeserializable.h"
#include "Image.h"
#include "hypermedia/Link.h"
#include "WmvFile.h"
#include "SmoothManifest.h"

namespace ready4air
{
    namespace dto
    {
        class Bundle : public JsonDeserializable
        {

        public:
            Bundle() : TAG("ready4air::dto::Bundle")
            {
            }

            virtual ~Bundle()
            {
            }

            Maybe <STRING_T> GetId() const
            {
                return mId;
            }

            void SetId(const STRING_T &id)
            {
                mId = id;
            }

            const Maybe <STRING_T> &GetExternalId() const
            {
                return mExternalId;
            }

            void SetExternalId(const STRING_T &externalId)
            {
                mExternalId = externalId;
            }

            const Maybe <STRING_T> &GetOriginalTitle() const
            {
                return mOriginalTitle;
            }

            void SetOriginalTitle(const STRING_T &originalTitle)
            {
                mOriginalTitle = originalTitle;
            }

            const Maybe <STRING_T> &GetOriginalSummary() const
            {
                return mOriginalSummary;
            }

            void SetOriginalSummary(const STRING_T &originalSummary)
            {
                mOriginalSummary = originalSummary;
            }

            const Maybe <STRING_T> &GetLocalTitle() const
            {
                return mLocalTitle;
            }

            void SetLocalTitle(const STRING_T &localTitle)
            {
                mLocalTitle = localTitle;
            }

            const Maybe <STRING_T> &GetLocalSummary() const
            {
                return mLocalSummary;
            }

            void SetLocalSummary(const STRING_T &localSummary)
            {
                mLocalSummary = localSummary;
            }

            const Maybe <VECTOR_T<Image>> &GetImages() const
            {
                return mImages;
            }

            void SetImages(const VECTOR_T<Image> &images)
            {
                mImages = images;
            }

            const Maybe <VECTOR_T<Link>> &GetMediaProductLinks() const
            {
                return mMediaProductLinks;
            }

            void SetMediaProductLinks(const VECTOR_T<Link> &mediaProductLinks)
            {
                mMediaProductLinks = mediaProductLinks;
            }

            const Maybe <VECTOR_T<WmvFile>> &GetWmvFiles() const
            {
                return mWmvFiles;
            }

            void SetWmvFiles(const VECTOR_T<WmvFile> &wmvFiles)
            {
                mWmvFiles = wmvFiles;
            }

            const Maybe <VECTOR_T<SmoothManifest>> &GetSmoothManifests() const
            {
                return mSmoothManifests;
            }

            void SetSmoothManifests(const VECTOR_T<SmoothManifest> &smoothManifests)
            {
                mSmoothManifests = smoothManifests;
            }

            const Maybe <Link> &GetSelf() const
            {
                return mSelf;
            }

            void SetSelf(const Link &self)
            {
                mSelf = self;
            }

            virtual BOOL_T InitFromJsonValue(const rapidjson::Value &value, ParseErrors &parseErrors,
                                             VECTOR_T<STRING_T> &context)
            {
                STRING_T id;
                STRING_T externalId;
                STRING_T originalTitle;
                STRING_T originalSummary;
                STRING_T localTitle;
                STRING_T localSummary;
                VECTOR_T<Image> images;
                VECTOR_T<Link> mediaProductLinks;
                VECTOR_T<WmvFile> wmvFiles;
                VECTOR_T<SmoothManifest> smoothManifests;
                Link self;

                context.push_back(TAG);

                if (ParseString(value, "Id", true, id, parseErrors, context))
                    SetId(id);

                if (ParseString(value, "ExternalId", true, externalId, parseErrors, context))
                    SetExternalId(externalId);

                if (ParseString(value, "OriginalTitle", false, originalTitle, parseErrors, context))
                    SetOriginalTitle(originalTitle);

                if (ParseString(value, "OriginalSummary", false, originalSummary, parseErrors, context))
                    SetOriginalSummary(originalSummary);

                if (ParseString(value, "LocalTitle", false, localTitle, parseErrors, context))
                    SetLocalTitle(localTitle);

                if (ParseString(value, "LocalSummary", false, localSummary, parseErrors, context))
                    SetLocalSummary(localSummary);

                if (VerifyArray(value, "Images", false, parseErrors, context))
                {
                    for (rapidjson::SizeType i = 0; i < value["Images"].Size(); i += 1)
                    {
                        Image image;
                        if (ParseObject(value["Images"][i], "", false, image, parseErrors, context))
                            images.push_back(image);
                    }
                    SetImages(images);
                }

                if (VerifyArray(value, "MediaProductLinks", false, parseErrors, context))
                {
                    for (rapidjson::SizeType i = 0; i < value["MediaProductLinks"].Size(); i += 1)
                    {
                        Link mediaProductLink;
                        if (ParseObject(value["MediaProductLinks"][i], "", false, mediaProductLink, parseErrors,
                                        context))
                            mediaProductLinks.push_back(mediaProductLink);
                    }
                    SetMediaProductLinks(mediaProductLinks);
                }

                if (VerifyArray(value, "WmvFiles", false, parseErrors, context))
                {
                    for (rapidjson::SizeType i = 0; i < value["WmvFiles"].Size(); i += 1)
                    {
                        WmvFile wmvFile;
                        if (ParseObject(value["WmvFiles"][i], "", false, wmvFile, parseErrors, context))
                            wmvFiles.push_back(wmvFile);
                    }
                    SetWmvFiles(wmvFiles);
                }

                if (VerifyArray(value, "SmoothManifests", false, parseErrors, context))
                {
                    for (rapidjson::SizeType i = 0; i < value["SmoothManifests"].Size(); i += 1)
                    {
                        SmoothManifest smoothManifest;
                        if (ParseObject(value["SmoothManifests"][i], "", false, smoothManifest, parseErrors,
                                        context))
                            smoothManifests.push_back(smoothManifest);
                    }
                    SetSmoothManifests(smoothManifests);
                }

                if (ParseObject(value, "Self", false, self, parseErrors, context))
                    SetSelf(self);

                context.pop_back();
                return !parseErrors;
            }


        private:
            Maybe <STRING_T> mId;
            Maybe <STRING_T> mExternalId;
            Maybe <STRING_T> mOriginalTitle;
            Maybe <STRING_T> mOriginalSummary;
            Maybe <STRING_T> mLocalTitle;
            Maybe <STRING_T> mLocalSummary;
            Maybe <VECTOR_T<Image>> mImages;
            Maybe <VECTOR_T<Link>> mMediaProductLinks;
            Maybe <VECTOR_T<WmvFile>> mWmvFiles;
            Maybe <VECTOR_T<SmoothManifest>> mSmoothManifests;
            Maybe <Link> mSelf;
            STRING_T TAG;
        };
    }
}

#endif //READY4AIR_BUNDLE_H
