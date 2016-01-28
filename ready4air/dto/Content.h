#ifndef READY4AIR_CONTENT_H
#define READY4AIR_CONTENT_H

#include "../common/Maybe.h"
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
    namespace dto
    {
        class Content : public JsonDeserializable
        {

        public:
            Content() : TAG("ready4air::dto::Content")
            {
            }

            virtual ~Content()
            {
            }

            const Maybe<VECTOR_T<Button> > &GetButtons() const
            {
                return mButtons;
            }

            void SetButtons(const VECTOR_T<Button> &buttons)
            {
                mButtons = buttons;
            }

            const Maybe<VECTOR_T<MenuItem> > &GetMenuItems() const
            {
                return mMenuItems;
            }

            void SetMenuItems(const VECTOR_T<MenuItem> &menuItems)
            {
                mMenuItems = menuItems;
            }

            const Maybe<VECTOR_T<Section> > &GetSections() const
            {
                return mSections;
            }

            void SetSections(const VECTOR_T<Section> &sections)
            {
                mSections = sections;
            }

            const Maybe<VECTOR_T<Teaser> > &GetTeasers() const
            {
                return mTeasers;
            }

            void SetTeasers(const VECTOR_T<Teaser> &teasers)
            {
                mTeasers = teasers;
            }

            const Maybe<VECTOR_T<Promotion> > &GetPromotions() const
            {
                return mPromotions;
            }

            void SetPromotions(const VECTOR_T<Promotion> &promotions)
            {
                mPromotions = promotions;
            }

            const Maybe<VECTOR_T<LiveSection> > &GetLiveSections() const
            {
                return mLiveSections;
            }

            void SetLiveSections(const VECTOR_T<LiveSection> &liveSections)
            {
                mLiveSections = liveSections;
            }

            const Maybe<Catalogue> &GetCatalogue() const
            {
                return mCatalogue;
            }

            void SetCatalogue(const Catalogue &catalogue)
            {
                mCatalogue = catalogue;
            }

            virtual BOOL_T InitFromJsonValue(const rapidjson::Value &value, ParseErrors &parseErrors)
            {
                VECTOR_T<Button> buttons;
                VECTOR_T<MenuItem> menuItems;
                VECTOR_T<Section> sections;
                VECTOR_T<Teaser> teasers;
                VECTOR_T<Promotion> promotions;
                VECTOR_T<LiveSection> liveSections;
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
            Maybe<VECTOR_T<Button> > mButtons;
            Maybe<VECTOR_T<MenuItem> > mMenuItems;
            Maybe<VECTOR_T<Section> > mSections;
            Maybe<VECTOR_T<Teaser> > mTeasers;
            Maybe<VECTOR_T<Promotion> > mPromotions;
            Maybe<VECTOR_T<LiveSection> > mLiveSections;
            Maybe<Catalogue> mCatalogue;
            const STRING_T TAG;
        };
    }
}

#endif //READY4AIR_CONTENT_H
