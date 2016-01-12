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

        virtual bool InitFromJsonValue(const rapidjson::Value &value, ParseErrors &parseErrors)
        {
            int typeId;
            std::string typeName;
            Link link;

            if (ParseInt(value, "TypeId", true, typeId, parseErrors))
                SetTypeId(typeId);

            if (ParseString(value, "TypeName", true, typeName, parseErrors))
                SetTypeName(typeName);

            if (ParseObject(value, "Link", true, link, parseErrors))
                SetLink(link);

            return !parseErrors;
        }

    private:
        Maybe <int> mTypeId;
        Maybe <std::string> mTypeName;
        Maybe <Link> mLink;
    };
}

#endif //READY4AIR_FILEBASE_H
