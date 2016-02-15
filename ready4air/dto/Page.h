#ifndef READY4AIR_PAGE_H
#define READY4AIR_PAGE_H

#include "../common/Maybe.h"
#include "abstract/JsonDeserializable.h"
#include "Content.h"
#include "hypermedia/Link.h"

namespace ready4air
{
    namespace dto
    {
        class Page : public JsonDeserializable
        {
        public:
            Page() : TAG("ready4air::dto::Page")
            {
            }

            virtual ~Page()
            {
            }

            const Maybe<STRING_T> &GetID() const
            {
                return mID;
            }

            void SetID(const STRING_T &ID)
            {
                mID = ID;
            }

            const Maybe<STRING_T> &GetTitle() const
            {
                return mTitle;
            }

            void SetTitle(const STRING_T &title)
            {
                mTitle = title;
            }

            const Maybe<STRING_T> &GetDescription() const
            {
                return mDescription;
            }

            void SetDescription(const STRING_T &description)
            {
                mDescription = description;
            }

            const Maybe<STRING_T> &GetVmaMessage() const
            {
                return mVmaMessage;
            }

            void SetVmaMessage(const STRING_T &vmaMessage)
            {
                mVmaMessage = vmaMessage;
            }

            const Maybe<STRING_T> &GetType() const
            {
                return mType;
            }

            void SetType(const STRING_T &type)
            {
                mType = type;
            }

            const Maybe<Content> &GetContent() const
            {
                return mContent;
            }

            void SetContent(const Content &content)
            {
                mContent = content;
            }

            const Maybe<Link> &GetSelf() const
            {
                return mSelf;
            }

            void SetSelf(const Link &self)
            {
                mSelf = self;
            }

            virtual BOOL_T InitFromJsonValue(const rapidjson::Value &value, ParseErrors &parseErrors,
                                             VECTOR_T<STRING_T> &context)
            {
                STRING_T id;
                STRING_T title;
                STRING_T description;
                STRING_T vmaMessage;
                STRING_T type;
                Content content;
                Link self;

                context.push_back(TAG);

                if (ParseString(value, "ID", true, id, parseErrors, context))
                    SetID(id);

                if (ParseString(value, "Title", false, title, parseErrors, context))
                    SetTitle(title);

                if (ParseString(value, "Description", false, description, parseErrors, context))
                    SetDescription(description);

                if (ParseString(value, "VmaMessage", false, vmaMessage, parseErrors, context))
                    SetVmaMessage(vmaMessage);

                if (ParseString(value, "Type", false, type, parseErrors, context))
                    SetType(type);

                if (ParseObject(value, "Content", true, content, parseErrors, context))
                    SetContent(content);

                if (ParseObject(value, "Self", true, self, parseErrors, context))
                    SetSelf(self);

                context.pop_back();
                return !parseErrors;
            }

        private:
            Maybe<STRING_T> mID;
            Maybe<STRING_T> mTitle;
            Maybe<STRING_T> mDescription;
            Maybe<STRING_T> mVmaMessage;
            Maybe<STRING_T> mType;
            Maybe<Content> mContent;
            Maybe<Link> mSelf;
            STRING_T TAG;
        };
    }
}

#endif //READY4AIR_PAGE_H
