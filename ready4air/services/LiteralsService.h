#ifndef READY4AIR_SERVICES_LITERALSSERVICE_H
#define READY4AIR_SERVICES_LITERALSSERVICE_H

#include "../dto/Literal.h"
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
        typedef MAP_T <STRING_T, dto::Literal> Literals;

        template <typename HTTP_CLIENT_TYPE, typename EVENT_TYPE, typename EVENT_PAYLOAD_TYPE>
        class LiteralsService : public HTTP_CLIENT_TYPE
        {
        public:
            LiteralsService()
            {
                if (!std::is_base_of<IHttpClient, HTTP_CLIENT_TYPE>::value) throw mBadHttpClientType;
                if (!std::is_base_of<IEventPayload, EVENT_PAYLOAD_TYPE>::value) throw mBadEventPayloadType;
                if (!std::is_base_of<IEvent <EVENT_PAYLOAD_TYPE>, EVENT_TYPE>::value) throw mBadEventType;
            }

            virtual ~LiteralsService()
            {
            }

            const Maybe<dto::Literal> GetLiteral(const STRING_T &key) const
            {
                Maybe <dto::Literal> result;

                Literals::const_iterator it = mLiterals.find(key);
                if (it != mLiterals.end())
                    result = it->second;

                return result;
            }

        protected:
            void SetLiteral(const STRING_T &key, const dto::Literal &value)
            {
                mLiterals[key] = value;
            }

            virtual void OnReceivedResponse(const RequestData &requestData, const ResponseData &responseData)
            {
                UNUSED(requestData);
                dto::ParseErrors parseErrors;
                EVENT_PAYLOAD_TYPE payload;
                IEventPayload *pPayload = &payload;
                IEvent <EVENT_PAYLOAD_TYPE> *pEvent = &LiteralsEvent;

                pPayload->SetHttpStatusCode(responseData.GetStatusCode());

                if (responseData.GetStatusCode() == ResponseData::HTTP_STATUS_CODE_OK)
                {
                    rapidjson::Document d;

                    if (d.Parse(responseData.GetBody().c_str()).HasParseError() || !d.IsArray())
                    {
                        // @TODO: Add error reporting
                        pPayload->SetMessage("Unexpected literals response.");
                    }
                    else
                    {
                        for (rapidjson::SizeType i = 0; i < d.Size(); i += 1)
                        {
                            dto::Literal literal;
                            if (literal.InitFromJsonString(responseData.GetBody(), parseErrors) && literal.GetKey())
                            {
                                SetLiteral(literal.GetKey().Just(), literal);
                            }
                        }
                    }
                }
                else
                {
                    // @TODO: Add error reporting
                    pPayload->SetMessage("Unexpected literals response.");
                }
                pEvent->Emit(payload);
            }

        public:
            EVENT_TYPE LiteralsEvent;

        private:
            Literals mLiterals;
            BadHttpClientType mBadHttpClientType;
            BadEventType mBadEventType;
            BadEventPayloadType mBadEventPayloadType;
        };
    }
}

#endif //READY4AIR_SERVICES_LITERALSSERVICE_H
