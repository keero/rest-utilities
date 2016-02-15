#ifndef READY4AIR_QUOTEIMAGE_H
#define READY4AIR_QUOTEIMAGE_H

#include "../common/Maybe.h"
#include "abstract/JsonDeserializable.h"
#include "hypermedia/Link.h"

namespace ready4air
{
    namespace dto
    {
        class QuoteImage : public JsonDeserializable
        {
        public:
            QuoteImage() : TAG("ready4air::dto::QuoteImage")
            {
            }

            virtual ~QuoteImage()
            {
            }

            const Maybe<int> &GetWidth() const
            {
                return mWidth;
            }

            void SetWidth(int width)
            {
                mWidth = width;
            }

            const Maybe<int> &GetHeight() const
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

            virtual BOOL_T InitFromJsonValue(const rapidjson::Value &value, ParseErrors &parseErrors,
                                             VECTOR_T<STRING_T> &context)
            {
                INT32_T width;
                INT32_T height;
                Link link;

                context.push_back(TAG);

                if (ParseInt(value, "Width", true, width, parseErrors, context))
                    SetWidth(width);

                if (ParseInt(value, "Height", true, height, parseErrors, context))
                    SetHeight(height);

                if (ParseObject(value, "Link", false, link, parseErrors, context))
                    SetLink(link);

                context.pop_back();
                return !parseErrors;
            }

        private:
            Maybe<int> mWidth;
            Maybe<int> mHeight;
            Maybe <Link> mLink;
            STRING_T TAG;
        };
    }
}

#endif //READY4AIR_QUOTEIMAGE_H
