#ifndef READY4AIR_MENUITEM_H
#define READY4AIR_MENUITEM_H

#include "../maybe/Maybe.h"
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

        const Maybe <std::string> &GetText() const
        {
            return mText;
        }

        void SetText(const std::string &text)
        {
            mText = text;
        }

        const Maybe <Link> &GetLink() const
        {
            return mLink;
        }

        void SetLink(const Link &link)
        {
            mLink = link;
        }

        const Maybe <std::vector<MenuItem> > &GetMenuItems() const
        {
            return mMenuItems;
        }

        void SetMenuItems(const std::vector<MenuItem> &menuItems)
        {
            mMenuItems = menuItems;
        }

        virtual bool InitFromJsonValue(const rapidjson::Value &value, ParseErrors &parseErrors)
        {
            std::string text;
            Link link;
            std::vector<MenuItem> menuItems;

            if (ParseString(value, "Text", true, text, parseErrors))
                SetText(text);

            if (ParseObject(value, "Link", false, link, parseErrors))
                SetLink(link);

            if (VerifyArray(value, "MenuItems", false, parseErrors))
            {
                for (rapidjson::SizeType i = 0; i < value["MenuItems"].Size(); i += 1)
                {
                    MenuItem menuItem;
                    if (ParseObject(value["MenuItems"][i], "", false, menuItem, parseErrors))
                        menuItems.push_back(menuItem);
                }
                SetMenuItems(menuItems);
            }

            return !parseErrors;
        }

    private:
        Maybe <std::string> mText;
        Maybe <Link> mLink;
        Maybe <std::vector<MenuItem> > mMenuItems;
    };
}

#endif //READY4AIR_MENUITEM_H
