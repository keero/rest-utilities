#ifndef READY4AIR_PROMOTION_H
#define READY4AIR_PROMOTION_H

#include "../common/Maybe.h"
#include "abstract/JsonDeserializable.h"
#include "hypermedia/Link.h"

namespace ready4air
{
    namespace dto
    {
        class Promotion : public JsonDeserializable
        {
        public:
            Promotion() : TAG("ready4air::dto::Promotion")
            {
            }

            virtual ~Promotion()
            {
            }

            const Maybe <Link> &GetImage() const
            {
                return mImage;
            }

            void SetImage(const Link &image)
            {
                mImage = image;
            }

            const Maybe <Link> &GetImageLink() const
            {
                return mImageLink;
            }

            void SetImageLink(const Link &imageLink)
            {
                mImageLink = imageLink;
            }

            const Maybe <Link> &GetExternalSource() const
            {
                return mExternalSource;
            }

            void SetExternalSource(const Link &externalSource)
            {
                mExternalSource = externalSource;
            }

            const Maybe <STRING_T> &GetSource() const
            {
                return mSource;
            }

            void SetSource(const STRING_T &source)
            {
                mSource = source;
            }

            virtual BOOL_T InitFromJsonValue(const rapidjson::Value &value, ParseErrors &parseErrors)
            {
                Link image;
                Link imageLink;
                Link externalSource;
                STRING_T source;

                if (ParseObject(value, "Image", false, image, parseErrors))
                    SetImage(image);

                if (ParseObject(value, "ImageLink", false, imageLink, parseErrors))
                    SetImageLink(imageLink);

                if (ParseObject(value, "ExternalSource", false, externalSource, parseErrors))
                    SetExternalSource(externalSource);

                if (ParseString(value, "Source", false, source, parseErrors))
                    SetSource(source);

                return !parseErrors;
            }

        private:
            Maybe <Link> mImage;
            Maybe <Link> mImageLink;
            Maybe <Link> mExternalSource;
            Maybe <STRING_T> mSource;
            STRING_T TAG;
        };
    }
}

#endif //READY4AIR_PROMOTION_H
