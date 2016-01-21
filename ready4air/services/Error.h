#ifndef READY4AIR_ERROR_H
#define READY4AIR_ERROR_H

#include "../dto/abstract/JsonDeserializable.h"
#include "../external/ResponseData.h"

namespace ready4air
{
    class Error
    {
    public:
        Error()
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

        const std::string &GetMessage() const
        {
            return mMessage;
        }

        void SetMessage(const std::string &message)
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
        std::string mMessage;
        dto::ParseErrors mParseErrors;
    };
}

#endif //READY4AIR_ERROR_H
