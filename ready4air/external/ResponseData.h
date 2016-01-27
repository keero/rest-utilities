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

        ResponseData()
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

        const std::string &GetBody() const
        {
            return mBody;
        }

        void SetBody(const std::string &body)
        {
            mBody = body;
        }

        inline friend std::ostream &operator<<(std::ostream &str, const ResponseData &rhs)
        {
            return str << rhs.GetStatusCode() << " Content-Length: " << rhs.GetBody().length();
        }

    private:
        HTTP_STATUS_CODE mStatusCode;
        std::string mBody;
    };
}

#endif //READY4AIR_SERVICES_RESPONSEDATA_H
