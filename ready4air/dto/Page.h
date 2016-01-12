#ifndef READY4AIR_PAGE_H
#define READY4AIR_PAGE_H

#include "../maybe/Maybe.h"
#include "abstract/JsonDeserializable.h"
#include "Content.h"
#include "hypermedia/Link.h"

namespace ready4air
{
    class Page : public JsonDeserializable
    {
    public:
        Page()
        {
        }

        virtual ~Page()
        {
        }

        const Maybe <std::string> &GetID() const
        {
            return mID;
        }

        void SetID(const std::string &ID)
        {
            mID = ID;
        }

        const Maybe <std::string> &GetTitle() const
        {
            return mTitle;
        }

        void SetTitle(const std::string &title)
        {
            mTitle = title;
        }

        const Maybe <std::string> &GetDescription() const
        {
            return mDescription;
        }

        void SetDescription(const std::string &description)
        {
            mDescription = description;
        }

        const Maybe <std::string> &GetVmaMessage() const
        {
            return mVmaMessage;
        }

        void SetVmaMessage(const std::string &vmaMessage)
        {
            mVmaMessage = vmaMessage;
        }

        const Maybe <std::string> &GetType() const
        {
            return mType;
        }

        void SetType(const std::string &type)
        {
            mType = type;
        }

        const Maybe <Content> &GetContent() const
        {
            return mContent;
        }

        void SetContent(const Content &content)
        {
            mContent = content;
        }

        const Maybe <Link> &GetSelf() const
        {
            return mSelf;
        }

        void SetSelf(const Link &self)
        {
            mSelf = self;
        }

        virtual bool InitFromJsonValue(const rapidjson::Value &value, ParseErrors &parseErrors)
        {
            std::string id;
            std::string title;
            std::string description;
            std::string vmaMessage;
            std::string type;
            Content content;
            Link self;

            if (ParseString(value, "ID", true, id, parseErrors))
                SetID(id);

            if (ParseString(value, "Title", false, title, parseErrors))
                SetTitle(title);

            if (ParseString(value, "Description", false, description, parseErrors))
                SetDescription(description);

            if (ParseString(value, "VmaMessage", false, vmaMessage, parseErrors))
                SetVmaMessage(vmaMessage);

            if (ParseString(value, "Type", false, type, parseErrors))
                SetType(type);

            if (ParseObject(value, "Content", true, content, parseErrors))
                SetContent(content);

            if (ParseObject(value, "Self", true, self, parseErrors))
                SetSelf(self);

            return !parseErrors;
        }

    private:
        Maybe <std::string> mID;
        Maybe <std::string> mTitle;
        Maybe <std::string> mDescription;
        Maybe <std::string> mVmaMessage;
        Maybe <std::string> mType;
        Maybe <Content> mContent;
        Maybe <Link> mSelf;
    };
}

#endif //READY4AIR_PAGE_H
