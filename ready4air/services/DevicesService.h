#ifndef READY4AIR_SERVICES_DEVICESSERVICE_H
#define READY4AIR_SERVICES_DEVICESSERVICE_H


#include "../dto/Device.h"
#include "../external/IHttpClient.h"
#include "../external/IEvent.h"
#include "../external/IEventPayload.h"
#include "../external/RequestData.h"
#include "../external/ResponseData.h"
#include "Error.h"
#include "PagesService.h"
#include "HelpsService.h"
#include "RequestService.h"
#include "LiteralsService.h"
#include "UsersService.h"
#include "PaginationService.h"
#include "MediasService.h"
#include "MoviesService.h"
#include "SeriesService.h"
#include "BundlesService.h"
#include "exceptions/BadEventType.h"
#include "exceptions/BadHttpClientType.h"

namespace ready4air
{
    namespace services
    {
        template <typename HTTP_CLIENT_TYPE, typename EVENT_TYPE, typename EVENT_PAYLOAD_TYPE>
        class DevicesService : public HTTP_CLIENT_TYPE
        {
        public:
            DevicesService()
            {
                if (!std::is_base_of<IHttpClient, HTTP_CLIENT_TYPE>::value) throw mBadHttpClientType;
                if (!std::is_base_of<IEventPayload, EVENT_PAYLOAD_TYPE>::value) throw mBadEventPayloadType;
                if (!std::is_base_of<IEvent <EVENT_PAYLOAD_TYPE>, EVENT_TYPE>::value) throw mBadEventType;
            }

            virtual ~DevicesService()
            {
            }

            BOOL_T Home(IHttpClient *pClient, const STRING_T &language) const
            {
                if (GetDevice() && GetDevice().Just().GetHome())
                {
                    RequestData requestData;

                    dto::Link link = GetDevice().Just().GetHome().Just();
                    link.SetParam("language", language);

                    requestData = RequestService::CreateRequestFromLink(DEVICE_HOME_REQUEST, link);

                    pClient->DoRequest(requestData);
                    return true;
                }
                else
                    return false;
            }

            BOOL_T Helps(IHttpClient *pClient, const STRING_T &language) const
            {
                if (GetDevice() && GetDevice().Just().GetHelps())
                {
                    RequestData requestData;

                    dto::Link link = GetDevice().Just().GetHelps().Just();
                    link.SetParam("language", language);

                    requestData = RequestService::CreateRequestFromLink(DEVICE_HELPS_REQUEST, link);

                    pClient->DoRequest(requestData);
                    return true;
                }
                else
                    return false;
            }

            BOOL_T Literals(IHttpClient *pClient, const STRING_T &language) const
            {
                if (GetDevice() && GetDevice().Just().GetLiterals())
                {
                    RequestData requestData;

                    dto::Link link = GetDevice().Just().GetLiterals().Just();
                    link.SetParam("language", language);

                    requestData = RequestService::CreateRequestFromLink(DEVICE_LITERALS_REQUEST, link);

                    pClient->DoRequest(requestData);
                    return true;
                }
                else
                    return false;
            }

            BOOL_T Login(IHttpClient *pClient, const STRING_T &username, const STRING_T &password) const
            {
                if (GetDevice() && GetDevice().Just().GetLogin())
                {
                    RequestData requestData;

                    dto::Link link = GetDevice().Just().GetLogin().Just();
                    link.SetParam("username", username);
                    link.SetParam("password", password);

                    requestData = RequestService::CreateRequestFromLink(DEVICE_LOGIN_REQUEST, link);

                    pClient->DoRequest(requestData);
                    return true;
                }
                else
                    return false;
            }

            BOOL_T Register(IHttpClient *pClient, const STRING_T &email, const STRING_T &password) const
            {
                if (GetDevice() && GetDevice().Just().GetRegister() && GetDevice().Just().GetRegister().Just().GetAction())
                {
                    RequestData requestData;

                    dto::Form form = GetDevice().Just().GetRegister().Just();
                    dto::Link link = form.GetAction().Just();
                    link.SetParam("email", email);
                    link.SetParam("password", password);
                    form.SetAction(link);

                    requestData = RequestService::CreateRequestFromForm(DEVICE_REGISTER_REQUEST, form);

                    pClient->DoRequest(requestData);
                    return true;
                }
                else
                    return false;
            }

            BOOL_T ForgotPassword(IHttpClient *pClient, const STRING_T &userName) const
            {
                if (GetDevice() && GetDevice().Just().GetForgotPassword() && GetDevice().Just().GetForgotPassword().Just().GetAction())
                {
                    RequestData requestData;

                    dto::Form form = GetDevice().Just().GetForgotPassword().Just();
                    dto::Link link = form.GetAction().Just();
                    link.SetParam("userName", userName);
                    form.SetAction(link);

                    requestData = RequestService::CreateRequestFromForm(DEVICE_FORGOTPASSWORD_REQUEST, form);

                    pClient->DoRequest(requestData);
                    return true;
                }
                else
                    return false;
            }

            BOOL_T Self(void) const
            {
                if (GetDevice() && GetDevice().Just().GetSelf())
                {
                    IHttpClient *pClient = this;
                    RequestData requestData;

                    dto::Link link = GetDevice().Just().GetSelf().Just();

                    requestData = RequestService::CreateRequestFromLink(DEVICE_SELF_REQUEST, link);

                    pClient->DoRequest(requestData);
                    return true;
                }
                else
                    return false;

            }

            BOOL_T Search(IHttpClient *pClient, const STRING_T &search) const
            {
                if (GetDevice() && GetDevice().Just().GetSearch())
                {
                    RequestData requestData;

                    dto::Link link = GetDevice().Just().GetSearch().Just();
                    link.SetParam("search", search);

                    requestData = RequestService::CreateRequestFromLink(DEVICE_SEARCH_REQUEST, link);

                    pClient->DoRequest(requestData);
                    return true;
                }
                else
                    return false;
            }

            BOOL_T SearchAsYouType(IHttpClient *pClient, const STRING_T &search) const
            {
                if (GetDevice() && GetDevice().Just().GetSearchAsYouType())
                {
                    RequestData requestData;

                    dto::Link link = GetDevice().Just().GetSearchAsYouType().Just();
                    link.SetParam("search", search);

                    requestData = RequestService::CreateRequestFromLink(DEVICE_SEARCHASYOUTYPE_REQUEST, link);

                    pClient->DoRequest(requestData);
                    return true;
                }
                else
                    return false;
            }

            BOOL_T SearchMovies(IHttpClient *pClient, const STRING_T &search) const
            {
                if (GetDevice() && GetDevice().Just().GetSearchMovies())
                {
                    RequestData requestData;

                    dto::Link link = GetDevice().Just().GetSearchMovies().Just();
                    link.SetParam("search", search);

                    requestData = RequestService::CreateRequestFromLink(DEVICE_SEARCHMOVIES_REQUEST, link);

                    pClient->DoRequest(requestData);
                    return true;
                }
                else
                    return false;
            }

            BOOL_T SearchSeries(IHttpClient *pClient, const STRING_T &search) const
            {
                if (GetDevice() && GetDevice().Just().GetSearchSeries())
                {
                    RequestData requestData;

                    dto::Link link = GetDevice().Just().GetSearchSeries().Just();
                    link.SetParam("search", search);

                    requestData = RequestService::CreateRequestFromLink(DEVICE_SEARCHSERIES_REQUEST, link);

                    pClient->DoRequest(requestData);
                    return true;
                }
                else
                    return false;
            }

            BOOL_T SearchBundles(IHttpClient *pClient, const STRING_T &search) const
            {
                if (GetDevice() && GetDevice().Just().GetSearchBundles())
                {
                    RequestData requestData;

                    dto::Link link = GetDevice().Just().GetSearchBundles().Just();
                    link.SetParam("search", search);

                    requestData = RequestService::CreateRequestFromLink(DEVICE_SEARCHBUNDLES_REQUEST, link);

                    pClient->DoRequest(requestData);
                    return true;
                }
                else
                    return false;
            }

            BOOL_T SearchMoviesByPerson(IHttpClient *pClient, const STRING_T &personId) const
            {
                if (GetDevice() && GetDevice().Just().GetSearchMoviesByPerson())
                {
                    RequestData requestData;

                    dto::Link link = GetDevice().Just().GetSearchMoviesByPerson().Just();
                    link.SetParam("personId", personId);

                    requestData = RequestService::CreateRequestFromLink(DEVICE_SEARCHMOVIESBYPERSON_REQUEST, link);

                    pClient->DoRequest(requestData);
                    return true;
                }
                else
                    return false;
            }

            const Maybe<dto::Device> &GetDevice() const
            {
                return mDevice;
            }

        protected:
            void SetDevice(const dto::Device &device)
            {
                mDevice = device;
            }

            virtual void OnReceivedResponse(const RequestData &requestData, const ResponseData &responseData)
            {
                dto::ParseErrors parseErrors;
                EVENT_PAYLOAD_TYPE payload;
                IEventPayload *pPayload = &payload;
                IEvent <EVENT_PAYLOAD_TYPE> *pEvent = &AuthDeviceEvent;

                pPayload->SetHttpStatusCode(responseData.GetStatusCode());

                if (responseData.GetStatusCode() == ResponseData::HTTP_STATUS_CODE_OK)
                {
                    dto::Device device;
                    if (device.InitFromJsonString(responseData.GetBody(), parseErrors))
                    {
                        SetDevice(device);
                    }
                    else
                    {
                        pPayload->SetMessage("Failed to parse Device.");
                    }
                    pEvent->Emit(payload);
                }
                else if (responseData.GetStatusCode() == ResponseData::HTTP_STATUS_CODE_NOT_FOUND && requestData.GetCallee() ==
                                                                                                     ROOT_AUTHDEVICE_REQUEST)
                {
                    dto::Form form;
                    if (form.InitFromJsonString(responseData.GetBody(), parseErrors) && form.GetAction() && form.GetMethod())
                    {
                        IHttpClient *pClient = this;
                        RequestData reqData = RequestService::CreateRequestFromForm(ROOT_ADDDEVICE_REQUEST, form);
                        pClient->DoRequest(reqData);
                    }
                    else
                    {
                        pPayload->SetMessage("Failed to parse FormTest for adding device.");
                        pEvent->Emit(payload);
                    }
                }
                else
                {
                    // @TODO: Add error reporting
                    pPayload->SetMessage("Unexpected devices response.");
                    pEvent->Emit(payload);
                }
            }

        public:
            EVENT_TYPE AuthDeviceEvent;

        private:
            Maybe <dto::Device> mDevice;
            BadHttpClientType mBadHttpClientType;
            BadEventType mBadEventType;
            BadEventPayloadType mBadEventPayloadType;
        };
    }
}

#endif //READY4AIR_SERVICES_DEVICESSERVICE_H
