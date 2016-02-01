#include "dto.h"
#include "external.h"
#ifndef READY4AIR_SERVICES_REQUESTSERVICE_H
#define READY4AIR_SERVICES_REQUESTSERVICE_H
namespace ready4air
{
    namespace services
    {
        class RequestService
        {
        public:
            static const RequestData CreateRequestFromLink(Callee callee, dto::Link &link)
            {
                RequestData requestData;
                requestData.SetURI(link.GetExpandedUrl());
                requestData.SetMethod("GET");
                requestData.SetWithCredentials(link.GetWithCredentials() ? link.GetWithCredentials().Just() : false);
                requestData.SetCallee(callee);
                return requestData;
            }
            static const RequestData CreateRequestFromForm(Callee callee, dto::Form &form)
            {
                RequestData requestData;
                if (form.GetAction())
                {
                    requestData.SetURI(form.GetAction().Just().GetExpandedUrl());
                    requestData.SetWithCredentials(
                            form.GetAction().Just().GetWithCredentials()
                            ? form.GetAction().Just().GetWithCredentials().Just() : false);
                }
                requestData.SetMethod(form.GetMethod() ? form.GetMethod().Just() : "");
                requestData.SetCallee(callee);
                return requestData;
            }
        };
    }
}
#endif //READY4AIR_SERVICES_REQUESTSERVICE_H

#ifndef READY4AIR_ERROR_H
#define READY4AIR_ERROR_H
namespace ready4air
{
    class Error
    {
    public:
        Error() : TAG("ready4air::Error")
        {
        }
        virtual ~Error()
        {
        }
        ResponseData::HTTP_STATUS_CODE GetHttpStatusCode() const
        {
            return mHttpStatusCode;
        }
        void SetHttpStatusCode(ResponseData::HTTP_STATUS_CODE httpStatusCode)
        {
            mHttpStatusCode = httpStatusCode;
        }
        const STRING_T &GetMessage() const
        {
            return mMessage;
        }
        void SetMessage(const STRING_T &message)
        {
            mMessage = message;
        }
        const dto::ParseErrors &GetParseErrors() const
        {
            return mParseErrors;
        }
        void SetParseErrors(const dto::ParseErrors &parseErrors)
        {
            mParseErrors = parseErrors;
        }
    private:
        ResponseData::HTTP_STATUS_CODE mHttpStatusCode;
        STRING_T mMessage;
        dto::ParseErrors mParseErrors;
        STRING_T TAG;
    };
}
#endif //READY4AIR_ERROR_H

#ifndef READY4AIR_SERVICES_BADHTTPCLIENTTYPE_H
#define READY4AIR_SERVICES_BADHTTPCLIENTTYPE_H
#include <exception>
namespace ready4air
{
    class BadHttpClientType : public std::exception
    {
        virtual const INT8_T *what() const throw()
        {
            return "Template class HTTP_CLIENT_TYPE must implement ready4air::IHttpClient";
        }
    };
}
#endif //READY4AIR_SERVICES_BADHTTPCLIENTTYPE_H

#ifndef READY4AIR_SERVICES_BADEVENTTYPE_H
#define READY4AIR_SERVICES_BADEVENTTYPE_H
#include <exception>
namespace ready4air
{
    class BadEventType : public std::exception
    {
        virtual const INT8_T *what() const throw()
        {
            return "Template class EVENT_TYPE must implement ready4air::IEvent";
        }
    };
}
#endif //READY4AIR_SERVICES_BADEVENTTYPE_H

#ifndef READY4AIR_SERVICES_BADEVENTPAYLOADTYPE_H
#define READY4AIR_SERVICES_BADEVENTPAYLOADTYPE_H
#include <exception>
namespace ready4air
{
    class BadEventPayloadType : public std::exception
    {
        virtual const INT8_T *what() const throw()
        {
            return "Template class EVENT_PAYLOAD_TYPE must implement ready4air::IEventPayload";
        }
    };
}
#endif //READY4AIR_SERVICES_BADEVENTPAYLOADTYPE_H

#ifndef READY4AIR_SERVICES_BADPAGINATEDTYPE_H
#define READY4AIR_SERVICES_BADPAGINATEDTYPE_H
#include <exception>
namespace ready4air
{
    class BadPaginatedType : public std::exception
    {
        virtual const INT8_T *what() const throw()
        {
            return "Template class SERVICE_TYPE must implement ready4air::dto::IJsonDeserializable";
        }
    };
}
#endif //READY4AIR_SERVICES_BADPAGINATEDTYPE_H

#ifndef READY4AIR_SERVICES_PAGESSERVICE_H
#define READY4AIR_SERVICES_PAGESSERVICE_H
namespace ready4air
{
    namespace services
    {
        template <typename HTTP_CLIENT_TYPE, typename EVENT_TYPE, typename EVENT_PAYLOAD_TYPE>
        class PagesService : public HTTP_CLIENT_TYPE
        {
        public:
            PagesService() : TAG("ready4air::services::PagesService")
            {
                if (!std::is_base_of<IHttpClient, HTTP_CLIENT_TYPE>::value) throw mBadHttpClientType;
                if (!std::is_base_of<IEventPayload, EVENT_PAYLOAD_TYPE>::value) throw mBadEventPayloadType;
                if (!std::is_base_of<IEvent <EVENT_PAYLOAD_TYPE>, EVENT_TYPE>::value) throw mBadEventType;
            }
            virtual ~PagesService()
            {
            }
            const Maybe<dto::Page> &GetPage() const
            {
                return mPage;
            }
        protected:
            void SetPage(const dto::Page &page)
            {
                mPage = page;
            }
            virtual void OnReceivedResponse(const RequestData &requestData, const ResponseData &responseData)
            {
                UNUSED(requestData);
                dto::ParseErrors parseErrors;
                EVENT_PAYLOAD_TYPE payload;
                IEventPayload *pPayload = &payload;
                IEvent <EVENT_PAYLOAD_TYPE> *pEvent = &HomeEvent;
                pPayload->SetHttpStatusCode(responseData.GetStatusCode());
                if (responseData.GetStatusCode() == ResponseData::HTTP_STATUS_CODE_OK)
                {
                    dto::Page page;
                    if (page.InitFromJsonString(responseData.GetBody(), parseErrors))
                    {
                        SetPage(page);
                    }
                    else
                    {
                        pPayload->SetMessage("Failed to parse Page.");
                    }
                }
                else
                {
                    // @TODO: Add error reporting
                    pPayload->SetMessage("Unexpected pages response.");
                }
                pEvent->Emit(payload);
            }
        public:
            EVENT_TYPE HomeEvent;
        private:
            Maybe <dto::Page> mPage;
            BadHttpClientType mBadHttpClientType;
            BadEventType mBadEventType;
            BadEventPayloadType mBadEventPayloadType;
            STRING_T TAG;
        };
    }
}
#endif //READY4AIR_SERVICES_PAGESSERVICE_H

#ifndef READY4AIR_SERVICES_HELPSSERVICE_H
#define READY4AIR_SERVICES_HELPSSERVICE_H
namespace ready4air
{
    namespace services
    {
        template <typename HTTP_CLIENT_TYPE, typename EVENT_TYPE, typename EVENT_PAYLOAD_TYPE>
        class HelpsService : public HTTP_CLIENT_TYPE
        {
        public:
            HelpsService() : TAG("ready4air::services::HelpsService")
            {
                if (!std::is_base_of<IHttpClient, HTTP_CLIENT_TYPE>::value) throw mBadHttpClientType;
                if (!std::is_base_of<IEventPayload, EVENT_PAYLOAD_TYPE>::value) throw mBadEventPayloadType;
                if (!std::is_base_of<IEvent <EVENT_PAYLOAD_TYPE>, EVENT_TYPE>::value) throw mBadEventType;
            }
            virtual ~HelpsService()
            {
            }
            const Maybe<dto::Help> &GetHelp() const
            {
                return mHelp;
            }
        protected:
            void SetHelp(const dto::Help &help)
            {
                mHelp = help;
            }
            virtual void OnReceivedResponse(const RequestData &requestData, const ResponseData &responseData)
            {
                UNUSED(requestData);
                dto::ParseErrors parseErrors;
                EVENT_PAYLOAD_TYPE payload;
                IEventPayload *pPayload = &payload;
                IEvent <EVENT_PAYLOAD_TYPE> *pEvent = &HelpsEvent;
                pPayload->SetHttpStatusCode(responseData.GetStatusCode());
                if (responseData.GetStatusCode() == ResponseData::HTTP_STATUS_CODE_OK)
                {
                    dto::Help help;
                    if (help.InitFromJsonString(responseData.GetBody(), parseErrors))
                    {
                        SetHelp(help);
                    }
                    else
                    {
                        pPayload->SetMessage("Failed to parse Help.");
                    }
                }
                else
                {
                    // @TODO: Add error reporting
                    pPayload->SetMessage("Unexpected helps response.");
                }
                pEvent->Emit(payload);
            }
        public:
            EVENT_TYPE HelpsEvent;
        private:
            Maybe <dto::Help> mHelp;
            BadHttpClientType mBadHttpClientType;
            BadEventType mBadEventType;
            BadEventPayloadType mBadEventPayloadType;
            STRING_T TAG;
        };
    }
}
#endif //READY4AIR_SERVICES_HELPSSERVICE_H

#ifndef READY4AIR_SERVICES_LITERALSSERVICE_H
#define READY4AIR_SERVICES_LITERALSSERVICE_H
namespace ready4air
{
    namespace services
    {
        typedef MAP_T <STRING_T, dto::Literal> Literals;
        template <typename HTTP_CLIENT_TYPE, typename EVENT_TYPE, typename EVENT_PAYLOAD_TYPE>
        class LiteralsService : public HTTP_CLIENT_TYPE
        {
        public:
            LiteralsService() : TAG("ready4air::services::LiteralsService")
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
            STRING_T TAG;
        };
    }
}
#endif //READY4AIR_SERVICES_LITERALSSERVICE_H

#ifndef READY4AIR_SERVICES_USERSSERVICE_H
#define READY4AIR_SERVICES_USERSSERVICE_H
namespace ready4air
{
    namespace services
    {
        template <typename HTTP_CLIENT_TYPE, typename EVENT_TYPE, typename EVENT_PAYLOAD_TYPE>
        class UsersService : public HTTP_CLIENT_TYPE
        {
        public:
            UsersService() : TAG("ready4air::services::UsersService")
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
            STRING_T TAG;
        };
    }
}
#endif //READY4AIR_SERVICES_USERSSERVICE_H

#ifndef READY4AIR_SERVICES_PAGINATEDSERVICE_H
#define READY4AIR_SERVICES_PAGINATEDSERVICE_H
namespace ready4air
{
    namespace services
    {
        template <typename SERVICE_TYPE, typename HTTP_CLIENT_TYPE, typename EVENT_TYPE, typename EVENT_PAYLOAD_TYPE>
        class PaginationService : public HTTP_CLIENT_TYPE
        {
        public:
            PaginationService() : TAG("ready4air::services::PaginationService")
            {
                if (!std::is_base_of<IHttpClient, HTTP_CLIENT_TYPE>::value) throw mBadHttpClientType;
                if (!std::is_base_of<IEventPayload, EVENT_PAYLOAD_TYPE>::value) throw mBadEventPayloadType;
                if (!std::is_base_of<IEvent <EVENT_PAYLOAD_TYPE>, EVENT_TYPE>::value) throw mBadEventType;
                if (!std::is_base_of<dto::IJsonDeserializable, SERVICE_TYPE>::value) throw mBadPaginatedType;
            }
            virtual ~PaginationService()
            {
            }
            BOOL_T Next(void) const
            {
                if (GetPaginated() && GetPaginated().Just().GetNext())
                {
                    IHttpClient *pClient = this;
                    RequestData requestData;
                    dto::Link link = GetPaginated().Just().GetNext().Just();
                    requestData = RequestService::CreateRequestFromLink(PAGINATED_NEXT_REQUEST, link);
                    pClient->DoRequest(requestData);
                    return true;
                }
                else
                    return false;
            }
            BOOL_T Prev(void) const
            {
                if (GetPaginated() && GetPaginated().Just().GetPrev())
                {
                    IHttpClient *pClient = this;
                    RequestData requestData;
                    dto::Link link = GetPaginated().Just().GetPrev().Just();
                    requestData = RequestService::CreateRequestFromLink(PAGINATED_PREV_REQUEST, link);
                    pClient->DoRequest(requestData);
                    return true;
                }
                else
                    return false;
            }
            const Maybe <VECTOR_T <SERVICE_TYPE> > &GetItems() const
            {
                return GetPaginated().Just().GetItems();
            }
        protected:
            void SetPaginated(const dto::GenericPage <SERVICE_TYPE> &genericPage)
            {
                mPaginated = genericPage;
            }
            const Maybe <dto::GenericPage <SERVICE_TYPE> > &GetPaginated() const
            {
                return mPaginated;
            }
            virtual void OnReceivedResponse(const RequestData &requestData, const ResponseData &responseData)
            {
                dto::ParseErrors parseErrors;
                EVENT_PAYLOAD_TYPE payload;
                IEventPayload *pPayload = &payload;
                IEvent <EVENT_PAYLOAD_TYPE> *pEvent = &PaginatedEvent;
                pPayload->SetHttpStatusCode(responseData.GetStatusCode());
                switch (requestData.GetCallee())
                {
                    case PAGINATED_NEXT_REQUEST:
                    case PAGINATED_PREV_REQUEST:
                    default:
                        break;
                }
                if (responseData.GetStatusCode() == ResponseData::HTTP_STATUS_CODE_OK)
                {
                    dto::GenericPage <SERVICE_TYPE> paginated;
                    if (paginated.InitFromJsonString(responseData.GetBody(), parseErrors))
                    {
                        SetPaginated(paginated);
                    }
                    else
                    {
                        pPayload->SetMessage("Failed to parse GenericPage.");
                    }
                }
                else
                {
                    // @TODO: Add error reporting
                    pPayload->SetMessage("Unexpected paginated response.");
                }
                pEvent->Emit(payload);
            }
        public:
            EVENT_TYPE PaginatedEvent;
        private:
            Maybe <dto::GenericPage <SERVICE_TYPE> > mPaginated;
            BadHttpClientType mBadHttpClientType;
            BadEventType mBadEventType;
            BadEventPayloadType mBadEventPayloadType;
            BadPaginatedType mBadPaginatedType;
            STRING_T TAG;
        };
    }
}
#endif //READY4AIR_SERVICES_PAGINATEDSERVICE_H

#ifndef READY4AIR_SERVICES_MEDIASSERVICE_H
#define READY4AIR_SERVICES_MEDIASSERVICE_H
namespace ready4air
{
    namespace services
    {
        template <typename HTTP_CLIENT_TYPE, typename EVENT_TYPE, typename EVENT_PAYLOAD_TYPE>
        class MediasService : public HTTP_CLIENT_TYPE, public dto::IJsonDeserializable
        {
        public:
            MediasService() : TAG("ready4air::services::MediasService")
            {
                if (!std::is_base_of<IHttpClient, HTTP_CLIENT_TYPE>::value) throw mBadHttpClientType;
                if (!std::is_base_of<IEventPayload, EVENT_PAYLOAD_TYPE>::value) throw mBadEventPayloadType;
                if (!std::is_base_of<IEvent <EVENT_PAYLOAD_TYPE>, EVENT_TYPE>::value) throw mBadEventType;
            }
            virtual ~MediasService()
            {
            }
            const Maybe<dto::MediaProduct> &GetMedia() const
            {
                return mMedia;
            }
            virtual BOOL_T InitFromJsonValue(const rapidjson::Value &value, dto::ParseErrors &parseErrors)
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
            virtual void OnReceivedResponse(const RequestData &requestData, const ResponseData &responseData)
            {
                dto::ParseErrors parseErrors;
                EVENT_PAYLOAD_TYPE payload;
                IEventPayload *pPayload = &payload;
                IEvent <EVENT_PAYLOAD_TYPE> *pEvent = &MediaEvent;
                pPayload->SetHttpStatusCode(responseData.GetStatusCode());
                switch (requestData.GetCallee())
                {
                    case MEDIA_SELF_REQUEST:
                    default:
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
                            pPayload->SetMessage("Failed to parse Media.");
                        }
                        break;
                    }
                    default:
                        // @TODO: Add error reporting
                        pPayload->SetMessage("Unexpected medias response.");
                        break;
                }
                pEvent->Emit(payload);
            }
        public:
            EVENT_TYPE MediaEvent;
        private:
            Maybe <dto::MediaProduct> mMedia;
            BadHttpClientType mBadHttpClientType;
            BadEventType mBadEventType;
            BadEventPayloadType mBadEventPayloadType;
            STRING_T TAG;
        };
    }
}
#endif //READY4AIR_SERVICES_MEDIASSERVICE_H

#ifndef READY4AIR_SERVICES_MOVIESSERVICE_H
#define READY4AIR_SERVICES_MOVIESSERVICE_H
namespace ready4air
{
    namespace services
    {
        template <typename HTTP_CLIENT_TYPE, typename EVENT_TYPE, typename EVENT_PAYLOAD_TYPE>
        class MoviesService : public HTTP_CLIENT_TYPE, public dto::IJsonDeserializable
        {
        public:
            MoviesService() : TAG("ready4air::services::MoviesService")
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
            STRING_T TAG;
        };
    }
}
#endif //READY4AIR_SERVICES_MOVIESSERVICE_H

#ifndef READY4AIR_SERVICES_SERIESSERVICE_H
#define READY4AIR_SERVICES_SERIESSERVICE_H
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

#ifndef READY4AIR_SERVICES_BUNDLESSERVICE_H
#define READY4AIR_SERVICES_BUNDLESSERVICE_H
namespace ready4air
{
    namespace services
    {
        template <typename HTTP_CLIENT_TYPE, typename EVENT_TYPE, typename EVENT_PAYLOAD_TYPE>
        class BundlesService : public HTTP_CLIENT_TYPE, public dto::IJsonDeserializable
        {
        public:
            BundlesService() : TAG("ready4air::services::BundlesService")
            {
                if (!std::is_base_of<IHttpClient, HTTP_CLIENT_TYPE>::value) throw mBadHttpClientType;
                if (!std::is_base_of<IEventPayload, EVENT_PAYLOAD_TYPE>::value) throw mBadEventPayloadType;
                if (!std::is_base_of<IEvent <EVENT_PAYLOAD_TYPE>, EVENT_TYPE>::value) throw mBadEventType;
            }
            virtual ~BundlesService()
            {
            }
            const Maybe<dto::Bundle> &GetBundle() const
            {
                return mBundle;
            }
            virtual BOOL_T InitFromJsonValue(const rapidjson::Value &value, dto::ParseErrors &parseErrors)
            {
                dto::Bundle bundle;
                if (bundle.InitFromJsonValue(value, parseErrors))
                {
                    SetBundle(bundle);
                    return true;
                }
                else
                    return false;
            }
        protected:
            void SetBundle(const dto::Bundle &bundle)
            {
                mBundle = bundle;
            }
            virtual void OnReceivedResponse(const RequestData &requestData, const ResponseData &responseData)
            {
                dto::ParseErrors parseErrors;
                EVENT_PAYLOAD_TYPE payload;
                IEventPayload *pPayload = &payload;
                IEvent <EVENT_PAYLOAD_TYPE> *pEvent = &BundleEvent;
                pPayload->SetHttpStatusCode(responseData.GetStatusCode());
                switch (requestData.GetCallee())
                {
                    case BUNDLE_SELF_REQUEST:
                    default:
                        break;
                }
                switch (responseData.GetStatusCode())
                {
                    case ResponseData::HTTP_STATUS_CODE_OK:
                    {
                        dto::Bundle bundle;
                        if (bundle.InitFromJsonString(responseData.GetBody(), parseErrors))
                        {
                            SetBundle(bundle);
                        }
                        else
                        {
                            pPayload->SetMessage("Failed to parse Bundle.");
                        }
                        break;
                    }
                    default:
                        // @TODO: Add error reporting
                        pPayload->SetMessage("Unexpected bundles response.");
                        break;
                }
                pEvent->Emit(payload);
            }
        public:
            EVENT_TYPE BundleEvent;
        private:
            Maybe <dto::Bundle> mBundle;
            BadHttpClientType mBadHttpClientType;
            BadEventType mBadEventType;
            BadEventPayloadType mBadEventPayloadType;
            STRING_T TAG;
        };
    }
}
#endif //READY4AIR_SERVICES_BUNDLESSERVICE_H

#ifndef READY4AIR_SERVICES_DEVICESSERVICE_H
#define READY4AIR_SERVICES_DEVICESSERVICE_H
namespace ready4air
{
    namespace services
    {
        template <typename HTTP_CLIENT_TYPE, typename EVENT_TYPE, typename EVENT_PAYLOAD_TYPE>
        class DevicesService : public HTTP_CLIENT_TYPE
        {
        public:
            DevicesService() : TAG("ready4air::services::DevicesService")
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
            STRING_T TAG;
        };
    }
}
#endif //READY4AIR_SERVICES_DEVICESSERVICE_H

#ifndef READY4AIR_SERVICES_ROOT_H
#define READY4AIR_SERVICES_ROOT_H
namespace ready4air
{
    namespace services
    {
        class Root
        {
        private:
        public:
            Root() : TAG("ready4air::services::Root")
            {
            }
            virtual ~Root()
            {
            }
            void Init(const STRING_T &serviceRootURL)
            {
                mServiceRoot.SetHref(serviceRootURL);
                mServiceRoot.SetTemplated(true);
                mServiceRoot.SetWithCredentials(true);
            }
            BOOL_T AuthDevice(IHttpClient *pClient, const STRING_T &apiKey, const STRING_T &manufacturer, const STRING_T &model, const STRING_T &udid)
            {
                RequestData requestData;
                mServiceRoot.SetParam("apiKey", apiKey);
                mServiceRoot.SetParam("manufacturer", manufacturer);
                mServiceRoot.SetParam("model", model);
                mServiceRoot.SetParam("udid", udid);
                requestData = RequestService::CreateRequestFromLink(ROOT_AUTHDEVICE_REQUEST, mServiceRoot);
                pClient->DoRequest(requestData);
                return true;
            }
        private:
            dto::Link mServiceRoot;
            STRING_T TAG;
        };
    }
}
#endif //READY4AIR_SERVICES_ROOT_H

