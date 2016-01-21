#ifndef READY4AIR_LITERAL_H
#define READY4AIR_LITERAL_H

#include "../common/Maybe.h"
#include "abstract/JsonDeserializable.h"
#include "hypermedia/Link.h"
#include "abstract/Mappable.h"

namespace ready4air
{
    namespace dto
    {
        class Literal : public JsonDeserializable, public Mappable
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

            virtual bool InitFromJsonValue(const rapidjson::Value &value, ParseErrors &parseErrors)
            {
                std::string key;
                std::string val;
                std::string language;
                Link self;

                if (ParseString(value, "Key", true, key, parseErrors))
                    SetKey(key);

                if (ParseString(value, "Value", true, val, parseErrors))
                    SetValue(val);

                if (ParseString(value, "Language", true, language, parseErrors))
                    SetLanguage(language);

                if (ParseObject(value, "Self", true, self, parseErrors))
                    SetSelf(self);

                return !parseErrors;
            }

        private:
            Maybe <std::string> mKey;
            Maybe <std::string> mValue;
            Maybe <std::string> mLanguage;
            Maybe <Link> mSelf;
        };
    }
}

#endif //READY4AIR_LITERAL_H
