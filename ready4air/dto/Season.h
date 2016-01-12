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

        virtual bool InitFromJsonValue(const rapidjson::Value &value, ParseErrors &parseErrors)
        {
            int seasonNo;
            Link serie;
            std::vector<Episode> episodes;
            std::vector<SeasonProduct> seasonProducts;
            std::string titleId;
            Link titleLink;
            std::string originalTitle;
            bool adult;
            std::string localTitle;
            std::string shortTitle;
            std::string longSummary;
            std::string shortSummary;
            std::string sortTitle;
            std::string productionCountry;
            int year;
            int length;
            std::string publishDate;
            std::string unPublishDate;
            int ageLimit;
            std::string modified;
            std::vector<Cast> casts;
            std::vector<Image> images;
            std::vector<Genre> genres;
            Link self;
            Link watchedEpisodes;
            Link allEpisodes;

            if (ParseInt(value, "SeasonNo", true, seasonNo, parseErrors))
                SetSeasonNo(seasonNo);

            if (ParseObject(value, "Serie", true, serie, parseErrors))
                SetSerie(serie);

            if (VerifyArray(value, "Episodes", false, parseErrors))
            {
                for (rapidjson::SizeType i = 0; i < value["Episodes"].Size(); i += 1)
                {
                    Episode episode;
                    if (ParseObject(value["Episodes"][i], "", false, episode, parseErrors))
                        episodes.push_back(episode);
                }
                SetEpisodes(episodes);
            }

            if (VerifyArray(value, "SeasonProducts", false, parseErrors))
            {
                for (rapidjson::SizeType i = 0; i < value["SeasonProducts"].Size(); i += 1)
                {
                    SeasonProduct seasonProduct;
                    if (ParseObject(value["SeasonProducts"][i], "", false, seasonProduct, parseErrors))
                        seasonProducts.push_back(seasonProduct);
                }
                SetSeasonProducts(seasonProducts);
            }

            if (ParseString(value, "TitleId", false, titleId, parseErrors))
                SetTitleId(titleId);

            if (ParseObject(value, "TitleLink", false, titleLink, parseErrors))
                SetTitleLink(titleLink);

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

            if (ParseString(value, "ProductionCountry", false, productionCountry, parseErrors))
                SetProductionCountry(productionCountry);

            if (ParseInt(value, "Year", true, year, parseErrors))
                SetYear((short) year);

            if (ParseInt(value, "Length", false, length, parseErrors))
                SetLength(length);

            if (ParseString(value, "PublishDate", false, publishDate, parseErrors))
                SetPublishDate(publishDate);

            if (ParseString(value, "UnPublishDate", false, unPublishDate, parseErrors))
                SetUnPublishDate(unPublishDate);

            if (ParseInt(value, "AgeLimit", false, ageLimit, parseErrors))
                SetAgeLimit(ageLimit);

            if (ParseString(value, "Modified", false, modified, parseErrors))
                SetModified(modified);

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

            if (ParseObject(value, "Self", false, self, parseErrors))
                SetSelf(self);

            if (ParseObject(value, "WatchedEpisodes", false, watchedEpisodes, parseErrors))
                SetWatchedEpisodes(watchedEpisodes);

            if (ParseObject(value, "AllEpisodes", true, allEpisodes, parseErrors))
                SetAllEpisodes(allEpisodes);

            return !parseErrors;
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
    };
}

#endif //READY4AIR_SEASON_H
