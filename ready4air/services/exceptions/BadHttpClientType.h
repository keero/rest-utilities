#ifndef READY4AIR_SERVICES_BADHTTPCLIENTTYPE_H
#define READY4AIR_SERVICES_BADHTTPCLIENTTYPE_H

#include <exception>

namespace ready4air
{
    class BadHttpClientType : public std::exception
    {
        virtual const INT8_T *what() const throw()
        {
            return "Template class HTTP_CLIENT_TYPE must implement ready4air::IHttpClient";
        }
    };
}

#endif //READY4AIR_SERVICES_BADHTTPCLIENTTYPE_H
