#ifndef READY4AIR_CONTENT_H
#define READY4AIR_CONTENT_H

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

        const std::vector<Button> &GetButtons() const
        {
            return mButtons;
        }

        void SetButtons(const std::vector<Button> &buttons)
        {
            mButtons = buttons;
        }

        const std::vector<MenuItem> &GetMenuItems() const
        {
            return mMenuItems;
        }

        void SetMenuItems(const std::vector<MenuItem> &menuItems)
        {
            mMenuItems = menuItems;
        }

        const std::vector<Section> &GetSections() const
        {
            return mSections;
        }

        void SetSections(const std::vector<Section> &sections)
        {
            mSections = sections;
        }

        const std::vector<Teaser> &GetTeasers() const
        {
            return mTeasers;
        }

        void SetTeasers(const std::vector<Teaser> &teasers)
        {
            mTeasers = teasers;
        }

        const std::vector<Promotion> &GetPromotions() const
        {
            return mPromotions;
        }

        void SetPromotions(const std::vector<Promotion> &promotions)
        {
            mPromotions = promotions;
        }

        const std::vector<LiveSection> &GetLiveSections() const
        {
            return mLiveSections;
        }

        void SetLiveSections(const std::vector<LiveSection> &liveSections)
        {
            mLiveSections = liveSections;
        }

        const Catalogue &GetCatalogue() const
        {
            return mCatalogue;
        }

        void SetCatalogue(const Catalogue &catalogue)
        {
            mCatalogue = catalogue;
        }

    private:
        std::vector<Button> mButtons;
        std::vector<MenuItem> mMenuItems;
        std::vector<Section> mSections;
        std::vector<Teaser> mTeasers;
        std::vector<Promotion> mPromotions;
        std::vector<LiveSection> mLiveSections;
        Catalogue mCatalogue;

    };
}

#endif //READY4AIR_CONTENT_H
