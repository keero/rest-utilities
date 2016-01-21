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
            Promotion()
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

            const Maybe <std::string> &GetSource() const
            {
                return mSource;
            }

            void SetSource(const std::string &source)
            {
                mSource = source;
            }

            virtual bool InitFromJsonValue(const rapidjson::Value &value, ParseErrors &parseErrors)
            {
                Link image;
                Link imageLink;
                Link externalSource;
                std::string source;

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
            Maybe <std::string> mSource;
        };
    }
}

#endif //READY4AIR_PROMOTION_H
