#ifndef READY4AIR_CRITICSQUOTE_H
#define READY4AIR_CRITICSQUOTE_H

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

        const std::string &GetText() const
        {
            return mText;
        }

        void SetText(const std::string &text)
        {
            mText = text;
        }

        const std::string &GetSource() const
        {
            return mSource;
        }

        void SetSource(const std::string &source)
        {
            mSource = source;
        }

        const std::string &GetScore() const
        {
            return mScore;
        }

        void SetScore(const std::string &score)
        {
            mScore = score;
        }

        const Link &GetLink() const
        {
            return mLink;
        }

        void SetLink(const Link &link)
        {
            mLink = link;
        }

        const QuoteImages &GetImages() const
        {
            return mImages;
        }

        void SetImages(const QuoteImages &images)
        {
            mImages = images;
        }

        virtual bool InitFromJsonValue(const rapidjson::Value &value)
        {
            // Non-mandatory property
            if (value.HasMember("Text"))
            {
                if (!value["Text"].IsString()) return false;
                SetText(value["Text"].GetString());
            }

            // Non-mandatory property
            if (value.HasMember("Source"))
            {
                if (!value["Source"].IsString()) return false;
                SetSource(value["Source"].GetString());
            }

            // Non-mandatory property
            if (value.HasMember("Score"))
            {
                if (!value["Score"].IsString()) return false;
                SetScore(value["Score"].GetString());
            }

            // Non-mandatory property
            if (value.HasMember("Link"))
            {
                Link link;
                if (!value["Link"].IsObject() || !link.InitFromJsonValue(value["Link"])) return false;
                SetLink(link);
            }

            // Non-mandatory property
            if (value.HasMember("Images"))
            {
                QuoteImages images;
                if (!value["Images"].IsObject() || !images.InitFromJsonValue(value["Images"])) return false;
                SetImages(images);
            }

            return true;
        }

    private:
        std::string mText;
        std::string mSource;
        std::string mScore;
        Link mLink;
        QuoteImages mImages;
    };
}

#endif //READY4AIR_CRITICSQUOTE_H
