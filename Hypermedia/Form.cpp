#include "Form.h"

bool Form::CreateFromJsonString(const string& json, Form& form)
{
    rapidjson::Document d;
    
    if (d.Parse(json.c_str()).HasParseError() || !d.IsObject()) return false;
    
    return CreateFromJson(d, form);
}

bool Form::CreateFromJson(const rapidjson::Value& value, Form& form)
{
    // Mandatory property
    Link actionLink;
    if (!value.HasMember("Action") || !value["Action"].IsObject()) return false;
    if (!Link::CreateFromJson(value["Action"], actionLink)) return false;
    form.SetAction(actionLink);
    
    // Mandatory property
    if (!value.HasMember("Method") || !value["Method"].IsString()) return false;
    form.SetMethod(value["Method"].GetString());
    
    // Non-mandatory property
    Link bodyLink;
    if (value.HasMember("Body") && !value["Body"].IsObject()) return false;
    if (!Link::CreateFromJson(value["Action"], bodyLink)) return false;
    form.SetBody(bodyLink);
    
    return true;
}