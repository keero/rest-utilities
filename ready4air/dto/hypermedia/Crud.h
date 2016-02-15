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
            Crud() : TAG("ready4air::dto::Crud")
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

            virtual BOOL_T InitFromJsonValue(const rapidjson::Value &value, ParseErrors &parseErrors,
                                             VECTOR_T<STRING_T> &context)
            {
                Form createOrUpdateForm;
                Link readLink;
                Form deleteForm;

                context.push_back(TAG);

                if (ParseObject(value, "CreateOrUpdate", false, createOrUpdateForm, parseErrors, context))
                    SetCreateOrUpdate(createOrUpdateForm);

                if (ParseObject(value, "Read", false, readLink, parseErrors, context))
                    SetRead(readLink);

                if (ParseObject(value, "Delete", false, deleteForm, parseErrors, context))
                    SetDelete(deleteForm);

                context.pop_back();
                return !parseErrors;
            }

        private:
            Maybe <Form> mCreateOrUpdate;
            Maybe <Link> mRead;
            Maybe <Form> mDelete;
            STRING_T TAG;
        };
    }
}

#endif //READY4AIR_HYPERMEDIA_CRUD_H
