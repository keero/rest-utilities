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
            MediaProduct()
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

            const Maybe<std::string> &GetTitleId() const
            {
                return mTitleId;
            }

            void SetTitleId(const std::string &titleId)
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

            const Maybe<std::string> &GetExternalId() const
            {
                return mExternalId;
            }

            void SetExternalId(const std::string &externalId)
            {
                mExternalId = externalId;
            }

            const Maybe<std::string> &GetOriginalTitle() const
            {
                return mOriginalTitle;
            }

            void SetOriginalTitle(const std::string &originalTitle)
            {
                mOriginalTitle = originalTitle;
            }

            const Maybe<bool> &IsAdult() const
            {
                return mAdult;
            }

            void SetAdult(bool adult)
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

            const Maybe<std::string> &GetProductionCountry() const
            {
                return mProductionCountry;
            }

            void SetProductionCountry(const std::string &productionCountry)
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

            const Maybe<std::string> &GetLocalTitle() const
            {
                return mLocalTitle;
            }

            void SetLocalTitle(const std::string &localTitle)
            {
                mLocalTitle = localTitle;
            }

            const Maybe<std::string> &GetShortTitle() const
            {
                return mShortTitle;
            }

            void SetShortTitle(const std::string &shortTitle)
            {
                mShortTitle = shortTitle;
            }

            const Maybe<std::string> &GetLongSummary() const
            {
                return mLongSummary;
            }

            void SetLongSummary(const std::string &longSummary)
            {
                mLongSummary = longSummary;
            }

            const Maybe<std::string> &GetShortSummary() const
            {
                return mShortSummary;
            }

            void SetShortSummary(const std::string &shortSummary)
            {
                mShortSummary = shortSummary;
            }

            const Maybe<std::string> &GetSortTitle() const
            {
                return mSortTitle;
            }

            void SetSortTitle(const std::string &sortTitle)
            {
                mSortTitle = sortTitle;
            }

            const Maybe<std::string> &GetMainGenre() const
            {
                return mMainGenre;
            }

            void SetMainGenre(const std::string &mainGenre)
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

            const Maybe<bool> &IsHD() const
            {
                return mHD;
            }

            void SetHD(bool HD)
            {
                mHD = HD;
            }

            const Maybe<bool> &IsDubbed() const
            {
                return mDubbed;
            }

            void SetDubbed(bool dubbed)
            {
                mDubbed = dubbed;
            }

            const Maybe<std::string> &GetPublishDate() const
            {
                return mPublishDate;
            }

            void SetPublishDate(const std::string &publishDate)
            {
                mPublishDate = publishDate;
            }

            const Maybe<std::string> &GetUnPublishDate() const
            {
                return mUnPublishDate;
            }

            void SetUnPublishDate(const std::string &unPublishDate)
            {
                mUnPublishDate = unPublishDate;
            }

            const Maybe<std::string> &GetModified() const
            {
                return mModified;
            }

            void SetModified(const std::string &modified)
            {
                mModified = modified;
            }

            const Maybe<std::vector<std::string> > &GetAgeGroups() const
            {
                return mAgeGroups;
            }

            void SetAgeGroups(const std::vector<std::string> &ageGroups)
            {
                mAgeGroups = ageGroups;
            }

            const Maybe<std::vector<Entitlement> > &GetEntitlements() const
            {
                return mEntitlements;
            }

            void SetEntitlements(const std::vector<Entitlement> &entitlements)
            {
                mEntitlements = entitlements;
            }

            const Maybe<std::vector<Cast> > &GetCasts() const
            {
                return mCasts;
            }

            void SetCasts(const std::vector<Cast> &casts)
            {
                mCasts = casts;
            }

            const Maybe<std::vector<Image> > &GetImages() const
            {
                return mImages;
            }

            void SetImages(const std::vector<Image> &images)
            {
                mImages = images;
            }

            const Maybe<std::vector<WmvFile> > &GetWmvFiles() const
            {
                return mWmvFiles;
            }

            void SetWmvFiles(const std::vector<WmvFile> &wmvFiles)
            {
                mWmvFiles = wmvFiles;
            }

            const Maybe<std::vector<SmoothManifest> > &GetSmoothManifests() const
            {
                return mSmoothManifests;
            }

            void SetSmoothManifests(const std::vector<SmoothManifest> &smoothManifests)
            {
                mSmoothManifests = smoothManifests;
            }

            const Maybe<std::vector<Mp4File> > &GetMp4Files() const
            {
                return mMp4Files;
            }

            void SetMp4Files(const std::vector<Mp4File> &mp4Files)
            {
                mMp4Files = mp4Files;
            }

            const Maybe<std::vector<HlsManifest> > &GetHlsManifests() const
            {
                return mHlsManifests;
            }

            void SetHlsManifests(const std::vector<HlsManifest> &hlsManifests)
            {
                mHlsManifests = hlsManifests;
            }

            const Maybe<std::vector<Subtitle> > &GetSubtitles() const
            {
                return mSubtitles;
            }

            void SetSubtitles(const std::vector<Subtitle> &subtitles)
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

            const Maybe<Link> &GetFullPlay() const
            {
                return mFullPlay;
            }

            void SetFullPlay(const Link &fullPlay)
            {
                mFullPlay = fullPlay;
            }

            const Maybe<std::vector<PurchaseItem> > &GetPurchaseItems() const
            {
                return mPurchaseItems;
            }

            void SetPurchaseItems(const std::vector<PurchaseItem> &purchaseItems)
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

            const Maybe<std::vector<Genre> > &GetGenres() const
            {
                return mGenres;
            }

            void SetGenres(const std::vector<Genre> &genres)
            {
                mGenres = genres;
            }

            const Maybe<std::vector<Product> > &GetProducts() const
            {
                return mProducts;
            }

            void SetProducts(const std::vector<Product> &products)
            {
                mProducts = products;
            }

            virtual bool InitFromJsonValue(const rapidjson::Value &value, ParseErrors &parseErrors)
            {
                int productId;
                std::string titleId;
                Link titleLink;
                Link similar;
                int mediaId;
                std::string externalId;
                std::string originalTitle;
                bool adult;
                int year;
                std::string productionCountry;
                int length;
                std::string localTitle;
                std::string shortTitle;
                std::string longSummary;
                std::string shortSummary;
                std::string sortTitle;
                std::string mainGenre;
                int ageLimit;
                bool hd;
                bool dubbed;
                std::string publishDate;
                std::string unPublishDate;
                std::string modified;
                std::vector<std::string> ageGroups;
                std::vector<Entitlement> entitlements;
                std::vector<Cast> casts;
                std::vector<Image> images;
                std::vector<WmvFile> wmvFiles;
                std::vector<SmoothManifest> smoothManifests;
                std::vector<Mp4File> mp4Files;
                std::vector<HlsManifest> hlsManifests;
                std::vector<Subtitle> subtitles;
                Link self;
                Link fullPlay;
                std::vector<PurchaseItem> purchaseItems;
                Reviews reviews;
                std::vector<Genre> genres;
                std::vector<Product> products;

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
                        std::string ageGroup;
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
            Maybe<std::string> mTitleId;
            Maybe<Link> mTitleLink;
            Maybe<Link> mSimilar;
            Maybe<int> mMediaId;
            Maybe<std::string> mExternalId;
            Maybe<std::string> mOriginalTitle;
            Maybe<bool> mAdult;
            Maybe<int> mYear;
            Maybe<std::string> mProductionCountry;
            Maybe<int> mLength;
            Maybe<std::string> mLocalTitle;
            Maybe<std::string> mShortTitle;
            Maybe<std::string> mLongSummary;
            Maybe<std::string> mShortSummary;
            Maybe<std::string> mSortTitle;
            Maybe<std::string> mMainGenre;
            Maybe<int> mAgeLimit;
            Maybe<bool> mHD;
            Maybe<bool> mDubbed;
            Maybe<std::string> mPublishDate;
            Maybe<std::string> mUnPublishDate;
            Maybe<std::string> mModified;
            Maybe<std::vector<std::string> > mAgeGroups;
            Maybe<std::vector<Entitlement> > mEntitlements;
            Maybe<std::vector<Cast> > mCasts;
            Maybe<std::vector<Image> > mImages;
            Maybe<std::vector<WmvFile> > mWmvFiles;
            Maybe<std::vector<SmoothManifest> > mSmoothManifests;
            Maybe<std::vector<Mp4File> > mMp4Files;
            Maybe<std::vector<HlsManifest> > mHlsManifests;
            Maybe<std::vector<Subtitle> > mSubtitles;
            Maybe<Link> mSelf;
            Maybe<Link> mFullPlay;
            Maybe<std::vector<PurchaseItem> > mPurchaseItems;
            Maybe<Reviews> mReviews;
            Maybe<std::vector<Genre> > mGenres;
            Maybe<std::vector<Product> > mProducts;

        protected:
            Maybe<ProductType> mProductType;
        };
    }
}

#endif //READY4AIR_MEDIAPRODUCT_H
