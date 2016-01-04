#ifndef READY4AIR_DISPLAY_H
#define READY4AIR_DISPLAY_H

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

        const std::string &GetTitle() const
        {
            return mTitle;
        }

        void SetTitle(const std::string &title)
        {
            mTitle = title;
        }

        const std::string &GetMessage() const
        {
            return mMessage;
        }

        void SetMessage(const std::string &message)
        {
            mMessage = message;
        }

        virtual bool InitFromJsonValue(const rapidjson::Value &value)
        {
            {
                // Mandatory property
                if (!value.HasMember("Title") || !value["Title"].IsString()) return false;
                SetTitle(value["Title"].GetString());
            }
            {
                // Mandatory property
                if (!value.HasMember("Message") || !value["Message"].IsString()) return false;
                SetMessage(value["Message"].GetString());
            }

            return true;
        }


    private:
        std::string mTitle;
        std::string mMessage;
    };
}

#endif //READY4AIR_DISPLAY_H
