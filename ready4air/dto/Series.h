#ifndef READY4AIR_SERIES_H
#define READY4AIR_SERIES_H

#include "../maybe/Maybe.h"
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

        const Maybe <std::string> &GetId() const
        {
            return mId;
        }

        void SetId(const std::string &id)
        {
            mId = id;
        }

        const Maybe <std::string> &GetExternalId() const
        {
            return mExternalId;
        }

        void SetExternalId(const std::string &externalId)
        {
            mExternalId = externalId;
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

        const Maybe <short> &GetMinYear() const
        {
            return mMinYear;
        }

        void SetMinYear(short minYear)
        {
            mMinYear = minYear;
        }

        const Maybe <short> &GetMaxYear() const
        {
            return mMaxYear;
        }

        void SetMaxYear(short maxYear)
        {
            mMaxYear = maxYear;
        }

        const Maybe <int> &GetEpisodeLength() const
        {
            return mEpisodeLength;
        }

        void SetEpisodeLength(int episodeLength)
        {
            mEpisodeLength = episodeLength;
        }

        const Maybe <int> &GetAgeLimit() const
        {
            return mAgeLimit;
        }

        void SetAgeLimit(int ageLimit)
        {
            mAgeLimit = ageLimit;
        }

        const Maybe <std::string> &GetProductionCountry() const
        {
            return mProductionCountry;
        }

        void SetProductionCountry(const std::string &productionCountry)
        {
            mProductionCountry = productionCountry;
        }

        const Maybe <std::vector<std::string> > &GetAgeGroups() const
        {
            return mAgeGroups;
        }

        void SetAgeGroups(const std::vector<std::string> &ageGroups)
        {
            mAgeGroups = ageGroups;
        }

        const Maybe <std::vector<Image> > &GetImages() const
        {
            return mImages;
        }

        void SetImages(const std::vector<Image> &images)
        {
            mImages = images;
        }

        const Maybe <std::vector<Cast> > &GetCasts() const
        {
            return mCasts;
        }

        void SetCasts(const std::vector<Cast> &casts)
        {
            mCasts = casts;
        }

        const Maybe <std::vector<Genre> > &GetGenres() const
        {
            return mGenres;
        }

        void SetGenres(const std::vector<Genre> &genres)
        {
            mGenres = genres;
        }

        const Maybe <Form> &GetPurchaseFirstEpisode() const
        {
            return mPurchaseFirstEpisode;
        }

        void SetPurchaseFirstEpisode(const Form &purchaseFirstEpisode)
        {
            mPurchaseFirstEpisode = purchaseFirstEpisode;
        }

        const Maybe <std::string> &GetModified() const
        {
            return mModified;
        }

        void SetModified(const std::string &modified)
        {
            mModified = modified;
        }

        const Maybe <Link> &GetSeasons() const
        {
            return mSeasons;
        }

        void SetSeasons(const Link &seasons)
        {
            mSeasons = seasons;
        }

        const Maybe <Link> &GetSelf() const
        {
            return mSelf;
        }

        void SetSelf(const Link &self)
        {
            mSelf = self;
        }

        virtual bool InitFromJsonValue(const rapidjson::Value &value)
        {
            return false;
        }

    private:
        Maybe <std::string> mId;
        Maybe <std::string> mExternalId;
        Maybe <std::string> mOriginalTitle;
        Maybe <bool> mAdult;
        Maybe <std::string> mLocalTitle;
        Maybe <std::string> mShortTitle;
        Maybe <std::string> mLongSummary;
        Maybe <std::string> mShortSummary;
        Maybe <std::string> mSortTitle;
        Maybe <short> mMinYear;
        Maybe <short> mMaxYear;
        Maybe <int> mEpisodeLength;
        Maybe <int> mAgeLimit;
        Maybe <std::string> mProductionCountry;
        Maybe <std::vector<std::string> > mAgeGroups;
        Maybe <std::vector<Image> > mImages;
        Maybe <std::vector<Cast> > mCasts;
        Maybe <std::vector<Genre> > mGenres;
        Maybe <Form> mPurchaseFirstEpisode;
        Maybe <std::string> mModified;
        Maybe <Link> mSeasons;
        Maybe <Link> mSelf;
    };
}

#endif //READY4AIR_SERIES_H
