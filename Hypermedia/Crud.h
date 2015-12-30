#ifndef REST_UTILITIES_HYPERMEDIA_CRUD_H
#define REST_UTILITIES_HYPERMEDIA_CRUD_H

#include "Link.h"
#include "Form.h"

class Crud
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

    const Form &GetADelete() const
    {
        return mDelete;
    }

    void SetADelete(const Form &aDelete)
    {
        mDelete = aDelete;
    }

private:
    Form mCreateOrUpdate;
    Link mRead;
    Form mDelete;
};


#endif //REST_UTILITIES_HYPERMEDIA_CRUD_H
