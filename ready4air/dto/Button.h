#ifndef READY4AIR_BUTTON_H
#define READY4AIR_BUTTON_H

#include "../common/Maybe.h"
#include "abstract/JsonDeserializable.h"
#include "hypermedia/Link.h"

namespace ready4air
{
    namespace dto
    {
        class Button : public JsonDeserializable
        {

        public:
            Button()
            {
            }

            virtual ~Button()
            {
            }


            const Maybe<int> &GetAgeLimit() const
            {
                return mAgeLimit;
            }

            void SetAgeLimit(int ageLimit)
            {
                mAgeLimit = ageLimit;
            }

            const Maybe <STRING_T> &GetButtonImage() const
            {
                return mButtonImage;
            }

            void SetButtonImage(const STRING_T &buttonImage)
            {
                mButtonImage = buttonImage;
            }

            const Maybe<int> &GetPosition() const
            {
                return mPosition;
            }

            void SetPosition(int position)
            {
                mPosition = position;
            }

            const Maybe <STRING_T> &GetTitle() const
            {
                return mTitle;
            }

            void SetTitle(const STRING_T &title)
            {
                mTitle = title;
            }

            const Maybe <STRING_T> &GetType() const
            {
                return mType;
            }

            void SetType(const STRING_T &type)
            {
                mType = type;
            }

            const Maybe <Link> &GetLink() const
            {
                return mLink;
            }

            void SetLink(const Link &link)
            {
                mLink = link;
            }

            virtual BOOL_T InitFromJsonValue(const rapidjson::Value &value, ParseErrors &parseErrors)
            {
                INT32_T ageLimit;
                STRING_T buttonImage;
                INT32_T position;
                STRING_T title;
                STRING_T type;
                Link link;

                if (ParseInt(value, "AgeLimit", false, ageLimit, parseErrors))
                    SetAgeLimit(ageLimit);

                if (ParseString(value, "ButtonImage", false, buttonImage, parseErrors))
                    SetButtonImage(buttonImage);

                if (ParseInt(value, "Position", true, position, parseErrors))
                    SetPosition(position);

                if (ParseString(value, "Title", true, title, parseErrors))
                    SetTitle(title);

                if (ParseString(value, "Type", true, type, parseErrors))
                    SetType(type);

                if (ParseObject(value, "Link", true, link, parseErrors))
                    SetLink(link);

                return !parseErrors;
            }

        private:
            Maybe<int> mAgeLimit;
            Maybe <STRING_T> mButtonImage;
            Maybe<int> mPosition;
            Maybe <STRING_T> mTitle;
            Maybe <STRING_T> mType;
            Maybe <Link> mLink;
        };
    }
}

#endif //READY4AIR_BUTTON_H
