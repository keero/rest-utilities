#ifndef READY4AIR_HYPERMEDIA_FORM_H
#define READY4AIR_HYPERMEDIA_FORM_H

#include "../../common/Maybe.h"
#include "../abstract/JsonDeserializable.h"
#include "Link.h"

namespace ready4air
{
    namespace dto
    {
        class Form : public JsonDeserializable
        {
        public:
            Form() : TAG("ready4air::dto::Form")
            {
            }

            virtual ~Form()
            {
            }

            const Maybe <Link> &GetAction() const
            {
                return mAction;
            }

            void SetAction(const Link &action)
            {
                mAction = action;
            }

            const Maybe <STRING_T> &GetMethod() const
            {
                return mMethod;
            }

            void SetMethod(const STRING_T &method)
            {
                mMethod = method;
            }

            const Maybe <Link> &GetBody() const
            {
                return mBody;
            }

            void SetBody(const Link &body)
            {
                mBody = body;
            }

            virtual BOOL_T InitFromJsonValue(const rapidjson::Value &value, ParseErrors &parseErrors,
                                             VECTOR_T<STRING_T> &context)
            {
                Link actionLink;
                STRING_T method;
                Link bodyLink;

                context.push_back(TAG);

                if (ParseObject(value, "Action", true, actionLink, parseErrors, context))
                    SetAction(actionLink);

                if (ParseString(value, "Method", true, method, parseErrors, context))
                    SetMethod(method);

                if (ParseObject(value, "Body", false, bodyLink, parseErrors, context))
                    SetBody(bodyLink);

                context.pop_back();
                return !parseErrors;
            }

        private:
            Maybe <Link> mAction;
            Maybe <STRING_T> mMethod;
            Maybe <Link> mBody;
            STRING_T TAG;
        };
    }
}

#endif //READY4AIR_HYPERMEDIA_FORM_H
