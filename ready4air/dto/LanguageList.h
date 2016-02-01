#ifndef READY4AIR_LANGUAGELIST_H
#define READY4AIR_LANGUAGELIST_H

#include "../common/Maybe.h"
#include "abstract/JsonDeserializable.h"
#include "Language.h"

namespace ready4air
{
    namespace dto
    {
        class LanguageList : public JsonDeserializable
        {
        public:
            LanguageList() : TAG("ready4air::dto::LanguageList")
            {
            }

            virtual ~LanguageList()
            {
            }

            const Maybe<Language> &GetLanguage() const
            {
                return mLanguage;
            }

            void SetLanguage(const Language &language)
            {
                mLanguage = language;
            }

            const Maybe<STRING_T> &GetName() const
            {
                return mName;
            }

            void SetName(const STRING_T &name)
            {
                mName = name;
            }

            const Maybe<STRING_T> &GetDescription() const
            {
                return mDescription;
            }

            void SetDescription(const STRING_T &description)
            {
                mDescription = description;
            }

            const Maybe<BOOL_T> &IsGenre() const
            {
                return mIsGenre;
            }

            void SetIsGenre(BOOL_T isGenre)
            {
                mIsGenre = isGenre;
            }

            virtual BOOL_T InitFromJsonValue(const rapidjson::Value &value, ParseErrors &parseErrors)
            {
                Language language;
                STRING_T name;
                STRING_T description;
                BOOL_T isGenre;

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
            Maybe<Language> mLanguage;
            Maybe<STRING_T> mName;
            Maybe<STRING_T> mDescription;
            Maybe<BOOL_T> mIsGenre;
            STRING_T TAG;
        };
    }
}

#endif //READY4AIR_LANGUAGELIST_H
