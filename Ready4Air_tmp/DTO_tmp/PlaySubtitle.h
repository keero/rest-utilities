#ifndef READY4AIR_PLAYSUBTITLE_H
#define READY4AIR_PLAYSUBTITLE_H

#include "abstract/JsonDeserializable.h"
#include "hypermedia/Link.h"

namespace ready4air
{
    class PlaySubtitle : public JsonDeserializable
    {
    public:
        PlaySubtitle()
        {
        }

        virtual ~PlaySubtitle()
        {
        }

        const std::string &GetEncoding() const
        {
            return mEncoding;
        }

        void SetEncoding(const std::string &encoding)
        {
            mEncoding = encoding;
        }

        const std::string &GetFormat() const
        {
            return mFormat;
        }

        void SetFormat(const std::string &format)
        {
            mFormat = format;
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
        std::string mEncoding;
        std::string mFormat;
        std::string mLanguage;
        Link mLink;
    };
}

#endif //READY4AIR_PLAYSUBTITLE_H
