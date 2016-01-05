#ifndef READY4AIR_LANGUAGE_H
#define READY4AIR_LANGUAGE_H

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

        const std::string &GetCode() const
        {
            return mCode;
        }

        void SetCode(const std::string &code)
        {
            mCode = code;
        }

        const std::string &GetISO6391Code() const
        {
            return mISO6391Code;
        }

        void SetISO6391Code(const std::string &ISO6391Code)
        {
            mISO6391Code = ISO6391Code;
        }

        const std::string &GetISO6392Code() const
        {
            return mISO6392Code;
        }

        void SetISO6392Code(const std::string &ISO6392Code)
        {
            mISO6392Code = ISO6392Code;
        }

        const std::string &GetEnglishName() const
        {
            return mEnglishName;
        }

        void SetEnglishName(const std::string &englishName)
        {
            mEnglishName = englishName;
        }

        virtual bool InitFromJsonValue(const rapidjson::Value &value)
        {
            {
                // Mandatory property
                if (!value.HasMember("Code") || !value["Code"].IsString()) return false;
                SetCode(value["Code"].GetString());
            }
            {
                // Mandatory property
                if (!value.HasMember("ISO6391Code") || !value["ISO6391Code"].IsString()) return false;
                SetISO6391Code(value["ISO6391Code"].GetString());
            }
            {
                // Mandatory property
                if (!value.HasMember("ISO6392Code") || !value["ISO6392Code"].IsString()) return false;
                SetISO6392Code(value["ISO6392Code"].GetString());
            }
            {
                // Mandatory property
                if (!value.HasMember("EnglishName") || !value["EnglishName"].IsString()) return false;
                SetEnglishName(value["EnglishName"].GetString());
            }

            return true;
        }

    private:
        std::string mCode;
        std::string mISO6391Code;
        std::string mISO6392Code;
        std::string mEnglishName;
    };
}

#endif //READY4AIR_LANGUAGE_H
