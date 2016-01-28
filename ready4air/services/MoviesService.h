#ifndef READY4AIR_SERVICES_MOVIESSERVICE_H
#define READY4AIR_SERVICES_MOVIESSERVICE_H

#include "../dto/Movie.h"
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
        class MoviesService : public HTTP_CLIENT_TYPE, public dto::IJsonDeserializable
        {
        public:
            MoviesService()
            {
                if (!std::is_base_of<IHttpClient, HTTP_CLIENT_TYPE>::value) throw mBadHttpClientType;
                if (!std::is_base_of<IEventPayload, EVENT_PAYLOAD_TYPE>::value) throw mBadEventPayloadType;
                if (!std::is_base_of<IEvent <EVENT_PAYLOAD_TYPE>, EVENT_TYPE>::value) throw mBadEventType;
            }

            virtual ~MoviesService()
            {
            }

            const Maybe<dto::Movie> &GetMovie() const
            {
                return mMovie;
            }

            virtual BOOL_T InitFromJsonValue(const rapidjson::Value &value, dto::ParseErrors &parseErrors)
            {
                dto::Movie movie;
                if (movie.InitFromJsonValue(value, parseErrors))
                {
                    SetMovie(movie);
                    return true;
                }
                else
                    return false;
            }

        protected:
            void SetMovie(const dto::Movie &movie)
            {
                mMovie = movie;
            }

            virtual void OnReceivedResponse(const RequestData &requestData, const ResponseData &responseData)
            {
                dto::ParseErrors parseErrors;
                EVENT_PAYLOAD_TYPE payload;
                IEventPayload *pPayload = &payload;
                IEvent <EVENT_PAYLOAD_TYPE> *pEvent = &MovieEvent;

                pPayload->SetHttpStatusCode(responseData.GetStatusCode());

                switch (requestData.GetCallee())
                {
                    case MOVIE_SELF_REQUEST:
                    default:
                        break;
                }

                switch (responseData.GetStatusCode())
                {
                    case ResponseData::HTTP_STATUS_CODE_OK:
                    {
                        dto::Movie movie;
                        if (movie.InitFromJsonString(responseData.GetBody(), parseErrors))
                        {
                            SetMovie(movie);
                        }
                        else
                        {
                            pPayload->SetMessage("Failed to parse Movie.");
                        }
                        break;
                    }
                    default:
                        // @TODO: Add error reporting
                        pPayload->SetMessage("Unexpected movies response.");
                        break;
                }

                pEvent->Emit(payload);
            }

        public:
            EVENT_TYPE MovieEvent;

        private:
            Maybe <dto::Movie> mMovie;
            BadHttpClientType mBadHttpClientType;
            BadEventType mBadEventType;
            BadEventPayloadType mBadEventPayloadType;
        };
    }
}

#endif //READY4AIR_SERVICES_MOVIESSERVICE_H
