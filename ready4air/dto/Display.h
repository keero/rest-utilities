#ifndef READY4AIR_DISPLAY_H
#define READY4AIR_DISPLAY_H

#include "../common/Maybe.h"
#include "abstract/JsonDeserializable.h"

namespace ready4air
{
    namespace dto
    {
        class Display : public JsonDeserializable
        {
        public:
            Display() : TAG("ready4air::dto::Display")
            {
            }

            virtual ~Display()
            {
            }

            const Maybe <STRING_T> &GetTitle() const
            {
                return mTitle;
            }

            void SetTitle(const STRING_T &title)
            {
                mTitle = title;
            }

            const Maybe <STRING_T> &GetMessage() const
            {
                return mMessage;
            }

            void SetMessage(const STRING_T &message)
            {
                mMessage = message;
            }

            virtual BOOL_T InitFromJsonValue(const rapidjson::Value &value, ParseErrors &parseErrors,
                                             VECTOR_T<STRING_T> &context)
            {
                STRING_T title;
                STRING_T message;

                context.push_back(TAG);

                if (ParseString(value, "Title", true, title, parseErrors, context))
                    SetTitle(title);

                if (ParseString(value, "Message", true, message, parseErrors, context))
                    SetMessage(message);

                context.pop_back();
                return !parseErrors;
            }

        private:
            Maybe <STRING_T> mTitle;
            Maybe <STRING_T> mMessage;
            STRING_T TAG;
        };
    }
}

#endif //READY4AIR_DISPLAY_H
