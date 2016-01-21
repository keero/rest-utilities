#ifndef READY4AIR_TESTS_SERVICES_EVENT_H
#define READY4AIR_TESTS_SERVICES_EVENT_H

#include "../../external/IEvent.h"
#include "../../services/DevicesService.h"

namespace ready4air
{
    class AuthDeviceEvent : public IEvent <services::AuthDeviceResponse>
    {
        void Emit(const services::AuthDeviceResponse &payload)
        {
            if (payload)
            {
                std::cout << payload.Just().GetMessage() << std::endl;
            }
        }
    };
}

#endif //READY4AIR_TESTS_SERVICES_EVENT_H
