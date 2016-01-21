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
#include "exceptions/BadHttpClientType.h"

namespace ready4air
{
    namespace services
    {
        typedef Maybe <Error> PagesResponse;

        template <typename HTTP_CLIENT_TYPE, typename EVENT_TYPE>
        class PagesService : public HTTP_CLIENT_TYPE
        {
        public:
            typedef enum {
                HOME_PAGE_REQUEST = 1,
                SELF_PAGE_REQUEST
            } _;

            PagesService()
            {
                if (!std::is_base_of<IHttpClient, HTTP_CLIENT_TYPE>::value) throw mBadHttpClientType;
                if (!std::is_base_of<IEvent <PagesResponse>, EVENT_TYPE>::value) throw mBadEventType;
            }

            virtual ~PagesService()
            {
            }

            const Maybe<dto::Page> &GetPage() const
            {
                return mPage;
            }

            EVENT_TYPE GetHomeEvent() const
            {
                return mHomeEvent;
            }

        protected:
            void SetPage(const dto::Page &page)
            {
                mPage = page;
            }

            const RequestService &GetRequestService() const
            {
                return mRequestService;
            }

            virtual void OnReceivedResponse(const RequestData &requestData, const ResponseData &responseData)
            {
                dto::ParseErrors parseErrors;
                PagesResponse payload;
                Error error;
                IEvent <PagesResponse> *pEvent = GetHomeEvent();

                error.SetHttpStatusCode(responseData.GetStatusCode());

                if (responseData.GetStatusCode() == ResponseData::HTTP_STATUS_CODE_OK)
                {
                    dto::Page page;
                    if (page.InitFromJsonString(responseData.GetBody(), parseErrors))
                    {
                        SetPage(page);
                    }
                    else
                    {
                        error.SetMessage("Failed to parse Page.");
                        error.SetParseErrors(parseErrors);
                        payload = error;
                    }
                    pEvent->Emit(payload);
                }
                else
                {
                    // @TODO: Add error reporting
                    error.SetMessage("Unexpected pages response.");
                    payload = error;
                    pEvent->Emit(payload);
                }
            }


        private:
            EVENT_TYPE mHomeEvent;
            Maybe <dto::Page> mPage;
            RequestService mRequestService;
            BadHttpClientType mBadHttpClientType;
            BadEventType mBadEventType;
        };
    }
}

#endif //READY4AIR_SERVICES_PAGESSERVICE_H
