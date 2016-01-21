#ifndef READY4AIR_ERRORFORM_H
#define READY4AIR_ERRORFORM_H

#include "../common/Maybe.h"
#include "abstract/JsonDeserializable.h"
#include "hypermedia/Form.h"

namespace ready4air
{
    namespace dto
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

            const Maybe<Form> &GetForm() const
            {
                return mForm;
            }

            void SetForm(const Form &form)
            {
                mForm = form;
            }

            const Maybe<std::string> &GetMessage() const
            {
                return mMessage;
            }

            void SetMessage(const std::string &message)
            {
                mMessage = message;
            }

            virtual bool InitFromJsonValue(const rapidjson::Value &value, ParseErrors &parseErrors)
            {
                Form form;
                std::string message;

                if (ParseObject(value, "Form", true, form, parseErrors))
                    SetForm(form);

                if (ParseString(value, "Message", false, message, parseErrors))
                    SetMessage(message);

                return !parseErrors;
            }


        private:
            Maybe<Form> mForm;
            Maybe<std::string> mMessage;
        };
    }
}

#endif //READY4AIR_ERRORFORM_H
