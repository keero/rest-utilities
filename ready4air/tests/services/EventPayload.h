#ifndef READY4AIR_TESTS_SERVICES_EVENTPAYLOAD_H
#define READY4AIR_TESTS_SERVICES_EVENTPAYLOAD_H

#include "../../external/IEvent.h"
#include "../../services/DevicesService.h"

namespace ready4air
{
    class EventPayload : public IEventPayload
    {
    public:
        virtual void SetHttpStatusCode(ResponseData::HTTP_STATUS_CODE httpStatusCode)
        {
            mHttpStatusCode = httpStatusCode;
        }

        virtual void SetMessage(const STRING_T &message)
        {
            mMessage = message;
        }

        const STRING_T &GetMessage() const
        {
            return mMessage;
        }

        const ResponseData::HTTP_STATUS_CODE &GetHttpStatusCode() const
        {
            return mHttpStatusCode;
        }

    private:
        STRING_T mMessage;
        ResponseData::HTTP_STATUS_CODE mHttpStatusCode;
    };
}

#endif //READY4AIR_TESTS_SERVICES_EVENTPAYLOAD_H
