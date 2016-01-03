#ifndef READY4AIR_SERIES_H
#define READY4AIR_SERIES_H

#include "abstract/JsonDeserializable.h"
#include "Image.h"
#include "Cast.h"
#include "Genre.h"
#include "hypermedia/Form.h"
#include "hypermedia/Link.h"

namespace ready4air
{
    class Series : public JsonDeserializable
    {
    public:
        Series()
        {
        }

        virtual ~Series()
        {
        }

        const std::string &GetId() const
        {
            return mId;
        }

        void SetId(const std::string &id)
        {
            mId = id;
        }

        const std::string &GetExternalId() const
        {
            return mExternalId;
        }

        void SetExternalId(const std::string &externalId)
        {
            mExternalId = externalId;
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

        short GetMinYear() const
        {
            return mMinYear;
        }

        void SetMinYear(short minYear)
        {
            mMinYear = minYear;
        }

        short GetMaxYear() const
        {
            return mMaxYear;
        }

        void SetMaxYear(short maxYear)
        {
            mMaxYear = maxYear;
        }

        int GetEpisodeLength() const
        {
            return mEpisodeLength;
        }

        void SetEpisodeLength(int episodeLength)
        {
            mEpisodeLength = episodeLength;
        }

        int GetAgeLimit() const
        {
            return mAgeLimit;
        }

        void SetAgeLimit(int ageLimit)
        {
            mAgeLimit = ageLimit;
        }

        const std::string &GetProductionCountry() const
        {
            return mProductionCountry;
        }

        void SetProductionCountry(const std::string &productionCountry)
        {
            mProductionCountry = productionCountry;
        }

        const std::vector<std::string> &GetAgeGroups() const
        {
            return mAgeGroups;
        }

        void SetAgeGroups(const std::vector<std::string> &ageGroups)
        {
            mAgeGroups = ageGroups;
        }

        const std::vector<Image> &GetImages() const
        {
            return mImages;
        }

        void SetImages(const std::vector<Image> &images)
        {
            mImages = images;
        }

        const std::vector<Cast> &GetCasts() const
        {
            return mCasts;
        }

        void SetCasts(const std::vector<Cast> &casts)
        {
            mCasts = casts;
        }

        const std::vector<Genre> &GetGenres() const
        {
            return mGenres;
        }

        void SetGenres(const std::vector<Genre> &genres)
        {
            mGenres = genres;
        }

        const Form &GetPurchaseFirstEpisode() const
        {
            return mPurchaseFirstEpisode;
        }

        void SetPurchaseFirstEpisode(const Form &purchaseFirstEpisode)
        {
            mPurchaseFirstEpisode = purchaseFirstEpisode;
        }

        const std::string &GetModified() const
        {
            return mModified;
        }

        void SetModified(const std::string &modified)
        {
            mModified = modified;
        }

        const Link &GetSeasons() const
        {
            return mSeasons;
        }

        void SetSeasons(const Link &seasons)
        {
            mSeasons = seasons;
        }

        const Link &GetSelf() const
        {
            return mSelf;
        }

        void SetSelf(const Link &self)
        {
            mSelf = self;
        }

    private:
        std::string mId;
        std::string mExternalId;
        std::string mOriginalTitle;
        bool mAdult;
        std::string mLocalTitle;
        std::string mShortTitle;
        std::string mLongSummary;
        std::string mShortSummary;
        std::string mSortTitle;
        short mMinYear;
        short mMaxYear;
        int mEpisodeLength;
        int mAgeLimit;
        std::string mProductionCountry;
        std::vector<std::string> mAgeGroups;
        std::vector<Image> mImages;
        std::vector<Cast> mCasts;
        std::vector<Genre> mGenres;
        Form mPurchaseFirstEpisode;
        std::string mModified;
        Link mSeasons;
        Link mSelf;
    };
}

#endif //READY4AIR_SERIES_H
