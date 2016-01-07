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

        virtual bool InitFromJsonValue(const rapidjson::Value &value)
        {
            {
                // Non-mandatory property
                if (value.HasMember("Text"))
                {
                    if (!value["Text"].IsString()) return false;
                    SetText(value["Text"].GetString());
                }
            }
            {
                // Non-mandatory property
                if (value.HasMember("Source"))
                {
                    if (!value["Source"].IsString()) return false;
                    SetSource(value["Source"].GetString());
                }
            }
            {
                // Non-mandatory property
                if (value.HasMember("Score"))
                {
                    if (!value["Score"].IsString()) return false;
                    SetScore(value["Score"].GetString());
                }
            }
            {
                // Non-mandatory property
                if (value.HasMember("Link"))
                {
                    Link link;
                    if (!value["Link"].IsObject() || !link.InitFromJsonValue(value["Link"])) return false;
                    SetLink(link);
                }
            }
            {
                // Non-mandatory property
                if (value.HasMember("Images"))
                {
                    QuoteImages images;
                    if (!value["Images"].IsObject() || !images.InitFromJsonValue(value["Images"])) return false;
                    SetImages(images);
                }
            }

            return true;
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
