#ifndef READY4AIR_PAGE_H
#define READY4AIR_PAGE_H

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

        const std::string &GetID() const
        {
            return mID;
        }

        void SetID(const std::string &ID)
        {
            mID = ID;
        }

        const std::string &GetTitle() const
        {
            return mTitle;
        }

        void SetTitle(const std::string &title)
        {
            mTitle = title;
        }

        const std::string &GetDescription() const
        {
            return mDescription;
        }

        void SetDescription(const std::string &description)
        {
            mDescription = description;
        }

        const std::string &GetVmaMessage() const
        {
            return mVmaMessage;
        }

        void SetVmaMessage(const std::string &vmaMessage)
        {
            mVmaMessage = vmaMessage;
        }

        const std::string &GetType() const
        {
            return mType;
        }

        void SetType(const std::string &type)
        {
            mType = type;
        }

        const Content &GetContent() const
        {
            return mContent;
        }

        void SetContent(const Content &content)
        {
            mContent = content;
        }

        const Link &GetSelf() const
        {
            return mSelf;
        }

        void SetSelf(const Link &self)
        {
            mSelf = self;
        }

        virtual bool InitFromJsonValue(const rapidjson::Value &value)
        {
            return false;
        }

    private:
        std::string mID;
        std::string mTitle;
        std::string mDescription;
        std::string mVmaMessage;
        std::string mType;
        Content mContent;
        Link mSelf;
    };
}

#endif //READY4AIR_PAGE_H
