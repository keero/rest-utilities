#ifndef READY4AIR_CONTENT_H
#define READY4AIR_CONTENT_H

#include "../maybe/Maybe.h"
#include "abstract/JsonDeserializable.h"
#include "Button.h"
#include "MenuItem.h"
#include "Section.h"
#include "Teaser.h"
#include "Promotion.h"
#include "LiveSection.h"
#include "Catalogue.h"

namespace ready4air
{
    class Content : public JsonDeserializable
    {

    public:
        Content()
        {
        }

        virtual ~Content()
        {
        }

        const Maybe <std::vector<Button> > &GetButtons() const
        {
            return mButtons;
        }

        void SetButtons(const std::vector<Button> &buttons)
        {
            mButtons = buttons;
        }

        const Maybe <std::vector<MenuItem> > &GetMenuItems() const
        {
            return mMenuItems;
        }

        void SetMenuItems(const std::vector<MenuItem> &menuItems)
        {
            mMenuItems = menuItems;
        }

        const Maybe <std::vector<Section> > &GetSections() const
        {
            return mSections;
        }

        void SetSections(const std::vector<Section> &sections)
        {
            mSections = sections;
        }

        const Maybe <std::vector<Teaser> > &GetTeasers() const
        {
            return mTeasers;
        }

        void SetTeasers(const std::vector<Teaser> &teasers)
        {
            mTeasers = teasers;
        }

        const Maybe <std::vector<Promotion> > &GetPromotions() const
        {
            return mPromotions;
        }

        void SetPromotions(const std::vector<Promotion> &promotions)
        {
            mPromotions = promotions;
        }

        const Maybe <std::vector<LiveSection> > &GetLiveSections() const
        {
            return mLiveSections;
        }

        void SetLiveSections(const std::vector<LiveSection> &liveSections)
        {
            mLiveSections = liveSections;
        }

        const Maybe <Catalogue> &GetCatalogue() const
        {
            return mCatalogue;
        }

        void SetCatalogue(const Catalogue &catalogue)
        {
            mCatalogue = catalogue;
        }

        virtual bool InitFromJsonValue(const rapidjson::Value &value, ParseErrors &parseErrors)
        {
            std::vector<Button> buttons;
            std::vector<MenuItem> menuItems;
            std::vector<Section> sections;
            std::vector<Teaser> teasers;
            std::vector<Promotion> promotions;
            std::vector<LiveSection> liveSections;
            Catalogue catalogue;

            if (VerifyArray(value, "Buttons", false, parseErrors))
            {
                for (rapidjson::SizeType i = 0; i < value["Buttons"].Size(); i += 1)
                {
                    Button button;
                    if (ParseObject(value["Buttons"][i], "", false, button, parseErrors))
                        buttons.push_back(button);
                }
                SetButtons(buttons);
            }

            if (VerifyArray(value, "MenuItems", true, parseErrors))
            {
                for (rapidjson::SizeType i = 0; i < value["MenuItems"].Size(); i += 1)
                {
                    MenuItem menuItem;
                    if (ParseObject(value["MenuItems"][i], "", false, menuItem, parseErrors))
                        menuItems.push_back(menuItem);
                }
                SetMenuItems(menuItems);
            }

            if (VerifyArray(value, "Sections", false, parseErrors))
            {
                for (rapidjson::SizeType i = 0; i < value["Sections"].Size(); i += 1)
                {
                    Section section;
                    if (ParseObject(value["Sections"][i], "", false, section, parseErrors))
                        sections.push_back(section);
                }
                SetSections(sections);
            }

            if (VerifyArray(value, "Teasers", false, parseErrors))
            {
                for (rapidjson::SizeType i = 0; i < value["Teasers"].Size(); i += 1)
                {
                    Teaser teaser;
                    if (ParseObject(value["Teasers"][i], "", false, teaser, parseErrors))
                        teasers.push_back(teaser);
                }
                SetTeasers(teasers);
            }

            if (VerifyArray(value, "Promotions", false, parseErrors))
            {
                for (rapidjson::SizeType i = 0; i < value["Promotions"].Size(); i += 1)
                {
                    Promotion promotion;
                    if (ParseObject(value["Promotions"][i], "", false, promotion, parseErrors))
                        promotions.push_back(promotion);
                }
                SetPromotions(promotions);
            }

            if (VerifyArray(value, "LiveSections", false, parseErrors))
            {
                for (rapidjson::SizeType i = 0; i < value["LiveSections"].Size(); i += 1)
                {
                    LiveSection liveSection;
                    if (ParseObject(value["LiveSections"][i], "", false, liveSection, parseErrors))
                        liveSections.push_back(liveSection);
                }
                SetLiveSections(liveSections);
            }

            if (ParseObject(value, "Catalogue", true, catalogue, parseErrors))
                SetCatalogue(catalogue);

            return !parseErrors;
        }

    private:
        Maybe <std::vector<Button> > mButtons;
        Maybe <std::vector<MenuItem> > mMenuItems;
        Maybe <std::vector<Section> > mSections;
        Maybe <std::vector<Teaser> > mTeasers;
        Maybe <std::vector<Promotion> > mPromotions;
        Maybe <std::vector<LiveSection> > mLiveSections;
        Maybe <Catalogue> mCatalogue;
    };
}

#endif //READY4AIR_CONTENT_H
