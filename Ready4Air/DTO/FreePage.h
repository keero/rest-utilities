#ifndef READY4AIR_FREEPAGE_H
#define READY4AIR_FREEPAGE_H

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

        const std::string &GetId() const
        {
            return mId;
        }

        void SetId(const std::string &id)
        {
            mId = id;
        }

        const std::string &GetName() const
        {
            return mName;
        }

        void SetName(const std::string &name)
        {
            mName = name;
        }

        const std::string &GetLanguage() const
        {
            return mLanguage;
        }

        void SetLanguage(const std::string &language)
        {
            mLanguage = language;
        }

        const std::string &GetContent() const
        {
            return mContent;
        }

        void SetContent(const std::string &content)
        {
            mContent = content;
        }

    private:
        std::string mId;
        std::string mName;
        std::string mLanguage;
        std::string mContent; // @NOTE: Type of content is client specific, change appropriately.
    };
}

#endif //READY4AIR_FREEPAGE_H
