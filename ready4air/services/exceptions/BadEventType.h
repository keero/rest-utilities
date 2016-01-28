#ifndef READY4AIR_SERVICES_BADEVENTTYPE_H
#define READY4AIR_SERVICES_BADEVENTTYPE_H

#include <exception>

namespace ready4air
{
    class BadEventType : public std::exception
    {
        virtual const INT8_T *what() const throw()
        {
            return "Template class EVENT_TYPE must implement ready4air::IEvent";
        }
    };
}

#endif //READY4AIR_SERVICES_BADEVENTTYPE_H
