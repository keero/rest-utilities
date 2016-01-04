#ifndef READY4AIR_LANGUAGELIST_H
#define READY4AIR_LANGUAGELIST_H

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

        const Language &GetLanguage() const
        {
            return mLanguage;
        }

        void SetLanguage(const Language &language)
        {
            mLanguage = language;
        }

        const std::string &GetName() const
        {
            return mName;
        }

        void SetName(const std::string &name)
        {
            mName = name;
        }

        const std::string &GetDescription() const
        {
            return mDescription;
        }

        void SetDescription(const std::string &description)
        {
            mDescription = description;
        }

        bool IsGenre() const
        {
            return mIsGenre;
        }

        void SetIsGenre(bool isGenre)
        {
            mIsGenre = isGenre;
        }

        virtual bool InitFromJsonValue(const rapidjson::Value &value)
        {
            return false;
        }

    private:
        Language mLanguage;
        std::string mName;
        std::string mDescription;
        bool mIsGenre;
    };
}

#endif //READY4AIR_LANGUAGELIST_H
