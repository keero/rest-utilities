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

        virtual bool InitFromJsonValue(const rapidjson::Value &value, ParseErrors &parseErrors)
        {
            Language language;
            std::string name;
            std::string description;
            bool isGenre;

            if (ParseObject(value, "Language", true, language, parseErrors))
                SetLanguage(language);

            if (ParseString(value, "Name", true, name, parseErrors))
                SetName(name);

            if (ParseString(value, "Description", true, description, parseErrors))
                SetDescription(description);

            if (ParseBool(value, "IsGenre", true, isGenre, parseErrors))
                SetIsGenre(isGenre);

            return !parseErrors;
        }

    private:
        Maybe <Language> mLanguage;
        Maybe <std::string> mName;
        Maybe <std::string> mDescription;
        Maybe <bool> mIsGenre;
    };
}

#endif //READY4AIR_LANGUAGELIST_H
