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

        virtual bool InitFromJsonValue(const rapidjson::Value &value)
        {
            {
                // Mandatory property
                if (!value.HasMember("Code") || !value["Code"].IsInt()) return false;
                SetCode(value["Code"].GetInt());
            }
            {
                // Non-mandatory property
                if (value.HasMember("Message"))
                {
                    if (!value["Message"].IsString()) return false;
                    SetMessage(value["Message"].GetString());
                }
            }
            {
                // Non-mandatory property
                if (value.HasMember("Display"))
                {
                    Display display;
                    if (!value["Display"].IsObject() || !display.InitFromJsonValue(value["Display"])) return false;
                    SetDisplay(display);
                }
            }

            return true;
        }

    private:
        Maybe <int> mCode;
        Maybe <std::string> mMessage;
        Maybe <Display> mDisplay;
    };
}

#endif //READY4AIR_ERROR_H
