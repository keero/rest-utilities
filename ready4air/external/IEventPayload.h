#ifndef READ4AIR_IEVENTPAYLOAD_H
#define READ4AIR_IEVENTPAYLOAD_H

#include "ResponseData.h"

namespace ready4air
{
    class IEventPayload
    {
    public:
        virtual void SetHttpStatusCode(ResponseData::HTTP_STATUS_CODE httpStatusCode) = 0;
        virtual void SetMessage(const std::string &message) = 0;
    };
}

#endif //READ4AIR_IEVENTPAYLOAD_H
