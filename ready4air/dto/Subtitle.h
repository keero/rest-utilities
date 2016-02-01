#ifndef READY4AIR_SUBTITLE_H
#define READY4AIR_SUBTITLE_H

#include "../common/Maybe.h"
#include "abstract/JsonDeserializable.h"
#include "hypermedia/Link.h"

namespace ready4air
{
    namespace dto
    {
        class Subtitle : public JsonDeserializable
        {
        public:
            Subtitle() : TAG("ready4air::dto::Subtitle")
            {
            }

            virtual ~Subtitle()
            {
            }

            const Maybe <STRING_T> &GetType() const
            {
                return mType;
            }

            void SetType(const STRING_T &type)
            {
                mType = type;
            }

            const Maybe <STRING_T> &GetEncoding() const
            {
                return mEncoding;
            }

            void SetEncoding(const STRING_T &encoding)
            {
                mEncoding = encoding;
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

            virtual BOOL_T InitFromJsonValue(const rapidjson::Value &value, ParseErrors &parseErrors)
            {
                STRING_T type;
                STRING_T encoding;
                STRING_T language;
                Link link;

                if (ParseString(value, "Type", true, type, parseErrors))
                    SetType(type);

                if (ParseString(value, "Encoding", true, encoding, parseErrors))
                    SetEncoding(encoding);

                if (ParseString(value, "Language", true, language, parseErrors))
                    SetLanguage(language);

                if (ParseObject(value, "Link", false, link, parseErrors))
                    SetLink(link);

                return !parseErrors;
            }

        private:
            Maybe <STRING_T> mType;
            Maybe <STRING_T> mEncoding;
            Maybe <STRING_T> mLanguage;
            Maybe <Link> mLink;
            STRING_T TAG;
        };
    }
}

#endif //READY4AIR_SUBTITLE_H
