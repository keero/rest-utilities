#ifndef READY4AIR_TESTS_SERVICES_HTTPCLIENT_H
#define READY4AIR_TESTS_SERVICES_HTTPCLIENT_H

#include "../../external/IHttpClient.h"

namespace ready4air
{
    class HttpClient : public IHttpClient
    {
    public:
        HttpClient()
        {
        }

        virtual ~HttpClient()
        {
        }

        void DoRequest(const RequestData &requestData)
        {
        }

        virtual void OnReceivedResponse(const RequestData &requestData, const ResponseData &responseData) = 0;
    };
}

#endif //READY4AIR_TESTS_SERVICES_HTTPCLIENT_H
