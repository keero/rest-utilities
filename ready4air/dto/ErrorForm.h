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
            ErrorForm() : TAG("ready4air::dto::ErrorForm")
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

            const Maybe<STRING_T> &GetMessage() const
            {
                return mMessage;
            }

            void SetMessage(const STRING_T &message)
            {
                mMessage = message;
            }

            virtual BOOL_T InitFromJsonValue(const rapidjson::Value &value, ParseErrors &parseErrors)
            {
                Form form;
                STRING_T message;

                if (ParseObject(value, "Form", true, form, parseErrors))
                    SetForm(form);

                if (ParseString(value, "Message", false, message, parseErrors))
                    SetMessage(message);

                return !parseErrors;
            }


        private:
            Maybe<Form> mForm;
            Maybe<STRING_T> mMessage;
            STRING_T TAG;
        };
    }
}

#endif //READY4AIR_ERRORFORM_H
