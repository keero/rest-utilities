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
#include "exceptions/BadEventPayloadType.h"
#include "exceptions/BadHttpClientType.h"

namespace ready4air
{
    namespace services
    {
        template <typename HTTP_CLIENT_TYPE, typename EVENT_TYPE, typename EVENT_PAYLOAD_TYPE>
        class BundlesService : public HTTP_CLIENT_TYPE, public dto::IJsonDeserializable
        {
        public:
            BundlesService()
            {
                if (!std::is_base_of<IHttpClient, HTTP_CLIENT_TYPE>::value) throw mBadHttpClientType;
                if (!std::is_base_of<IEventPayload, EVENT_PAYLOAD_TYPE>::value) throw mBadEventPayloadType;
                if (!std::is_base_of<IEvent <EVENT_PAYLOAD_TYPE>, EVENT_TYPE>::value) throw mBadEventType;
            }

            virtual ~BundlesService()
            {
            }

            const Maybe<dto::Bundle> &GetBundle() const
            {
                return mBundle;
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

            virtual void OnReceivedResponse(const RequestData &requestData, const ResponseData &responseData)
            {
                dto::ParseErrors parseErrors;
                EVENT_PAYLOAD_TYPE payload;
                IEventPayload *pPayload = &payload;
                IEvent <EVENT_PAYLOAD_TYPE> *pEvent = &BundleEvent;

                pPayload->SetHttpStatusCode(responseData.GetStatusCode());

                switch (requestData.GetCallee())
                {
                    case BUNDLE_SELF_REQUEST:
                    default:
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
                            pPayload->SetMessage("Failed to parse Bundle.");
                        }
                        break;
                    }
                    default:
                        // @TODO: Add error reporting
                        pPayload->SetMessage("Unexpected bundles response.");
                        break;
                }

                pEvent->Emit(payload);
            }

        public:
            EVENT_TYPE BundleEvent;

        private:
            Maybe <dto::Bundle> mBundle;
            BadHttpClientType mBadHttpClientType;
            BadEventType mBadEventType;
            BadEventPayloadType mBadEventPayloadType;
        };
    }
}

#endif //READY4AIR_SERVICES_BUNDLESSERVICE_H
