#ifndef READY4AIR_LANGUAGE_H
#define READY4AIR_LANGUAGE_H

#include "../common/Maybe.h"
#include "abstract/JsonDeserializable.h"

namespace ready4air
{
    namespace dto
    {
        class Language : public JsonDeserializable
        {
        public:
            Language() : TAG("ready4air::dto::Language")
            {
            }

            virtual ~Language()
            {
            }

            const Maybe <STRING_T> &GetCode() const
            {
                return mCode;
            }

            void SetCode(const STRING_T &code)
            {
                mCode = code;
            }

            const Maybe <STRING_T> &GetISO6391Code() const
            {
                return mISO6391Code;
            }

            void SetISO6391Code(const STRING_T &ISO6391Code)
            {
                mISO6391Code = ISO6391Code;
            }

            const Maybe <STRING_T> &GetISO6392Code() const
            {
                return mISO6392Code;
            }

            void SetISO6392Code(const STRING_T &ISO6392Code)
            {
                mISO6392Code = ISO6392Code;
            }

            const Maybe <STRING_T> &GetEnglishName() const
            {
                return mEnglishName;
            }

            void SetEnglishName(const STRING_T &englishName)
            {
                mEnglishName = englishName;
            }

            virtual BOOL_T InitFromJsonValue(const rapidjson::Value &value, ParseErrors &parseErrors)
            {
                STRING_T code;
                STRING_T iso6391Code;
                STRING_T iso6392Code;
                STRING_T englishName;

                if (ParseString(value, "Code", true, code, parseErrors))
                    SetCode(code);

                if (ParseString(value, "ISO6391Code", true, iso6391Code, parseErrors))
                    SetISO6391Code(iso6391Code);

                if (ParseString(value, "ISO6392Code", true, iso6392Code, parseErrors))
                    SetISO6392Code(iso6392Code);

                if (ParseString(value, "EnglishName", true, englishName, parseErrors))
                    SetEnglishName(englishName);

                return !parseErrors;
            }

        private:
            Maybe <STRING_T> mCode;
            Maybe <STRING_T> mISO6391Code;
            Maybe <STRING_T> mISO6392Code;
            Maybe <STRING_T> mEnglishName;
            const STRING_T TAG;
        };
    }
}

#endif //READY4AIR_LANGUAGE_H
