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
        typedef Maybe <Error> SeriesResponse;

        template <typename HTTP_CLIENT_TYPE, typename EVENT_TYPE>
        class SeriesService : public HTTP_CLIENT_TYPE, public dto::IJsonDeserializable
        {
        public:
            typedef enum {
                SELF_SERIES_REQUEST = 1
            } _;

            SeriesService()
            {
                if (!std::is_base_of<IHttpClient, HTTP_CLIENT_TYPE>::value) throw mBadHttpClientType;
                if (!std::is_base_of<IEvent <SeriesResponse>, EVENT_TYPE>::value) throw mBadEventType;
            }

            virtual ~SeriesService()
            {
            }

            const Maybe<dto::Series> &GetSeries() const
            {
                return mSeries;
            }

            EVENT_TYPE GetSelfEvent() const
            {
                return mSelfEvent;
            }

            virtual bool InitFromJsonValue(const rapidjson::Value &value, dto::ParseErrors &parseErrors)
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

            const RequestService &GetRequestService() const
            {
                return mRequestService;
            }

            virtual void OnReceivedResponse(const RequestData &requestData, const ResponseData &responseData)
            {
                dto::ParseErrors parseErrors;
                SeriesResponse payload;
                Error error;
                IEvent <SeriesResponse> *pEvent;

                switch (requestData.GetCallee())
                {
                    case SELF_SERIES_REQUEST:
                    default:
                        pEvent = GetSelfEvent();
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
                            error.SetMessage("Failed to parse Series.");
                            error.SetParseErrors(parseErrors);
                            payload = error;
                        }
                        break;
                    }
                    default:
                        // @TODO: Add error reporting
                        error.SetMessage("Unexpected series response.");
                        payload = error;
                        break;
                }

                pEvent->Emit(payload);
            }

        private:
            EVENT_TYPE mSelfEvent;
            Maybe <dto::Series> mSeries;
            RequestService mRequestService;
            BadHttpClientType mBadHttpClientType;
            BadEventType mBadEventType;
        };
    }
}

#endif //READY4AIR_SERVICES_SERIESSERVICE_H
