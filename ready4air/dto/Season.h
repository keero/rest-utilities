#ifndef READY4AIR_SEASON_H
#define READY4AIR_SEASON_H

#include "../maybe/Maybe.h"
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

        const Maybe <int> &GetSeasonNo() const
        {
            return mSeasonNo;
        }

        void SetSeasonNo(int seasonNo)
        {
            mSeasonNo = seasonNo;
        }

        const Maybe <Link> &GetSerie() const
        {
            return mSerie;
        }

        void SetSerie(const Link &serie)
        {
            mSerie = serie;
        }

        const Maybe <std::vector<Episode> > &GetEpisodes() const
        {
            return mEpisodes;
        }

        void SetEpisodes(const std::vector<Episode> &episodes)
        {
            mEpisodes = episodes;
        }

        const Maybe <std::vector<SeasonProduct> > &GetSeasonProducts() const
        {
            return mSeasonProducts;
        }

        void SetSeasonProducts(const std::vector<SeasonProduct> &seasonProducts)
        {
            mSeasonProducts = seasonProducts;
        }

        const Maybe <std::string> &GetTitleId() const
        {
            return mTitleId;
        }

        void SetTitleId(const std::string &titleId)
        {
            mTitleId = titleId;
        }

        const Maybe <Link> &GetTitleLink() const
        {
            return mTitleLink;
        }

        void SetTitleLink(const Link &titleLink)
        {
            mTitleLink = titleLink;
        }

        const Maybe <std::string> &GetOriginalTitle() const
        {
            return mOriginalTitle;
        }

        void SetOriginalTitle(const std::string &originalTitle)
        {
            mOriginalTitle = originalTitle;
        }

        const Maybe <bool> &IsAdult() const
        {
            return mAdult;
        }

        void SetAdult(bool adult)
        {
            mAdult = adult;
        }

        const Maybe <std::string> &GetLocalTitle() const
        {
            return mLocalTitle;
        }

        void SetLocalTitle(const std::string &localTitle)
        {
            mLocalTitle = localTitle;
        }

        const Maybe <std::string> &GetShortTitle() const
        {
            return mShortTitle;
        }

        void SetShortTitle(const std::string &shortTitle)
        {
            mShortTitle = shortTitle;
        }

        const Maybe <std::string> &GetLongSummary() const
        {
            return mLongSummary;
        }

        void SetLongSummary(const std::string &longSummary)
        {
            mLongSummary = longSummary;
        }

        const Maybe <std::string> &GetShortSummary() const
        {
            return mShortSummary;
        }

        void SetShortSummary(const std::string &shortSummary)
        {
            mShortSummary = shortSummary;
        }

        const Maybe <std::string> &GetSortTitle() const
        {
            return mSortTitle;
        }

        void SetSortTitle(const std::string &sortTitle)
        {
            mSortTitle = sortTitle;
        }

        const Maybe <std::string> &GetProductionCountry() const
        {
            return mProductionCountry;
        }

        void SetProductionCountry(const std::string &productionCountry)
        {
            mProductionCountry = productionCountry;
        }

        const Maybe <short> &GetYear() const
        {
            return mYear;
        }

        void SetYear(short year)
        {
            mYear = year;
        }

        const Maybe <int> &GetLength() const
        {
            return mLength;
        }

        void SetLength(int length)
        {
            mLength = length;
        }

        const Maybe <std::string> &GetPublishDate() const
        {
            return mPublishDate;
        }

        void SetPublishDate(const std::string &publishDate)
        {
            mPublishDate = publishDate;
        }

        const Maybe <std::string> &GetUnPublishDate() const
        {
            return mUnPublishDate;
        }

        void SetUnPublishDate(const std::string &unPublishDate)
        {
            mUnPublishDate = unPublishDate;
        }

        const Maybe <int> &GetAgeLimit() const
        {
            return mAgeLimit;
        }

        void SetAgeLimit(int ageLimit)
        {
            mAgeLimit = ageLimit;
        }

        const Maybe <std::string> &GetModified() const
        {
            return mModified;
        }

        void SetModified(const std::string &modified)
        {
            mModified = modified;
        }

        const Maybe <std::vector<Cast> > &GetCasts() const
        {
            return mCasts;
        }

        void SetCasts(const std::vector<Cast> &casts)
        {
            mCasts = casts;
        }

        const Maybe <std::vector<Image> > &GetImages() const
        {
            return mImages;
        }

        void SetImages(const std::vector<Image> &images)
        {
            mImages = images;
        }

        const Maybe <std::vector<Genre> > &GetGenres() const
        {
            return mGenres;
        }

        void SetGenres(const std::vector<Genre> &genres)
        {
            mGenres = genres;
        }

        const Maybe <Link> &GetSelf() const
        {
            return mSelf;
        }

        void SetSelf(const Link &self)
        {
            mSelf = self;
        }

        const Maybe <Link> &GetWatchedEpisodes() const
        {
            return mWatchedEpisodes;
        }

        void SetWatchedEpisodes(const Link &watchedEpisodes)
        {
            mWatchedEpisodes = watchedEpisodes;
        }

        const Maybe <Link> &GetAllEpisodes() const
        {
            return mAllEpisodes;
        }

        void SetAllEpisodes(const Link &allEpisodes)
        {
            mAllEpisodes = allEpisodes;
        }

        const Maybe <Form> &GetPurchase() const
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
        Maybe <int> mSeasonNo;
        Maybe <Link> mSerie;
        Maybe <std::vector<Episode> > mEpisodes;
        Maybe <std::vector<SeasonProduct> > mSeasonProducts;
        Maybe <std::string> mTitleId;
        Maybe <Link> mTitleLink;
        Maybe <std::string> mOriginalTitle;
        Maybe <bool> mAdult;
        Maybe <std::string> mLocalTitle;
        Maybe <std::string> mShortTitle;
        Maybe <std::string> mLongSummary;
        Maybe <std::string> mShortSummary;
        Maybe <std::string> mSortTitle;
        Maybe <std::string> mProductionCountry;
        Maybe <short> mYear;
        Maybe <int> mLength;
        Maybe <std::string> mPublishDate;
        Maybe <std::string> mUnPublishDate;
        Maybe <int> mAgeLimit;
        Maybe <std::string> mModified;
        Maybe <std::vector<Cast> > mCasts;
        Maybe <std::vector<Image> > mImages;
        Maybe <std::vector<Genre> > mGenres;
        Maybe <Link> mSelf;
        Maybe <Link> mWatchedEpisodes;
        Maybe <Link> mAllEpisodes;
        Maybe <Form> mPurchase;
    };
}

#endif //READY4AIR_SEASON_H
