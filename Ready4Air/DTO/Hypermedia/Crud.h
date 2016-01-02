#ifndef REST_UTILITIES_HYPERMEDIA_CRUD_H
#define REST_UTILITIES_HYPERMEDIA_CRUD_H

#include "Link.h"
#include "Form.h"

class Crud : public JsonDeserializable
{

public:
    Crud()
    {
    }

    virtual ~Crud()
    {
    }

    const Form &GetCreateOrUpdate() const
    {
        return mCreateOrUpdate;
    }

    void SetCreateOrUpdate(const Form &createOrUpdate)
    {
        mCreateOrUpdate = createOrUpdate;
    }

    const Link &GetRead() const
    {
        return mRead;
    }

    void SetRead(const Link &read)
    {
        mRead = read;
    }

    const Form &GetDelete() const
    {
        return mDelete;
    }

    void SetDelete(const Form &aDelete)
    {
        mDelete = aDelete;
    }

    virtual bool InitFromJsonValue(const rapidjson::Value &value);

private:
    Form mCreateOrUpdate;
    Link mRead;
    Form mDelete;
};


#endif //REST_UTILITIES_HYPERMEDIA_CRUD_H
