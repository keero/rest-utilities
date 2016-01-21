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
            Form()
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

            const Maybe <std::string> &GetMethod() const
            {
                return mMethod;
            }

            void SetMethod(const std::string &method)
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

            virtual bool InitFromJsonValue(const rapidjson::Value &value, ParseErrors &parseErrors)
            {
                Link actionLink;
                std::string method;
                Link bodyLink;

                if (ParseObject(value, "Action", true, actionLink, parseErrors))
                    SetAction(actionLink);

                if (ParseString(value, "Method", true, method, parseErrors))
                    SetMethod(method);

                if (ParseObject(value, "Body", false, bodyLink, parseErrors))
                    SetBody(bodyLink);

                return !parseErrors;
            }

        private:
            Maybe <Link> mAction;
            Maybe <std::string> mMethod;
            Maybe <Link> mBody;
        };
    }
}

#endif //READY4AIR_HYPERMEDIA_FORM_H
