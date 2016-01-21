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

#define READY4AIR_SERVICE_ROOT_HREF "https://pp.sfanytime.com/Neonstingray.Nettv4.RestApi/api/devices{?apiKey,manufacturer,model,udid}"

namespace ready4air
{

    namespace services
    {
        template <typename HTTP_CLIENT_TYPE, typename EVENT_TYPE>
        class Root
        {
        public:
            Root()
            {
                if (!std::is_base_of<IHttpClient, HTTP_CLIENT_TYPE>::value) throw mBadHttpClientType;
                if (!std::is_base_of<IEvent <AuthDeviceResponse>, EVENT_TYPE>::value) throw mBadEventType;
            }

            virtual ~Root()
            {
            }

            void Init(const std::string &serviceRootURL)
            {
                mServiceRoot.SetHref(serviceRootURL);
                mServiceRoot.SetTemplated(true);
                mServiceRoot.SetWithCredentials(true);
            }

            bool AuthDevice(DevicesService <HTTP_CLIENT_TYPE, EVENT_TYPE> &devicesService, const std::string &apiKey, const std::string &manufacturer, const std::string &model, const std::string &udid)
            {
                IHttpClient *pClient = &devicesService;
                RequestData requestData;

                mServiceRoot.SetParam("apiKey", apiKey);
                mServiceRoot.SetParam("manufacturer", manufacturer);
                mServiceRoot.SetParam("model", model);
                mServiceRoot.SetParam("udid", udid);

                requestData = mRequestService.CreateRequestFromLink(DevicesService <HTTP_CLIENT_TYPE, EVENT_TYPE>::AUTH_DEVICE_REQUEST, mServiceRoot);

                pClient->DoRequest(requestData);
                return true;
            }

        private:
            dto::Link mServiceRoot;
            RequestService mRequestService;
            BadHttpClientType mBadHttpClientType;
            BadEventType mBadEventType;
        };
    }
}

#endif //READY4AIR_SERVICES_ROOT_H
