#ifndef READY4AIR_MENUITEM_H
#define READY4AIR_MENUITEM_H

#include "../common/Maybe.h"
#include "abstract/JsonDeserializable.h"
#include "hypermedia/Link.h"

namespace ready4air
{
    namespace dto
    {
        class MenuItem : public JsonDeserializable
        {
        public:
            MenuItem() : TAG("ready4air::dto::MenuItem")
            {
            }

            virtual ~MenuItem()
            {
            }

            const Maybe <STRING_T> &GetText() const
            {
                return mText;
            }

            void SetText(const STRING_T &text)
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

            const Maybe <VECTOR_T<MenuItem>> &GetMenuItems() const
            {
                return mMenuItems;
            }

            void SetMenuItems(const VECTOR_T<MenuItem> &menuItems)
            {
                mMenuItems = menuItems;
            }

            virtual BOOL_T InitFromJsonValue(const rapidjson::Value &value, ParseErrors &parseErrors,
                                             VECTOR_T<STRING_T> &context)
            {
                STRING_T text;
                Link link;
                VECTOR_T<MenuItem> menuItems;

                context.push_back(TAG);

                if (ParseString(value, "Text", true, text, parseErrors, context))
                    SetText(text);

                if (ParseObject(value, "Link", false, link, parseErrors, context))
                    SetLink(link);

                if (VerifyArray(value, "MenuItems", false, parseErrors, context))
                {
                    for (rapidjson::SizeType i = 0; i < value["MenuItems"].Size(); i += 1)
                    {
                        MenuItem menuItem;
                        if (ParseObject(value["MenuItems"][i], "", false, menuItem, parseErrors, context))
                            menuItems.push_back(menuItem);
                    }
                    SetMenuItems(menuItems);
                }

                context.pop_back();
                return !parseErrors;
            }

        private:
            Maybe <STRING_T> mText;
            Maybe <Link> mLink;
            Maybe <VECTOR_T<MenuItem>> mMenuItems;
            STRING_T TAG;
        };
    }
}

#endif //READY4AIR_MENUITEM_H
