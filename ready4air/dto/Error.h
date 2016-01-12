#ifndef READY4AIR_ERROR_H
#define READY4AIR_ERROR_H

#include "../maybe/Maybe.h"
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

        const Maybe <int> &GetCode() const
        {
            return mCode;
        }

        void SetCode(int code)
        {
            mCode = code;
        }

        const Maybe <std::string> &GetMessage() const
        {
            return mMessage;
        }

        void SetMessage(const std::string &message)
        {
            mMessage = message;
        }

        const Maybe <Display> &GetDisplay() const
        {
            return mDisplay;
        }

        void SetDisplay(const Display &display)
        {
            mDisplay = display;
        }

        virtual bool InitFromJsonValue(const rapidjson::Value &value, ParseErrors &parseErrors)
        {
            int code;
            std::string message;
            Display display;

            if (ParseInt(value, "Code", true, code, parseErrors))
                SetCode(code);

            if (ParseString(value, "Message", false, message, parseErrors))
                SetMessage(message);

            if (ParseObject(value, "Display", false, display, parseErrors))
                SetDisplay(display);

            return !parseErrors;
        }

    private:
        Maybe <int> mCode;
        Maybe <std::string> mMessage;
        Maybe <Display> mDisplay;
    };
}

#endif //READY4AIR_ERROR_H
