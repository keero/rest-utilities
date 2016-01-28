#ifndef READY4AIR_MEDIAPRODUCT_H
#define READY4AIR_MEDIAPRODUCT_H

#include "../common/Maybe.h"
#include "abstract/JsonDeserializable.h"
#include "hypermedia/Link.h"
#include "Entitlement.h"
#include "Cast.h"
#include "Image.h"
#include "WmvFile.h"
#include "SmoothManifest.h"
#include "Mp4File.h"
#include "HlsManifest.h"
#include "Subtitle.h"
#include "PurchaseItem.h"
#include "Reviews.h"
#include "Genre.h"
#include "Product.h"
#include "Play.h"

namespace ready4air
{
    namespace dto
    {
        enum ProductType
        {
            MovieProductType = 0,
            EpisodeProductType = 1,
            SeasonProductType = 2
        };

        class MediaProduct : public JsonDeserializable
        {
        public:
            MediaProduct() : TAG("ready4air::dto::MediaProduct")
            {
            }

            virtual ~MediaProduct()
            {
            }

            const Maybe<int> &GetProductId() const
            {
                return mProductId;
            }

            void SetProductId(int productId)
            {
                mProductId = productId;
            }

            const Maybe<ProductType> &GetProductType() const
            {
                return mProductType;
            }

            void SetProductType(const ProductType &productType)
            {
                mProductType = productType;
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

            const Maybe<Link> &GetSimilar() const
            {
                return mSimilar;
            }

            void SetSimilar(const Link &similar)
            {
                mSimilar = similar;
            }

            const Maybe<int> &GetMediaId() const
            {
                return mMediaId;
            }

            void SetMediaId(int mediaId)
            {
                mMediaId = mediaId;
            }

            const Maybe<STRING_T> &GetExternalId() const
            {
                return mExternalId;
            }

            void SetExternalId(const STRING_T &externalId)
            {
                mExternalId = externalId;
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

            const Maybe<int> &GetYear() const
            {
                return mYear;
            }

            void SetYear(int year)
            {
                mYear = year;
            }

            const Maybe<STRING_T> &GetProductionCountry() const
            {
                return mProductionCountry;
            }

            void SetProductionCountry(const STRING_T &productionCountry)
            {
                mProductionCountry = productionCountry;
            }

            const Maybe<int> &GetLength() const
            {
                return mLength;
            }

            void SetLength(int length)
            {
                mLength = length;
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

            const Maybe<STRING_T> &GetMainGenre() const
            {
                return mMainGenre;
            }

            void SetMainGenre(const STRING_T &mainGenre)
            {
                mMainGenre = mainGenre;
            }

            const Maybe<int> &GetAgeLimit() const
            {
                return mAgeLimit;
            }

            void SetAgeLimit(int ageLimit)
            {
                mAgeLimit = ageLimit;
            }

            const Maybe<BOOL_T> &IsHD() const
            {
                return mHD;
            }

            void SetHD(BOOL_T HD)
            {
                mHD = HD;
            }

            const Maybe<BOOL_T> &IsDubbed() const
            {
                return mDubbed;
            }

            void SetDubbed(BOOL_T dubbed)
            {
                mDubbed = dubbed;
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

            const Maybe<STRING_T> &GetModified() const
            {
                return mModified;
            }

            void SetModified(const STRING_T &modified)
            {
                mModified = modified;
            }

            const Maybe<VECTOR_T<STRING_T> > &GetAgeGroups() const
            {
                return mAgeGroups;
            }

            void SetAgeGroups(const VECTOR_T<STRING_T> &ageGroups)
            {
                mAgeGroups = ageGroups;
            }

            const Maybe<VECTOR_T<Entitlement> > &GetEntitlements() const
            {
                return mEntitlements;
            }

            void SetEntitlements(const VECTOR_T<Entitlement> &entitlements)
            {
                mEntitlements = entitlements;
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

            const Maybe<VECTOR_T<WmvFile> > &GetWmvFiles() const
            {
                return mWmvFiles;
            }

            void SetWmvFiles(const VECTOR_T<WmvFile> &wmvFiles)
            {
                mWmvFiles = wmvFiles;
            }

            const Maybe<VECTOR_T<SmoothManifest> > &GetSmoothManifests() const
            {
                return mSmoothManifests;
            }

            void SetSmoothManifests(const VECTOR_T<SmoothManifest> &smoothManifests)
            {
                mSmoothManifests = smoothManifests;
            }

            const Maybe<VECTOR_T<Mp4File> > &GetMp4Files() const
            {
                return mMp4Files;
            }

            void SetMp4Files(const VECTOR_T<Mp4File> &mp4Files)
            {
                mMp4Files = mp4Files;
            }

            const Maybe<VECTOR_T<HlsManifest> > &GetHlsManifests() const
            {
                return mHlsManifests;
            }

            void SetHlsManifests(const VECTOR_T<HlsManifest> &hlsManifests)
            {
                mHlsManifests = hlsManifests;
            }

            const Maybe<VECTOR_T<Subtitle> > &GetSubtitles() const
            {
                return mSubtitles;
            }

            void SetSubtitles(const VECTOR_T<Subtitle> &subtitles)
            {
                mSubtitles = subtitles;
            }

            const Maybe<Link> &GetSelf() const
            {
                return mSelf;
            }

            void SetSelf(const Link &self)
            {
                mSelf = self;
            }

            const Maybe<Play> &GetPlay() const
            {
                return mPlay;
            }

            void SetPlay(const Play &play)
            {
                mPlay = play;
            }

            const Maybe<Link> &GetFullPlay() const
            {
                return mFullPlay;
            }

            void SetFullPlay(const Link &fullPlay)
            {
                mFullPlay = fullPlay;
            }

            const Maybe<VECTOR_T<PurchaseItem> > &GetPurchaseItems() const
            {
                return mPurchaseItems;
            }

            void SetPurchaseItems(const VECTOR_T<PurchaseItem> &purchaseItems)
            {
                mPurchaseItems = purchaseItems;
            }

            const Maybe<Reviews> &GetReviews() const
            {
                return mReviews;
            }

            void SetReviews(const Reviews &reviews)
            {
                mReviews = reviews;
            }

            const Maybe<VECTOR_T<Genre> > &GetGenres() const
            {
                return mGenres;
            }

            void SetGenres(const VECTOR_T<Genre> &genres)
            {
                mGenres = genres;
            }

            const Maybe<VECTOR_T<Product> > &GetProducts() const
            {
                return mProducts;
            }

            void SetProducts(const VECTOR_T<Product> &products)
            {
                mProducts = products;
            }

            virtual BOOL_T InitFromJsonValue(const rapidjson::Value &value, ParseErrors &parseErrors)
            {
                INT32_T productId;
                STRING_T titleId;
                Link titleLink;
                Link similar;
                INT32_T mediaId;
                STRING_T externalId;
                STRING_T originalTitle;
                BOOL_T adult;
                INT32_T year;
                STRING_T productionCountry;
                INT32_T length;
                STRING_T localTitle;
                STRING_T shortTitle;
                STRING_T longSummary;
                STRING_T shortSummary;
                STRING_T sortTitle;
                STRING_T mainGenre;
                INT32_T ageLimit;
                BOOL_T hd;
                BOOL_T dubbed;
                STRING_T publishDate;
                STRING_T unPublishDate;
                STRING_T modified;
                VECTOR_T<STRING_T> ageGroups;
                VECTOR_T<Entitlement> entitlements;
                VECTOR_T<Cast> casts;
                VECTOR_T<Image> images;
                VECTOR_T<WmvFile> wmvFiles;
                VECTOR_T<SmoothManifest> smoothManifests;
                VECTOR_T<Mp4File> mp4Files;
                VECTOR_T<HlsManifest> hlsManifests;
                VECTOR_T<Subtitle> subtitles;
                Link self;
                Play play;
                Link fullPlay;
                VECTOR_T<PurchaseItem> purchaseItems;
                Reviews reviews;
                VECTOR_T<Genre> genres;
                VECTOR_T<Product> products;

                if (ParseInt(value, "ProductId", true, productId, parseErrors))
                    SetProductId(productId);

                if (ParseString(value, "TitleId", false, titleId, parseErrors))
                    SetTitleId(titleId);

                if (ParseObject(value, "TitleLink", false, titleLink, parseErrors))
                    SetTitleLink(titleLink);

                if (ParseObject(value, "Similar", false, similar, parseErrors))
                    SetSimilar(similar);

                if (ParseInt(value, "MediaId", true, mediaId, parseErrors))
                    SetMediaId(mediaId);

                if (ParseString(value, "ExternalId", false, externalId, parseErrors))
                    SetExternalId(externalId);

                if (ParseString(value, "OriginalTitle", false, originalTitle, parseErrors))
                    SetOriginalTitle(originalTitle);

                if (ParseBool(value, "Adult", true, adult, parseErrors))
                    SetAdult(adult);

                if (ParseInt(value, "Year", true, year, parseErrors))
                    SetYear(year);

                if (ParseString(value, "ProductionCountry", false, productionCountry, parseErrors))
                    SetProductionCountry(productionCountry);

                if (ParseInt(value, "Length", false, length, parseErrors))
                    SetLength(length);

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

                if (ParseString(value, "MainGenre", false, mainGenre, parseErrors))
                    SetMainGenre(mainGenre);

                if (ParseInt(value, "AgeLimit", false, ageLimit, parseErrors))
                    SetAgeLimit(ageLimit);

                if (ParseBool(value, "HD", false, hd, parseErrors))
                    SetHD(hd);

                if (ParseBool(value, "Dubbed", false, dubbed, parseErrors))
                    SetDubbed(dubbed);

                if (ParseString(value, "PublishDate", false, publishDate, parseErrors))
                    SetPublishDate(publishDate);

                if (ParseString(value, "UnPublishDate", false, unPublishDate, parseErrors))
                    SetUnPublishDate(unPublishDate);

                if (ParseString(value, "Modified", false, modified, parseErrors))
                    SetModified(modified);

                if (VerifyArray(value, "AgeGroups", false, parseErrors))
                {
                    for (rapidjson::SizeType i = 0; i < value["AgeGroups"].Size(); i += 1)
                    {
                        STRING_T ageGroup;
                        if (ParseString(value["AgeGroups"][i], "", false, ageGroup, parseErrors))
                            ageGroups.push_back(ageGroup);
                    }
                    SetAgeGroups(ageGroups);
                }

                if (VerifyArray(value, "Entitlements", false, parseErrors))
                {
                    for (rapidjson::SizeType i = 0; i < value["Entitlements"].Size(); i += 1)
                    {
                        Entitlement entitlement;
                        if (ParseObject(value["Entitlements"][i], "", false, entitlement, parseErrors))
                            entitlements.push_back(entitlement);
                    }
                    SetEntitlements(entitlements);
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

                if (VerifyArray(value, "WmvFiles", false, parseErrors))
                {
                    for (rapidjson::SizeType i = 0; i < value["WmvFiles"].Size(); i += 1)
                    {
                        WmvFile wmvFile;
                        if (ParseObject(value["WmvFiles"][i], "", false, wmvFile, parseErrors))
                            wmvFiles.push_back(wmvFile);
                    }
                    SetWmvFiles(wmvFiles);
                }

                if (VerifyArray(value, "SmoothManifests", false, parseErrors))
                {
                    for (rapidjson::SizeType i = 0; i < value["SmoothManifests"].Size(); i += 1)
                    {
                        SmoothManifest smoothManifest;
                        if (ParseObject(value["SmoothManifests"][i], "", false, smoothManifest, parseErrors))
                            smoothManifests.push_back(smoothManifest);
                    }
                    SetSmoothManifests(smoothManifests);
                }

                if (VerifyArray(value, "Mp4Files", false, parseErrors))
                {
                    for (rapidjson::SizeType i = 0; i < value["Mp4Files"].Size(); i += 1)
                    {
                        Mp4File mp4File;
                        if (ParseObject(value["Mp4Files"][i], "", false, mp4File, parseErrors))
                            mp4Files.push_back(mp4File);
                    }
                    SetMp4Files(mp4Files);
                }

                if (VerifyArray(value, "HlsManifests", false, parseErrors))
                {
                    for (rapidjson::SizeType i = 0; i < value["HlsManifests"].Size(); i += 1)
                    {
                        HlsManifest hlsManifest;
                        if (ParseObject(value["HlsManifests"][i], "", false, hlsManifest, parseErrors))
                            hlsManifests.push_back(hlsManifest);
                    }
                    SetHlsManifests(hlsManifests);
                }

                if (VerifyArray(value, "Subtitles", false, parseErrors))
                {
                    for (rapidjson::SizeType i = 0; i < value["Subtitles"].Size(); i += 1)
                    {
                        Subtitle subtitle;
                        if (ParseObject(value["Subtitles"][i], "", false, subtitle, parseErrors))
                            subtitles.push_back(subtitle);
                    }
                    SetSubtitles(subtitles);
                }

                if (ParseObject(value, "Self", false, self, parseErrors))
                    SetSelf(self);

                if (ParseObject(value, "Play", false, play, parseErrors))
                    SetPlay(play);

                if (ParseObject(value, "FullPlay", false, fullPlay, parseErrors))
                    SetFullPlay(fullPlay);

                if (VerifyArray(value, "PurchaseItems", false, parseErrors))
                {
                    for (rapidjson::SizeType i = 0; i < value["PurchaseItems"].Size(); i += 1)
                    {
                        PurchaseItem purchaseItem;
                        if (ParseObject(value["PurchaseItems"][i], "", false, purchaseItem, parseErrors))
                            purchaseItems.push_back(purchaseItem);
                    }
                    SetPurchaseItems(purchaseItems);
                }

                if (ParseObject(value, "Reviews", false, reviews, parseErrors))
                    SetReviews(reviews);

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

                if (VerifyArray(value, "Products", false, parseErrors))
                {
                    for (rapidjson::SizeType i = 0; i < value["Products"].Size(); i += 1)
                    {
                        Product product;
                        if (ParseObject(value["Products"][i], "", false, product, parseErrors))
                            products.push_back(product);
                    }
                    SetProducts(products);
                }

                return !parseErrors;
            }

        private:
            Maybe<int> mProductId;
            Maybe<STRING_T> mTitleId;
            Maybe<Link> mTitleLink;
            Maybe<Link> mSimilar;
            Maybe<int> mMediaId;
            Maybe<STRING_T> mExternalId;
            Maybe<STRING_T> mOriginalTitle;
            Maybe<BOOL_T> mAdult;
            Maybe<int> mYear;
            Maybe<STRING_T> mProductionCountry;
            Maybe<int> mLength;
            Maybe<STRING_T> mLocalTitle;
            Maybe<STRING_T> mShortTitle;
            Maybe<STRING_T> mLongSummary;
            Maybe<STRING_T> mShortSummary;
            Maybe<STRING_T> mSortTitle;
            Maybe<STRING_T> mMainGenre;
            Maybe<int> mAgeLimit;
            Maybe<BOOL_T> mHD;
            Maybe<BOOL_T> mDubbed;
            Maybe<STRING_T> mPublishDate;
            Maybe<STRING_T> mUnPublishDate;
            Maybe<STRING_T> mModified;
            Maybe<VECTOR_T<STRING_T> > mAgeGroups;
            Maybe<VECTOR_T<Entitlement> > mEntitlements;
            Maybe<VECTOR_T<Cast> > mCasts;
            Maybe<VECTOR_T<Image> > mImages;
            Maybe<VECTOR_T<WmvFile> > mWmvFiles;
            Maybe<VECTOR_T<SmoothManifest> > mSmoothManifests;
            Maybe<VECTOR_T<Mp4File> > mMp4Files;
            Maybe<VECTOR_T<HlsManifest> > mHlsManifests;
            Maybe<VECTOR_T<Subtitle> > mSubtitles;
            Maybe<Link> mSelf;
            Maybe<Play> mPlay;
            Maybe<Link> mFullPlay;
            Maybe<VECTOR_T<PurchaseItem> > mPurchaseItems;
            Maybe<Reviews> mReviews;
            Maybe<VECTOR_T<Genre> > mGenres;
            Maybe<VECTOR_T<Product> > mProducts;
            const STRING_T TAG;

        protected:
            Maybe<ProductType> mProductType;
        };
    }
}

#endif //READY4AIR_MEDIAPRODUCT_H
