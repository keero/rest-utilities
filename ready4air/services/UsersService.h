#ifndef READY4AIR_SERVICES_USERSSERVICE_H
#define READY4AIR_SERVICES_USERSSERVICE_H

#include "../dto/User.h"
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
        class UsersService : public HTTP_CLIENT_TYPE
        {
        public:
            UsersService()
            {
                if (!std::is_base_of<IHttpClient, HTTP_CLIENT_TYPE>::value) throw mBadHttpClientType;
                if (!std::is_base_of<IEventPayload, EVENT_PAYLOAD_TYPE>::value) throw mBadEventPayloadType;
                if (!std::is_base_of<IEvent <EVENT_PAYLOAD_TYPE>, EVENT_TYPE>::value) throw mBadEventType;
            }

            virtual ~UsersService()
            {
            }

            const Maybe<dto::User> &GetUser() const
            {
                return mUser;
            }

        protected:
            void SetUser(const dto::User &user)
            {
                mUser = user;
            }

            virtual void OnReceivedResponse(const RequestData &requestData, const ResponseData &responseData)
            {
                dto::ParseErrors parseErrors;
                EVENT_PAYLOAD_TYPE payload;
                IEventPayload *pPayload = &payload;
                IEvent <EVENT_PAYLOAD_TYPE> *pEvent;

                pPayload->SetHttpStatusCode(responseData.GetStatusCode());

                switch (requestData.GetCallee())
                {
                    case DEVICE_LOGIN_REQUEST:
                    case USER_SELF_REQUEST:
                    {
                        pEvent = &LoginEvent;
                        switch (responseData.GetStatusCode())
                        {
                            case ResponseData::HTTP_STATUS_CODE_OK:
                            {
                                dto::User user;
                                if (user.InitFromJsonString(responseData.GetBody(), parseErrors))
                                {
                                    SetUser(user);
                                }
                                else
                                {
                                    pPayload->SetMessage("Failed to parse User.");
                                }
                                break;
                            }

                            default:
                            {
                                pPayload->SetMessage("Login failed.");
                                break;
                            }
                        }
                        pEvent->Emit(payload);
                        break;
                    }

                    case DEVICE_REGISTER_REQUEST:
                    {
                        pEvent = &RegisterEvent;
                        switch (responseData.GetStatusCode())
                        {
                            case ResponseData::HTTP_STATUS_CODE_OK:
                                break;

                            default:
                            {
                                pPayload->SetMessage("Register failed.");
                                break;
                            }
                        }
                        pEvent->Emit(payload);
                        break;
                    }

                    case DEVICE_FORGOTPASSWORD_REQUEST:
                    {
                        pEvent = &ForgotPasswordEvent;
                        switch (responseData.GetStatusCode())
                        {
                            case ResponseData::HTTP_STATUS_CODE_OK:
                                break;

                            default:
                            {
                                pPayload->SetMessage("ForgotPassword failed.");
                                break;
                            }
                        }
                        pEvent->Emit(payload);
                        break;
                    }

                    default:
                        break;
                }
            }

        public:
            EVENT_TYPE LoginEvent;
            EVENT_TYPE RegisterEvent;
            EVENT_TYPE ForgotPasswordEvent;

        private:
            Maybe <dto::User> mUser;
            BadHttpClientType mBadHttpClientType;
            BadEventType mBadEventType;
            BadEventPayloadType mBadEventPayloadType;
        };
    }
}

#endif //READY4AIR_SERVICES_USERSSERVICE_H
