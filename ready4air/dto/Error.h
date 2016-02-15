#ifndef READY4AIR_ERROR_H
#define READY4AIR_ERROR_H

#include "../common/Maybe.h"
#include "abstract/JsonDeserializable.h"
#include "Display.h"

namespace ready4air
{
    namespace dto
    {
        class Error : public JsonDeserializable
        {
        public:
            Error() : TAG("ready4air::dto::Error")
            {
            }

            virtual ~Error()
            {
            }

            const Maybe<int> &GetCode() const
            {
                return mCode;
            }

            void SetCode(int code)
            {
                mCode = code;
            }

            const Maybe<STRING_T> &GetMessage() const
            {
                return mMessage;
            }

            void SetMessage(const STRING_T &message)
            {
                mMessage = message;
            }

            const Maybe<Display> &GetDisplay() const
            {
                return mDisplay;
            }

            void SetDisplay(const Display &display)
            {
                mDisplay = display;
            }

            virtual BOOL_T InitFromJsonValue(const rapidjson::Value &value, ParseErrors &parseErrors,
                                             VECTOR_T<STRING_T> &context)
            {
                INT32_T code;
                STRING_T message;
                Display display;

                context.push_back(TAG);

                if (ParseInt(value, "Code", true, code, parseErrors, context))
                    SetCode(code);

                if (ParseString(value, "Message", false, message, parseErrors, context))
                    SetMessage(message);

                if (ParseObject(value, "Display", false, display, parseErrors, context))
                    SetDisplay(display);

                context.pop_back();
                return !parseErrors;
            }

        private:
            Maybe<int> mCode;
            Maybe<STRING_T> mMessage;
            Maybe<Display> mDisplay;
            STRING_T TAG;
        };
    }
}

#endif //READY4AIR_ERROR_H
