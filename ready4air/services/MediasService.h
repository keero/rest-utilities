#ifndef READY4AIR_SERVICES_MEDIASSERVICE_H
#define READY4AIR_SERVICES_MEDIASSERVICE_H

#include "../dto/MediaProduct.h"
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
        class MediasService : public HTTP_CLIENT_TYPE, public dto::IJsonDeserializable
        {
        public:
            MediasService() : TAG("ready4air::services::MediasService")
            {
                if (!std::is_base_of<IHttpClient, HTTP_CLIENT_TYPE>::value) throw mBadHttpClientType;
                if (!std::is_base_of<IEventPayload, EVENT_PAYLOAD_TYPE>::value) throw mBadEventPayloadType;
                if (!std::is_base_of<IEvent <EVENT_PAYLOAD_TYPE>, EVENT_TYPE>::value) throw mBadEventType;
            }

            virtual ~MediasService()
            {
            }

            const Maybe<dto::MediaProduct> &GetMedia() const
            {
                return mMedia;
            }

            virtual BOOL_T InitFromJsonValue(const rapidjson::Value &value, dto::ParseErrors &parseErrors)
            {
                dto::MediaProduct media;
                if (media.InitFromJsonValue(value, parseErrors))
                {
                    SetMedia(media);
                    return true;
                }
                else
                    return false;
            }

        protected:
            void SetMedia(const dto::MediaProduct &media)
            {
                mMedia = media;
            }

            virtual void OnReceivedResponse(const RequestData &requestData, const ResponseData &responseData)
            {
                dto::ParseErrors parseErrors;
                EVENT_PAYLOAD_TYPE payload;
                IEventPayload *pPayload = &payload;
                IEvent <EVENT_PAYLOAD_TYPE> *pEvent = &MediaEvent;

                pPayload->SetHttpStatusCode(responseData.GetStatusCode());

                switch (requestData.GetCallee())
                {
                    case MEDIA_SELF_REQUEST:
                    default:
                        break;
                }

                switch (responseData.GetStatusCode())
                {
                    case ResponseData::HTTP_STATUS_CODE_OK:
                    {
                        dto::MediaProduct media;
                        if (media.InitFromJsonString(responseData.GetBody(), parseErrors))
                        {
                            SetMedia(media);
                        }
                        else
                        {
                            pPayload->SetMessage("Failed to parse Media.");
                        }
                        break;
                    }
                    default:
                        // @TODO: Add error reporting
                        pPayload->SetMessage("Unexpected medias response.");
                        break;
                }

                pEvent->Emit(payload);
            }

        public:
            EVENT_TYPE MediaEvent;

        private:
            Maybe <dto::MediaProduct> mMedia;
            BadHttpClientType mBadHttpClientType;
            BadEventType mBadEventType;
            BadEventPayloadType mBadEventPayloadType;
            STRING_T TAG;
        };
    }
}

#endif //READY4AIR_SERVICES_MEDIASSERVICE_H
