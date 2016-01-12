#ifndef READY4AIR_DISPLAY_H
#define READY4AIR_DISPLAY_H

#include "../maybe/Maybe.h"
#include "abstract/JsonDeserializable.h"

namespace ready4air
{
    class Display : public JsonDeserializable
    {
    public:
        Display()
        {
        }

        virtual ~Display()
        {
        }

        const Maybe <std::string> &GetTitle() const
        {
            return mTitle;
        }

        void SetTitle(const std::string &title)
        {
            mTitle = title;
        }

        const Maybe <std::string> &GetMessage() const
        {
            return mMessage;
        }

        void SetMessage(const std::string &message)
        {
            mMessage = message;
        }

        virtual bool InitFromJsonValue(const rapidjson::Value &value, ParseErrors &parseErrors)
        {
            std::string title;
            std::string message;

            if (ParseString(value, "Title", true, title, parseErrors))
                SetTitle(title);

            if (ParseString(value, "Message", true, message, parseErrors))
                SetMessage(message);

            return !parseErrors;
        }

    private:
        Maybe <std::string> mTitle;
        Maybe <std::string> mMessage;
    };
}

#endif //READY4AIR_DISPLAY_H
