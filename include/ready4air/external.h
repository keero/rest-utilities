#include "common.h"
#ifndef READY4AIR_REQUESTDATA_H
#define READY4AIR_REQUESTDATA_H
#include <string>
namespace ready4air
{
    typedef enum {
        ROOT_AUTHDEVICE_REQUEST = 1,
        ROOT_ADDDEVICE_REQUEST,
        DEVICE_HOME_REQUEST,
        DEVICE_HELPS_REQUEST,
        DEVICE_LITERALS_REQUEST,
        DEVICE_LOGIN_REQUEST,
        DEVICE_REGISTER_REQUEST,
        DEVICE_FORGOTPASSWORD_REQUEST,
        DEVICE_SELF_REQUEST,
        DEVICE_SEARCH_REQUEST,
        DEVICE_SEARCHASYOUTYPE_REQUEST,
        DEVICE_SEARCHMOVIES_REQUEST,
        DEVICE_SEARCHSERIES_REQUEST,
        DEVICE_SEARCHBUNDLES_REQUEST,
        DEVICE_SEARCHMOVIESBYPERSON_REQUEST,
        BUNDLE_SELF_REQUEST,
        MEDIA_SELF_REQUEST,
        MOVIE_SELF_REQUEST,
        SERIES_SELF_REQUEST,
        PAGINATED_NEXT_REQUEST,
        PAGINATED_PREV_REQUEST,
        USER_SELF_REQUEST
    } Callee;
    class RequestData
    {
    public:
        RequestData() : TAG("ready4air::RequestData")
        {
        }
        virtual ~RequestData()
        {
        }
        const STRING_T &GetURI() const
        {
            return mURI;
        }
        void SetURI(const STRING_T &URI)
        {
            mURI = URI;
        }
        const STRING_T &GetMethod() const
        {
            return mMethod;
        }
        void SetMethod(const STRING_T &method)
        {
            mMethod = method;
        }
        BOOL_T IsWithCredentials() const
        {
            return mWithCredentials;
        }
        void SetWithCredentials(BOOL_T withCredentials)
        {
            mWithCredentials = withCredentials;
        }
        const Maybe<STRING_T> &GetBody() const
        {
            return mBody;
        }
        void SetBody(const STRING_T &body)
        {
            mBody = body;
        }
        Callee GetCallee() const
        {
            return mCallee;
        }
        void SetCallee(Callee callee)
        {
            mCallee = callee;
        }
        inline friend std::ostream &operator<<(std::ostream &str, const RequestData &rhs)
        {
            str << rhs.GetMethod() << ' ' << rhs.GetURI() << ' ' << rhs.IsWithCredentials();
            if (rhs.GetBody())
                str << std::endl << rhs.GetBody();
            return str;
        }
    private:
        STRING_T mURI;
        STRING_T mMethod;
        BOOL_T mWithCredentials;
        Maybe <STRING_T> mBody;
        Callee mCallee;
        STRING_T TAG;
    };
}
#endif //READY4AIR_REQUESTDATA_H

#ifndef READY4AIR_SERVICES_RESPONSEDATA_H
#define READY4AIR_SERVICES_RESPONSEDATA_H
#include <string>
namespace ready4air
{
    class ResponseData
    {
    public:
        typedef enum
        {
            HTTP_STATUS_CODE_NONE = 0,
            HTTP_STATUS_CODE_OK = 200,
            HTTP_STATUS_CODE_NOT_MODIFIED = 304,
            HTTP_STATUS_CODE_UNAUTHORIZED = 401,
            HTTP_STATUS_CODE_PAYMENT_REQUIRED = 402,
            HTTP_STATUS_CODE_NOT_FOUND = 404,
            HTTP_STATUS_CODE_UNDEFINED = 999
        } HTTP_STATUS_CODE;
        ResponseData() : TAG("ready4air::ResponseData")
        {
        }
        virtual ~ResponseData()
        {
        }
        HTTP_STATUS_CODE GetStatusCode() const
        {
            return mStatusCode;
        }
        void SetStatusCode(HTTP_STATUS_CODE statusCode)
        {
            mStatusCode = statusCode;
        }
        const STRING_T &GetBody() const
        {
            return mBody;
        }
        void SetBody(const STRING_T &body)
        {
            mBody = body;
        }
        inline friend std::ostream &operator<<(std::ostream &str, const ResponseData &rhs)
        {
            return str << rhs.GetStatusCode() << " Content-Length: " << rhs.GetBody().length();
        }
    private:
        HTTP_STATUS_CODE mStatusCode;
        STRING_T mBody;
        STRING_T TAG;
    };
}
#endif //READY4AIR_SERVICES_RESPONSEDATA_H

#ifndef READ4AIR_IEVENTPAYLOAD_H
#define READ4AIR_IEVENTPAYLOAD_H
namespace ready4air
{
    class IEventPayload
    {
    public:
        virtual void SetHttpStatusCode(ResponseData::HTTP_STATUS_CODE httpStatusCode) = 0;
        virtual void SetMessage(const STRING_T &message) = 0;
    };
}
#endif //READ4AIR_IEVENTPAYLOAD_H

#ifndef READ4AIR_IEVENT_H
#define READ4AIR_IEVENT_H
namespace ready4air
{
    template<typename T>
    class IEvent
    {
    public:
        virtual void Emit(const T &payload) = 0;
    };
}
#endif //READ4AIR_IEVENT_H

#ifndef READY4AIR_IHTTPCLIENT_H
#define READY4AIR_IHTTPCLIENT_H
namespace ready4air
{
    class IHttpClient
    {
    public:
        virtual void DoRequest (const RequestData &requestData) = 0;
    protected:
        virtual void OnReceivedResponse(const RequestData &requestData, const ResponseData &responseData) = 0;
    };
}
#endif //READY4AIR_IHTTPCLIENT_H

