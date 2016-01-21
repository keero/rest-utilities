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
        typedef Maybe <Error> UsersResponse;

        template <typename HTTP_CLIENT_TYPE, typename EVENT_TYPE>
        class UsersService : public HTTP_CLIENT_TYPE
        {
        public:
            typedef enum {
                LOGIN_USER_REQUEST = 1,
                REGISTER_USER_REQUEST,
                FORGOT_PASSWORD_USER_REQUEST,
                SELF_USER_REQUEST
            } _;

            UsersService()
            {
                if (!std::is_base_of<IHttpClient, HTTP_CLIENT_TYPE>::value) throw mBadHttpClientType;
                if (!std::is_base_of<IEvent <UsersResponse>, EVENT_TYPE>::value) throw mBadEventType;
            }

            virtual ~UsersService()
            {
            }

            const Maybe<dto::User> &GetUser() const
            {
                return mUser;
            }

            EVENT_TYPE GetLoginEvent() const
            {
                return mLoginEvent;
            }

            EVENT_TYPE GetRegisterEvent() const
            {
                return mRegisterEvent;
            }

            EVENT_TYPE GetForgotPasswordEvent() const
            {
                return mForgotPasswordEvent;
            }

        protected:
            void SetUser(const dto::User &user)
            {
                mUser = user;
            }

            const RequestService &GetRequestService() const
            {
                return mRequestService;
            }

            virtual void OnReceivedResponse(const RequestData &requestData, const ResponseData &responseData)
            {
                dto::ParseErrors parseErrors;
                UsersResponse payload;
                Error error;
                error.SetHttpStatusCode(responseData.GetStatusCode());

                switch (requestData.GetCallee())
                {
                    case LOGIN_USER_REQUEST:
                    case SELF_USER_REQUEST:
                    {
                        IEvent <UsersResponse> *pEvent = GetLoginEvent();
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
                                    error.SetMessage("Failed to parse User.");
                                    error.SetParseErrors(parseErrors);
                                    payload = error;
                                }
                                break;
                            }

                            default:
                            {
                                error.SetMessage("Login failed.");
                                payload = error;
                                break;
                            }
                        }
                        pEvent->Emit(payload);
                        break;
                    }

                    case REGISTER_USER_REQUEST:
                    {
                        IEvent <UsersResponse> *pEvent = GetRegisterEvent();
                        switch (responseData.GetStatusCode())
                        {
                            case ResponseData::HTTP_STATUS_CODE_OK:
                                break;

                            default:
                            {
                                error.SetMessage("Register failed.");
                                payload = error;
                                break;
                            }
                        }
                        pEvent->Emit(payload);
                        break;
                    }

                    case FORGOT_PASSWORD_USER_REQUEST:
                    {
                        IEvent <UsersResponse> *pEvent = GetForgotPasswordEvent();
                        switch (responseData.GetStatusCode())
                        {
                            case ResponseData::HTTP_STATUS_CODE_OK:
                                break;

                            default:
                            {
                                error.SetMessage("ForgotPassword failed.");
                                payload = error;
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


        private:
            EVENT_TYPE mLoginEvent;
            EVENT_TYPE mRegisterEvent;
            EVENT_TYPE mForgotPasswordEvent;
            Maybe <dto::User> mUser;
            RequestService mRequestService;
            BadHttpClientType mBadHttpClientType;
            BadEventType mBadEventType;
        };
    }
}

#endif //READY4AIR_SERVICES_USERSSERVICE_H
