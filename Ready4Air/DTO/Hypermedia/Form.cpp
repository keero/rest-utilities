#include "Form.h"

bool Form::InitFromJsonValue(const rapidjson::Value &value)
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
