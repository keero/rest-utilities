#ifndef READY4AIR_SERVICES_ROOT_H
#define READY4AIR_SERVICES_ROOT_H

#include "../dto/hypermedia/Link.h"
#include "../external/IHttpClient.h"
#include "../external/IEvent.h"
#include "../external/RequestData.h"
#include "../external/ResponseData.h"
#include "../common/Either.h"
#include "../dto/hypermedia/Form.h"
#include "../dto/Device.h"
#include "DevicesService.h"
#include "RequestService.h"
#include "Error.h"
#include "exceptions/BadEventType.h"
#include "exceptions/BadHttpClientType.h"

namespace ready4air
{

    namespace services
    {
        class Root
        {
        private:

        public:
            Root() : TAG("ready4air::services::Root")
            {
            }

            virtual ~Root()
            {
            }

            void Init(const STRING_T &serviceRootURL)
            {
                mServiceRoot.SetHref(serviceRootURL);
                mServiceRoot.SetTemplated(true);
                mServiceRoot.SetWithCredentials(true);
            }

            BOOL_T AuthDevice(IHttpClient *pClient, const STRING_T &apiKey, const STRING_T &manufacturer, const STRING_T &model, const STRING_T &udid)
            {
                RequestData requestData;

                mServiceRoot.SetParam("apiKey", apiKey);
                mServiceRoot.SetParam("manufacturer", manufacturer);
                mServiceRoot.SetParam("model", model);
                mServiceRoot.SetParam("udid", udid);

                requestData = RequestService::CreateRequestFromLink(ROOT_AUTHDEVICE_REQUEST, mServiceRoot);

                pClient->DoRequest(requestData);
                return true;
            }

        private:
            dto::Link mServiceRoot;
            STRING_T TAG;
        };
    }
}

#endif //READY4AIR_SERVICES_ROOT_H
