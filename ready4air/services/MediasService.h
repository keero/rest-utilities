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
#include "exceptions/BadHttpClientType.h"

namespace ready4air
{
    namespace services
    {
        typedef Maybe <Error> MediasResponse;

        template <typename HTTP_CLIENT_TYPE, typename EVENT_TYPE>
        class MediasService : public HTTP_CLIENT_TYPE, public dto::IJsonDeserializable
        {
        public:
            typedef enum {
                SELF_MEDIA_REQUEST = 1
            } _;

            MediasService()
            {
                if (!std::is_base_of<IHttpClient, HTTP_CLIENT_TYPE>::value) throw mBadHttpClientType;
                if (!std::is_base_of<IEvent <MediasResponse>, EVENT_TYPE>::value) throw mBadEventType;
            }

            virtual ~MediasService()
            {
            }

            const Maybe<dto::MediaProduct> &GetMedia() const
            {
                return mMedia;
            }

            EVENT_TYPE GetSelfEvent() const
            {
                return mSelfEvent;
            }

            virtual bool InitFromJsonValue(const rapidjson::Value &value, dto::ParseErrors &parseErrors)
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

            const RequestService &GetRequestService() const
            {
                return mRequestService;
            }

            virtual void OnReceivedResponse(const RequestData &requestData, const ResponseData &responseData)
            {
                dto::ParseErrors parseErrors;
                MediasResponse payload;
                Error error;
                IEvent <MediasResponse> *pEvent;

                switch (requestData.GetCallee())
                {
                    case SELF_MEDIA_REQUEST:
                    default:
                        pEvent = GetSelfEvent();
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
                            error.SetMessage("Failed to parse Media.");
                            error.SetParseErrors(parseErrors);
                            payload = error;
                        }
                        break;
                    }
                    default:
                        // @TODO: Add error reporting
                        error.SetMessage("Unexpected medias response.");
                        payload = error;
                        break;
                }

                pEvent->Emit(payload);
            }

        private:
            EVENT_TYPE mSelfEvent;
            Maybe <dto::MediaProduct> mMedia;
            RequestService mRequestService;
            BadHttpClientType mBadHttpClientType;
            BadEventType mBadEventType;
        };
    }
}

#endif //READY4AIR_SERVICES_MEDIASSERVICE_H
