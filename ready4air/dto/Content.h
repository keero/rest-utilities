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

        virtual bool InitFromJsonValue(const rapidjson::Value &value)
        {
            {
                // Non-mandatory property
                if (value.HasMember("Buttons"))
                {
                    if (!value["Buttons"].IsArray()) return false;
                    std::vector<Button> buttons;
                    for (rapidjson::SizeType i = 0; i < value["Buttons"].Size(); i += 1)
                    {
                        Button button;
                        if (!value["Buttons"][i].IsObject() || !button.InitFromJsonValue(value["Buttons"][i])) return false;
                        buttons.push_back(button);
                    }
                    SetButtons(buttons);
                }
            }
            {
                // Mandatory property
                if (!value.HasMember("MenuItems") || !value["MenuItems"].IsArray()) return false;
                std::vector<MenuItem> menuItems;
                for (rapidjson::SizeType i = 0; i < value["MenuItems"].Size(); i += 1)
                {
                    MenuItem menuItem;
                    if (!value["MenuItems"][i].IsObject() || !menuItem.InitFromJsonValue(value["MenuItems"][i])) return false;
                    menuItems.push_back(menuItem);
                }
                SetMenuItems(menuItems);
            }
            {
                // Non-mandatory property
                if (value.HasMember("Sections"))
                {
                    if (!value["Sections"].IsArray()) return false;
                    std::vector<Section> sections;
                    for (rapidjson::SizeType i = 0; i < value["Sections"].Size(); i += 1)
                    {
                        Section section;
                        if (!value["Sections"][i].IsObject() || !section.InitFromJsonValue(value["Sections"][i])) return false;
                        sections.push_back(section);
                    }
                    SetSections(sections);
                }
            }
            {
                // Non-mandatory property
                if (value.HasMember("Teasers"))
                {
                    if (!value["Teasers"].IsArray()) return false;
                    std::vector<Teaser> teasers;
                    for (rapidjson::SizeType i = 0; i < value["Teasers"].Size(); i += 1)
                    {
                        Teaser teaser;
                        if (!value["Teasers"][i].IsObject() || !teaser.InitFromJsonValue(value["Teasers"][i])) return false;
                        teasers.push_back(teaser);
                    }
                    SetTeasers(teasers);
                }
            }
            {
                // Non-mandatory property
                if (value.HasMember("Promotions"))
                {
                    if (!value["Promotions"].IsArray()) return false;
                    std::vector<Promotion> promotions;
                    for (rapidjson::SizeType i = 0; i < value["Promotions"].Size(); i += 1)
                    {
                        Promotion promotion;
                        if (!value["Promotions"][i].IsObject() || !promotion.InitFromJsonValue(value["Promotions"][i])) return false;
                        promotions.push_back(promotion);
                    }
                    SetPromotions(promotions);
                }
            }
            {
                // Non-mandatory property
                if (value.HasMember("LiveSections"))
                {
                    if (!value["LiveSections"].IsArray()) return false;
                    std::vector<LiveSection> liveSections;
                    for (rapidjson::SizeType i = 0; i < value["LiveSections"].Size(); i += 1)
                    {
                        LiveSection liveSection;
                        if (!value["LiveSections"][i].IsObject() || !liveSection.InitFromJsonValue(value["LiveSections"][i])) return false;
                        liveSections.push_back(liveSection);
                    }
                    SetLiveSections(liveSections);
                }
            }
            {
                // Mandatory property
                Catalogue catalogue;
                if (!value.HasMember("Catalogue") || !value["Catalogue"].IsObject() || !catalogue.InitFromJsonValue(value["Catalogue"])) return false;
                SetCatalogue(catalogue);
            }

            return true;
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
