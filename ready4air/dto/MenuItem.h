#ifndef READY4AIR_MENUITEM_H
#define READY4AIR_MENUITEM_H

#include "abstract/JsonDeserializable.h"
#include "hypermedia/Link.h"

namespace ready4air
{
    class MenuItem : public JsonDeserializable
    {
    public:
        MenuItem()
        {
        }

        virtual ~MenuItem()
        {
        }

        const std::string &GetText() const
        {
            return mText;
        }

        void SetText(const std::string &text)
        {
            mText = text;
        }

        const Link &GetLink() const
        {
            return mLink;
        }

        void SetLink(const Link &link)
        {
            mLink = link;
        }

        const std::vector<MenuItem> &GetMenuItems() const
        {
            return mMenuItems;
        }

        void SetMenuItems(const std::vector<MenuItem> &menuItems)
        {
            mMenuItems = menuItems;
        }

        virtual bool InitFromJsonValue(const rapidjson::Value &value)
        {
            return false;
        }

    private:
        std::string mText;
        Link mLink;
        std::vector<MenuItem> mMenuItems;
    };
}

#endif //READY4AIR_MENUITEM_H
