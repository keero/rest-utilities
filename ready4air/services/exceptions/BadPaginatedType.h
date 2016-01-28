#ifndef READY4AIR_SERVICES_BADPAGINATEDTYPE_H
#define READY4AIR_SERVICES_BADPAGINATEDTYPE_H

#include <exception>

namespace ready4air
{
    class BadPaginatedType : public std::exception
    {
        virtual const INT8_T *what() const throw()
        {
            return "Template class SERVICE_TYPE must implement ready4air::dto::IJsonDeserializable";
        }
    };
}

#endif //READY4AIR_SERVICES_BADPAGINATEDTYPE_H
