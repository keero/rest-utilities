#ifndef READY4AIR_FILEBASE_H
#define READY4AIR_FILEBASE_H

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

        int GetTypeId() const
        {
            return mTypeId;
        }

        void SetTypeId(int typeId)
        {
            mTypeId = typeId;
        }

        const std::string &GetTypeName() const
        {
            return mTypeName;
        }

        void SetTypeName(const std::string &typeName)
        {
            mTypeName = typeName;
        }

        const Link &GetLink() const
        {
            return mLink;
        }

        void SetLink(const Link &link)
        {
            mLink = link;
        }

    private:
        int mTypeId;
        std::string mTypeName;
        Link mLink;
    };
}

#endif //READY4AIR_FILEBASE_H
