#ifndef READY4AIR_HYPERMEDIA_CRUD_H
#define READY4AIR_HYPERMEDIA_CRUD_H

#include "../../common/Maybe.h"
#include "../abstract/JsonDeserializable.h"
#include "Form.h"
#include "Link.h"

namespace ready4air
{
    namespace dto
    {
        class Crud : public JsonDeserializable
        {
        public:
            Crud()
            {
            }

            virtual ~Crud()
            {
            }

            const Maybe <Form> &GetCreateOrUpdate() const
            {
                return mCreateOrUpdate;
            }

            void SetCreateOrUpdate(const Form &createOrUpdate)
            {
                mCreateOrUpdate = createOrUpdate;
            }

            const Maybe <Link> &GetRead() const
            {
                return mRead;
            }

            void SetRead(const Link &read)
            {
                mRead = read;
            }

            const Maybe <Form> &GetDelete() const
            {
                return mDelete;
            }

            void SetDelete(const Form &aDelete)
            {
                mDelete = aDelete;
            }

            virtual BOOL_T InitFromJsonValue(const rapidjson::Value &value, ParseErrors &parseErrors)
            {
                Form createOrUpdateForm;
                Link readLink;
                Form deleteForm;

                if (ParseObject(value, "CreateOrUpdate", false, createOrUpdateForm, parseErrors))
                    SetCreateOrUpdate(createOrUpdateForm);

                if (ParseObject(value, "Read", false, readLink, parseErrors))
                    SetRead(readLink);

                if (ParseObject(value, "Delete", false, deleteForm, parseErrors))
                    SetDelete(deleteForm);

                return !parseErrors;
            }

        private:
            Maybe <Form> mCreateOrUpdate;
            Maybe <Link> mRead;
            Maybe <Form> mDelete;
        };
    }
}

#endif //READY4AIR_HYPERMEDIA_CRUD_H
