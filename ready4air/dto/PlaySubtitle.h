#ifndef READY4AIR_PLAYSUBTITLE_H
#define READY4AIR_PLAYSUBTITLE_H

#include "../common/Maybe.h"
#include "abstract/JsonDeserializable.h"
#include "hypermedia/Link.h"

namespace ready4air
{
    namespace dto
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

            const Maybe<STRING_T> &GetEncoding() const
            {
                return mEncoding;
            }

            void SetEncoding(const STRING_T &encoding)
            {
                mEncoding = encoding;
            }

            const Maybe<STRING_T> &GetFormat() const
            {
                return mFormat;
            }

            void SetFormat(const STRING_T &format)
            {
                mFormat = format;
            }

            const Maybe<STRING_T> &GetLanguage() const
            {
                return mLanguage;
            }

            void SetLanguage(const STRING_T &language)
            {
                mLanguage = language;
            }

            const Maybe<Link> &GetLink() const
            {
                return mLink;
            }

            void SetLink(const Link &link)
            {
                mLink = link;
            }

            virtual BOOL_T InitFromJsonValue(const rapidjson::Value &value, ParseErrors &parseErrors)
            {
                STRING_T encoding;
                STRING_T format;
                STRING_T language;
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
            Maybe<STRING_T> mEncoding;
            Maybe<STRING_T> mFormat;
            Maybe<STRING_T> mLanguage;
            Maybe<Link> mLink;
        };
    }
}

#endif //READY4AIR_PLAYSUBTITLE_H
