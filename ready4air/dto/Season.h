#ifndef READY4AIR_SEASON_H
#define READY4AIR_SEASON_H

#include "../common/Maybe.h"
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
    namespace dto
    {
        class Season : public JsonDeserializable
        {
        public:
            Season() : TAG("ready4air::dto::Season")
            {
            }

            virtual ~Season()
            {
            }

            const Maybe<int> &GetSeasonNo() const
            {
                return mSeasonNo;
            }

            void SetSeasonNo(int seasonNo)
            {
                mSeasonNo = seasonNo;
            }

            const Maybe<Link> &GetSerie() const
            {
                return mSerie;
            }

            void SetSerie(const Link &serie)
            {
                mSerie = serie;
            }

            const Maybe<VECTOR_T<Episode> > &GetEpisodes() const
            {
                return mEpisodes;
            }

            void SetEpisodes(const VECTOR_T<Episode> &episodes)
            {
                mEpisodes = episodes;
            }

            const Maybe<VECTOR_T<SeasonProduct> > &GetSeasonProducts() const
            {
                return mSeasonProducts;
            }

            void SetSeasonProducts(const VECTOR_T<SeasonProduct> &seasonProducts)
            {
                mSeasonProducts = seasonProducts;
            }

            const Maybe<STRING_T> &GetTitleId() const
            {
                return mTitleId;
            }

            void SetTitleId(const STRING_T &titleId)
            {
                mTitleId = titleId;
            }

            const Maybe<Link> &GetTitleLink() const
            {
                return mTitleLink;
            }

            void SetTitleLink(const Link &titleLink)
            {
                mTitleLink = titleLink;
            }

            const Maybe<STRING_T> &GetOriginalTitle() const
            {
                return mOriginalTitle;
            }

            void SetOriginalTitle(const STRING_T &originalTitle)
            {
                mOriginalTitle = originalTitle;
            }

            const Maybe<BOOL_T> &IsAdult() const
            {
                return mAdult;
            }

            void SetAdult(BOOL_T adult)
            {
                mAdult = adult;
            }

            const Maybe<STRING_T> &GetLocalTitle() const
            {
                return mLocalTitle;
            }

            void SetLocalTitle(const STRING_T &localTitle)
            {
                mLocalTitle = localTitle;
            }

            const Maybe<STRING_T> &GetShortTitle() const
            {
                return mShortTitle;
            }

            void SetShortTitle(const STRING_T &shortTitle)
            {
                mShortTitle = shortTitle;
            }

            const Maybe<STRING_T> &GetLongSummary() const
            {
                return mLongSummary;
            }

            void SetLongSummary(const STRING_T &longSummary)
            {
                mLongSummary = longSummary;
            }

            const Maybe<STRING_T> &GetShortSummary() const
            {
                return mShortSummary;
            }

            void SetShortSummary(const STRING_T &shortSummary)
            {
                mShortSummary = shortSummary;
            }

            const Maybe<STRING_T> &GetSortTitle() const
            {
                return mSortTitle;
            }

            void SetSortTitle(const STRING_T &sortTitle)
            {
                mSortTitle = sortTitle;
            }

            const Maybe<STRING_T> &GetProductionCountry() const
            {
                return mProductionCountry;
            }

            void SetProductionCountry(const STRING_T &productionCountry)
            {
                mProductionCountry = productionCountry;
            }

            const Maybe<INT16_T> &GetYear() const
            {
                return mYear;
            }

            void SetYear(INT16_T year)
            {
                mYear = year;
            }

            const Maybe<int> &GetLength() const
            {
                return mLength;
            }

            void SetLength(int length)
            {
                mLength = length;
            }

            const Maybe<STRING_T> &GetPublishDate() const
            {
                return mPublishDate;
            }

            void SetPublishDate(const STRING_T &publishDate)
            {
                mPublishDate = publishDate;
            }

            const Maybe<STRING_T> &GetUnPublishDate() const
            {
                return mUnPublishDate;
            }

            void SetUnPublishDate(const STRING_T &unPublishDate)
            {
                mUnPublishDate = unPublishDate;
            }

            const Maybe<int> &GetAgeLimit() const
            {
                return mAgeLimit;
            }

            void SetAgeLimit(int ageLimit)
            {
                mAgeLimit = ageLimit;
            }

            const Maybe<STRING_T> &GetModified() const
            {
                return mModified;
            }

            void SetModified(const STRING_T &modified)
            {
                mModified = modified;
            }

            const Maybe<VECTOR_T<Cast> > &GetCasts() const
            {
                return mCasts;
            }

            void SetCasts(const VECTOR_T<Cast> &casts)
            {
                mCasts = casts;
            }

            const Maybe<VECTOR_T<Image> > &GetImages() const
            {
                return mImages;
            }

            void SetImages(const VECTOR_T<Image> &images)
            {
                mImages = images;
            }

            const Maybe<VECTOR_T<Genre> > &GetGenres() const
            {
                return mGenres;
            }

            void SetGenres(const VECTOR_T<Genre> &genres)
            {
                mGenres = genres;
            }

            const Maybe<Link> &GetSelf() const
            {
                return mSelf;
            }

            void SetSelf(const Link &self)
            {
                mSelf = self;
            }

            const Maybe<Link> &GetWatchedEpisodes() const
            {
                return mWatchedEpisodes;
            }

            void SetWatchedEpisodes(const Link &watchedEpisodes)
            {
                mWatchedEpisodes = watchedEpisodes;
            }

            const Maybe<Link> &GetAllEpisodes() const
            {
                return mAllEpisodes;
            }

            void SetAllEpisodes(const Link &allEpisodes)
            {
                mAllEpisodes = allEpisodes;
            }

            virtual BOOL_T InitFromJsonValue(const rapidjson::Value &value, ParseErrors &parseErrors,
                                             VECTOR_T<STRING_T> &context)
            {
                INT32_T seasonNo;
                Link serie;
                VECTOR_T<Episode> episodes;
                VECTOR_T<SeasonProduct> seasonProducts;
                STRING_T titleId;
                Link titleLink;
                STRING_T originalTitle;
                BOOL_T adult;
                STRING_T localTitle;
                STRING_T shortTitle;
                STRING_T longSummary;
                STRING_T shortSummary;
                STRING_T sortTitle;
                STRING_T productionCountry;
                INT32_T year;
                INT32_T length;
                STRING_T publishDate;
                STRING_T unPublishDate;
                INT32_T ageLimit;
                STRING_T modified;
                VECTOR_T<Cast> casts;
                VECTOR_T<Image> images;
                VECTOR_T<Genre> genres;
                Link self;
                Link watchedEpisodes;
                Link allEpisodes;

                context.push_back(TAG);

                if (ParseInt(value, "SeasonNo", true, seasonNo, parseErrors, context))
                    SetSeasonNo(seasonNo);

                if (ParseObject(value, "Serie", true, serie, parseErrors, context))
                    SetSerie(serie);

                if (VerifyArray(value, "Episodes", false, parseErrors, context))
                {
                    for (rapidjson::SizeType i = 0; i < value["Episodes"].Size(); i += 1)
                    {
                        Episode episode;
                        if (ParseObject(value["Episodes"][i], "", false, episode, parseErrors, context))
                            episodes.push_back(episode);
                    }
                    SetEpisodes(episodes);
                }

                if (VerifyArray(value, "SeasonProducts", false, parseErrors, context))
                {
                    for (rapidjson::SizeType i = 0; i < value["SeasonProducts"].Size(); i += 1)
                    {
                        SeasonProduct seasonProduct;
                        if (ParseObject(value["SeasonProducts"][i], "", false, seasonProduct, parseErrors,
                                        context))
                            seasonProducts.push_back(seasonProduct);
                    }
                    SetSeasonProducts(seasonProducts);
                }

                if (ParseString(value, "TitleId", false, titleId, parseErrors, context))
                    SetTitleId(titleId);

                if (ParseObject(value, "TitleLink", false, titleLink, parseErrors, context))
                    SetTitleLink(titleLink);

                if (ParseString(value, "OriginalTitle", false, originalTitle, parseErrors, context))
                    SetOriginalTitle(originalTitle);

                if (ParseBool(value, "Adult", true, adult, parseErrors, context))
                    SetAdult(adult);

                if (ParseString(value, "LocalTitle", false, localTitle, parseErrors, context))
                    SetLocalTitle(localTitle);

                if (ParseString(value, "ShortTitle", false, shortTitle, parseErrors, context))
                    SetShortTitle(shortTitle);

                if (ParseString(value, "LongSummary", false, longSummary, parseErrors, context))
                    SetLongSummary(longSummary);

                if (ParseString(value, "ShortSummary", false, shortSummary, parseErrors, context))
                    SetShortSummary(shortSummary);

                if (ParseString(value, "SortTitle", false, sortTitle, parseErrors, context))
                    SetSortTitle(sortTitle);

                if (ParseString(value, "ProductionCountry", false, productionCountry, parseErrors, context))
                    SetProductionCountry(productionCountry);

                if (ParseInt(value, "Year", true, year, parseErrors, context))
                    SetYear((INT16_T) year);

                if (ParseInt(value, "Length", false, length, parseErrors, context))
                    SetLength(length);

                if (ParseString(value, "PublishDate", false, publishDate, parseErrors, context))
                    SetPublishDate(publishDate);

                if (ParseString(value, "UnPublishDate", false, unPublishDate, parseErrors, context))
                    SetUnPublishDate(unPublishDate);

                if (ParseInt(value, "AgeLimit", false, ageLimit, parseErrors, context))
                    SetAgeLimit(ageLimit);

                if (ParseString(value, "Modified", false, modified, parseErrors, context))
                    SetModified(modified);

                if (VerifyArray(value, "Casts", false, parseErrors, context))
                {
                    for (rapidjson::SizeType i = 0; i < value["Casts"].Size(); i += 1)
                    {
                        Cast cast;
                        if (ParseObject(value["Casts"][i], "", false, cast, parseErrors, context))
                            casts.push_back(cast);
                    }
                    SetCasts(casts);
                }

                if (VerifyArray(value, "Images", false, parseErrors, context))
                {
                    for (rapidjson::SizeType i = 0; i < value["Images"].Size(); i += 1)
                    {
                        Image image;
                        if (ParseObject(value["Images"][i], "", false, image, parseErrors, context))
                            images.push_back(image);
                    }
                    SetImages(images);
                }

                if (VerifyArray(value, "Genres", false, parseErrors, context))
                {
                    for (rapidjson::SizeType i = 0; i < value["Genres"].Size(); i += 1)
                    {
                        Genre genre;
                        if (ParseObject(value["Genres"][i], "", false, genre, parseErrors, context))
                            genres.push_back(genre);
                    }
                    SetGenres(genres);
                }

                if (ParseObject(value, "Self", false, self, parseErrors, context))
                    SetSelf(self);

                if (ParseObject(value, "WatchedEpisodes", false, watchedEpisodes, parseErrors, context))
                    SetWatchedEpisodes(watchedEpisodes);

                if (ParseObject(value, "AllEpisodes", true, allEpisodes, parseErrors, context))
                    SetAllEpisodes(allEpisodes);

                context.pop_back();
                return !parseErrors;
            }

        private:
            Maybe<int> mSeasonNo;
            Maybe<Link> mSerie;
            Maybe<VECTOR_T<Episode> > mEpisodes;
            Maybe<VECTOR_T<SeasonProduct> > mSeasonProducts;
            Maybe<STRING_T> mTitleId;
            Maybe<Link> mTitleLink;
            Maybe<STRING_T> mOriginalTitle;
            Maybe<BOOL_T> mAdult;
            Maybe<STRING_T> mLocalTitle;
            Maybe<STRING_T> mShortTitle;
            Maybe<STRING_T> mLongSummary;
            Maybe<STRING_T> mShortSummary;
            Maybe<STRING_T> mSortTitle;
            Maybe<STRING_T> mProductionCountry;
            Maybe<INT16_T> mYear;
            Maybe<int> mLength;
            Maybe<STRING_T> mPublishDate;
            Maybe<STRING_T> mUnPublishDate;
            Maybe<int> mAgeLimit;
            Maybe<STRING_T> mModified;
            Maybe<VECTOR_T<Cast> > mCasts;
            Maybe<VECTOR_T<Image> > mImages;
            Maybe<VECTOR_T<Genre> > mGenres;
            Maybe<Link> mSelf;
            Maybe<Link> mWatchedEpisodes;
            Maybe<Link> mAllEpisodes;
            STRING_T TAG;
        };
    }
}

#endif //READY4AIR_SEASON_H
