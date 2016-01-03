#ifndef READY4AIR_HYPERMEDIA_FORM_H
#define READY4AIR_HYPERMEDIA_FORM_H

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

        const Link &GetAction() const
        {
            return mAction;
        }

        void SetAction(const Link &action)
        {
            mAction = action;
        }

        const std::string &GetMethod() const
        {
            return mMethod;
        }

        void SetMethod(const std::string &method)
        {
            mMethod = method;
        }

        const Link &GetBody() const
        {
            return mBody;
        }

        void SetBody(const Link &body)
        {
            mBody = body;
        }

        virtual bool InitFromJsonValue(const rapidjson::Value &value)
        {
            // Mandatory property
            Link actionLink;
            if (!value.HasMember("Action") || !value["Action"].IsObject()) return false;
            if (!actionLink.InitFromJsonValue(value["Action"])) return false;
            SetAction(actionLink);

            // Mandatory property
            if (!value.HasMember("Method") || !value["Method"].IsString()) return false;
            SetMethod(value["Method"].GetString());

            // Non-mandatory property
            if (value.HasMember("Body"))
            {
                Link bodyLink;
                if (!value["Body"].IsObject()) return false;
                if (!bodyLink.InitFromJsonValue(value["Action"])) return false;
                SetBody(bodyLink);
            }

            return true;
        }

    private:
        Link mAction;
        std::string mMethod;
        Link mBody;
    };
}

#endif //READY4AIR_HYPERMEDIA_FORM_H
