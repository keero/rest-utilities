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
        typedef Maybe <Error> PaginatedResponse;

        template <typename SERVICE_TYPE, typename HTTP_CLIENT_TYPE, typename EVENT_TYPE>
        class PaginationService : public HTTP_CLIENT_TYPE
        {
        public:
            typedef enum {
                FIRST_PAGINATED_REQUEST = 1,
                NEXT_PAGINATED_REQUEST,
                PREV_PAGINATED_REQUEST
            } _;

            PaginationService()
            {
                if (!std::is_base_of<IHttpClient, HTTP_CLIENT_TYPE>::value) throw mBadHttpClientType;
                if (!std::is_base_of<IEvent <PaginatedResponse>, EVENT_TYPE>::value) throw mBadEventType;
                if (!std::is_base_of<dto::IJsonDeserializable, SERVICE_TYPE>::value) throw mBadPaginatedType;
            }

            virtual ~PaginationService()
            {
            }

            bool Next(void) const
            {
                if (GetPaginated() && GetPaginated().Just().GetNext())
                {
                    IHttpClient *pClient = this;
                    RequestData requestData;

                    dto::Link link = GetPaginated().Just().GetNext().Just();

                    requestData = GetRequestService().CreateRequestFromLink(NEXT_PAGINATED_REQUEST, link);

                    pClient->DoRequest(requestData);
                    return true;
                }
                else
                    return false;
            }

            bool Prev(void) const
            {
                if (GetPaginated() && GetPaginated().Just().GetPrev())
                {
                    IHttpClient *pClient = this;
                    RequestData requestData;

                    dto::Link link = GetPaginated().Just().GetPrev().Just();

                    requestData = GetRequestService().CreateRequestFromLink(NEXT_PAGINATED_REQUEST, link);

                    pClient->DoRequest(requestData);
                    return true;
                }
                else
                    return false;
            }

            const std::vector <SERVICE_TYPE> &GetItems() const
            {
                if (GetPaginated() && GetPaginated().Just() && GetPaginated().Just().GetItems())
                    return GetPaginated().Just().GetItems().Just();
                else
                    return mNoItems;
            }

            EVENT_TYPE GetFirstEvent() const
            {
                return mFirstEvent;
            }

            EVENT_TYPE GetNextEvent() const
            {
                return mNextEvent;
            }

            EVENT_TYPE GetPrevEvent() const
            {
                return mPrevEvent;
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

            const RequestService &GetRequestService() const
            {
                return mRequestService;
            }

            virtual void OnReceivedResponse(const RequestData &requestData, const ResponseData &responseData)
            {
                dto::ParseErrors parseErrors;
                PaginatedResponse payload;
                Error error;
                error.SetHttpStatusCode(responseData.GetStatusCode());
                IEvent <PaginatedResponse> *pEvent;

                switch (requestData.GetCallee())
                {
                    case NEXT_PAGINATED_REQUEST:
                        pEvent = GetNextEvent();
                        break;
                    case PREV_PAGINATED_REQUEST:
                        pEvent = GetPrevEvent();
                        break;
                    case FIRST_PAGINATED_REQUEST:
                    default:
                        pEvent = GetFirstEvent();
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
                        error.SetMessage("Failed to parse GenericPage.");
                        error.SetParseErrors(parseErrors);
                        payload = error;
                    }
                }
                else
                {
                    // @TODO: Add error reporting
                    error.SetMessage("Unexpected paginated response.");
                    payload = error;
                }

                pEvent->Emit(payload);
            }


        private:
            EVENT_TYPE mFirstEvent;
            EVENT_TYPE mNextEvent;
            EVENT_TYPE mPrevEvent;
            Maybe <dto::GenericPage <SERVICE_TYPE> > mPaginated;
            const std::vector <SERVICE_TYPE> mNoItems;
            RequestService mRequestService;
            BadHttpClientType mBadHttpClientType;
            BadEventType mBadEventType;
            BadPaginatedType mBadPaginatedType;
        };
    }
}

#endif //READY4AIR_SERVICES_PAGINATEDSERVICE_H
