#ifndef READY4AIR_SERVICES_BUNDLESSERVICE_H
#define READY4AIR_SERVICES_BUNDLESSERVICE_H

#include "../dto/Bundle.h"
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
        typedef Maybe <Error> BundlesResponse;

        template <typename HTTP_CLIENT_TYPE, typename EVENT_TYPE>
        class BundlesService : public HTTP_CLIENT_TYPE, public dto::IJsonDeserializable
        {
        public:
            typedef enum {
                SELF_BUNDLE_REQUEST = 1
            } _;

            BundlesService()
            {
                if (!std::is_base_of<IHttpClient, HTTP_CLIENT_TYPE>::value) throw mBadHttpClientType;
                if (!std::is_base_of<IEvent <BundlesResponse>, EVENT_TYPE>::value) throw mBadEventType;
            }

            virtual ~BundlesService()
            {
            }

            const Maybe<dto::Bundle> &GetBundle() const
            {
                return mBundle;
            }

            EVENT_TYPE GetSelfEvent() const
            {
                return mSelfEvent;
            }

            virtual bool InitFromJsonValue(const rapidjson::Value &value, dto::ParseErrors &parseErrors)
            {
                dto::Bundle bundle;
                if (bundle.InitFromJsonValue(value, parseErrors))
                {
                    SetBundle(bundle);
                    return true;
                }
                else
                    return false;
            }

        protected:
            void SetBundle(const dto::Bundle &bundle)
            {
                mBundle = bundle;
            }

            const RequestService &GetRequestService() const
            {
                return mRequestService;
            }

            virtual void OnReceivedResponse(const RequestData &requestData, const ResponseData &responseData)
            {
                dto::ParseErrors parseErrors;
                BundlesResponse payload;
                Error error;
                IEvent <BundlesResponse> *pEvent;

                switch (requestData.GetCallee())
                {
                    case SELF_BUNDLE_REQUEST:
                    default:
                        pEvent = GetSelfEvent();
                        break;
                }

                switch (responseData.GetStatusCode())
                {
                    case ResponseData::HTTP_STATUS_CODE_OK:
                    {
                        dto::Bundle bundle;
                        if (bundle.InitFromJsonString(responseData.GetBody(), parseErrors))
                        {
                            SetBundle(bundle);
                        }
                        else
                        {
                            error.SetMessage("Failed to parse Bundle.");
                            error.SetParseErrors(parseErrors);
                            payload = error;
                        }
                        break;
                    }
                    default:
                        // @TODO: Add error reporting
                        error.SetMessage("Unexpected bundles response.");
                        payload = error;
                        break;
                }

                pEvent->Emit(payload);
            }

        private:
            EVENT_TYPE mSelfEvent;
            Maybe <dto::Bundle> mBundle;
            RequestService mRequestService;
            BadHttpClientType mBadHttpClientType;
            BadEventType mBadEventType;
        };
    }
}

#endif //READY4AIR_SERVICES_BUNDLESSERVICE_H
