#ifndef READY4AIR_CRITICSQUOTE_H
#define READY4AIR_CRITICSQUOTE_H

#include "../maybe/Maybe.h"
#include "abstract/JsonDeserializable.h"
#include "hypermedia/Link.h"
#include "QuoteImages.h"

namespace ready4air
{
    class CriticsQuote : public JsonDeserializable
    {
    public:
        CriticsQuote()
        {
        }

        virtual ~CriticsQuote()
        {
        }

        const Maybe <std::string> &GetText() const
        {
            return mText;
        }

        void SetText(const std::string &text)
        {
            mText = text;
        }

        const Maybe <std::string> &GetSource() const
        {
            return mSource;
        }

        void SetSource(const std::string &source)
        {
            mSource = source;
        }

        const Maybe <std::string> &GetScore() const
        {
            return mScore;
        }

        void SetScore(const std::string &score)
        {
            mScore = score;
        }

        const Maybe <Link> &GetLink() const
        {
            return mLink;
        }

        void SetLink(const Link &link)
        {
            mLink = link;
        }

        const Maybe <QuoteImages> &GetImages() const
        {
            return mImages;
        }

        void SetImages(const QuoteImages &images)
        {
            mImages = images;
        }

        virtual bool InitFromJsonValue(const rapidjson::Value &value, ParseErrors &parseErrors)
        {
            std::string text;
            std::string source;
            std::string score;
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
        Maybe <std::string> mText;
        Maybe <std::string> mSource;
        Maybe <std::string> mScore;
        Maybe <Link> mLink;
        Maybe <QuoteImages> mImages;
    };
}

#endif //READY4AIR_CRITICSQUOTE_H
