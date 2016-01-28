#ifndef READY4AIR_TESTS_SERVICES_EVENT_H
#define READY4AIR_TESTS_SERVICES_EVENT_H

#include "../../external/IEvent.h"
#include "../../services/DevicesService.h"
#include "EventPayload.h"

namespace ready4air
{
    class AuthDeviceEvent : public IEvent <EventPayload>
    {
        void Emit(const EventPayload &payload)
        {
            std::cout << payload.GetMessage() << std::endl;
        }
    };
}

#endif //READY4AIR_TESTS_SERVICES_EVENT_H
