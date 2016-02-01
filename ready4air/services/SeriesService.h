#ifndef READY4AIR_SERVICES_SERIESSERVICE_H
#define READY4AIR_SERVICES_SERIESSERVICE_H

#include "../dto/Series.h"
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
        template <typename HTTP_CLIENT_TYPE, typename EVENT_TYPE, typename EVENT_PAYLOAD_TYPE>
        class SeriesService : public HTTP_CLIENT_TYPE, public dto::IJsonDeserializable
        {
        public:
            SeriesService() : TAG("ready4air::services::SeriesService")
            {
                if (!std::is_base_of<IHttpClient, HTTP_CLIENT_TYPE>::value) throw mBadHttpClientType;
                if (!std::is_base_of<IEventPayload, EVENT_PAYLOAD_TYPE>::value) throw mBadEventPayloadType;
                if (!std::is_base_of<IEvent <EVENT_PAYLOAD_TYPE>, EVENT_TYPE>::value) throw mBadEventType;
            }

            virtual ~SeriesService()
            {
            }

            const Maybe<dto::Series> &GetSeries() const
            {
                return mSeries;
            }

            virtual BOOL_T InitFromJsonValue(const rapidjson::Value &value, dto::ParseErrors &parseErrors)
            {
                dto::Series series;
                if (series.InitFromJsonValue(value, parseErrors))
                {
                    SetSeries(series);
                    return true;
                }
                else
                    return false;
            }

        protected:
            void SetSeries(const dto::Series &series)
            {
                mSeries = series;
            }

            virtual void OnReceivedResponse(const RequestData &requestData, const ResponseData &responseData)
            {
                dto::ParseErrors parseErrors;
                EVENT_PAYLOAD_TYPE payload;
                IEventPayload *pPayload = &payload;
                IEvent <EVENT_PAYLOAD_TYPE> *pEvent = &SeriesEvent;

                pPayload->SetHttpStatusCode(responseData.GetStatusCode());

                switch (requestData.GetCallee())
                {
                    case SERIES_SELF_REQUEST:
                    default:
                        break;
                }

                switch (responseData.GetStatusCode())
                {
                    case ResponseData::HTTP_STATUS_CODE_OK:
                    {
                        dto::Series series;
                        if (series.InitFromJsonString(responseData.GetBody(), parseErrors))
                        {
                            SetSeries(series);
                        }
                        else
                        {
                            pPayload->SetMessage("Failed to parse Series.");
                        }
                        break;
                    }
                    default:
                        // @TODO: Add error reporting
                        pPayload->SetMessage("Unexpected series response.");
                        break;
                }

                pEvent->Emit(payload);
            }

        public:
            EVENT_TYPE SeriesEvent;

        private:
            Maybe <dto::Series> mSeries;
            BadHttpClientType mBadHttpClientType;
            BadEventType mBadEventType;
            BadEventPayloadType mBadEventPayloadType;
            STRING_T TAG;
        };
    }
}

#endif //READY4AIR_SERVICES_SERIESSERVICE_H
