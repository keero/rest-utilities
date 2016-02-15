#ifndef READY4AIR_LITERAL_H
#define READY4AIR_LITERAL_H

#include "../common/Maybe.h"
#include "abstract/JsonDeserializable.h"
#include "hypermedia/Link.h"

namespace ready4air
{
    namespace dto
    {
        class Literal : public JsonDeserializable
        {
        public:
            Literal() : TAG("ready4air::dto::Literal")
            {
            }

            virtual ~Literal()
            {
            }

            const Maybe <STRING_T> &GetKey() const
            {
                return mKey;
            }

            void SetKey(const STRING_T &key)
            {
                mKey = key;
            }

            const Maybe <STRING_T> &GetValue() const
            {
                return mValue;
            }

            void SetValue(const STRING_T &value)
            {
                mValue = value;
            }

            const Maybe <STRING_T> &GetLanguage() const
            {
                return mLanguage;
            }

            void SetLanguage(const STRING_T &language)
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

            virtual BOOL_T InitFromJsonValue(const rapidjson::Value &value, ParseErrors &parseErrors,
                                             VECTOR_T<STRING_T> &context)
            {
                STRING_T key;
                STRING_T val;
                STRING_T language;
                Link self;

                context.push_back(TAG);

                if (ParseString(value, "Key", true, key, parseErrors, context))
                    SetKey(key);

                if (ParseString(value, "Value", true, val, parseErrors, context))
                    SetValue(val);

                if (ParseString(value, "Language", true, language, parseErrors, context))
                    SetLanguage(language);

                if (ParseObject(value, "Self", true, self, parseErrors, context))
                    SetSelf(self);

                context.pop_back();
                return !parseErrors;
            }

        private:
            Maybe <STRING_T> mKey;
            Maybe <STRING_T> mValue;
            Maybe <STRING_T> mLanguage;
            Maybe <Link> mSelf;
            STRING_T TAG;
        };
    }
}

#endif //READY4AIR_LITERAL_H
