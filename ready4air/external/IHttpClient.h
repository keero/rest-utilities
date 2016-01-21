#ifndef READY4AIR_IHTTPCLIENT_H
#define READY4AIR_IHTTPCLIENT_H

#include "RequestData.h"
#include "ResponseData.h"

namespace ready4air
{
    class IHttpClient
    {
    public:
        virtual void DoRequest (const RequestData &requestData) = 0;

    protected:
        virtual void OnReceivedResponse(const RequestData &requestData, const ResponseData &responseData) = 0;
    };
}

#endif //READY4AIR_IHTTPCLIENT_H
