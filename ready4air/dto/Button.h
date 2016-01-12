#ifndef READY4AIR_BUTTON_H
#define READY4AIR_BUTTON_H

#include "../maybe/Maybe.h"
#include "abstract/JsonDeserializable.h"
#include "hypermedia/Link.h"

namespace ready4air
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


        const Maybe <int> &GetAgeLimit() const
        {
            return mAgeLimit;
        }

        void SetAgeLimit(int ageLimit)
        {
            mAgeLimit = ageLimit;
        }

        const Maybe <std::string> &GetButtonImage() const
        {
            return mButtonImage;
        }

        void SetButtonImage(const std::string &buttonImage)
        {
            mButtonImage = buttonImage;
        }

        const Maybe <int> &GetPosition() const
        {
            return mPosition;
        }

        void SetPosition(int position)
        {
            mPosition = position;
        }

        const Maybe <std::string> &GetTitle() const
        {
            return mTitle;
        }

        void SetTitle(const std::string &title)
        {
            mTitle = title;
        }

        const Maybe <std::string> &GetType() const
        {
            return mType;
        }

        void SetType(const std::string &type)
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

        virtual bool InitFromJsonValue(const rapidjson::Value &value, ParseErrors &parseErrors)
        {
            int ageLimit;
            std::string buttonImage;
            int position;
            std::string title;
            std::string type;
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
        Maybe <int> mAgeLimit;
        Maybe <std::string> mButtonImage;
        Maybe <int> mPosition;
        Maybe <std::string> mTitle;
        Maybe <std::string> mType;
        Maybe <Link> mLink;
    };
}

#endif //READY4AIR_BUTTON_H
