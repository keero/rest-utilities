#ifndef READY4AIR_SERVICES_HELPSSERVICE_H
#define READY4AIR_SERVICES_HELPSSERVICE_H

#include "../dto/Help.h"
#include "../external/IHttpClient.h"
#include "../external/IEvent.h"
#include "../external/RequestData.h"
#include "../external/ResponseData.h"
#include "RequestService.h"
#include "Error.h"
#include "exceptions/BadEventType.h"
#include "exceptions/BadHttpClientType.h"

namespace ready4air
{
    namespace services
    {
        typedef Maybe <Error> HelpsResponse;

        template <typename HTTP_CLIENT_TYPE, typename EVENT_TYPE>
        class HelpsService : public HTTP_CLIENT_TYPE
        {
        public:
            typedef enum {
                HELPS_REQUEST = 1,
                SELF_HELPS_REQUEST
            } _;

            HelpsService()
            {
                if (!std::is_base_of<IHttpClient, HTTP_CLIENT_TYPE>::value) throw mBadHttpClientType;
                if (!std::is_base_of<IEvent <HelpsResponse>, EVENT_TYPE>::value) throw mBadEventType;
            }

            virtual ~HelpsService()
            {
            }

            const Maybe<dto::Help> &GetHelp() const
            {
                return mHelp;
            }

            EVENT_TYPE GetHelpsEvent() const
            {
                return mHelpsEvent;
            }

        protected:
            void SetHelp(const dto::Help &help)
            {
                mHelp = help;
            }

            const RequestService &GetRequestService() const
            {
                return mRequestService;
            }

            virtual void OnReceivedResponse(const RequestData &requestData, const ResponseData &responseData)
            {
                dto::ParseErrors parseErrors;
                HelpsResponse payload;
                Error error;
                IEvent <HelpsResponse> *pEvent = GetHelpsEvent();

                error.SetHttpStatusCode(responseData.GetStatusCode());

                if (responseData.GetStatusCode() == ResponseData::HTTP_STATUS_CODE_OK)
                {
                    dto::Help help;
                    if (help.InitFromJsonString(responseData.GetBody(), parseErrors))
                    {
                        SetHelp(help);
                    }
                    else
                    {
                        error.SetMessage("Failed to parse Help.");
                        error.SetParseErrors(parseErrors);
                        payload = error;
                    }
                    pEvent->Emit(payload);
                }
                else
                {
                    // @TODO: Add error reporting
                    error.SetMessage("Unexpected helps response.");
                    payload = error;
                    pEvent->Emit(payload);
                }
            }


        private:
            EVENT_TYPE mHelpsEvent;
            Maybe <dto::Help> mHelp;
            RequestService mRequestService;
            BadHttpClientType mBadHttpClientType;
            BadEventType mBadEventType;
        };
    }
}

#endif //READY4AIR_SERVICES_HELPSSERVICE_H
