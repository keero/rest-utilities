#ifndef READY4AIR_REQUESTDATA_H
#define READY4AIR_REQUESTDATA_H

#include <string>
#include "../common/Maybe.h"

namespace ready4air
{
    class RequestData
    {
    public:
        RequestData()
        {
        }

        virtual ~RequestData()
        {
        }

        const std::string &GetURI() const
        {
            return mURI;
        }

        void SetURI(const std::string &URI)
        {
            mURI = URI;
        }

        const std::string &GetMethod() const
        {
            return mMethod;
        }

        void SetMethod(const std::string &method)
        {
            mMethod = method;
        }

        bool IsWithCredentials() const
        {
            return mWithCredentials;
        }

        void SetWithCredentials(bool withCredentials)
        {
            mWithCredentials = withCredentials;
        }

        const Maybe<std::string> &GetBody() const
        {
            return mBody;
        }

        void SetBody(const std::string &body)
        {
            mBody = body;
        }

        int GetCallee() const
        {
            return mCallee;
        }

        void SetCallee(int callee)
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
        std::string mURI;
        std::string mMethod;
        bool mWithCredentials;
        Maybe <std::string> mBody;
        int mCallee;
    };
}

#endif //READY4AIR_REQUESTDATA_H
