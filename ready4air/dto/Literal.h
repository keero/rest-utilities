#ifndef READY4AIR_LITERAL_H
#define READY4AIR_LITERAL_H

#include "../maybe/Maybe.h"
#include "abstract/JsonDeserializable.h"
#include "hypermedia/Link.h"

namespace ready4air
{
    class Literal : public JsonDeserializable
    {
    public:
        Literal()
        {
        }

        virtual ~Literal()
        {
        }

        const Maybe <std::string> &GetKey() const
        {
            return mKey;
        }

        void SetKey(const std::string &key)
        {
            mKey = key;
        }

        const Maybe <std::string> &GetValue() const
        {
            return mValue;
        }

        void SetValue(const std::string &value)
        {
            mValue = value;
        }

        const Maybe <std::string> &GetLanguage() const
        {
            return mLanguage;
        }

        void SetLanguage(const std::string &language)
        {
            mLanguage = language;
        }

        const Maybe <Link> &GetSelf() const
        {
            return mSelf;
        }

        void SetSelf(const Link &self)
        {
            mSelf = self;
        }

        virtual bool InitFromJsonValue(const rapidjson::Value &value)
        {
            return false;
        }

    private:
        Maybe <std::string> mKey;
        Maybe <std::string> mValue;
        Maybe <std::string> mLanguage;
        Maybe <Link> mSelf;
    };
}

#endif //READY4AIR_LITERAL_H
