#ifndef READY4AIR_SERVICES_DEVICESSERVICE_H
#define READY4AIR_SERVICES_DEVICESSERVICE_H


#include "../dto/Device.h"
#include "../external/IHttpClient.h"
#include "../external/IEvent.h"
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
        typedef Maybe <Error> AuthDeviceResponse;

        template <typename HTTP_CLIENT_TYPE, typename EVENT_TYPE>
        class DevicesService : public HTTP_CLIENT_TYPE
        {
        public:
            typedef enum {
                AUTH_DEVICE_REQUEST = 1,
                REAUTH_DEVICE_REQUEST,
                SELF_DEVICE_REQUEST,
                ADD_DEVICE_REQUEST
            } _;

            DevicesService()
            {
                if (!std::is_base_of<IHttpClient, HTTP_CLIENT_TYPE>::value) throw mBadHttpClientType;
                if (!std::is_base_of<IEvent <AuthDeviceResponse>, EVENT_TYPE>::value) throw mBadEventType;
            }

            virtual ~DevicesService()
            {
            }

            bool Home(PagesService <HTTP_CLIENT_TYPE, EVENT_TYPE> &pagesService, const std::string &language) const
            {
                if (GetDevice() && GetDevice().Just().GetHome())
                {
                    IHttpClient *pClient = &pagesService;
                    RequestData requestData;

                    dto::Link link = GetDevice().Just().GetHome().Just();
                    link.SetParam("language", language);

                    requestData = GetRequestService().CreateRequestFromLink(PagesService <HTTP_CLIENT_TYPE, EVENT_TYPE>::HOME_PAGE_REQUEST, link);

                    pClient->DoRequest(requestData);
                    return true;
                }
                else
                    return false;
            }

            bool Helps(HelpsService <HTTP_CLIENT_TYPE, EVENT_TYPE> &helpsService, const std::string &language) const
            {
                if (GetDevice() && GetDevice().Just().GetHelps())
                {
                    IHttpClient *pClient = &helpsService;
                    RequestData requestData;

                    dto::Link link = GetDevice().Just().GetHelps().Just();
                    link.SetParam("language", language);

                    requestData = GetRequestService().CreateRequestFromLink(HelpsService <HTTP_CLIENT_TYPE, EVENT_TYPE>::HELPS_REQUEST, link);

                    pClient->DoRequest(requestData);
                    return true;
                }
                else
                    return false;
            }

            bool Literals(LiteralsService <HTTP_CLIENT_TYPE, EVENT_TYPE> &literalsService, const std::string &language) const
            {
                if (GetDevice() && GetDevice().Just().GetLiterals())
                {
                    IHttpClient *pClient = &literalsService;
                    RequestData requestData;

                    dto::Link link = GetDevice().Just().GetLiterals().Just();
                    link.SetParam("language", language);

                    requestData = GetRequestService().CreateRequestFromLink(LiteralsService <HTTP_CLIENT_TYPE, EVENT_TYPE>::LITERALS_REQUEST, link);

                    pClient->DoRequest(requestData);
                    return true;
                }
                else
                    return false;
            }

            bool Login(UsersService <HTTP_CLIENT_TYPE, EVENT_TYPE> &usersService, const std::string &username, const std::string &password) const
            {
                if (GetDevice() && GetDevice().Just().GetLogin())
                {
                    IHttpClient *pClient = &usersService;
                    RequestData requestData;

                    dto::Link link = GetDevice().Just().GetLogin().Just();
                    link.SetParam("username", username);
                    link.SetParam("password", password);

                    requestData = GetRequestService().CreateRequestFromLink(UsersService <HTTP_CLIENT_TYPE, EVENT_TYPE>::LOGIN_USER_REQUEST, link);

                    pClient->DoRequest(requestData);
                    return true;
                }
                else
                    return false;
            }

            bool Register(UsersService <HTTP_CLIENT_TYPE, EVENT_TYPE> &usersService, const std::string &email, const std::string &password) const
            {
                if (GetDevice() && GetDevice().Just().GetRegister() && GetDevice().Just().GetRegister().Just().GetAction())
                {
                    IHttpClient *pClient = &usersService;
                    RequestData requestData;

                    dto::Form form = GetDevice().Just().GetRegister().Just();
                    dto::Link link = form.GetAction().Just();
                    link.SetParam("email", email);
                    link.SetParam("password", password);

                    requestData.SetURI(link.GetExpandedUrl());
                    requestData.SetWithCredentials(link.GetWithCredentials() ? link.GetWithCredentials().Just() : false);
                    requestData.SetMethod(form.GetMethod() ? form.GetMethod().Just() : "POST");
                    requestData.SetCallee(UsersService <HTTP_CLIENT_TYPE, EVENT_TYPE>::REGISTER_USER_REQUEST);

                    pClient->DoRequest(requestData);
                    return true;
                }
                else
                    return false;
            }

            bool ForgotPassword(UsersService <HTTP_CLIENT_TYPE, EVENT_TYPE> &usersService, const std::string &userName) const
            {
                if (GetDevice() && GetDevice().Just().GetForgotPassword() && GetDevice().Just().GetForgotPassword().Just().GetAction())
                {
                    IHttpClient *pClient = &usersService;
                    RequestData requestData;

                    dto::Form form = GetDevice().Just().GetForgotPassword().Just();
                    dto::Link link = form.GetAction().Just();
                    link.SetParam("userName", userName);

                    requestData.SetURI(link.GetExpandedUrl());
                    requestData.SetWithCredentials(link.GetWithCredentials() ? link.GetWithCredentials().Just() : false);
                    requestData.SetMethod(form.GetMethod() ? form.GetMethod().Just() : "PUT");
                    requestData.SetCallee(UsersService <HTTP_CLIENT_TYPE, EVENT_TYPE>::FORGOT_PASSWORD_USER_REQUEST);

                    pClient->DoRequest(requestData);
                    return true;
                }
                else
                    return false;
            }

            bool Self(void) const
            {
                if (GetDevice() && GetDevice().Just().GetSelf())
                {
                    IHttpClient *pClient = this;
                    RequestData requestData;

                    dto::Link link = GetDevice().Just().GetSelf().Just();

                    requestData = GetRequestService().CreateRequestFromLink(SELF_DEVICE_REQUEST, link);

                    pClient->DoRequest(requestData);
                    return true;
                }
                else
                    return false;

            }

            bool Search(PaginationService <MediasService <HTTP_CLIENT_TYPE, EVENT_TYPE>, HTTP_CLIENT_TYPE, EVENT_TYPE> &paginationService, const std::string &search) const
            {
                if (GetDevice() && GetDevice().Just().GetSearch())
                {
                    IHttpClient *pClient = &paginationService;
                    RequestData requestData;

                    dto::Link link = GetDevice().Just().GetSearch().Just();
                    link.SetParam("search", search);

                    requestData = GetRequestService().CreateRequestFromLink(PaginationService <MediasService <HTTP_CLIENT_TYPE, EVENT_TYPE>, HTTP_CLIENT_TYPE, EVENT_TYPE>::FIRST_PAGINATED_REQUEST, link);

                    pClient->DoRequest(requestData);
                    return true;
                }
                else
                    return false;
            }

            bool SearchAsYouType(PaginationService <MediasService <HTTP_CLIENT_TYPE, EVENT_TYPE>, HTTP_CLIENT_TYPE, EVENT_TYPE> &paginationService, const std::string &search) const
            {
                if (GetDevice() && GetDevice().Just().GetSearchAsYouType())
                {
                    IHttpClient *pClient = &paginationService;
                    RequestData requestData;

                    dto::Link link = GetDevice().Just().GetSearchAsYouType().Just();
                    link.SetParam("search", search);

                    requestData = GetRequestService().CreateRequestFromLink(PaginationService <MediasService <HTTP_CLIENT_TYPE, EVENT_TYPE>, HTTP_CLIENT_TYPE, EVENT_TYPE>::FIRST_PAGINATED_REQUEST, link);

                    pClient->DoRequest(requestData);
                    return true;
                }
                else
                    return false;
            }

            bool SearchMovies(PaginationService <MoviesService <HTTP_CLIENT_TYPE, EVENT_TYPE>, HTTP_CLIENT_TYPE, EVENT_TYPE> &paginationService, const std::string &search) const
            {
                if (GetDevice() && GetDevice().Just().GetSearchMovies())
                {
                    IHttpClient *pClient = &paginationService;
                    RequestData requestData;

                    dto::Link link = GetDevice().Just().GetSearchMovies().Just();
                    link.SetParam("search", search);

                    requestData = GetRequestService().CreateRequestFromLink(PaginationService <MoviesService <HTTP_CLIENT_TYPE, EVENT_TYPE>, HTTP_CLIENT_TYPE, EVENT_TYPE>::FIRST_PAGINATED_REQUEST, link);

                    pClient->DoRequest(requestData);
                    return true;
                }
                else
                    return false;
            }

            bool SearchSeries(PaginationService <SeriesService <HTTP_CLIENT_TYPE, EVENT_TYPE>, HTTP_CLIENT_TYPE, EVENT_TYPE> &paginationService, const std::string &search) const
            {
                if (GetDevice() && GetDevice().Just().GetSearchSeries())
                {
                    IHttpClient *pClient = &paginationService;
                    RequestData requestData;

                    dto::Link link = GetDevice().Just().GetSearchSeries().Just();
                    link.SetParam("search", search);

                    requestData = GetRequestService().CreateRequestFromLink(PaginationService <SeriesService <HTTP_CLIENT_TYPE, EVENT_TYPE>, HTTP_CLIENT_TYPE, EVENT_TYPE>::FIRST_PAGINATED_REQUEST, link);

                    pClient->DoRequest(requestData);
                    return true;
                }
                else
                    return false;
            }

            bool SearchBundles(PaginationService <BundlesService <HTTP_CLIENT_TYPE, EVENT_TYPE>, HTTP_CLIENT_TYPE, EVENT_TYPE> &paginationService, const std::string &search) const
            {
                if (GetDevice() && GetDevice().Just().GetSearchBundles())
                {
                    IHttpClient *pClient = &paginationService;
                    RequestData requestData;

                    dto::Link link = GetDevice().Just().GetSearchBundles().Just();
                    link.SetParam("search", search);

                    requestData = GetRequestService().CreateRequestFromLink(PaginationService <BundlesService <HTTP_CLIENT_TYPE, EVENT_TYPE>, HTTP_CLIENT_TYPE, EVENT_TYPE>::FIRST_PAGINATED_REQUEST, link);

                    pClient->DoRequest(requestData);
                    return true;
                }
                else
                    return false;
            }

            bool SearchMoviesByPerson(PaginationService <MoviesService <HTTP_CLIENT_TYPE, EVENT_TYPE>, HTTP_CLIENT_TYPE, EVENT_TYPE> &paginationService, const std::string &personId) const
            {
                if (GetDevice() && GetDevice().Just().GetSearchMoviesByPerson())
                {
                    IHttpClient *pClient = &paginationService;
                    RequestData requestData;

                    dto::Link link = GetDevice().Just().GetSearchMoviesByPerson().Just();
                    link.SetParam("personId", personId);

                    requestData = GetRequestService().CreateRequestFromLink(PaginationService <MoviesService <HTTP_CLIENT_TYPE, EVENT_TYPE>, HTTP_CLIENT_TYPE, EVENT_TYPE>::FIRST_PAGINATED_REQUEST, link);

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

            const EVENT_TYPE &GetAuthDeviceEvent() const
            {
                return mAuthDeviceEvent;
            }

        protected:
            void SetDevice(const dto::Device &device)
            {
                mDevice = device;
            }

            const RequestService &GetRequestService() const
            {
                return mRequestService;
            }

            virtual void OnReceivedResponse(const RequestData &requestData, const ResponseData &responseData)
            {
                dto::ParseErrors parseErrors;
                AuthDeviceResponse payload;
                Error error;
                IEvent <AuthDeviceResponse> *pEvent = &mAuthDeviceEvent;

                error.SetHttpStatusCode(responseData.GetStatusCode());

                if (responseData.GetStatusCode() == ResponseData::HTTP_STATUS_CODE_OK)
                {
                    dto::Device device;
                    if (device.InitFromJsonString(responseData.GetBody(), parseErrors))
                    {
                        SetDevice(device);
                    }
                    else
                    {
                        error.SetMessage("Failed to parse Device.");
                        error.SetParseErrors(parseErrors);
                        payload = error;
                    }
                    pEvent->Emit(payload);
                }
                else if (responseData.GetStatusCode() == ResponseData::HTTP_STATUS_CODE_NOT_FOUND && requestData.GetCallee() == AUTH_DEVICE_REQUEST)
                {
                    dto::Form form;
                    if (form.InitFromJsonString(responseData.GetBody(), parseErrors) && form.GetAction() && form.GetMethod())
                    {
                        IHttpClient *pClient = this;
                        RequestData reqData;
                        dto::Link actionLink = form.GetAction().Just();
                        reqData.SetURI(actionLink.GetExpandedUrl());
                        reqData.SetMethod(form.GetMethod().Just());
                        reqData.SetCallee(ADD_DEVICE_REQUEST);
                        pClient->DoRequest(requestData);
                    }
                    else
                    {
                        error.SetMessage("Failed to parse Form for adding device.");
                        error.SetParseErrors(parseErrors);
                        payload = error;
                        pEvent->Emit(payload);
                    }
                }
                else
                {
                    // @TODO: Add error reporting
                    error.SetMessage("Unexpected devices response.");
                    payload = error;
                    pEvent->Emit(payload);
                }
            }

        private:
            EVENT_TYPE mAuthDeviceEvent;
            Maybe <dto::Device> mDevice;
            RequestService mRequestService;
            BadHttpClientType mBadHttpClientType;
            BadEventType mBadEventType;
        };
    }
}

#endif //READY4AIR_SERVICES_DEVICESSERVICE_H
