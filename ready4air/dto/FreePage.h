#ifndef READY4AIR_FREEPAGE_H
#define READY4AIR_FREEPAGE_H

#include "../common/Maybe.h"
#include "abstract/JsonDeserializable.h"

namespace ready4air
{
    namespace dto
    {
        class FreePage : public JsonDeserializable
        {
        public:
            FreePage() : TAG("ready4air::dto::FreePage")
            {
            }

            virtual ~FreePage()
            {
            }

            const Maybe <STRING_T> &GetId() const
            {
                return mId;
            }

            void SetId(const STRING_T &id)
            {
                mId = id;
            }

            const Maybe <STRING_T> &GetName() const
            {
                return mName;
            }

            void SetName(const STRING_T &name)
            {
                mName = name;
            }

            const Maybe <STRING_T> &GetLanguage() const
            {
                return mLanguage;
            }

            void SetLanguage(const STRING_T &language)
            {
                mLanguage = language;
            }

            const Maybe <STRING_T> &GetContent() const
            {
                return mContent;
            }

            void SetContent(const STRING_T &content)
            {
                mContent = content;
            }

            virtual BOOL_T InitFromJsonValue(const rapidjson::Value &value, ParseErrors &parseErrors)
            {
                STRING_T id;
                STRING_T name;
                STRING_T language;
                STRING_T content;

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
            Maybe <STRING_T> mId;
            Maybe <STRING_T> mName;
            Maybe <STRING_T> mLanguage;
            Maybe <STRING_T> mContent; // @NOTE: Type of content is client specific, change appropriately.
            const STRING_T TAG;
        };
    }
}

#endif //READY4AIR_FREEPAGE_H
