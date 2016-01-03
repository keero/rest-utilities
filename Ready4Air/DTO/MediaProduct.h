#ifndef READY4AIR_MEDIAPRODUCT_H
#define READY4AIR_MEDIAPRODUCT_H

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

        int GetProductId() const
        {
            return mProductId;
        }

        void SetProductId(int productId)
        {
            mProductId = productId;
        }

        const ProductType &GetProductType() const
        {
            return mProductType;
        }

        void SetProductType(const ProductType &productType)
        {
            mProductType = productType;
        }

        const std::string &GetTitleId() const
        {
            return mTitleId;
        }

        void SetTitleId(const std::string &titleId)
        {
            mTitleId = titleId;
        }

        const Link &GetTitleLink() const
        {
            return mTitleLink;
        }

        void SetTitleLink(const Link &titleLink)
        {
            mTitleLink = titleLink;
        }

        const Link &GetSimilar() const
        {
            return mSimilar;
        }

        void SetSimilar(const Link &similar)
        {
            mSimilar = similar;
        }

        int GetMediaId() const
        {
            return mMediaId;
        }

        void SetMediaId(int mediaId)
        {
            mMediaId = mediaId;
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

        int GetYear() const
        {
            return mYear;
        }

        void SetYear(int year)
        {
            mYear = year;
        }

        const std::string &GetProductionCountry() const
        {
            return mProductionCountry;
        }

        void SetProductionCountry(const std::string &productionCountry)
        {
            mProductionCountry = productionCountry;
        }

        int GetLength() const
        {
            return mLength;
        }

        void SetLength(int length)
        {
            mLength = length;
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

        const std::string &GetMainGenre() const
        {
            return mMainGenre;
        }

        void SetMainGenre(const std::string &mainGenre)
        {
            mMainGenre = mainGenre;
        }

        int GetAgeLimit() const
        {
            return mAgeLimit;
        }

        void SetAgeLimit(int ageLimit)
        {
            mAgeLimit = ageLimit;
        }

        bool IsHD() const
        {
            return mHD;
        }

        void SetHD(bool HD)
        {
            mHD = HD;
        }

        bool IsDubbed() const
        {
            return mDubbed;
        }

        void SetDubbed(bool dubbed)
        {
            mDubbed = dubbed;
        }

        const std::string &GetPublishDate() const
        {
            return mPublishDate;
        }

        void SetPublishDate(const std::string &publishDate)
        {
            mPublishDate = publishDate;
        }

        const std::string &GetUnPublishDate() const
        {
            return mUnPublishDate;
        }

        void SetUnPublishDate(const std::string &unPublishDate)
        {
            mUnPublishDate = unPublishDate;
        }

        const std::string &GetModified() const
        {
            return mModified;
        }

        void SetModified(const std::string &modified)
        {
            mModified = modified;
        }

        const std::vector<std::string> &GetAgeGroups() const
        {
            return mAgeGroups;
        }

        void SetAgeGroups(const std::vector<std::string> &ageGroups)
        {
            mAgeGroups = ageGroups;
        }

        const std::vector<Entitlement> &GetEntitlements() const
        {
            return mEntitlements;
        }

        void SetEntitlements(const std::vector<Entitlement> &entitlements)
        {
            mEntitlements = entitlements;
        }

        const std::vector<Cast> &GetCasts() const
        {
            return mCasts;
        }

        void SetCasts(const std::vector<Cast> &casts)
        {
            mCasts = casts;
        }

        const std::vector<Image> &GetImages() const
        {
            return mImages;
        }

        void SetImages(const std::vector<Image> &images)
        {
            mImages = images;
        }

        const std::vector<WmvFile> &GetWmvFiles() const
        {
            return mWmvFiles;
        }

        void SetWmvFiles(const std::vector<WmvFile> &wmvFiles)
        {
            mWmvFiles = wmvFiles;
        }

        const std::vector<SmoothManifest> &GetSmoothManifests() const
        {
            return mSmoothManifests;
        }

        void SetSmoothManifests(const std::vector<SmoothManifest> &smoothManifests)
        {
            mSmoothManifests = smoothManifests;
        }

        const std::vector<Mp4File> &GetMp4Files() const
        {
            return mMp4Files;
        }

        void SetMp4Files(const std::vector<Mp4File> &mp4Files)
        {
            mMp4Files = mp4Files;
        }

        const std::vector<HlsManifest> &GetHlsManifests() const
        {
            return mHlsManifests;
        }

        void SetHlsManifests(const std::vector<HlsManifest> &hlsManifests)
        {
            mHlsManifests = hlsManifests;
        }

        const std::vector<Subtitle> &GetSubtitles() const
        {
            return mSubtitles;
        }

        void SetSubtitles(const std::vector<Subtitle> &subtitles)
        {
            mSubtitles = subtitles;
        }

        const Link &GetSelf() const
        {
            return mSelf;
        }

        void SetSelf(const Link &self)
        {
            mSelf = self;
        }

        const Link &GetFullPlay() const
        {
            return mFullPlay;
        }

        void SetFullPlay(const Link &fullPlay)
        {
            mFullPlay = fullPlay;
        }

        const std::vector<PurchaseItem> &GetPurchaseItems() const
        {
            return mPurchaseItems;
        }

        void SetPurchaseItems(const std::vector<PurchaseItem> &purchaseItems)
        {
            mPurchaseItems = purchaseItems;
        }

        const Reviews &GetReviews() const
        {
            return mReviews;
        }

        void SetReviews(const Reviews &reviews)
        {
            mReviews = reviews;
        }

        const std::vector<Genre> &GetGenres() const
        {
            return mGenres;
        }

        void SetGenres(const std::vector<Genre> &genres)
        {
            mGenres = genres;
        }

    private:
        int mProductId;
        std::string mTitleId;
        Link mTitleLink;
        Link mSimilar;
        int mMediaId;
        std::string mExternalId;
        std::string mOriginalTitle;
        bool mAdult;
        int mYear;
        std::string mProductionCountry;
        int mLength;
        std::string mLocalTitle;
        std::string mShortTitle;
        std::string mLongSummary;
        std::string mShortSummary;
        std::string mSortTitle;
        std::string mMainGenre;
        int mAgeLimit;
        bool mHD;
        bool mDubbed;
        std::string mPublishDate;
        std::string mUnPublishDate;
        std::string mModified;
        std::vector<std::string> mAgeGroups;
        std::vector<Entitlement> mEntitlements;
        std::vector<Cast> mCasts;
        std::vector<Image> mImages;
        std::vector<WmvFile> mWmvFiles;
        std::vector<SmoothManifest> mSmoothManifests;
        std::vector<Mp4File> mMp4Files;
        std::vector<HlsManifest> mHlsManifests;
        std::vector<Subtitle> mSubtitles;
        Link mSelf;
        Link mFullPlay;
        std::vector<PurchaseItem> mPurchaseItems;
        Reviews mReviews;
        std::vector<Genre> mGenres;

    protected:
        ProductType mProductType;
    };
}

#endif //READY4AIR_MEDIAPRODUCT_H
