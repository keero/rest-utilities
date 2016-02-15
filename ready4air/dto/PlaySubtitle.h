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
            PlaySubtitle() : TAG("ready4air::dto::PlaySubtitle")
            {
            }

            virtual ~PlaySubtitle()
            {
            }

            const Maybe <STRING_T> &GetEncoding() const
            {
                return mEncoding;
            }

            void SetEncoding(const STRING_T &encoding)
            {
                mEncoding = encoding;
            }

            const Maybe <STRING_T> &GetFormat() const
            {
                return mFormat;
            }

            void SetFormat(const STRING_T &format)
            {
                mFormat = format;
            }

            const Maybe <STRING_T> &GetLanguage() const
            {
                return mLanguage;
            }

            void SetLanguage(const STRING_T &language)
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

            virtual BOOL_T InitFromJsonValue(const rapidjson::Value &value, ParseErrors &parseErrors,
                                             VECTOR_T<STRING_T> &context)
            {
                STRING_T encoding;
                STRING_T format;
                STRING_T language;
                Link link;

                context.push_back(TAG);

                if (ParseString(value, "Encoding", true, encoding, parseErrors, context))
                    SetEncoding(encoding);

                if (ParseString(value, "Format", true, format, parseErrors, context))
                    SetFormat(format);

                if (ParseString(value, "Language", true, language, parseErrors, context))
                    SetLanguage(language);

                if (ParseObject(value, "Link", true, link, parseErrors, context))
                    SetLink(link);

                context.pop_back();
                return !parseErrors;
            }

        private:
            Maybe <STRING_T> mEncoding;
            Maybe <STRING_T> mFormat;
            Maybe <STRING_T> mLanguage;
            Maybe <Link> mLink;
            STRING_T TAG;
        };
    }
}

#endif //READY4AIR_PLAYSUBTITLE_H
