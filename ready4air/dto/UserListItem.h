#ifndef READY4AIR_USERLISTITEM_H
#define READY4AIR_USERLISTITEM_H

#include "../common/Maybe.h"
#include "abstract/JsonDeserializable.h"

namespace ready4air
{
    namespace dto
    {
        class UserListItem : public JsonDeserializable
        {
        public:
            UserListItem() : TAG("ready4air::dto::UserListItem")
            {
            }

            virtual ~UserListItem()
            {
            }

            const Maybe<int> &GetPosition() const
            {
                return mPosition;
            }

            void SetPosition(int position)
            {
                mPosition = position;
            }

            const Maybe <STRING_T> &GetContentId() const
            {
                return mContentId;
            }

            void SetContentId(const STRING_T &contentId)
            {
                mContentId = contentId;
            }

            virtual BOOL_T InitFromJsonValue(const rapidjson::Value &value, ParseErrors &parseErrors)
            {
                INT32_T position;
                STRING_T contentId;

                if (ParseInt(value, "Position", true, position, parseErrors))
                    SetPosition(position);

                if (ParseString(value, "ContentId", true, contentId, parseErrors))
                    SetContentId(contentId);

                return !parseErrors;
            }

        private:
            Maybe<int> mPosition;
            Maybe <STRING_T> mContentId;
            STRING_T TAG;
        };
    }
}

#endif //READY4AIR_USERLISTITEM_H
