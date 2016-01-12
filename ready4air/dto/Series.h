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

        virtual bool InitFromJsonValue(const rapidjson::Value &value, ParseErrors &parseErrors)
        {
            std::string id;
            std::string externalId;
            std::string originalTitle;
            bool adult;
            std::string localTitle;
            std::string shortTitle;
            std::string longSummary;
            std::string shortSummary;
            std::string sortTitle;
            int minYear;
            int maxYear;
            int episodeLength;
            int ageLimit;
            std::string productionCountry;
            std::vector<std::string> ageGroups;
            std::vector<Image> images;
            std::vector<Cast> casts;
            std::vector<Genre> genres;
            Form purchaseFirstEpisode;
            std::string modified;
            Link seasons;
            Link self;

            if (ParseString(value, "Id", true, id, parseErrors))
                SetId(id);

            if (ParseString(value, "ExternalId", true, externalId, parseErrors))
                SetExternalId(externalId);

            if (ParseString(value, "OriginalTitle", false, originalTitle, parseErrors))
                SetOriginalTitle(originalTitle);

            if (ParseBool(value, "Adult", true, adult, parseErrors))
                SetAdult(adult);

            if (ParseString(value, "LocalTitle", false, localTitle, parseErrors))
                SetLocalTitle(localTitle);

            if (ParseString(value, "ShortTitle", false, shortTitle, parseErrors))
                SetShortTitle(shortTitle);

            if (ParseString(value, "LongSummary", false, longSummary, parseErrors))
                SetLongSummary(longSummary);

            if (ParseString(value, "ShortSummary", false, shortSummary, parseErrors))
                SetShortSummary(shortSummary);

            if (ParseString(value, "SortTitle", false, sortTitle, parseErrors))
                SetSortTitle(sortTitle);

            if (ParseInt(value, "MinYear", true, minYear, parseErrors))
                SetMinYear((short) minYear);

            if (ParseInt(value, "MaxYear", true, maxYear, parseErrors))
                SetMaxYear((short) maxYear);

            if (ParseInt(value, "EpisodeLength", false, episodeLength, parseErrors))
                SetEpisodeLength(episodeLength);

            if (ParseInt(value, "AgeLimit", false, ageLimit, parseErrors))
                SetAgeLimit(ageLimit);

            if (ParseString(value, "ProductionCountry", false, productionCountry, parseErrors))
                SetProductionCountry(productionCountry);

            if (VerifyArray(value, "AgeGroups", false, parseErrors))
            {
                for (rapidjson::SizeType i = 0; i < value["AgeGroups"].Size(); i += 1)
                {
                    std::string ageGroup;
                    if (ParseString(value["AgeGroups"][i], "", false, ageGroup, parseErrors))
                        ageGroups.push_back(ageGroup);
                }
                SetAgeGroups(ageGroups);
            }

            if (VerifyArray(value, "Images", false, parseErrors))
            {
                for (rapidjson::SizeType i = 0; i < value["Images"].Size(); i += 1)
                {
                    Image image;
                    if (ParseObject(value["Images"][i], "", false, image, parseErrors))
                        images.push_back(image);
                }
                SetImages(images);
            }

            if (VerifyArray(value, "Casts", false, parseErrors))
            {
                for (rapidjson::SizeType i = 0; i < value["Casts"].Size(); i += 1)
                {
                    Cast cast;
                    if (ParseObject(value["Casts"][i], "", false, cast, parseErrors))
                        casts.push_back(cast);
                }
                SetCasts(casts);
            }

            if (VerifyArray(value, "Genres", false, parseErrors))
            {
                for (rapidjson::SizeType i = 0; i < value["Genres"].Size(); i += 1)
                {
                    Genre genre;
                    if (ParseObject(value["Genres"][i], "", false, genre, parseErrors))
                        genres.push_back(genre);
                }
                SetGenres(genres);
            }

            if (ParseObject(value, "PurchaseFirstEpisode", false, purchaseFirstEpisode, parseErrors))
                SetPurchaseFirstEpisode(purchaseFirstEpisode);

            if (ParseString(value, "Modified", false, modified, parseErrors))
                SetModified(modified);

            if (ParseObject(value, "Seasons", false, seasons, parseErrors))
                SetSeasons(seasons);

            if (ParseObject(value, "Self", false, self, parseErrors))
                SetSelf(self);

            return !parseErrors;
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
