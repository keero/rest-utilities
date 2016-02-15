#ifndef READY4AIR_HELP_H
#define READY4AIR_HELP_H

#include "../common/Maybe.h"
#include "abstract/JsonDeserializable.h"
#include "hypermedia/Link.h"

namespace ready4air
{
    namespace dto
    {
        class Help : public JsonDeserializable
        {
        public:
            Help() : TAG("ready4air::dto::Help")
            {
            }

            virtual ~Help()
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

            const Maybe <STRING_T> &GetTitle() const
            {
                return mTitle;
            }

            void SetTitle(const STRING_T &title)
            {
                mTitle = title;
            }

            const Maybe <STRING_T> &GetBody() const
            {
                return mBody;
            }

            void SetBody(const STRING_T &body)
            {
                mBody = body;
            }

            const Maybe <Link> &GetSelf() const
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
                STRING_T body;
                Link self;

                context.push_back(TAG);

                if (ParseString(value, "Id", true, id, parseErrors, context))
                    SetId(id);

                if (ParseString(value, "Title", true, title, parseErrors, context))
                    SetTitle(title);

                if (ParseString(value, "Body", true, body, parseErrors, context))
                    SetBody(body);

                if (ParseObject(value, "Self", true, self, parseErrors, context))
                    SetSelf(self);

                context.pop_back();
                return !parseErrors;
            }

        private:
            Maybe <STRING_T> mId;
            Maybe <STRING_T> mTitle;
            Maybe <STRING_T> mBody;
            Maybe <Link> mSelf;
            STRING_T TAG;
        };
    }
}

#endif //READY4AIR_HELP_H
