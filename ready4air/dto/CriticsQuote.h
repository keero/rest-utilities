#ifndef READY4AIR_CRITICSQUOTE_H
#define READY4AIR_CRITICSQUOTE_H

#include "../common/Maybe.h"
#include "abstract/JsonDeserializable.h"
#include "hypermedia/Link.h"
#include "QuoteImages.h"

namespace ready4air
{
    namespace dto
    {
        class CriticsQuote : public JsonDeserializable
        {
        public:
            CriticsQuote() : TAG("ready4air::dto::CriticsQuote")
            {
            }

            virtual ~CriticsQuote()
            {
            }

            const Maybe<STRING_T> &GetText() const
            {
                return mText;
            }

            void SetText(const STRING_T &text)
            {
                mText = text;
            }

            const Maybe<STRING_T> &GetSource() const
            {
                return mSource;
            }

            void SetSource(const STRING_T &source)
            {
                mSource = source;
            }

            const Maybe<STRING_T> &GetScore() const
            {
                return mScore;
            }

            void SetScore(const STRING_T &score)
            {
                mScore = score;
            }

            const Maybe<Link> &GetLink() const
            {
                return mLink;
            }

            void SetLink(const Link &link)
            {
                mLink = link;
            }

            const Maybe<QuoteImages> &GetImages() const
            {
                return mImages;
            }

            void SetImages(const QuoteImages &images)
            {
                mImages = images;
            }

            virtual BOOL_T InitFromJsonValue(const rapidjson::Value &value, ParseErrors &parseErrors)
            {
                STRING_T text;
                STRING_T source;
                STRING_T score;
                Link link;
                QuoteImages images;

                if (ParseString(value, "Text", false, text, parseErrors))
                    SetText(text);

                if (ParseString(value, "Source", false, source, parseErrors))
                    SetSource(source);

                if (ParseString(value, "Score", false, score, parseErrors))
                    SetScore(score);

                if (ParseObject(value, "Link", false, link, parseErrors))
                    SetLink(link);

                if (ParseObject(value, "Images", false, images, parseErrors))
                    SetImages(images);

                return !parseErrors;
            }

        private:
            Maybe<STRING_T> mText;
            Maybe<STRING_T> mSource;
            Maybe<STRING_T> mScore;
            Maybe<Link> mLink;
            Maybe<QuoteImages> mImages;
            STRING_T TAG;
        };
    }
}

#endif //READY4AIR_CRITICSQUOTE_H
