#ifndef READY4AIR_HYPERMEDIA_FORM_H
#define READY4AIR_HYPERMEDIA_FORM_H

#include <maybe/Maybe.h>
#include "../abstract/JsonDeserializable.h"
#include "Link.h"

namespace ready4air
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

        const Maybe<Link> &GetAction() const
        {
            return mAction;
        }

        void SetAction(const Link &action)
        {
            mAction.Set(action);
        }

        const Maybe<std::string> &GetMethod() const
        {
            return mMethod;
        }

        void SetMethod(const std::string &method)
        {
            mMethod.Set(method);
        }

        const Maybe<Link> &GetBody() const
        {
            return mBody;
        }

        void SetBody(const Link &body)
        {
            mBody.Set(body);
        }

        virtual bool InitFromJsonValue(const rapidjson::Value &value)
        {
            {
                // Mandatory property
                Link actionLink;
                if (!value.HasMember("Action") || !value["Action"].IsObject() || !actionLink.InitFromJsonValue(value["Action"])) return false;
                SetAction(actionLink);
            }
            {
                // Mandatory property
                if (!value.HasMember("Method") || !value["Method"].IsString()) return false;
                SetMethod(value["Method"].GetString());
            }
            {
                // Non-mandatory property
                if (value.HasMember("Body"))
                {
                    Link bodyLink;
                    if (!value["Body"].IsObject() || !bodyLink.InitFromJsonValue(value["Action"])) return false;
                    SetBody(bodyLink);
                }
            }

            return true;
        }

    private:
        Maybe<Link> mAction;
        Maybe<std::string> mMethod;
        Maybe<Link> mBody;
    };
}

#endif //READY4AIR_HYPERMEDIA_FORM_H
