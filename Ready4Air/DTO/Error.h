#ifndef READY4AIR_ERROR_H
#define READY4AIR_ERROR_H

#include "abstract/JsonDeserializable.h"
#include "Display.h"

namespace ready4air
{
    class Error : public JsonDeserializable
    {
    public:
        Error()
        {
        }

        virtual ~Error()
        {
        }

        int GetCode() const
        {
            return mCode;
        }

        void SetCode(int code)
        {
            mCode = code;
        }

        const std::string &GetMessage() const
        {
            return mMessage;
        }

        void SetMessage(const std::string &message)
        {
            mMessage = message;
        }

        const Display &GetDisplay() const
        {
            return mDisplay;
        }

        void SetDisplay(const Display &display)
        {
            mDisplay = display;
        }

    private:
        int mCode;
        std::string mMessage;
        Display mDisplay;
    };
}

#endif //READY4AIR_ERROR_H
