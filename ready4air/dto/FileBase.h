#ifndef READY4AIR_FILEBASE_H
#define READY4AIR_FILEBASE_H

#include "../maybe/Maybe.h"
#include "abstract/JsonDeserializable.h"
#include "hypermedia/Link.h"

namespace ready4air
{
    class FileBase : public JsonDeserializable
    {
    public:
        FileBase()
        {
        }

        virtual ~FileBase()
        {
        }

        const Maybe <int> &GetTypeId() const
        {
            return mTypeId;
        }

        void SetTypeId(int typeId)
        {
            mTypeId = typeId;
        }

        const Maybe <std::string> &GetTypeName() const
        {
            return mTypeName;
        }

        void SetTypeName(const std::string &typeName)
        {
            mTypeName = typeName;
        }

        const Maybe <Link> &GetLink() const
        {
            return mLink;
        }

        void SetLink(const Link &link)
        {
            mLink = link;
        }

        virtual bool InitFromJsonValue(const rapidjson::Value &value)
        {
            {
                // Mandatory property
                if (!value.HasMember("TypeId") || !value["TypeId"].IsInt()) return false;
                SetTypeId(value["TypeId"].GetInt());
            }
            {
                // Mandatory property
                if (!value.HasMember("TypeName") || !value["TypeName"].IsString()) return false;
                SetTypeName(value["TypeName"].GetString());
            }
            {
                // Mandatory property
                Link link;
                if (!value.HasMember("Link") || !value["Link"].IsObject() || !link.InitFromJsonValue(value["Link"])) return false;
                SetLink(link);
            }

            return true;
        }

    private:
        Maybe <int> mTypeId;
        Maybe <std::string> mTypeName;
        Maybe <Link> mLink;
    };
}

#endif //READY4AIR_FILEBASE_H
