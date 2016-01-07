#ifndef READY4AIR_MEDIAPRODUCT_H
#define READY4AIR_MEDIAPRODUCT_H

#include "../maybe/Maybe.h"
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

namespace ready4air
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

        const Maybe <int> &GetProductId() const
        {
            return mProductId;
        }

        void SetProductId(int productId)
        {
            mProductId = productId;
        }

        const Maybe <ProductType> &GetProductType() const
        {
            return mProductType;
        }

        void SetProductType(const ProductType &productType)
        {
            mProductType = productType;
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

        const Maybe <Link> &GetSimilar() const
        {
            return mSimilar;
        }

        void SetSimilar(const Link &similar)
        {
            mSimilar = similar;
        }

        const Maybe <int> &GetMediaId() const
        {
            return mMediaId;
        }

        void SetMediaId(int mediaId)
        {
            mMediaId = mediaId;
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

        const Maybe <int> &GetYear() const
        {
            return mYear;
        }

        void SetYear(int year)
        {
            mYear = year;
        }

        const Maybe <std::string> &GetProductionCountry() const
        {
            return mProductionCountry;
        }

        void SetProductionCountry(const std::string &productionCountry)
        {
            mProductionCountry = productionCountry;
        }

        const Maybe <int> &GetLength() const
        {
            return mLength;
        }

        void SetLength(int length)
        {
            mLength = length;
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

        const Maybe <std::string> &GetMainGenre() const
        {
            return mMainGenre;
        }

        void SetMainGenre(const std::string &mainGenre)
        {
            mMainGenre = mainGenre;
        }

        const Maybe <int> &GetAgeLimit() const
        {
            return mAgeLimit;
        }

        void SetAgeLimit(int ageLimit)
        {
            mAgeLimit = ageLimit;
        }

        const Maybe <bool> &IsHD() const
        {
            return mHD;
        }

        void SetHD(bool HD)
        {
            mHD = HD;
        }

        const Maybe <bool> &IsDubbed() const
        {
            return mDubbed;
        }

        void SetDubbed(bool dubbed)
        {
            mDubbed = dubbed;
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

        const Maybe <std::string> &GetModified() const
        {
            return mModified;
        }

        void SetModified(const std::string &modified)
        {
            mModified = modified;
        }

        const Maybe <std::vector<std::string> > &GetAgeGroups() const
        {
            return mAgeGroups;
        }

        void SetAgeGroups(const std::vector<std::string> &ageGroups)
        {
            mAgeGroups = ageGroups;
        }

        const Maybe <std::vector<Entitlement> > &GetEntitlements() const
        {
            return mEntitlements;
        }

        void SetEntitlements(const std::vector<Entitlement> &entitlements)
        {
            mEntitlements = entitlements;
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

        const Maybe <std::vector<WmvFile> > &GetWmvFiles() const
        {
            return mWmvFiles;
        }

        void SetWmvFiles(const std::vector<WmvFile> &wmvFiles)
        {
            mWmvFiles = wmvFiles;
        }

        const Maybe <std::vector<SmoothManifest> > &GetSmoothManifests() const
        {
            return mSmoothManifests;
        }

        void SetSmoothManifests(const std::vector<SmoothManifest> &smoothManifests)
        {
            mSmoothManifests = smoothManifests;
        }

        const Maybe <std::vector<Mp4File> > &GetMp4Files() const
        {
            return mMp4Files;
        }

        void SetMp4Files(const std::vector<Mp4File> &mp4Files)
        {
            mMp4Files = mp4Files;
        }

        const Maybe <std::vector<HlsManifest> > &GetHlsManifests() const
        {
            return mHlsManifests;
        }

        void SetHlsManifests(const std::vector<HlsManifest> &hlsManifests)
        {
            mHlsManifests = hlsManifests;
        }

        const Maybe <std::vector<Subtitle> > &GetSubtitles() const
        {
            return mSubtitles;
        }

        void SetSubtitles(const std::vector<Subtitle> &subtitles)
        {
            mSubtitles = subtitles;
        }

        const Maybe <Link> &GetSelf() const
        {
            return mSelf;
        }

        void SetSelf(const Link &self)
        {
            mSelf = self;
        }

        const Maybe <Link> &GetFullPlay() const
        {
            return mFullPlay;
        }

        void SetFullPlay(const Link &fullPlay)
        {
            mFullPlay = fullPlay;
        }

        const Maybe <std::vector<PurchaseItem> > &GetPurchaseItems() const
        {
            return mPurchaseItems;
        }

        void SetPurchaseItems(const std::vector<PurchaseItem> &purchaseItems)
        {
            mPurchaseItems = purchaseItems;
        }

        const Maybe <Reviews> &GetReviews() const
        {
            return mReviews;
        }

        void SetReviews(const Reviews &reviews)
        {
            mReviews = reviews;
        }

        const Maybe <std::vector<Genre> > &GetGenres() const
        {
            return mGenres;
        }

        void SetGenres(const std::vector<Genre> &genres)
        {
            mGenres = genres;
        }

        virtual bool InitFromJsonValue(const rapidjson::Value &value)
        {
            return false;
        }

    private:
        Maybe <int> mProductId;
        Maybe <std::string> mTitleId;
        Maybe <Link> mTitleLink;
        Maybe <Link> mSimilar;
        Maybe <int> mMediaId;
        Maybe <std::string> mExternalId;
        Maybe <std::string> mOriginalTitle;
        Maybe <bool> mAdult;
        Maybe <int> mYear;
        Maybe <std::string> mProductionCountry;
        Maybe <int> mLength;
        Maybe <std::string> mLocalTitle;
        Maybe <std::string> mShortTitle;
        Maybe <std::string> mLongSummary;
        Maybe <std::string> mShortSummary;
        Maybe <std::string> mSortTitle;
        Maybe <std::string> mMainGenre;
        Maybe <int> mAgeLimit;
        Maybe <bool> mHD;
        Maybe <bool> mDubbed;
        Maybe <std::string> mPublishDate;
        Maybe <std::string> mUnPublishDate;
        Maybe <std::string> mModified;
        Maybe <std::vector<std::string> > mAgeGroups;
        Maybe <std::vector<Entitlement> > mEntitlements;
        Maybe <std::vector<Cast> > mCasts;
        Maybe <std::vector<Image> > mImages;
        Maybe <std::vector<WmvFile> > mWmvFiles;
        Maybe <std::vector<SmoothManifest> > mSmoothManifests;
        Maybe <std::vector<Mp4File> > mMp4Files;
        Maybe <std::vector<HlsManifest> > mHlsManifests;
        Maybe <std::vector<Subtitle> > mSubtitles;
        Maybe <Link> mSelf;
        Maybe <Link> mFullPlay;
        Maybe <std::vector<PurchaseItem> > mPurchaseItems;
        Maybe <Reviews> mReviews;
        Maybe <std::vector<Genre> > mGenres;

    protected:
        Maybe <ProductType> mProductType;
    };
}

#endif //READY4AIR_MEDIAPRODUCT_H
