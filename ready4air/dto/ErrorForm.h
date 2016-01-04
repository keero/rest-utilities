#ifndef READY4AIR_ERRORFORM_H
#define READY4AIR_ERRORFORM_H

#include "abstract/JsonDeserializable.h"
#include "hypermedia/Form.h"

namespace ready4air
{
    class ErrorForm : public JsonDeserializable
    {
    public:
        ErrorForm()
        {
        }

        virtual ~ErrorForm()
        {
        }

        const Form &GetForm() const
        {
            return mForm;
        }

        void SetForm(const Form &form)
        {
            mForm = form;
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
                Form form;
                if (!value.HasMember("Form") || !value["Form"].IsObject() || !form.InitFromJsonValue(value["Form"])) return false;
                SetForm(form);
            }
            {
                // Non-mandatory property
                if (value.HasMember("Message"))
                {
                    if (!value["Message"].IsString()) return false;
                    SetMessage(value["Message"].GetString());
                }
            }

            return true;
        }


    private:
        Form mForm;
        std::string mMessage;
    };
}

#endif //READY4AIR_ERRORFORM_H
