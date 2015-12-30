#include "Link.h"

bool Link::CreateFromJsonString(const string& json, Link& link)
{
    rapidjson::Document d;
    
    if (d.Parse(json.c_str()).HasParseError() || !d.IsObject()) return false;
    
    return CreateFromJson(d, link);
}

bool Link::CreateFromJson(const rapidjson::Value& value, Link& link)
{
    // Mandatory property
    if (!value.HasMember("Href") || !value["Href"].IsString()) return false;
    link.SetHref(value["Href"].GetString());
    
    // Non-mandatory property
    if (value.HasMember("Templated") && !value["Templated"].IsBool()) return false;
    if (value.HasMember("Templated")) link.SetTemplated(value["Templated"].GetBool());
        
    // Non-mandatory property
    if (value.HasMember("WithCredentials") && !value["WithCredentials"].IsBool()) return false;
    if (value.HasMember("WithCredentials")) link.SetWithCredentials(value["WithCredentials"].GetBool());

    return true;
}