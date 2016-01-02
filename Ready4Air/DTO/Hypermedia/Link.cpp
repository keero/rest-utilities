#include "Link.h"

bool Link::InitFromJsonValue(const rapidjson::Value &value)
{
    // Mandatory property
    if (!value.HasMember("Href") || !value["Href"].IsString()) return false;
    SetHref(value["Href"].GetString());

    // Non-mandatory property
    if (value.HasMember("Templated") && !value["Templated"].IsBool()) return false;
    if (value.HasMember("Templated")) SetTemplated(value["Templated"].GetBool());

    // Non-mandatory property
    if (value.HasMember("WithCredentials"))
    {
        if (!value["WithCredentials"].IsBool()) return false;
        SetWithCredentials(value["WithCredentials"].GetBool());
    }

    return true;
}
