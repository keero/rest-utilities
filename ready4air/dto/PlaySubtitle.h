#ifndef READY4AIR_PLAYSUBTITLE_H
#define READY4AIR_PLAYSUBTITLE_H

#include "../maybe/Maybe.h"
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

        const Maybe <std::string> &GetEncoding() const
        {
            return mEncoding;
        }

        void SetEncoding(const std::string &encoding)
        {
            mEncoding = encoding;
        }

        const Maybe <std::string> &GetFormat() const
        {
            return mFormat;
        }

        void SetFormat(const std::string &format)
        {
            mFormat = format;
        }

        const Maybe <std::string> &GetLanguage() const
        {
            return mLanguage;
        }

        void SetLanguage(const std::string &language)
        {
            mLanguage = language;
        }

        const Maybe <Link> &GetLink() const
        {
            return mLink;
        }

        void SetLink(const Link &link)
        {
            mLink = link;
        }

        virtual bool InitFromJsonValue(const rapidjson::Value &value, ParseErrors &parseErrors)
        {
            std::string encoding;
            std::string format;
            std::string language;
            Link link;

            if (ParseString(value, "Encoding", true, encoding, parseErrors))
                SetEncoding(encoding);

            if (ParseString(value, "Format", true, format, parseErrors))
                SetFormat(format);

            if (ParseString(value, "Language", true, language, parseErrors))
                SetLanguage(language);

            if (ParseObject(value, "Link", true, link, parseErrors))
                SetLink(link);

            return !parseErrors;
        }

    private:
        Maybe <std::string> mEncoding;
        Maybe <std::string> mFormat;
        Maybe <std::string> mLanguage;
        Maybe <Link> mLink;
    };
}

#endif //READY4AIR_PLAYSUBTITLE_H
