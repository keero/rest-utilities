#ifndef READY4AIR_SERIES_H
#define READY4AIR_SERIES_H

#include "../common/Maybe.h"
#include "abstract/JsonDeserializable.h"
#include "Image.h"
#include "Cast.h"
#include "Genre.h"
#include "hypermedia/Form.h"
#include "hypermedia/Link.h"

namespace ready4air
{
    namespace dto
    {
        class Series : public JsonDeserializable
        {
        public:
            Series() : TAG("ready4air::dto::Series")
            {
            }

            virtual ~Series()
            {
            }

            const Maybe <STRING_T> &GetId() const
            {
                return mId;
            }

            void SetId(const STRING_T &id)
            {
                mId = id;
            }

            const Maybe <STRING_T> &GetExternalId() const
            {
                return mExternalId;
            }

            void SetExternalId(const STRING_T &externalId)
            {
                mExternalId = externalId;
            }

            const Maybe <STRING_T> &GetOriginalTitle() const
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

            const Maybe <STRING_T> &GetLocalTitle() const
            {
                return mLocalTitle;
            }

            void SetLocalTitle(const STRING_T &localTitle)
            {
                mLocalTitle = localTitle;
            }

            const Maybe <STRING_T> &GetShortTitle() const
            {
                return mShortTitle;
            }

            void SetShortTitle(const STRING_T &shortTitle)
            {
                mShortTitle = shortTitle;
            }

            const Maybe <STRING_T> &GetLongSummary() const
            {
                return mLongSummary;
            }

            void SetLongSummary(const STRING_T &longSummary)
            {
                mLongSummary = longSummary;
            }

            const Maybe <STRING_T> &GetShortSummary() const
            {
                return mShortSummary;
            }

            void SetShortSummary(const STRING_T &shortSummary)
            {
                mShortSummary = shortSummary;
            }

            const Maybe <STRING_T> &GetSortTitle() const
            {
                return mSortTitle;
            }

            void SetSortTitle(const STRING_T &sortTitle)
            {
                mSortTitle = sortTitle;
            }

            const Maybe<INT16_T> &GetMinYear() const
            {
                return mMinYear;
            }

            void SetMinYear(INT16_T minYear)
            {
                mMinYear = minYear;
            }

            const Maybe<INT16_T> &GetMaxYear() const
            {
                return mMaxYear;
            }

            void SetMaxYear(INT16_T maxYear)
            {
                mMaxYear = maxYear;
            }

            const Maybe<int> &GetEpisodeLength() const
            {
                return mEpisodeLength;
            }

            void SetEpisodeLength(int episodeLength)
            {
                mEpisodeLength = episodeLength;
            }

            const Maybe<int> &GetAgeLimit() const
            {
                return mAgeLimit;
            }

            void SetAgeLimit(int ageLimit)
            {
                mAgeLimit = ageLimit;
            }

            const Maybe <STRING_T> &GetProductionCountry() const
            {
                return mProductionCountry;
            }

            void SetProductionCountry(const STRING_T &productionCountry)
            {
                mProductionCountry = productionCountry;
            }

            const Maybe <VECTOR_T<STRING_T>> &GetAgeGroups() const
            {
                return mAgeGroups;
            }

            void SetAgeGroups(const VECTOR_T<STRING_T> &ageGroups)
            {
                mAgeGroups = ageGroups;
            }

            const Maybe <VECTOR_T<Image>> &GetImages() const
            {
                return mImages;
            }

            void SetImages(const VECTOR_T<Image> &images)
            {
                mImages = images;
            }

            const Maybe <VECTOR_T<Cast>> &GetCasts() const
            {
                return mCasts;
            }

            void SetCasts(const VECTOR_T<Cast> &casts)
            {
                mCasts = casts;
            }

            const Maybe <VECTOR_T<Genre>> &GetGenres() const
            {
                return mGenres;
            }

            void SetGenres(const VECTOR_T<Genre> &genres)
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

            const Maybe <STRING_T> &GetModified() const
            {
                return mModified;
            }

            void SetModified(const STRING_T &modified)
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

            virtual BOOL_T InitFromJsonValue(const rapidjson::Value &value, ParseErrors &parseErrors,
                                             VECTOR_T<STRING_T> &context)
            {
                STRING_T id;
                STRING_T externalId;
                STRING_T originalTitle;
                BOOL_T adult;
                STRING_T localTitle;
                STRING_T shortTitle;
                STRING_T longSummary;
                STRING_T shortSummary;
                STRING_T sortTitle;
                INT32_T minYear;
                INT32_T maxYear;
                INT32_T episodeLength;
                INT32_T ageLimit;
                STRING_T productionCountry;
                VECTOR_T<STRING_T> ageGroups;
                VECTOR_T<Image> images;
                VECTOR_T<Cast> casts;
                VECTOR_T<Genre> genres;
                Form purchaseFirstEpisode;
                STRING_T modified;
                Link seasons;
                Link self;

                context.push_back(TAG);

                if (ParseString(value, "Id", true, id, parseErrors, context))
                    SetId(id);

                if (ParseString(value, "ExternalId", true, externalId, parseErrors, context))
                    SetExternalId(externalId);

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

                if (ParseInt(value, "MinYear", true, minYear, parseErrors, context))
                    SetMinYear((INT16_T) minYear);

                if (ParseInt(value, "MaxYear", true, maxYear, parseErrors, context))
                    SetMaxYear((INT16_T) maxYear);

                if (ParseInt(value, "EpisodeLength", false, episodeLength, parseErrors, context))
                    SetEpisodeLength(episodeLength);

                if (ParseInt(value, "AgeLimit", false, ageLimit, parseErrors, context))
                    SetAgeLimit(ageLimit);

                if (ParseString(value, "ProductionCountry", false, productionCountry, parseErrors, context))
                    SetProductionCountry(productionCountry);

                if (VerifyArray(value, "AgeGroups", false, parseErrors, context))
                {
                    for (rapidjson::SizeType i = 0; i < value["AgeGroups"].Size(); i += 1)
                    {
                        STRING_T ageGroup;
                        if (ParseString(value["AgeGroups"][i], "", false, ageGroup, parseErrors, context))
                            ageGroups.push_back(ageGroup);
                    }
                    SetAgeGroups(ageGroups);
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

                if (ParseObject(value, "PurchaseFirstEpisode", false, purchaseFirstEpisode, parseErrors,
                                context))
                    SetPurchaseFirstEpisode(purchaseFirstEpisode);

                if (ParseString(value, "Modified", false, modified, parseErrors, context))
                    SetModified(modified);

                if (ParseObject(value, "Seasons", false, seasons, parseErrors, context))
                    SetSeasons(seasons);

                if (ParseObject(value, "Self", false, self, parseErrors, context))
                    SetSelf(self);

                context.pop_back();
                return !parseErrors;
            }

        private:
            Maybe <STRING_T> mId;
            Maybe <STRING_T> mExternalId;
            Maybe <STRING_T> mOriginalTitle;
            Maybe<BOOL_T> mAdult;
            Maybe <STRING_T> mLocalTitle;
            Maybe <STRING_T> mShortTitle;
            Maybe <STRING_T> mLongSummary;
            Maybe <STRING_T> mShortSummary;
            Maybe <STRING_T> mSortTitle;
            Maybe<INT16_T> mMinYear;
            Maybe<INT16_T> mMaxYear;
            Maybe<int> mEpisodeLength;
            Maybe<int> mAgeLimit;
            Maybe <STRING_T> mProductionCountry;
            Maybe <VECTOR_T<STRING_T>> mAgeGroups;
            Maybe <VECTOR_T<Image>> mImages;
            Maybe <VECTOR_T<Cast>> mCasts;
            Maybe <VECTOR_T<Genre>> mGenres;
            Maybe <Form> mPurchaseFirstEpisode;
            Maybe <STRING_T> mModified;
            Maybe <Link> mSeasons;
            Maybe <Link> mSelf;
            STRING_T TAG;
        };
    }
}

#endif //READY4AIR_SERIES_H
