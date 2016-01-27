#ifndef READY4AIR_SERVICES_PAGESSERVICE_H
#define READY4AIR_SERVICES_PAGESSERVICE_H

#include "../dto/Page.h"
#include "../external/IHttpClient.h"
#include "../external/IEvent.h"
#include "../external/RequestData.h"
#include "../external/ResponseData.h"
#include "RequestService.h"
#include "Error.h"
#include "exceptions/BadEventType.h"
#include "exceptions/BadEventPayloadType.h"
#include "exceptions/BadHttpClientType.h"

namespace ready4air
{
    namespace services
    {
        template <typename HTTP_CLIENT_TYPE, typename EVENT_TYPE, typename EVENT_PAYLOAD_TYPE>
        class PagesService : public HTTP_CLIENT_TYPE
        {
        public:
            PagesService()
            {
                if (!std::is_base_of<IHttpClient, HTTP_CLIENT_TYPE>::value) throw mBadHttpClientType;
                if (!std::is_base_of<IEventPayload, EVENT_PAYLOAD_TYPE>::value) throw mBadEventPayloadType;
                if (!std::is_base_of<IEvent <EVENT_PAYLOAD_TYPE>, EVENT_TYPE>::value) throw mBadEventType;
            }

            virtual ~PagesService()
            {
            }

            const Maybe<dto::Page> &GetPage() const
            {
                return mPage;
            }

        protected:
            void SetPage(const dto::Page &page)
            {
                mPage = page;
            }

            virtual void OnReceivedResponse(const RequestData &requestData, const ResponseData &responseData)
            {
                READY4AIR_UNUSED(requestData);
                dto::ParseErrors parseErrors;
                EVENT_PAYLOAD_TYPE payload;
                IEventPayload *pPayload = &payload;
                IEvent <EVENT_PAYLOAD_TYPE> *pEvent = &HomeEvent;

                pPayload->SetHttpStatusCode(responseData.GetStatusCode());

                if (responseData.GetStatusCode() == ResponseData::HTTP_STATUS_CODE_OK)
                {
                    dto::Page page;
                    if (page.InitFromJsonString(responseData.GetBody(), parseErrors))
                    {
                        SetPage(page);
                    }
                    else
                    {
                        pPayload->SetMessage("Failed to parse Page.");
                    }
                }
                else
                {
                    // @TODO: Add error reporting
                    pPayload->SetMessage("Unexpected pages response.");
                }
                pEvent->Emit(payload);
            }


        public:
            EVENT_TYPE HomeEvent;

        private:
            Maybe <dto::Page> mPage;
            BadHttpClientType mBadHttpClientType;
            BadEventType mBadEventType;
            BadEventPayloadType mBadEventPayloadType;
        };
    }
}

#endif //READY4AIR_SERVICES_PAGESSERVICE_H
