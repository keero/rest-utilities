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
#include "exceptions/BadEventPayloadType.h"

namespace ready4air
{
    namespace services
    {
        template <typename HTTP_CLIENT_TYPE, typename EVENT_TYPE, typename EVENT_PAYLOAD_TYPE>
        class HelpsService : public HTTP_CLIENT_TYPE
        {
        public:
            HelpsService() : TAG("ready4air::services::HelpsService")
            {
                if (!std::is_base_of<IHttpClient, HTTP_CLIENT_TYPE>::value) throw mBadHttpClientType;
                if (!std::is_base_of<IEventPayload, EVENT_PAYLOAD_TYPE>::value) throw mBadEventPayloadType;
                if (!std::is_base_of<IEvent <EVENT_PAYLOAD_TYPE>, EVENT_TYPE>::value) throw mBadEventType;
            }

            virtual ~HelpsService()
            {
            }

            const Maybe<dto::Help> &GetHelp() const
            {
                return mHelp;
            }

        protected:
            void SetHelp(const dto::Help &help)
            {
                mHelp = help;
            }

            virtual void OnReceivedResponse(const RequestData &requestData, const ResponseData &responseData)
            {
                UNUSED(requestData);
                dto::ParseErrors parseErrors;
                EVENT_PAYLOAD_TYPE payload;
                IEventPayload *pPayload = &payload;
                IEvent <EVENT_PAYLOAD_TYPE> *pEvent = &HelpsEvent;

                pPayload->SetHttpStatusCode(responseData.GetStatusCode());

                if (responseData.GetStatusCode() == ResponseData::HTTP_STATUS_CODE_OK)
                {
                    dto::Help help;
                    if (help.InitFromJsonString(responseData.GetBody(), parseErrors))
                    {
                        SetHelp(help);
                    }
                    else
                    {
                        pPayload->SetMessage("Failed to parse Help.");
                    }
                }
                else
                {
                    // @TODO: Add error reporting
                    pPayload->SetMessage("Unexpected helps response.");
                }
                pEvent->Emit(payload);
            }

        public:
            EVENT_TYPE HelpsEvent;

        private:
            Maybe <dto::Help> mHelp;
            BadHttpClientType mBadHttpClientType;
            BadEventType mBadEventType;
            BadEventPayloadType mBadEventPayloadType;
            const STRING_T TAG;
        };
    }
}

#endif //READY4AIR_SERVICES_HELPSSERVICE_H
