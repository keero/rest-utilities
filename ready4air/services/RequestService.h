#ifndef READY4AIR_SERVICES_REQUESTSERVICE_H
#define READY4AIR_SERVICES_REQUESTSERVICE_H


#include "../external/RequestData.h"
#include "../dto/hypermedia/Form.h"

namespace ready4air
{
    namespace services
    {
        class RequestService
        {
        public:
            static const RequestData CreateRequestFromLink(Callee callee, dto::Link &link) const
            {
                RequestData requestData;
                requestData.SetURI(link.GetExpandedUrl());
                requestData.SetMethod("GET");
                requestData.SetWithCredentials(link.GetWithCredentials() ? link.GetWithCredentials().Just() : false);
                requestData.SetCallee(callee);
                return requestData;
            }

            static const RequestData CreateRequestFromForm(Callee callee, dto::Form &form) const
            {
                RequestData requestData;
                if (form.GetAction())
                {
                    requestData.SetURI(form.GetAction().Just().GetExpandedUrl());
                    requestData.SetWithCredentials(
                            form.GetAction().Just().GetWithCredentials()
                            ? form.GetAction().Just().GetWithCredentials().Just() : false);
                }
                requestData.SetMethod(form.GetMethod() ? form.GetMethod().Just() : "");
                requestData.SetCallee(callee);
                return requestData;
            }
        };
    }
}

#endif //READY4AIR_SERVICES_REQUESTSERVICE_H
