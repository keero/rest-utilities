#ifndef READY4AIR_SERVICES_PAGINATEDSERVICE_H
#define READY4AIR_SERVICES_PAGINATEDSERVICE_H

#include "../dto/abstract/JsonDeserializable.h"
#include "../dto/GenericPage.h"
#include "../external/IHttpClient.h"
#include "../external/IEvent.h"
#include "../external/RequestData.h"
#include "../external/ResponseData.h"
#include "RequestService.h"
#include "Error.h"
#include "exceptions/BadEventType.h"
#include "exceptions/BadHttpClientType.h"
#include "exceptions/BadPaginatedType.h"

namespace ready4air
{
    namespace services
    {
        template <typename SERVICE_TYPE, typename HTTP_CLIENT_TYPE, typename EVENT_TYPE, typename EVENT_PAYLOAD_TYPE>
        class PaginationService : public HTTP_CLIENT_TYPE
        {
        public:
            PaginationService() : TAG("ready4air::services::PaginationService")
            {
                if (!std::is_base_of<IHttpClient, HTTP_CLIENT_TYPE>::value) throw mBadHttpClientType;
                if (!std::is_base_of<IEventPayload, EVENT_PAYLOAD_TYPE>::value) throw mBadEventPayloadType;
                if (!std::is_base_of<IEvent <EVENT_PAYLOAD_TYPE>, EVENT_TYPE>::value) throw mBadEventType;
                if (!std::is_base_of<dto::IJsonDeserializable, SERVICE_TYPE>::value) throw mBadPaginatedType;
            }

            virtual ~PaginationService()
            {
            }

            BOOL_T Next(void) const
            {
                if (GetPaginated() && GetPaginated().Just().GetNext())
                {
                    IHttpClient *pClient = this;
                    RequestData requestData;

                    dto::Link link = GetPaginated().Just().GetNext().Just();

                    requestData = RequestService::CreateRequestFromLink(PAGINATED_NEXT_REQUEST, link);

                    pClient->DoRequest(requestData);
                    return true;
                }
                else
                    return false;
            }

            BOOL_T Prev(void) const
            {
                if (GetPaginated() && GetPaginated().Just().GetPrev())
                {
                    IHttpClient *pClient = this;
                    RequestData requestData;

                    dto::Link link = GetPaginated().Just().GetPrev().Just();

                    requestData = RequestService::CreateRequestFromLink(PAGINATED_PREV_REQUEST, link);

                    pClient->DoRequest(requestData);
                    return true;
                }
                else
                    return false;
            }

            const Maybe <VECTOR_T <SERVICE_TYPE> > &GetItems() const
            {
                return GetPaginated().Just().GetItems();
            }

        protected:
            void SetPaginated(const dto::GenericPage <SERVICE_TYPE> &genericPage)
            {
                mPaginated = genericPage;
            }

            const Maybe <dto::GenericPage <SERVICE_TYPE> > &GetPaginated() const
            {
                return mPaginated;
            }

            virtual void OnReceivedResponse(const RequestData &requestData, const ResponseData &responseData)
            {
                dto::ParseErrors parseErrors;
                EVENT_PAYLOAD_TYPE payload;
                IEventPayload *pPayload = &payload;
                IEvent <EVENT_PAYLOAD_TYPE> *pEvent = &PaginatedEvent;

                pPayload->SetHttpStatusCode(responseData.GetStatusCode());

                switch (requestData.GetCallee())
                {
                    case PAGINATED_NEXT_REQUEST:
                    case PAGINATED_PREV_REQUEST:
                    default:
                        break;
                }

                if (responseData.GetStatusCode() == ResponseData::HTTP_STATUS_CODE_OK)
                {
                    dto::GenericPage <SERVICE_TYPE> paginated;
                    if (paginated.InitFromJsonString(responseData.GetBody(), parseErrors))
                    {
                        SetPaginated(paginated);
                    }
                    else
                    {
                        pPayload->SetMessage("Failed to parse GenericPage.");
                    }
                }
                else
                {
                    // @TODO: Add error reporting
                    pPayload->SetMessage("Unexpected paginated response.");
                }

                pEvent->Emit(payload);
            }

        public:
            EVENT_TYPE PaginatedEvent;

        private:
            Maybe <dto::GenericPage <SERVICE_TYPE> > mPaginated;
            BadHttpClientType mBadHttpClientType;
            BadEventType mBadEventType;
            BadEventPayloadType mBadEventPayloadType;
            BadPaginatedType mBadPaginatedType;
            const STRING_T TAG;
        };
    }
}

#endif //READY4AIR_SERVICES_PAGINATEDSERVICE_H
