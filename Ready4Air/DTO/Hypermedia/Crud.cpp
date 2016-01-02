#include "Crud.h"

bool Crud::InitFromJsonValue(const rapidjson::Value &value)
{
    // Non-mandatory property
    if (value.HasMember("CreateOrUpdate"))
    {
        Form createOrUpdateForm;
        if (!value["CreateOrUpdate"].IsObject()) return false;
        if (!createOrUpdateForm.InitFromJsonValue(value["CreateOrUpdate"])) return false;
        SetCreateOrUpdate(createOrUpdateForm);
    }

    // Non-mandatory property
    if (value.HasMember("Read"))
    {
        Link readLink;
        if (!value["Read"].IsObject()) return false;
        if (!readLink.InitFromJsonValue(value["Read"])) return false;
        SetRead(readLink);
    }

    // Non-mandatory property
    if (value.HasMember("Delete"))
    {
        Form deleteForm;
        if (!value["Delete"].IsObject()) return false;
        if (!deleteForm.InitFromJsonValue(value["Delete"])) return false;
        SetDelete(deleteForm);
    }

    return true;
}
