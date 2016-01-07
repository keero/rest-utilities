#ifndef READY4AIR_PROMOTION_H
#define READY4AIR_PROMOTION_H

#include "../maybe/Maybe.h"
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

        virtual bool InitFromJsonValue(const rapidjson::Value &value)
        {
            return false;
        }

    private:
        Maybe <Link> mImage;
        Maybe <Link> mImageLink;
        Maybe <Link> mExternalSource;
        Maybe <std::string> mSource;
    };
}

#endif //READY4AIR_PROMOTION_H
