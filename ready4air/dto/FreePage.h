#ifndef READY4AIR_FREEPAGE_H
#define READY4AIR_FREEPAGE_H

#include "../maybe/Maybe.h"
#include "abstract/JsonDeserializable.h"

namespace ready4air
{
    class FreePage : public JsonDeserializable
    {
    public:
        FreePage()
        {
        }

        virtual ~FreePage()
        {
        }

        const Maybe <std::string> &GetId() const
        {
            return mId;
        }

        void SetId(const std::string &id)
        {
            mId = id;
        }

        const Maybe <std::string> &GetName() const
        {
            return mName;
        }

        void SetName(const std::string &name)
        {
            mName = name;
        }

        const Maybe <std::string> &GetLanguage() const
        {
            return mLanguage;
        }

        void SetLanguage(const std::string &language)
        {
            mLanguage = language;
        }

        const Maybe <std::string> &GetContent() const
        {
            return mContent;
        }

        void SetContent(const std::string &content)
        {
            mContent = content;
        }

        virtual bool InitFromJsonValue(const rapidjson::Value &value)
        {
            {
                // Mandatory property
                if (!value.HasMember("Id") || !value["Id"].IsString()) return false;
                SetId(value["Id"].GetString());
            }
            {
                // Mandatory property
                if (!value.HasMember("Name") || !value["Name"].IsString()) return false;
                SetName(value["Name"].GetString());
            }
            {
                // Mandatory property
                if (!value.HasMember("Language") || !value["Language"].IsString()) return false;
                SetLanguage(value["Language"].GetString());
            }
            {
                // Mandatory property
                if (!value.HasMember("Content") || !value["Content"].IsString()) return false;
                SetContent(value["Content"].GetString());
            }

            return true;
        }

    private:
        Maybe <std::string> mId;
        Maybe <std::string> mName;
        Maybe <std::string> mLanguage;
        Maybe <std::string> mContent; // @NOTE: Type of content is client specific, change appropriately.
    };
}

#endif //READY4AIR_FREEPAGE_H
