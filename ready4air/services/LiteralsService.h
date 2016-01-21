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
#include "exceptions/BadHttpClientType.h"

namespace ready4air
{
    namespace services
    {
        typedef Maybe <Error> LiteralsResponse;
        typedef std::map <std::string, dto::Literal> Literals;

        template <typename HTTP_CLIENT_TYPE, typename EVENT_TYPE>
        class LiteralsService : public HTTP_CLIENT_TYPE
        {
        public:
            typedef enum {
                LITERALS_REQUEST = 1
            } _;

            LiteralsService()
            {
                if (!std::is_base_of<IHttpClient, HTTP_CLIENT_TYPE>::value) throw mBadHttpClientType;
                if (!std::is_base_of<IEvent <LiteralsResponse>, EVENT_TYPE>::value) throw mBadEventType;
            }

            virtual ~LiteralsService()
            {
            }

            const Maybe<dto::Literal> GetLiteral(const std::string &key) const
            {
                Maybe <dto::Literal> result;

                Literals::const_iterator it = mLiterals.find(key);
                if (it != mLiterals.end())
                    result = it->second;

                return result;
            }

            EVENT_TYPE GetLiteralsEvent() const
            {
                return mLiteralsEvent;
            }

        protected:
            void SetLiteral(const std::string &key, const dto::Literal &value)
            {
                mLiterals[key] = value;
            }

            const RequestService &GetRequestService() const
            {
                return mRequestService;
            }

            virtual void OnReceivedResponse(const RequestData &requestData, const ResponseData &responseData)
            {
                dto::ParseErrors parseErrors;
                LiteralsResponse payload;
                Error error;
                IEvent <LiteralsResponse> *pEvent = GetLiteralsEvent();

                error.SetHttpStatusCode(responseData.GetStatusCode());

                if (responseData.GetStatusCode() == ResponseData::HTTP_STATUS_CODE_OK)
                {
                    rapidjson::Document d;

                    if (d.Parse(responseData.GetBody().c_str()).HasParseError() || !d.IsArray())
                    {
                        // @TODO: Add error reporting
                        error.SetMessage("Unexpected literals response.");
                        payload = error;
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
                    error.SetMessage("Unexpected literals response.");
                    payload = error;
                }
                pEvent->Emit(payload);
            }


        private:
            EVENT_TYPE mLiteralsEvent;
            Literals mLiterals;
            RequestService mRequestService;
            BadHttpClientType mBadHttpClientType;
            BadEventType mBadEventType;
        };
    }
}

#endif //READY4AIR_SERVICES_LITERALSSERVICE_H
