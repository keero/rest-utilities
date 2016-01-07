#ifndef READY4AIR_HYPERMEDIA_CRUD_H
#define READY4AIR_HYPERMEDIA_CRUD_H

#include "../../maybe/Maybe.h"
#include "../abstract/JsonDeserializable.h"
#include "Form.h"
#include "Link.h"

namespace ready4air
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

        const Maybe<Form> &GetCreateOrUpdate() const
        {
            return mCreateOrUpdate;
        }

        void SetCreateOrUpdate(const Form &createOrUpdate)
        {
            mCreateOrUpdate = createOrUpdate;
        }

        const Maybe<Link> &GetRead() const
        {
            return mRead;
        }

        void SetRead(const Link &read)
        {
            mRead = read;
        }

        const Maybe<Form> &GetDelete() const
        {
            return mDelete;
        }

        void SetDelete(const Form &aDelete)
        {
            mDelete = aDelete;
        }

        virtual bool InitFromJsonValue(const rapidjson::Value &value)
        {
            {
                // Non-mandatory property
                if (value.HasMember("CreateOrUpdate"))
                {
                    Form createOrUpdateForm;
                    if (!value["CreateOrUpdate"].IsObject() || !createOrUpdateForm.InitFromJsonValue(value["CreateOrUpdate"])) return false;
                    SetCreateOrUpdate(createOrUpdateForm);
                }
            }
            {
                // Non-mandatory property
                if (value.HasMember("Read"))
                {
                    Link readLink;
                    if (!value["Read"].IsObject() || !readLink.InitFromJsonValue(value["Read"])) return false;
                    SetRead(readLink);
                }
            }
            {
                // Non-mandatory property
                if (value.HasMember("Delete"))
                {
                    Form deleteForm;
                    if (!value["Delete"].IsObject() || !deleteForm.InitFromJsonValue(value["Delete"])) return false;
                    SetDelete(deleteForm);
                }
            }

            return true;
        }

    private:
        Maybe<Form> mCreateOrUpdate;
        Maybe<Link> mRead;
        Maybe<Form> mDelete;
    };
}

#endif //READY4AIR_HYPERMEDIA_CRUD_H
