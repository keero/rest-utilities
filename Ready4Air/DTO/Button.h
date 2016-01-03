#ifndef READY4AIR_BUTTON_H
#define READY4AIR_BUTTON_H

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


        int GetAgeLimit() const
        {
            return mAgeLimit;
        }

        void SetAgeLimit(int ageLimit)
        {
            mAgeLimit = ageLimit;
        }

        const std::string &GetButtonImage() const
        {
            return mButtonImage;
        }

        void SetButtonImage(const std::string &buttonImage)
        {
            mButtonImage = buttonImage;
        }

        int GetPosition() const
        {
            return mPosition;
        }

        void SetPosition(int position)
        {
            mPosition = position;
        }

        const std::string &GetTitle() const
        {
            return mTitle;
        }

        void SetTitle(const std::string &title)
        {
            mTitle = title;
        }

        const std::string &GetType() const
        {
            return mType;
        }

        void SetType(const std::string &type)
        {
            mType = type;
        }

        const Link &GetLink() const
        {
            return mLink;
        }

        void SetLink(const Link &link)
        {
            mLink = link;
        }

    private:
        int mAgeLimit;
        std::string mButtonImage;
        int mPosition;
        std::string mTitle;
        std::string mType;
        Link mLink;
    };
}

#endif //READY4AIR_BUTTON_H
