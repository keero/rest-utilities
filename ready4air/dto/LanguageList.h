#ifndef READY4AIR_LANGUAGELIST_H
#define READY4AIR_LANGUAGELIST_H

#include "../maybe/Maybe.h"
#include "abstract/JsonDeserializable.h"
#include "Language.h"

namespace ready4air
{
    class LanguageList : public JsonDeserializable
    {
    public:
        LanguageList()
        {
        }

        virtual ~LanguageList()
        {
        }

        const Maybe <Language> &GetLanguage() const
        {
            return mLanguage;
        }

        void SetLanguage(const Language &language)
        {
            mLanguage = language;
        }

        const Maybe <std::string> &GetName() const
        {
            return mName;
        }

        void SetName(const std::string &name)
        {
            mName = name;
        }

        const Maybe <std::string> &GetDescription() const
        {
            return mDescription;
        }

        void SetDescription(const std::string &description)
        {
            mDescription = description;
        }

        const Maybe <bool> &IsGenre() const
        {
            return mIsGenre;
        }

        void SetIsGenre(bool isGenre)
        {
            mIsGenre = isGenre;
        }

        virtual bool InitFromJsonValue(const rapidjson::Value &value)
        {
            {
                // Mandatory property
                Language language;
                if (!value.HasMember("Language") || !value["Language"].IsObject() || !language.InitFromJsonValue(value["Language"])) return false;
                SetLanguage(language);
            }
            {
                // Mandatory property
                if (!value.HasMember("Name") || !value["Name"].IsString()) return false;
                SetName(value["Name"].GetString());
            }
            {
                // Mandatory property
                if (!value.HasMember("Description") || !value["Description"].IsString()) return false;
                SetDescription(value["Description"].GetString());
            }
            {
                // Mandatory property
                if (!value.HasMember("IsGenre") || !value["IsGenre"].IsBool()) return false;
                SetIsGenre(value["IsGenre"].GetBool());
            }

            return true;
        }

    private:
        Maybe <Language> mLanguage;
        Maybe <std::string> mName;
        Maybe <std::string> mDescription;
        Maybe <bool> mIsGenre;
    };
}

#endif //READY4AIR_LANGUAGELIST_H
