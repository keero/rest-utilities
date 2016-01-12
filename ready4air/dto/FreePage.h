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

        virtual bool InitFromJsonValue(const rapidjson::Value &value, ParseErrors &parseErrors)
        {
            std::string id;
            std::string name;
            std::string language;
            std::string content;

            if (ParseString(value, "Id", true, id, parseErrors))
                SetId(id);

            if (ParseString(value, "Name", true, name, parseErrors))
                SetName(name);

            if (ParseString(value, "Language", true, language, parseErrors))
                SetLanguage(language);

            if (ParseString(value, "Content", true, content, parseErrors))
                SetContent(content);

            return !parseErrors;
        }

    private:
        Maybe <std::string> mId;
        Maybe <std::string> mName;
        Maybe <std::string> mLanguage;
        Maybe <std::string> mContent; // @NOTE: Type of content is client specific, change appropriately.
    };
}

#endif //READY4AIR_FREEPAGE_H
