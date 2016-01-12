#ifndef READY4AIR_LANGUAGE_H
#define READY4AIR_LANGUAGE_H

#include "../maybe/Maybe.h"
#include "abstract/JsonDeserializable.h"

namespace ready4air
{
    class Language : public JsonDeserializable
    {
    public:
        Language()
        {
        }

        virtual ~Language()
        {
        }

        const Maybe <std::string> &GetCode() const
        {
            return mCode;
        }

        void SetCode(const std::string &code)
        {
            mCode = code;
        }

        const Maybe <std::string> &GetISO6391Code() const
        {
            return mISO6391Code;
        }

        void SetISO6391Code(const std::string &ISO6391Code)
        {
            mISO6391Code = ISO6391Code;
        }

        const Maybe <std::string> &GetISO6392Code() const
        {
            return mISO6392Code;
        }

        void SetISO6392Code(const std::string &ISO6392Code)
        {
            mISO6392Code = ISO6392Code;
        }

        const Maybe <std::string> &GetEnglishName() const
        {
            return mEnglishName;
        }

        void SetEnglishName(const std::string &englishName)
        {
            mEnglishName = englishName;
        }

        virtual bool InitFromJsonValue(const rapidjson::Value &value, ParseErrors &parseErrors)
        {
            std::string code;
            std::string iso6391Code;
            std::string iso6392Code;
            std::string englishName;

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
        Maybe <std::string> mCode;
        Maybe <std::string> mISO6391Code;
        Maybe <std::string> mISO6392Code;
        Maybe <std::string> mEnglishName;
    };
}

#endif //READY4AIR_LANGUAGE_H
