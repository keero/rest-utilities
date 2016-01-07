#ifndef READY4AIR_QUOTEIMAGE_H
#define READY4AIR_QUOTEIMAGE_H

#include "../maybe/Maybe.h"
#include "abstract/JsonDeserializable.h"
#include "hypermedia/Link.h"

namespace ready4air
{
    class QuoteImage : public JsonDeserializable
    {
    public:
        QuoteImage()
        {
        }

        virtual ~QuoteImage()
        {
        }

        const Maybe <int> &GetWidth() const
        {
            return mWidth;
        }

        void SetWidth(int width)
        {
            mWidth = width;
        }

        const Maybe <int> &GetHeight() const
        {
            return mHeight;
        }

        void SetHeight(int height)
        {
            mHeight = height;
        }

        const Maybe <Link> &GetLink() const
        {
            return mLink;
        }

        void SetLink(const Link &link)
        {
            mLink = link;
        }

        virtual bool InitFromJsonValue(const rapidjson::Value &value)
        {
            return false;
        }

    private:
        Maybe <int> mWidth;
        Maybe <int> mHeight;
        Maybe <Link> mLink;
    };
}

#endif //READY4AIR_QUOTEIMAGE_H
