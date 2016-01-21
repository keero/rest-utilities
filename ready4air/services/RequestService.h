#ifndef READY4AIR_SERVICES_REQUESTSERVICE_H
#define READY4AIR_SERVICES_REQUESTSERVICE_H


#include "../external/RequestData.h"
#include "../dto/hypermedia/Link.h"

namespace ready4air
{
    namespace services
    {
        class RequestService
        {
        public:
            const RequestData CreateRequestFromLink(int callee, const dto::Link &link) const
            {
                RequestData requestData;
                requestData.SetURI(link.GetExpandedUrl());
                requestData.SetMethod("GET");
                requestData.SetWithCredentials(link.GetWithCredentials() ? link.GetWithCredentials().Just() : false);
                requestData.SetCallee(callee);
                return requestData;
            }
        };
    }
}

#endif //READY4AIR_SERVICES_REQUESTSERVICE_H
