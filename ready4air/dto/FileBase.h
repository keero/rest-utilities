#ifndef READY4AIR_FILEBASE_H
#define READY4AIR_FILEBASE_H

#include "../common/Maybe.h"
#include "abstract/JsonDeserializable.h"
#include "hypermedia/Link.h"

namespace ready4air
{
    namespace dto
    {
        class FileBase : public JsonDeserializable
        {
        public:
            FileBase() : TAG("ready4air::dto::FileBase")
            {
            }

            virtual ~FileBase()
            {
            }

            const Maybe<int> &GetTypeId() const
            {
                return mTypeId;
            }

            void SetTypeId(int typeId)
            {
                mTypeId = typeId;
            }

            const Maybe <STRING_T> &GetTypeName() const
            {
                return mTypeName;
            }

            void SetTypeName(const STRING_T &typeName)
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

            virtual BOOL_T InitFromJsonValue(const rapidjson::Value &value, ParseErrors &parseErrors,
                                             VECTOR_T<STRING_T> &context)
            {
                INT32_T typeId;
                STRING_T typeName;
                Link link;

                context.push_back(TAG);

                if (ParseInt(value, "TypeId", true, typeId, parseErrors, context))
                    SetTypeId(typeId);

                if (ParseString(value, "TypeName", true, typeName, parseErrors, context))
                    SetTypeName(typeName);

                if (ParseObject(value, "Link", true, link, parseErrors, context))
                    SetLink(link);

                context.pop_back();
                return !parseErrors;
            }

        private:
            Maybe<int> mTypeId;
            Maybe <STRING_T> mTypeName;
            Maybe <Link> mLink;
            STRING_T TAG;
        };
    }
}

#endif //READY4AIR_FILEBASE_H
