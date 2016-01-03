#ifndef READY4AIR_SUBTITLE_H
#define READY4AIR_SUBTITLE_H

#include "abstract/JsonDeserializable.h"
#include "hypermedia/Link.h"

namespace ready4air
{
    class Subtitle : public JsonDeserializable
    {
    public:
        Subtitle()
        {
        }

        virtual ~Subtitle()
        {
        }

        const std::string &GetType() const
        {
            return mType;
        }

        void SetType(const std::string &type)
        {
            mType = type;
        }

        const std::string &GetEncoding() const
        {
            return mEncoding;
        }

        void SetEncoding(const std::string &encoding)
        {
            mEncoding = encoding;
        }

        const std::string &GetLanguage() const
        {
            return mLanguage;
        }

        void SetLanguage(const std::string &language)
        {
            mLanguage = language;
        }

        const Link &GetLink() const
        {
            return mLink;
        }

        void SetLink(const Link &link)
        {
            mLink = link;
        }

    private:
        std::string mType;
        std::string mEncoding;
        std::string mLanguage;
        Link mLink;
    };
}

#endif //READY4AIR_SUBTITLE_H
