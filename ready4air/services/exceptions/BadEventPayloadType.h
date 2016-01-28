#ifndef READY4AIR_SERVICES_BADEVENTPAYLOADTYPE_H
#define READY4AIR_SERVICES_BADEVENTPAYLOADTYPE_H

#include <exception>

namespace ready4air
{
    class BadEventPayloadType : public std::exception
    {
        virtual const INT8_T *what() const throw()
        {
            return "Template class EVENT_PAYLOAD_TYPE must implement ready4air::IEventPayload";
        }
    };
}

#endif //READY4AIR_SERVICES_BADEVENTPAYLOADTYPE_H
