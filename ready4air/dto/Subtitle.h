#ifndef READY4AIR_SUBTITLE_H
#define READY4AIR_SUBTITLE_H

#include "../maybe/Maybe.h"
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

        const Maybe <std::string> &GetType() const
        {
            return mType;
        }

        void SetType(const std::string &type)
        {
            mType = type;
        }

        const Maybe <std::string> &GetEncoding() const
        {
            return mEncoding;
        }

        void SetEncoding(const std::string &encoding)
        {
            mEncoding = encoding;
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

        virtual bool InitFromJsonValue(const rapidjson::Value &value)
        {
            return false;
        }

    private:
        Maybe <std::string> mType;
        Maybe <std::string> mEncoding;
        Maybe <std::string> mLanguage;
        Maybe <Link> mLink;
    };
}

#endif //READY4AIR_SUBTITLE_H
