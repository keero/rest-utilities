#ifndef READY4AIR_SEASON_H
#define READY4AIR_SEASON_H

#include "abstract/JsonDeserializable.h"
#include "hypermedia/Link.h"
#include "Episode.h"
#include "SeasonProduct.h"
#include "Cast.h"
#include "Image.h"
#include "Genre.h"
#include "hypermedia/Form.h"

namespace ready4air
{
    class Season : public JsonDeserializable
    {
    public:
        Season()
        {
        }

        virtual ~Season()
        {
        }

        int GetSeasonNo() const
        {
            return mSeasonNo;
        }

        void SetSeasonNo(int seasonNo)
        {
            mSeasonNo = seasonNo;
        }

        const Link &GetSerie() const
        {
            return mSerie;
        }

        void SetSerie(const Link &serie)
        {
            mSerie = serie;
        }

        const std::vector<Episode> &GetEpisodes() const
        {
            return mEpisodes;
        }

        void SetEpisodes(const std::vector<Episode> &episodes)
        {
            mEpisodes = episodes;
        }

        const std::vector<SeasonProduct> &GetSeasonProducts() const
        {
            return mSeasonProducts;
        }

        void SetSeasonProducts(const std::vector<SeasonProduct> &seasonProducts)
        {
            mSeasonProducts = seasonProducts;
        }

        const std::string &GetTitleId() const
        {
            return mTitleId;
        }

        void SetTitleId(const std::string &titleId)
        {
            mTitleId = titleId;
        }

        const Link &GetTitleLink() const
        {
            return mTitleLink;
        }

        void SetTitleLink(const Link &titleLink)
        {
            mTitleLink = titleLink;
        }

        const std::string &GetOriginalTitle() const
        {
            return mOriginalTitle;
        }

        void SetOriginalTitle(const std::string &originalTitle)
        {
            mOriginalTitle = originalTitle;
        }

        bool IsAdult() const
        {
            return mAdult;
        }

        void SetAdult(bool adult)
        {
            mAdult = adult;
        }

        const std::string &GetLocalTitle() const
        {
            return mLocalTitle;
        }

        void SetLocalTitle(const std::string &localTitle)
        {
            mLocalTitle = localTitle;
        }

        const std::string &GetShortTitle() const
        {
            return mShortTitle;
        }

        void SetShortTitle(const std::string &shortTitle)
        {
            mShortTitle = shortTitle;
        }

        const std::string &GetLongSummary() const
        {
            return mLongSummary;
        }

        void SetLongSummary(const std::string &longSummary)
        {
            mLongSummary = longSummary;
        }

        const std::string &GetShortSummary() const
        {
            return mShortSummary;
        }

        void SetShortSummary(const std::string &shortSummary)
        {
            mShortSummary = shortSummary;
        }

        const std::string &GetSortTitle() const
        {
            return mSortTitle;
        }

        void SetSortTitle(const std::string &sortTitle)
        {
            mSortTitle = sortTitle;
        }

        const std::string &GetProductionCountry() const
        {
            return mProductionCountry;
        }

        void SetProductionCountry(const std::string &productionCountry)
        {
            mProductionCountry = productionCountry;
        }

        short GetYear() const
        {
            return mYear;
        }

        void SetYear(short year)
        {
            mYear = year;
        }

        int GetLength() const
        {
            return mLength;
        }

        void SetLength(int length)
        {
            mLength = length;
        }

        const std::string &GetPublishDate() const
        {
            return mPublishDate;
        }

        void SetPublishDate(const std::string &publishDate)
        {
            mPublishDate = publishDate;
        }

        const std::string &GetUnPublishDate() const
        {
            return mUnPublishDate;
        }

        void SetUnPublishDate(const std::string &unPublishDate)
        {
            mUnPublishDate = unPublishDate;
        }

        int GetAgeLimit() const
        {
            return mAgeLimit;
        }

        void SetAgeLimit(int ageLimit)
        {
            mAgeLimit = ageLimit;
        }

        const std::string &GetModified() const
        {
            return mModified;
        }

        void SetModified(const std::string &modified)
        {
            mModified = modified;
        }

        const std::vector<Cast> &GetCasts() const
        {
            return mCasts;
        }

        void SetCasts(const std::vector<Cast> &casts)
        {
            mCasts = casts;
        }

        const std::vector<Image> &GetImages() const
        {
            return mImages;
        }

        void SetImages(const std::vector<Image> &images)
        {
            mImages = images;
        }

        const std::vector<Genre> &GetGenres() const
        {
            return mGenres;
        }

        void SetGenres(const std::vector<Genre> &genres)
        {
            mGenres = genres;
        }

        const Link &GetSelf() const
        {
            return mSelf;
        }

        void SetSelf(const Link &self)
        {
            mSelf = self;
        }

        const Link &GetWatchedEpisodes() const
        {
            return mWatchedEpisodes;
        }

        void SetWatchedEpisodes(const Link &watchedEpisodes)
        {
            mWatchedEpisodes = watchedEpisodes;
        }

        const Link &GetAllEpisodes() const
        {
            return mAllEpisodes;
        }

        void SetAllEpisodes(const Link &allEpisodes)
        {
            mAllEpisodes = allEpisodes;
        }

        const Form &GetPurchase() const
        {
            return mPurchase;
        }

        void SetPurchase(const Form &purchase)
        {
            mPurchase = purchase;
        }

        virtual bool InitFromJsonValue(const rapidjson::Value &value)
        {
            return false;
        }

    private:
        int mSeasonNo;
        Link mSerie;
        std::vector<Episode> mEpisodes;
        std::vector<SeasonProduct> mSeasonProducts;
        std::string mTitleId;
        Link mTitleLink;
        std::string mOriginalTitle;
        bool mAdult;
        std::string mLocalTitle;
        std::string mShortTitle;
        std::string mLongSummary;
        std::string mShortSummary;
        std::string mSortTitle;
        std::string mProductionCountry;
        short mYear;
        int mLength;
        std::string mPublishDate;
        std::string mUnPublishDate;
        int mAgeLimit;
        std::string mModified;
        std::vector<Cast> mCasts;
        std::vector<Image> mImages;
        std::vector<Genre> mGenres;
        Link mSelf;
        Link mWatchedEpisodes;
        Link mAllEpisodes;
        Form mPurchase;
    };
}

#endif //READY4AIR_SEASON_H
