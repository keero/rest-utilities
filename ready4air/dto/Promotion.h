#ifndef READY4AIR_PROMOTION_H
#define READY4AIR_PROMOTION_H

#include "abstract/JsonDeserializable.h"
#include "hypermedia/Link.h"

namespace ready4air
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

        const Link &GetImage() const
        {
            return mImage;
        }

        void SetImage(const Link &image)
        {
            mImage = image;
        }

        const Link &GetImageLink() const
        {
            return mImageLink;
        }

        void SetImageLink(const Link &imageLink)
        {
            mImageLink = imageLink;
        }

        const Link &GetExternalSource() const
        {
            return mExternalSource;
        }

        void SetExternalSource(const Link &externalSource)
        {
            mExternalSource = externalSource;
        }

        const std::string &GetSource() const
        {
            return mSource;
        }

        void SetSource(const std::string &source)
        {
            mSource = source;
        }

        virtual bool InitFromJsonValue(const rapidjson::Value &value)
        {
            return false;
        }

    private:
        Link mImage;
        Link mImageLink;
        Link mExternalSource;
        std::string mSource;
    };
}

#endif //READY4AIR_PROMOTION_H
