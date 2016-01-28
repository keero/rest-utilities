#ifndef READY4AIR_REQUESTDATA_H
#define READY4AIR_REQUESTDATA_H

#include <string>
#include "../common/Maybe.h"

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
        const STRING_T TAG;
    };
}

#endif //READY4AIR_REQUESTDATA_H
