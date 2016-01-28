#include "hypermedia.h"
#ifndef READY4AIR_BOOKMARK_H
#define READY4AIR_BOOKMARK_H
namespace ready4air
{
    namespace dto
    {
        class Bookmark : public JsonDeserializable
        {
        public:
            Bookmark()
            {
            }
            virtual ~Bookmark()
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
            const Maybe <STRING_T> &GetValue() const
            {
                return mValue;
            }
            void SetValue(const STRING_T &value)
            {
                mValue = value;
            }
            const Maybe <STRING_T> &GetCreated() const
            {
                return mCreated;
            }
            void SetCreated(const STRING_T &created)
            {
                mCreated = created;
            }
            const Maybe <STRING_T> &GetContentId() const
            {
                return mContentId;
            }
            void SetContentId(const STRING_T &contentId)
            {
                mContentId = contentId;
            }
            const Maybe <STRING_T> &GetDeviceId() const
            {
                return mDeviceId;
            }
            void SetDeviceId(const STRING_T &deviceId)
            {
                mDeviceId = deviceId;
            }
            const Maybe <STRING_T> &GetUserId() const
            {
                return mUserId;
            }
            void SetUserId(const STRING_T &userId)
            {
                mUserId = userId;
            }
            const Maybe <STRING_T> &GetModified() const
            {
                return mModified;
            }
            void SetModified(const STRING_T &modified)
            {
                mModified = modified;
            }
            virtual BOOL_T InitFromJsonValue(const rapidjson::Value &value, ParseErrors &parseErrors)
            {
                STRING_T id;
                STRING_T val;
                STRING_T created;
                STRING_T contentId;
                STRING_T deviceId;
                STRING_T userId;
                STRING_T modified;
                if (ParseString(value, "Id", true, id, parseErrors))
                    SetId(id);
                if (ParseString(value, "Value", true, val, parseErrors))
                    SetValue(val);
                if (ParseString(value, "Created", true, created, parseErrors))
                    SetCreated(created);
                if (ParseString(value, "ContentId", true, contentId, parseErrors))
                    SetContentId(contentId);
                if (ParseString(value, "DeviceId", false, deviceId, parseErrors))
                    SetDeviceId(deviceId);
                if (ParseString(value, "UserId", false, userId, parseErrors))
                    SetUserId(userId);
                if (ParseString(value, "Modified", false, modified, parseErrors))
                    SetModified(modified);
                return !parseErrors;
            }
        private:
            Maybe <STRING_T> mId;
            Maybe <STRING_T> mValue;
            Maybe <STRING_T> mCreated;
            Maybe <STRING_T> mContentId;
            Maybe <STRING_T> mDeviceId;
            Maybe <STRING_T> mUserId;
            Maybe <STRING_T> mModified;
        };
    }
}
#endif //READY4AIR_BOOKMARK_H

#ifndef READY4AIR_FILEBASE_H
#define READY4AIR_FILEBASE_H
namespace ready4air
{
    namespace dto
    {
        class FileBase : public JsonDeserializable
        {
        public:
            FileBase()
            {
            }
            virtual ~FileBase()
            {
            }
            const Maybe<int> &GetTypeId() const
            {
                return mTypeId;
            }
            void SetTypeId(int typeId)
            {
                mTypeId = typeId;
            }
            const Maybe<STRING_T> &GetTypeName() const
            {
                return mTypeName;
            }
            void SetTypeName(const STRING_T &typeName)
            {
                mTypeName = typeName;
            }
            const Maybe<Link> &GetLink() const
            {
                return mLink;
            }
            void SetLink(const Link &link)
            {
                mLink = link;
            }
            virtual BOOL_T InitFromJsonValue(const rapidjson::Value &value, ParseErrors &parseErrors)
            {
                INT32_T typeId;
                STRING_T typeName;
                Link link;
                if (ParseInt(value, "TypeId", true, typeId, parseErrors))
                    SetTypeId(typeId);
                if (ParseString(value, "TypeName", true, typeName, parseErrors))
                    SetTypeName(typeName);
                if (ParseObject(value, "Link", true, link, parseErrors))
                    SetLink(link);
                return !parseErrors;
            }
        private:
            Maybe<int> mTypeId;
            Maybe<STRING_T> mTypeName;
            Maybe<Link> mLink;
        };
    }
}
#endif //READY4AIR_FILEBASE_H

#ifndef READY4AIR_IMAGE_H
#define READY4AIR_IMAGE_H
namespace ready4air
{
    namespace dto
    {
        class Image : public FileBase
        {
        public:
            Image()
            {
            }
            virtual ~Image()
            {
            }
            const Maybe<Link> &GetSecureLink() const
            {
                return mSecureLink;
            }
            void SetSecureLink(const Link &secureLink)
            {
                mSecureLink = secureLink;
            }
            virtual BOOL_T InitFromJsonValue(const rapidjson::Value &value, ParseErrors &parseErrors)
            {
                Link secureLink;
                // Initialize parent properties
                FileBase::InitFromJsonValue(value, parseErrors);
                if (ParseObject(value, "SecureLink", false, secureLink, parseErrors))
                    SetSecureLink(secureLink);
                return !parseErrors;
            }
        private:
            Maybe<Link> mSecureLink;
        };
    }
}
#endif //READY4AIR_IMAGE_H

#ifndef READY4AIR_WMVFILE_H
#define READY4AIR_WMVFILE_H
namespace ready4air
{
    namespace dto
    {
        class WmvFile : public FileBase
        {
        public:
            WmvFile()
            {
            }
            virtual ~WmvFile()
            {
            }
            const Maybe<int> &GetLocation() const
            {
                return mLocation;
            }
            void SetLocation(int location)
            {
                mLocation = location;
            }
            const Maybe <Link> &GetMmsLink() const
            {
                return mMmsLink;
            }
            void SetMmsLink(const Link &mmsLink)
            {
                mMmsLink = mmsLink;
            }
            virtual BOOL_T InitFromJsonValue(const rapidjson::Value &value, ParseErrors &parseErrors)
            {
                INT32_T location;
                Link mmsLink;
                // Initialize parent properties
                FileBase::InitFromJsonValue(value, parseErrors);
                if (ParseInt(value, "Location", true, location, parseErrors))
                    SetLocation(location);
                if (ParseObject(value, "MmsLink", false, mmsLink, parseErrors))
                    SetMmsLink(mmsLink);
                return !parseErrors;
            }
        private:
            Maybe<int> mLocation;
            Maybe <Link> mMmsLink;
        };
    }
}
#endif //READY4AIR_WMVFILE_H

#ifndef READY4AIR_SMOOTHMANIFEST_H
#define READY4AIR_SMOOTHMANIFEST_H
namespace ready4air
{
    namespace dto
    {
        class SmoothManifest : public FileBase
        {
        public:
            SmoothManifest()
            {
            }
            virtual ~SmoothManifest()
            {
            }
            const Maybe<int> &GetManifestTypeId() const
            {
                return mManifestTypeId;
            }
            void SetManifestTypeId(int manifestTypeId)
            {
                mManifestTypeId = manifestTypeId;
            }
            const Maybe <STRING_T> &GetManifestTypeName() const
            {
                return mManifestTypeName;
            }
            void SetManifestTypeName(const STRING_T &manifestTypeName)
            {
                mManifestTypeName = manifestTypeName;
            }
            const Maybe<int> &GetLocation() const
            {
                return mLocation;
            }
            void SetLocation(int location)
            {
                mLocation = location;
            }
            virtual BOOL_T InitFromJsonValue(const rapidjson::Value &value, ParseErrors &parseErrors)
            {
                INT32_T manifestTypeId;
                STRING_T manifestTypeName;
                INT32_T location;
                // Initialize parent properties
                FileBase::InitFromJsonValue(value, parseErrors);
                if (ParseInt(value, "ManifestTypeId", true, manifestTypeId, parseErrors))
                    SetManifestTypeId(manifestTypeId);
                if (ParseString(value, "ManifestTypeName", true, manifestTypeName, parseErrors))
                    SetManifestTypeName(manifestTypeName);
                if (ParseInt(value, "Location", true, location, parseErrors))
                    SetLocation(location);
                return !parseErrors;
            }
        private:
            Maybe<int> mManifestTypeId;
            Maybe <STRING_T> mManifestTypeName;
            Maybe<int> mLocation;
        };
    }
}
#endif //READY4AIR_SMOOTHMANIFEST_H

#ifndef READY4AIR_BUNDLE_H
#define READY4AIR_BUNDLE_H
namespace ready4air
{
    namespace dto
    {
        class Bundle : public JsonDeserializable
        {
        public:
            Bundle()
            {
            }
            virtual ~Bundle()
            {
            }
            Maybe<STRING_T> GetId() const
            {
                return mId;
            }
            void SetId(const STRING_T &id)
            {
                mId = id;
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
            const Maybe<STRING_T> &GetOriginalSummary() const
            {
                return mOriginalSummary;
            }
            void SetOriginalSummary(const STRING_T &originalSummary)
            {
                mOriginalSummary = originalSummary;
            }
            const Maybe<STRING_T> &GetLocalTitle() const
            {
                return mLocalTitle;
            }
            void SetLocalTitle(const STRING_T &localTitle)
            {
                mLocalTitle = localTitle;
            }
            const Maybe<STRING_T> &GetLocalSummary() const
            {
                return mLocalSummary;
            }
            void SetLocalSummary(const STRING_T &localSummary)
            {
                mLocalSummary = localSummary;
            }
            const Maybe<VECTOR_T<Image> > &GetImages() const
            {
                return mImages;
            }
            void SetImages(const VECTOR_T<Image> &images)
            {
                mImages = images;
            }
            const Maybe<VECTOR_T<Link> > &GetMediaProductLinks() const
            {
                return mMediaProductLinks;
            }
            void SetMediaProductLinks(const VECTOR_T<Link> &mediaProductLinks)
            {
                mMediaProductLinks = mediaProductLinks;
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
            const Maybe<Link> &GetSelf() const
            {
                return mSelf;
            }
            void SetSelf(const Link &self)
            {
                mSelf = self;
            }
            virtual BOOL_T InitFromJsonValue(const rapidjson::Value &value, ParseErrors &parseErrors)
            {
                STRING_T id;
                STRING_T externalId;
                STRING_T originalTitle;
                STRING_T originalSummary;
                STRING_T localTitle;
                STRING_T localSummary;
                VECTOR_T<Image> images;
                VECTOR_T<Link> mediaProductLinks;
                VECTOR_T<WmvFile> wmvFiles;
                VECTOR_T<SmoothManifest> smoothManifests;
                Link self;
                if (ParseString(value, "Id", true, id, parseErrors))
                    SetId(id);
                if (ParseString(value, "ExternalId", true, externalId, parseErrors))
                    SetExternalId(externalId);
                if (ParseString(value, "OriginalTitle", false, originalTitle, parseErrors))
                    SetOriginalTitle(originalTitle);
                if (ParseString(value, "OriginalSummary", false, originalSummary, parseErrors))
                    SetOriginalSummary(originalSummary);
                if (ParseString(value, "LocalTitle", false, localTitle, parseErrors))
                    SetLocalTitle(localTitle);
                if (ParseString(value, "LocalSummary", false, localSummary, parseErrors))
                    SetLocalSummary(localSummary);
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
                if (VerifyArray(value, "MediaProductLinks", false, parseErrors))
                {
                    for (rapidjson::SizeType i = 0; i < value["MediaProductLinks"].Size(); i += 1)
                    {
                        Link mediaProductLink;
                        if (ParseObject(value["MediaProductLinks"][i], "", false, mediaProductLink, parseErrors))
                            mediaProductLinks.push_back(mediaProductLink);
                    }
                    SetMediaProductLinks(mediaProductLinks);
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
                if (ParseObject(value, "Self", false, self, parseErrors))
                    SetSelf(self);
                return !parseErrors;
            }
        private:
            Maybe<STRING_T> mId;
            Maybe<STRING_T> mExternalId;
            Maybe<STRING_T> mOriginalTitle;
            Maybe<STRING_T> mOriginalSummary;
            Maybe<STRING_T> mLocalTitle;
            Maybe<STRING_T> mLocalSummary;
            Maybe<VECTOR_T<Image> > mImages;
            Maybe<VECTOR_T<Link> > mMediaProductLinks;
            Maybe<VECTOR_T<WmvFile> > mWmvFiles;
            Maybe<VECTOR_T<SmoothManifest> > mSmoothManifests;
            Maybe<Link> mSelf;
        };
    }
}
#endif //READY4AIR_BUNDLE_H

#ifndef READY4AIR_BUTTON_H
#define READY4AIR_BUTTON_H
namespace ready4air
{
    namespace dto
    {
        class Button : public JsonDeserializable
        {
        public:
            Button()
            {
            }
            virtual ~Button()
            {
            }
            const Maybe<int> &GetAgeLimit() const
            {
                return mAgeLimit;
            }
            void SetAgeLimit(int ageLimit)
            {
                mAgeLimit = ageLimit;
            }
            const Maybe <STRING_T> &GetButtonImage() const
            {
                return mButtonImage;
            }
            void SetButtonImage(const STRING_T &buttonImage)
            {
                mButtonImage = buttonImage;
            }
            const Maybe<int> &GetPosition() const
            {
                return mPosition;
            }
            void SetPosition(int position)
            {
                mPosition = position;
            }
            const Maybe <STRING_T> &GetTitle() const
            {
                return mTitle;
            }
            void SetTitle(const STRING_T &title)
            {
                mTitle = title;
            }
            const Maybe <STRING_T> &GetType() const
            {
                return mType;
            }
            void SetType(const STRING_T &type)
            {
                mType = type;
            }
            const Maybe <Link> &GetLink() const
            {
                return mLink;
            }
            void SetLink(const Link &link)
            {
                mLink = link;
            }
            virtual BOOL_T InitFromJsonValue(const rapidjson::Value &value, ParseErrors &parseErrors)
            {
                INT32_T ageLimit;
                STRING_T buttonImage;
                INT32_T position;
                STRING_T title;
                STRING_T type;
                Link link;
                if (ParseInt(value, "AgeLimit", false, ageLimit, parseErrors))
                    SetAgeLimit(ageLimit);
                if (ParseString(value, "ButtonImage", false, buttonImage, parseErrors))
                    SetButtonImage(buttonImage);
                if (ParseInt(value, "Position", true, position, parseErrors))
                    SetPosition(position);
                if (ParseString(value, "Title", true, title, parseErrors))
                    SetTitle(title);
                if (ParseString(value, "Type", true, type, parseErrors))
                    SetType(type);
                if (ParseObject(value, "Link", true, link, parseErrors))
                    SetLink(link);
                return !parseErrors;
            }
        private:
            Maybe<int> mAgeLimit;
            Maybe <STRING_T> mButtonImage;
            Maybe<int> mPosition;
            Maybe <STRING_T> mTitle;
            Maybe <STRING_T> mType;
            Maybe <Link> mLink;
        };
    }
}
#endif //READY4AIR_BUTTON_H

#ifndef READY4AIR_CAST_H
#define READY4AIR_CAST_H
namespace ready4air
{
    namespace dto
    {
        class Cast : public JsonDeserializable
        {
        public:
            Cast()
            {
            }
            virtual ~Cast()
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
            const Maybe<INT16_T> &GetCategoryId() const
            {
                return mCategoryId;
            }
            void SetCategoryId(INT16_T categoryId)
            {
                mCategoryId = categoryId;
            }
            const Maybe <STRING_T> &GetCategoryName() const
            {
                return mCategoryName;
            }
            void SetCategoryName(const STRING_T &categoryName)
            {
                mCategoryName = categoryName;
            }
            const Maybe <STRING_T> &GetFirstName() const
            {
                return mFirstName;
            }
            void SetFirstName(const STRING_T &firstName)
            {
                mFirstName = firstName;
            }
            const Maybe <STRING_T> &GetLastName() const
            {
                return mLastName;
            }
            void SetLastName(const STRING_T &lastName)
            {
                mLastName = lastName;
            }
            const Maybe <STRING_T> &GetMiddleName() const
            {
                return mMiddleName;
            }
            void SetMiddleName(const STRING_T &middleName)
            {
                mMiddleName = middleName;
            }
            const Maybe <STRING_T> &GetFullName() const
            {
                return mFullName;
            }
            void SetFullName(const STRING_T &fullName)
            {
                mFullName = fullName;
            }
            virtual BOOL_T InitFromJsonValue(const rapidjson::Value &value, ParseErrors &parseErrors)
            {
                STRING_T id;
                INT32_T categoryId;
                STRING_T categoryName;
                STRING_T firstName;
                STRING_T lastName;
                STRING_T middleName;
                STRING_T fullName;
                if (ParseString(value, "Id", true, id, parseErrors))
                    SetId(id);
                if (ParseInt(value, "CategoryId", true, categoryId, parseErrors))
                    SetCategoryId((INT16_T) categoryId);
                if (ParseString(value, "CategoryName", true, categoryName, parseErrors))
                    SetCategoryName(categoryName);
                if (ParseString(value, "FirstName", false, firstName, parseErrors))
                    SetFirstName(firstName);
                if (ParseString(value, "LastName", false, lastName, parseErrors))
                    SetLastName(lastName);
                if (ParseString(value, "MiddleName", false, middleName, parseErrors))
                    SetMiddleName(middleName);
                if (ParseString(value, "FullName", true, fullName, parseErrors))
                    SetFullName(fullName);
                return !parseErrors;
            }
        private:
            Maybe <STRING_T> mId;
            Maybe<INT16_T> mCategoryId;
            Maybe <STRING_T> mCategoryName;
            Maybe <STRING_T> mFirstName;
            Maybe <STRING_T> mLastName;
            Maybe <STRING_T> mMiddleName;
            Maybe <STRING_T> mFullName;
        };
    }
}
#endif //READY4AIR_CAST_H

#ifndef READY4AIR_CATALOGUE_H
#define READY4AIR_CATALOGUE_H
namespace ready4air
{
    namespace dto
    {
        class Catalogue : public JsonDeserializable
        {
        public:
            Catalogue()
            {
            }
            virtual ~Catalogue()
            {
            }
            const Maybe <Link> &GetAllMovies() const
            {
                return mAllMovies;
            }
            void SetAllMovies(const Link &allMovies)
            {
                mAllMovies = allMovies;
            }
            const Maybe <Link> &GetAllSeries() const
            {
                return mAllSeries;
            }
            void SetAllSeries(const Link &allSeries)
            {
                mAllSeries = allSeries;
            }
            const Maybe <Link> &GetAllBundles() const
            {
                return mAllBundles;
            }
            void SetAllBundles(const Link &allBundles)
            {
                mAllBundles = allBundles;
            }
            virtual BOOL_T InitFromJsonValue(const rapidjson::Value &value, ParseErrors &parseErrors)
            {
                Link allMovies;
                Link allSeries;
                Link allBundles;
                if (ParseObject(value, "AllMovies", true, allMovies, parseErrors))
                    SetAllMovies(allMovies);
                if (ParseObject(value, "AllSeries", true, allSeries, parseErrors))
                    SetAllSeries(allSeries);
                if (ParseObject(value, "AllBundles", true, allBundles, parseErrors))
                    SetAllBundles(allBundles);
                return !parseErrors;
            }
        private:
            Maybe <Link> mAllMovies;
            Maybe <Link> mAllSeries;
            Maybe <Link> mAllBundles;
        };
    }
}
#endif //READY4AIR_CATALOGUE_H

#ifndef READY4AIR_MENUITEM_H
#define READY4AIR_MENUITEM_H
namespace ready4air
{
    namespace dto
    {
        class MenuItem : public JsonDeserializable
        {
        public:
            MenuItem()
            {
            }
            virtual ~MenuItem()
            {
            }
            const Maybe <STRING_T> &GetText() const
            {
                return mText;
            }
            void SetText(const STRING_T &text)
            {
                mText = text;
            }
            const Maybe <Link> &GetLink() const
            {
                return mLink;
            }
            void SetLink(const Link &link)
            {
                mLink = link;
            }
            const Maybe <VECTOR_T<MenuItem> > &GetMenuItems() const
            {
                return mMenuItems;
            }
            void SetMenuItems(const VECTOR_T<MenuItem> &menuItems)
            {
                mMenuItems = menuItems;
            }
            virtual BOOL_T InitFromJsonValue(const rapidjson::Value &value, ParseErrors &parseErrors)
            {
                STRING_T text;
                Link link;
                VECTOR_T<MenuItem> menuItems;
                if (ParseString(value, "Text", true, text, parseErrors))
                    SetText(text);
                if (ParseObject(value, "Link", false, link, parseErrors))
                    SetLink(link);
                if (VerifyArray(value, "MenuItems", false, parseErrors))
                {
                    for (rapidjson::SizeType i = 0; i < value["MenuItems"].Size(); i += 1)
                    {
                        MenuItem menuItem;
                        if (ParseObject(value["MenuItems"][i], "", false, menuItem, parseErrors))
                            menuItems.push_back(menuItem);
                    }
                    SetMenuItems(menuItems);
                }
                return !parseErrors;
            }
        private:
            Maybe <STRING_T> mText;
            Maybe <Link> mLink;
            Maybe <VECTOR_T<MenuItem> > mMenuItems;
        };
    }
}
#endif //READY4AIR_MENUITEM_H

#ifndef READY4AIR_DRM_H
#define READY4AIR_DRM_H
namespace ready4air
{
    namespace dto
    {
        class DRM : public JsonDeserializable
        {
        public:
            DRM()
            {
            }
            virtual ~DRM()
            {
            }
            const Maybe <Link> &GetCookie() const
            {
                return mCookie;
            }
            void SetCookie(const Link &cookie)
            {
                mCookie = cookie;
            }
            const Maybe <STRING_T> &GetCustomData() const
            {
                return mCustomData;
            }
            void SetCustomData(const STRING_T &customData)
            {
                mCustomData = customData;
            }
            const Maybe <STRING_T> &GetCustomerToken() const
            {
                return mCustomerToken;
            }
            void SetCustomerToken(const STRING_T &customerToken)
            {
                mCustomerToken = customerToken;
            }
            const Maybe <STRING_T> &GetDeviceToken() const
            {
                return mDeviceToken;
            }
            void SetDeviceToken(const STRING_T &deviceToken)
            {
                mDeviceToken = deviceToken;
            }
            const Maybe <STRING_T> &GetContentId() const
            {
                return mContentId;
            }
            void SetContentId(const STRING_T &contentId)
            {
                mContentId = contentId;
            }
            virtual BOOL_T InitFromJsonValue(const rapidjson::Value &value, ParseErrors &parseErrors)
            {
                Link cookie;
                STRING_T customData;
                STRING_T customerToken;
                STRING_T deviceToken;
                STRING_T contentId;
                if (ParseObject(value, "Cookie", true, cookie, parseErrors))
                    SetCookie(cookie);
                if (ParseString(value, "CustomData", true, customData, parseErrors))
                    SetCustomData(customData);
                if (ParseString(value, "CustomerToken", true, customerToken, parseErrors))
                    SetCustomerToken(customerToken);
                if (ParseString(value, "DeviceToken", true, deviceToken, parseErrors))
                    SetDeviceToken(deviceToken);
                if (ParseString(value, "ContentId", true, contentId, parseErrors))
                    SetContentId(contentId);
                return !parseErrors;
            }
        private:
            Maybe <Link> mCookie;
            Maybe <STRING_T> mCustomData;
            Maybe <STRING_T> mCustomerToken;
            Maybe <STRING_T> mDeviceToken;
            Maybe <STRING_T> mContentId;
        };
    }
}
#endif //READY4AIR_DRM_H

#ifndef READY4AIR_ENTITLEMENT_H
#define READY4AIR_ENTITLEMENT_H
namespace ready4air
{
    namespace dto
    {
        class Entitlement : public JsonDeserializable
        {
        public:
            Entitlement()
            {
            }
            virtual ~Entitlement()
            {
            }
            const Maybe<STRING_T> &GetType() const
            {
                return mType;
            }
            void SetType(const STRING_T &type)
            {
                mType = type;
            }
            const Maybe<STRING_T> &GetEntitledTo() const
            {
                return mEntitledTo;
            }
            void SetEntitledTo(const STRING_T &entitledTo)
            {
                mEntitledTo = entitledTo;
            }
            const Maybe<STRING_T> &GetStartTime() const
            {
                return mStartTime;
            }
            void SetStartTime(const STRING_T &startTime)
            {
                mStartTime = startTime;
            }
            const Maybe<STRING_T> &GetEndTime() const
            {
                return mEndTime;
            }
            void SetEndTime(const STRING_T &endTime)
            {
                mEndTime = endTime;
            }
            const Maybe<DRM> &GetDRM() const
            {
                return mDRM;
            }
            void SetDRM(const DRM &DRM)
            {
                mDRM = DRM;
            }
            const Maybe<STRING_T> &GetIdentifier() const
            {
                return mIdentifier;
            }
            void SetIdentifier(const STRING_T &identifier)
            {
                mIdentifier = identifier;
            }
            virtual BOOL_T InitFromJsonValue(const rapidjson::Value &value, ParseErrors &parseErrors)
            {
                STRING_T type;
                STRING_T entitledTo;
                STRING_T startTime;
                STRING_T endTime;
                DRM drm;
                STRING_T identifier;
                if (ParseString(value, "Type", true, type, parseErrors))
                    SetType(type);
                if (ParseString(value, "EntitledTo", true, entitledTo, parseErrors))
                    SetEntitledTo(entitledTo);
                if (ParseString(value, "StartTime", false, startTime, parseErrors))
                    SetStartTime(startTime);
                if (ParseString(value, "EndTime", false, endTime, parseErrors))
                    SetEndTime(endTime);
                if (ParseObject(value, "DRM", false, drm, parseErrors))
                    SetDRM(drm);
                if (ParseString(value, "Identifier", false, identifier, parseErrors))
                    SetIdentifier(identifier);
                return !parseErrors;
            }
        private:
            Maybe<STRING_T> mType;
            Maybe<STRING_T> mEntitledTo;
            Maybe<STRING_T> mStartTime;
            Maybe<STRING_T> mEndTime;
            Maybe<DRM> mDRM;
            Maybe<STRING_T> mIdentifier;
        };
    }
}
#endif //READY4AIR_ENTITLEMENT_H

#ifndef READY4AIR_MP4FILE_H
#define READY4AIR_MP4FILE_H
namespace ready4air
{
    namespace dto
    {
        class Mp4File : public FileBase
        {
        public:
            Mp4File()
            {
            }
            virtual ~Mp4File()
            {
            }
            const Maybe<int> &GetLocation() const
            {
                return mLocation;
            }
            void SetLocation(int location)
            {
                mLocation = location;
            }
            const Maybe <Link> &GetMmsLink() const
            {
                return mMmsLink;
            }
            void SetMmsLink(const Link &mmsLink)
            {
                mMmsLink = mmsLink;
            }
            const Maybe <STRING_T> &GetLanguage() const
            {
                return mLanguage;
            }
            void SetLanguage(const STRING_T &language)
            {
                mLanguage = language;
            }
            const Maybe<INT16_T> &GetBandwidth() const
            {
                return mBandwidth;
            }
            void SetBandwidth(INT16_T bandwidth)
            {
                mBandwidth = bandwidth;
            }
            virtual BOOL_T InitFromJsonValue(const rapidjson::Value &value, ParseErrors &parseErrors)
            {
                INT32_T location;
                Link mmsLink;
                STRING_T language;
                INT32_T bandwidth;
                // Initialize parent properties
                FileBase::InitFromJsonValue(value, parseErrors);
                if (ParseInt(value, "Location", true, location, parseErrors))
                    SetLocation(location);
                if (ParseObject(value, "MmsLink", false, mmsLink, parseErrors))
                    SetMmsLink(mmsLink);
                if (ParseString(value, "Language", false, language, parseErrors))
                    SetLanguage(language);
                if (ParseInt(value, "Bandwidth", true, bandwidth, parseErrors))
                    SetBandwidth((INT16_T) bandwidth);
                return !parseErrors;
            }
        private:
            Maybe<int> mLocation;
            Maybe <Link> mMmsLink;
            Maybe <STRING_T> mLanguage;
            Maybe<INT16_T> mBandwidth;
        };
    }
}
#endif //READY4AIR_MP4FILE_H

#ifndef READY4AIR_HLSMANIFEST_H
#define READY4AIR_HLSMANIFEST_H
namespace ready4air
{
    namespace dto
    {
        class HlsManifest : public FileBase
        {
        public:
            HlsManifest()
            {
            }
            const Maybe <STRING_T> &GetLanguage() const
            {
                return mLanguage;
            }
            void SetLanguage(const STRING_T &language)
            {
                mLanguage = language;
            }
            const Maybe<INT16_T> &GetBandwidth() const
            {
                return mBandwidth;
            }
            void SetBandwidth(INT16_T bandwidth)
            {
                mBandwidth = bandwidth;
            }
            const Maybe<int> &GetManifestTypeId() const
            {
                return mManifestTypeId;
            }
            void SetManifestTypeId(int manifestTypeId)
            {
                mManifestTypeId = manifestTypeId;
            }
            const Maybe <STRING_T> &GetManifestTypeName() const
            {
                return mManifestTypeName;
            }
            void SetManifestTypeName(const STRING_T &manifestTypeName)
            {
                mManifestTypeName = manifestTypeName;
            }
            const Maybe<int> &GetLocation() const
            {
                return mLocation;
            }
            void SetLocation(int location)
            {
                mLocation = location;
            }
            const Maybe <Link> &GetMmsLink() const
            {
                return mMmsLink;
            }
            void SetMmsLink(const Link &mmsLink)
            {
                mMmsLink = mmsLink;
            }
            virtual BOOL_T InitFromJsonValue(const rapidjson::Value &value, ParseErrors &parseErrors)
            {
                STRING_T language;
                INT32_T bandwidth;
                INT32_T manifestTypeId;
                STRING_T manifestTypeName;
                INT32_T location;
                Link mmsLink;
                // Initialize parent properties
                FileBase::InitFromJsonValue(value, parseErrors);
                if (ParseString(value, "Language", false, language, parseErrors))
                    SetLanguage(language);
                if (ParseInt(value, "Bandwidth", true, bandwidth, parseErrors))
                    SetBandwidth((INT16_T) bandwidth);
                if (ParseInt(value, "ManifestTypeId", false, manifestTypeId, parseErrors))
                    SetManifestTypeId(manifestTypeId);
                if (ParseString(value, "ManifestTypeName", false, manifestTypeName, parseErrors))
                    SetManifestTypeName(manifestTypeName);
                if (ParseInt(value, "Location", true, location, parseErrors))
                    SetLocation(location);
                if (ParseObject(value, "MmsLink", false, mmsLink, parseErrors))
                    SetMmsLink(mmsLink);
                return !parseErrors;
            }
        private:
            Maybe <STRING_T> mLanguage;
            Maybe<INT16_T> mBandwidth;
            Maybe<int> mManifestTypeId;
            Maybe <STRING_T> mManifestTypeName;
            Maybe<int> mLocation;
            Maybe <Link> mMmsLink;
        };
    }
}
#endif //READY4AIR_HLSMANIFEST_H

#ifndef READY4AIR_SUBTITLE_H
#define READY4AIR_SUBTITLE_H
namespace ready4air
{
    namespace dto
    {
        class Subtitle : public JsonDeserializable
        {
        public:
            Subtitle()
            {
            }
            virtual ~Subtitle()
            {
            }
            const Maybe <STRING_T> &GetType() const
            {
                return mType;
            }
            void SetType(const STRING_T &type)
            {
                mType = type;
            }
            const Maybe <STRING_T> &GetEncoding() const
            {
                return mEncoding;
            }
            void SetEncoding(const STRING_T &encoding)
            {
                mEncoding = encoding;
            }
            const Maybe <STRING_T> &GetLanguage() const
            {
                return mLanguage;
            }
            void SetLanguage(const STRING_T &language)
            {
                mLanguage = language;
            }
            const Maybe <Link> &GetLink() const
            {
                return mLink;
            }
            void SetLink(const Link &link)
            {
                mLink = link;
            }
            virtual BOOL_T InitFromJsonValue(const rapidjson::Value &value, ParseErrors &parseErrors)
            {
                STRING_T type;
                STRING_T encoding;
                STRING_T language;
                Link link;
                if (ParseString(value, "Type", true, type, parseErrors))
                    SetType(type);
                if (ParseString(value, "Encoding", true, encoding, parseErrors))
                    SetEncoding(encoding);
                if (ParseString(value, "Language", true, language, parseErrors))
                    SetLanguage(language);
                if (ParseObject(value, "Link", false, link, parseErrors))
                    SetLink(link);
                return !parseErrors;
            }
        private:
            Maybe <STRING_T> mType;
            Maybe <STRING_T> mEncoding;
            Maybe <STRING_T> mLanguage;
            Maybe <Link> mLink;
        };
    }
}
#endif //READY4AIR_SUBTITLE_H

#ifndef READY4AIR_PURCHASEITEM_H
#define READY4AIR_PURCHASEITEM_H
namespace ready4air
{
    namespace dto
    {
        class PurchaseItem : public JsonDeserializable
        {
        public:
            PurchaseItem()
            {
            }
            virtual ~PurchaseItem()
            {
            }
            const Maybe <STRING_T> &GetBusinessType() const
            {
                return mBusinessType;
            }
            void SetBusinessType(const STRING_T &businessType)
            {
                mBusinessType = businessType;
            }
            const Maybe<DOUBLE_T> &GetPrice() const
            {
                return mPrice;
            }
            void SetPrice(DOUBLE_T price)
            {
                mPrice = price;
            }
            const Maybe <STRING_T> &GetCurrency() const
            {
                return mCurrency;
            }
            void SetCurrency(const STRING_T &currency)
            {
                mCurrency = currency;
            }
            const Maybe <STRING_T> &GetStrPrice() const
            {
                return mStrPrice;
            }
            void SetStrPrice(const STRING_T &strPrice)
            {
                mStrPrice = strPrice;
            }
            const Maybe <Form> &GetForm() const
            {
                return mForm;
            }
            void SetForm(const Form &form)
            {
                mForm = form;
            }
            virtual BOOL_T InitFromJsonValue(const rapidjson::Value &value, ParseErrors &parseErrors)
            {
                STRING_T businessType;
                DOUBLE_T price;
                STRING_T currency;
                STRING_T strPrice;
                Form form;
                if (ParseString(value, "BusinessType", true, businessType, parseErrors))
                    SetBusinessType(businessType);
                if (ParseDouble(value, "Price", false, price, parseErrors))
                    SetPrice(price);
                if (ParseString(value, "Currency", false, currency, parseErrors))
                    SetCurrency(currency);
                if (ParseString(value, "StrPrice", false, strPrice, parseErrors))
                    SetStrPrice(strPrice);
                if (ParseObject(value, "Form", false, form, parseErrors))
                    SetForm(form);
                return !parseErrors;
            }
        private:
            Maybe <STRING_T> mBusinessType;
            Maybe<DOUBLE_T> mPrice;
            Maybe <STRING_T> mCurrency;
            Maybe <STRING_T> mStrPrice;
            Maybe <Form> mForm;
        };
    }
}
#endif //READY4AIR_PURCHASEITEM_H

#ifndef READY4AIR_QUOTEIMAGE_H
#define READY4AIR_QUOTEIMAGE_H
namespace ready4air
{
    namespace dto
    {
        class QuoteImage : public JsonDeserializable
        {
        public:
            QuoteImage()
            {
            }
            virtual ~QuoteImage()
            {
            }
            const Maybe<int> &GetWidth() const
            {
                return mWidth;
            }
            void SetWidth(int width)
            {
                mWidth = width;
            }
            const Maybe<int> &GetHeight() const
            {
                return mHeight;
            }
            void SetHeight(int height)
            {
                mHeight = height;
            }
            const Maybe <Link> &GetLink() const
            {
                return mLink;
            }
            void SetLink(const Link &link)
            {
                mLink = link;
            }
            virtual BOOL_T InitFromJsonValue(const rapidjson::Value &value, ParseErrors &parseErrors)
            {
                INT32_T width;
                INT32_T height;
                Link link;
                if (ParseInt(value, "Width", true, width, parseErrors))
                    SetWidth(width);
                if (ParseInt(value, "Height", true, height, parseErrors))
                    SetHeight(height);
                if (ParseObject(value, "Link", false, link, parseErrors))
                    SetLink(link);
                return !parseErrors;
            }
        private:
            Maybe<int> mWidth;
            Maybe<int> mHeight;
            Maybe <Link> mLink;
        };
    }
}
#endif //READY4AIR_QUOTEIMAGE_H

#ifndef READY4AIR_QUOTEIMAGES_H
#define READY4AIR_QUOTEIMAGES_H
namespace ready4air
{
    namespace dto
    {
        class QuoteImages : public JsonDeserializable
        {
        public:
            QuoteImages()
            {
            }
            virtual ~QuoteImages()
            {
            }
            const Maybe<QuoteImage> &GetSmallLogo() const
            {
                return mSmallLogo;
            }
            void SetSmallLogo(const QuoteImage &smallLogo)
            {
                mSmallLogo = smallLogo;
            }
            const Maybe<QuoteImage> &GetLargeLogo() const
            {
                return mLargeLogo;
            }
            void SetLargeLogo(const QuoteImage &largeLogo)
            {
                mLargeLogo = largeLogo;
            }
            const Maybe<QuoteImage> &GetScore() const
            {
                return mScore;
            }
            void SetScore(const QuoteImage &score)
            {
                mScore = score;
            }
            virtual BOOL_T InitFromJsonValue(const rapidjson::Value &value, ParseErrors &parseErrors)
            {
                QuoteImage smallLogo;
                QuoteImage largeLogo;
                QuoteImage score;
                if (ParseObject(value, "SmallLogo", false, smallLogo, parseErrors))
                    SetSmallLogo(smallLogo);
                if (ParseObject(value, "LargeLogo", false, largeLogo, parseErrors))
                    SetLargeLogo(largeLogo);
                if (ParseObject(value, "Score", false, score, parseErrors))
                    SetScore(score);
                return !parseErrors;
            }
        private:
            Maybe<QuoteImage> mSmallLogo;
            Maybe<QuoteImage> mLargeLogo;
            Maybe<QuoteImage> mScore;
        };
    }
}
#endif //READY4AIR_QUOTEIMAGES_H

#ifndef READY4AIR_CRITICSQUOTE_H
#define READY4AIR_CRITICSQUOTE_H
namespace ready4air
{
    namespace dto
    {
        class CriticsQuote : public JsonDeserializable
        {
        public:
            CriticsQuote()
            {
            }
            virtual ~CriticsQuote()
            {
            }
            const Maybe<STRING_T> &GetText() const
            {
                return mText;
            }
            void SetText(const STRING_T &text)
            {
                mText = text;
            }
            const Maybe<STRING_T> &GetSource() const
            {
                return mSource;
            }
            void SetSource(const STRING_T &source)
            {
                mSource = source;
            }
            const Maybe<STRING_T> &GetScore() const
            {
                return mScore;
            }
            void SetScore(const STRING_T &score)
            {
                mScore = score;
            }
            const Maybe<Link> &GetLink() const
            {
                return mLink;
            }
            void SetLink(const Link &link)
            {
                mLink = link;
            }
            const Maybe<QuoteImages> &GetImages() const
            {
                return mImages;
            }
            void SetImages(const QuoteImages &images)
            {
                mImages = images;
            }
            virtual BOOL_T InitFromJsonValue(const rapidjson::Value &value, ParseErrors &parseErrors)
            {
                STRING_T text;
                STRING_T source;
                STRING_T score;
                Link link;
                QuoteImages images;
                if (ParseString(value, "Text", false, text, parseErrors))
                    SetText(text);
                if (ParseString(value, "Source", false, source, parseErrors))
                    SetSource(source);
                if (ParseString(value, "Score", false, score, parseErrors))
                    SetScore(score);
                if (ParseObject(value, "Link", false, link, parseErrors))
                    SetLink(link);
                if (ParseObject(value, "Images", false, images, parseErrors))
                    SetImages(images);
                return !parseErrors;
            }
        private:
            Maybe<STRING_T> mText;
            Maybe<STRING_T> mSource;
            Maybe<STRING_T> mScore;
            Maybe<Link> mLink;
            Maybe<QuoteImages> mImages;
        };
    }
}
#endif //READY4AIR_CRITICSQUOTE_H

#ifndef READY4AIR_USERRATING_H
#define READY4AIR_USERRATING_H
namespace ready4air
{
    namespace dto
    {
        class UserRating : public JsonDeserializable
        {
        public:
            UserRating()
            {
            }
            virtual ~UserRating()
            {
            }
            const Maybe<int> &GetNumberOfVotes() const
            {
                return mNumberOfVotes;
            }
            void SetNumberOfVotes(int numberOfVotes)
            {
                mNumberOfVotes = numberOfVotes;
            }
            const Maybe<int> &GetValue() const
            {
                return mValue;
            }
            void SetValue(int value)
            {
                mValue = value;
            }
            const Maybe<DOUBLE_T> &GetAverageValue() const
            {
                return mAverageValue;
            }
            void SetAverageValue(DOUBLE_T averageValue)
            {
                mAverageValue = averageValue;
            }
            virtual BOOL_T InitFromJsonValue(const rapidjson::Value &value, ParseErrors &parseErrors)
            {
                INT32_T numberOfVotes;
                INT32_T val;
                DOUBLE_T averageValue;
                if (ParseInt(value, "NumberOfVotes", true, numberOfVotes, parseErrors))
                    SetNumberOfVotes(numberOfVotes);
                if (ParseInt(value, "Value", true, val, parseErrors))
                    SetValue(val);
                if (ParseDouble(value, "AverageValue", true, averageValue, parseErrors))
                    SetAverageValue(averageValue);
                return !parseErrors;
            }
        private:
            Maybe<int> mNumberOfVotes;
            Maybe<int> mValue;
            Maybe<DOUBLE_T> mAverageValue;
        };
    }
}
#endif //READY4AIR_USERRATING_H

#ifndef READY4AIR_REVIEWS_H
#define READY4AIR_REVIEWS_H
namespace ready4air
{
    namespace dto
    {
        class Reviews : public JsonDeserializable
        {
        public:
            Reviews()
            {
            }
            virtual ~Reviews()
            {
            }
            const Maybe<UserRating> &GetUserRating() const
            {
                return mUserRating;
            }
            void SetUserRating(const UserRating &userRating)
            {
                mUserRating = userRating;
            }
            const Maybe<STRING_T> &GetFormattedAverageCriticsScore() const
            {
                return mFormattedAverageCriticsScore;
            }
            void SetFormattedAverageCriticsScore(const STRING_T &formattedAverageCriticsScore)
            {
                mFormattedAverageCriticsScore = formattedAverageCriticsScore;
            }
            const Maybe<VECTOR_T<CriticsQuote> > &GetCriticsQuotes() const
            {
                return mCriticsQuotes;
            }
            void SetCriticsQuotes(const VECTOR_T<CriticsQuote> &criticsQuotes)
            {
                mCriticsQuotes = criticsQuotes;
            }
            virtual BOOL_T InitFromJsonValue(const rapidjson::Value &value, ParseErrors &parseErrors)
            {
                UserRating userRating;
                STRING_T formattedAverageCriticsScore;
                VECTOR_T<CriticsQuote> criticsQuotes;
                if (ParseObject(value, "UserRating", false, userRating, parseErrors))
                    SetUserRating(userRating);
                if (ParseString(value, "FormattedAverageCriticsScore", false, formattedAverageCriticsScore,
                                parseErrors))
                    SetFormattedAverageCriticsScore(formattedAverageCriticsScore);
                if (VerifyArray(value, "CriticsQuotes", false, parseErrors))
                {
                    for (rapidjson::SizeType i = 0; i < value["CriticsQuotes"].Size(); i += 1)
                    {
                        CriticsQuote criticsQuote;
                        if (ParseObject(value["CriticsQuotes"][i], "", false, criticsQuote, parseErrors))
                            criticsQuotes.push_back(criticsQuote);
                    }
                    SetCriticsQuotes(criticsQuotes);
                }
                return !parseErrors;
            }
        private:
            Maybe<UserRating> mUserRating;
            Maybe<STRING_T> mFormattedAverageCriticsScore;
            Maybe<VECTOR_T<CriticsQuote> > mCriticsQuotes;
        };
    }
}
#endif //READY4AIR_REVIEWS_H

#ifndef READY4AIR_GENRE_H
#define READY4AIR_GENRE_H
namespace ready4air
{
    namespace dto
    {
        class Genre : public JsonDeserializable
        {
        public:
            Genre()
            {
            }
            virtual ~Genre()
            {
            }
            const Maybe <STRING_T> &GetName() const
            {
                return mName;
            }
            void SetName(const STRING_T &name)
            {
                mName = name;
            }
            const Maybe <Link> &GetLink() const
            {
                return mLink;
            }
            void SetLink(const Link &link)
            {
                mLink = link;
            }
            const Maybe<BOOL_T> &IsMain() const
            {
                return mIsMain;
            }
            void SetIsMain(BOOL_T isMain)
            {
                mIsMain = isMain;
            }
            const Maybe<int> &GetListId() const
            {
                return mListId;
            }
            void SetListId(int listId)
            {
                mListId = listId;
            }
            virtual BOOL_T InitFromJsonValue(const rapidjson::Value &value, ParseErrors &parseErrors)
            {
                STRING_T name;
                Link link;
                BOOL_T isMain;
                INT32_T listId;
                if (ParseString(value, "Name", false, name, parseErrors))
                    SetName(name);
                if (ParseObject(value, "Link", false, link, parseErrors))
                    SetLink(link);
                if (ParseBool(value, "IsMain", true, isMain, parseErrors))
                    SetIsMain(isMain);
                if (ParseInt(value, "ListId", true, listId, parseErrors))
                    SetListId(listId);
                return !parseErrors;
            }
        private:
            Maybe <STRING_T> mName;
            Maybe <Link> mLink;
            Maybe<BOOL_T> mIsMain;
            Maybe<int> mListId;
        };
    }
}
#endif //READY4AIR_GENRE_H

#ifndef READY4AIR_PROTECTIONDATA_H
#define READY4AIR_PROTECTIONDATA_H
namespace ready4air
{
    namespace dto
    {
        class ProtectionData : public JsonDeserializable
        {
        public:
            ProtectionData()
            {
            }
            virtual ~ProtectionData()
            {
            }
            const Maybe<STRING_T> &GetKeyId() const
            {
                return mKeyId;
            }
            void SetKeyId(const STRING_T &keyId)
            {
                mKeyId = keyId;
            }
            const Maybe<Link> &GetPlayReadyLicenser() const
            {
                return mPlayReadyLicenser;
            }
            void SetPlayReadyLicenser(const Link &playReadyLicenser)
            {
                mPlayReadyLicenser = playReadyLicenser;
            }
            const Maybe<Link> &GetWidevineLicenser() const
            {
                return mWidevineLicenser;
            }
            void SetWidevineLicenser(const Link &widevineLicenser)
            {
                mWidevineLicenser = widevineLicenser;
            }
            const Maybe<STRING_T> &GetWidevinePSSH() const
            {
                return mWidevinePSSH;
            }
            void SetWidevinePSSH(const STRING_T &widevinePSSH)
            {
                mWidevinePSSH = widevinePSSH;
            }
            virtual BOOL_T InitFromJsonValue(const rapidjson::Value &value, ParseErrors &parseErrors)
            {
                STRING_T keyId;
                Link playReadyLicenser;
                Link widevineLicenser;
                STRING_T widevinePSSH;
                if (ParseString(value, "KeyId", true, keyId, parseErrors))
                    SetKeyId(keyId);
                if (ParseObject(value, "PlayReadyLicenser", true, playReadyLicenser, parseErrors))
                    SetPlayReadyLicenser(playReadyLicenser);
                if (ParseObject(value, "WidevineLicenser", true, widevineLicenser, parseErrors))
                    SetWidevineLicenser(widevineLicenser);
                if (ParseString(value, "WidevinePSSH", true, widevinePSSH, parseErrors))
                    SetWidevinePSSH(widevinePSSH);
                return !parseErrors;
            }
        private:
            Maybe<STRING_T> mKeyId;
            Maybe<Link> mPlayReadyLicenser;
            Maybe<Link> mWidevineLicenser;
            Maybe<STRING_T> mWidevinePSSH;
        };
    }
}
#endif //READY4AIR_PROTECTIONDATA_H

#ifndef READY4AIR_PLAYSUBTITLE_H
#define READY4AIR_PLAYSUBTITLE_H
namespace ready4air
{
    namespace dto
    {
        class PlaySubtitle : public JsonDeserializable
        {
        public:
            PlaySubtitle()
            {
            }
            virtual ~PlaySubtitle()
            {
            }
            const Maybe<STRING_T> &GetEncoding() const
            {
                return mEncoding;
            }
            void SetEncoding(const STRING_T &encoding)
            {
                mEncoding = encoding;
            }
            const Maybe<STRING_T> &GetFormat() const
            {
                return mFormat;
            }
            void SetFormat(const STRING_T &format)
            {
                mFormat = format;
            }
            const Maybe<STRING_T> &GetLanguage() const
            {
                return mLanguage;
            }
            void SetLanguage(const STRING_T &language)
            {
                mLanguage = language;
            }
            const Maybe<Link> &GetLink() const
            {
                return mLink;
            }
            void SetLink(const Link &link)
            {
                mLink = link;
            }
            virtual BOOL_T InitFromJsonValue(const rapidjson::Value &value, ParseErrors &parseErrors)
            {
                STRING_T encoding;
                STRING_T format;
                STRING_T language;
                Link link;
                if (ParseString(value, "Encoding", true, encoding, parseErrors))
                    SetEncoding(encoding);
                if (ParseString(value, "Format", true, format, parseErrors))
                    SetFormat(format);
                if (ParseString(value, "Language", true, language, parseErrors))
                    SetLanguage(language);
                if (ParseObject(value, "Link", true, link, parseErrors))
                    SetLink(link);
                return !parseErrors;
            }
        private:
            Maybe<STRING_T> mEncoding;
            Maybe<STRING_T> mFormat;
            Maybe<STRING_T> mLanguage;
            Maybe<Link> mLink;
        };
    }
}
#endif //READY4AIR_PLAYSUBTITLE_H

#ifndef READY4AIR_MANIFEST_H
#define READY4AIR_MANIFEST_H
namespace ready4air
{
    namespace dto
    {
        class Manifest : public JsonDeserializable
        {
        public:
            Manifest()
            {
            }
            virtual ~Manifest()
            {
            }
            const Maybe<Link> &GetLink() const
            {
                return mLink;
            }
            void SetLink(const Link &link)
            {
                mLink = link;
            }
            const Maybe<ProtectionData> &GetProtectionData() const
            {
                return mProtectionData;
            }
            void SetProtectionData(const ProtectionData &protectionData)
            {
                mProtectionData = protectionData;
            }
            virtual BOOL_T InitFromJsonValue(const rapidjson::Value &value, ParseErrors &parseErrors)
            {
                Link link;
                ProtectionData protectionData;
                if (ParseObject(value, "Link", true, link, parseErrors))
                    SetLink(link);
                if (ParseObject(value, "ProtectionData", false, protectionData, parseErrors))
                    SetProtectionData(protectionData);
                return !parseErrors;
            }
        private:
            Maybe<Link> mLink;
            Maybe<ProtectionData> mProtectionData;
        };
    }
}
#endif //READY4AIR_MANIFEST_H

#ifndef READY4AIR_FILE_H
#define READY4AIR_FILE_H
namespace ready4air
{
    namespace dto
    {
        class File : public JsonDeserializable
        {
        public:
            File()
            {
            }
            virtual ~File()
            {
            }
            const Maybe<int> &GetFileTypeId() const
            {
                return mFileTypeId;
            }
            void SetFileTypeId(int fileTypeId)
            {
                mFileTypeId = fileTypeId;
            }
            const Maybe<STRING_T> &GetFileTypeName() const
            {
                return mFileTypeName;
            }
            void SetFileTypeName(const STRING_T &fileTypeName)
            {
                mFileTypeName = fileTypeName;
            }
            const Maybe<STRING_T> &GetLanguage() const
            {
                return mLanguage;
            }
            void SetLanguage(const STRING_T &language)
            {
                mLanguage = language;
            }
            const Maybe<Link> &GetLink() const
            {
                return mLink;
            }
            void SetLink(const Link &link)
            {
                mLink = link;
            }
            const Maybe<int> &GetBitrate() const
            {
                return mBitrate;
            }
            void SetBitrate(int bitrate)
            {
                mBitrate = bitrate;
            }
            const Maybe<ProtectionData> &GetProtectionData() const
            {
                return mProtectionData;
            }
            void SetProtectionData(const ProtectionData &protectionData)
            {
                mProtectionData = protectionData;
            }
            virtual BOOL_T InitFromJsonValue(const rapidjson::Value &value, ParseErrors &parseErrors)
            {
                INT32_T fileTypeId;
                STRING_T fileTypeName;
                STRING_T language;
                Link link;
                INT32_T bitrate;
                ProtectionData protectionData;
                if (ParseInt(value, "FileTypeId", true, fileTypeId, parseErrors))
                    SetFileTypeId(fileTypeId);
                if (ParseString(value, "FileTypeName", true, fileTypeName, parseErrors))
                    SetFileTypeName(fileTypeName);
                if (ParseString(value, "Language", true, language, parseErrors))
                    SetLanguage(language);
                if (ParseObject(value, "Link", true, link, parseErrors))
                    SetLink(link);
                if (ParseInt(value, "Bitrate", true, bitrate, parseErrors))
                    SetBitrate(bitrate);
                if (ParseObject(value, "ProtectionData", false, protectionData, parseErrors))
                    SetProtectionData(protectionData);
                return !parseErrors;
            }
        private:
            Maybe<int> mFileTypeId;
            Maybe<STRING_T> mFileTypeName;
            Maybe<STRING_T> mLanguage;
            Maybe<Link> mLink;
            Maybe<int> mBitrate;
            Maybe<ProtectionData> mProtectionData;
        };
    }
}
#endif //READY4AIR_FILE_H

#ifndef READY4AIR_MANIFESTS_H
#define READY4AIR_MANIFESTS_H
namespace ready4air
{
    namespace dto
    {
        class Manifests : public JsonDeserializable
        {
        public:
            Manifests()
            {
            }
            virtual ~Manifests()
            {
            }
            const Maybe<VECTOR_T<Manifest> > &GetSmooth() const
            {
                return mSmooth;
            }
            void SetSmooth(const VECTOR_T<Manifest> &smooth)
            {
                mSmooth = smooth;
            }
            const Maybe<VECTOR_T<Manifest> > &GetDash() const
            {
                return mDash;
            }
            void SetDash(const VECTOR_T<Manifest> &dash)
            {
                mDash = dash;
            }
            const Maybe<VECTOR_T<Manifest> > &GetHls() const
            {
                return mHls;
            }
            void SetHls(const VECTOR_T<Manifest> &hls)
            {
                mHls = hls;
            }
            const Maybe<VECTOR_T<PlaySubtitle> > &GetSubtitles() const
            {
                return mSubtitles;
            }
            void SetSubtitles(const VECTOR_T<PlaySubtitle> &subtitles)
            {
                mSubtitles = subtitles;
            }
            const Maybe<VECTOR_T<File> > &GetProgressive() const
            {
                return mProgressive;
            }
            void SetProgressive(const VECTOR_T<File> &progressive)
            {
                mProgressive = progressive;
            }
            const Maybe<Link> &GetThumbnails() const
            {
                return mThumbnails;
            }
            void SetThumbnails(const Link &thumbnails)
            {
                mThumbnails = thumbnails;
            }
            virtual BOOL_T InitFromJsonValue(const rapidjson::Value &value, ParseErrors &parseErrors)
            {
                VECTOR_T<Manifest> smooth;
                VECTOR_T<Manifest> dash;
                VECTOR_T<Manifest> hls;
                VECTOR_T<PlaySubtitle> subtitles;
                VECTOR_T<File> progressive;
                Link thumbnails;
                if (VerifyArray(value, "Smooth", false, parseErrors))
                {
                    for (rapidjson::SizeType i = 0; i < value["Smooth"].Size(); i += 1)
                    {
                        Manifest manifest;
                        if (ParseObject(value["Smooth"][i], "", false, manifest, parseErrors))
                            smooth.push_back(manifest);
                    }
                    SetSmooth(smooth);
                }
                if (VerifyArray(value, "Dash", false, parseErrors))
                {
                    for (rapidjson::SizeType i = 0; i < value["Dash"].Size(); i += 1)
                    {
                        Manifest manifest;
                        if (ParseObject(value["Dash"][i], "", false, manifest, parseErrors))
                            dash.push_back(manifest);
                    }
                    SetDash(dash);
                }
                if (VerifyArray(value, "Hls", false, parseErrors))
                {
                    for (rapidjson::SizeType i = 0; i < value["Hls"].Size(); i += 1)
                    {
                        Manifest manifest;
                        if (ParseObject(value["Hls"][i], "", false, manifest, parseErrors))
                            hls.push_back(manifest);
                    }
                    SetHls(hls);
                }
                if (VerifyArray(value, "Subtitles", false, parseErrors))
                {
                    for (rapidjson::SizeType i = 0; i < value["Subtitles"].Size(); i += 1)
                    {
                        PlaySubtitle playSubtitle;
                        if (ParseObject(value["Subtitles"][i], "", false, playSubtitle, parseErrors))
                            subtitles.push_back(playSubtitle);
                    }
                    SetSubtitles(subtitles);
                }
                if (VerifyArray(value, "Progressive", false, parseErrors))
                {
                    for (rapidjson::SizeType i = 0; i < value["Progressive"].Size(); i += 1)
                    {
                        File file;
                        if (ParseObject(value["Progressive"][i], "", false, file, parseErrors))
                            progressive.push_back(file);
                    }
                    SetProgressive(progressive);
                }
                if (ParseObject(value, "Thumbnails", false, thumbnails, parseErrors))
                    SetThumbnails(thumbnails);
                return !parseErrors;
            }
        private:
            Maybe<VECTOR_T<Manifest> > mSmooth;
            Maybe<VECTOR_T<Manifest> > mDash;
            Maybe<VECTOR_T<Manifest> > mHls;
            Maybe<VECTOR_T<PlaySubtitle> > mSubtitles;
            Maybe<VECTOR_T<File> > mProgressive;
            Maybe<Link> mThumbnails;
        };
    }
}
#endif //READY4AIR_MANIFESTS_H

#ifndef READY4AIR_PLAY_H
#define READY4AIR_PLAY_H
namespace ready4air
{
    namespace dto
    {
        class Play : public JsonDeserializable
        {
        public:
            Play()
            {
            }
            virtual ~Play()
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
            const Maybe<Manifests> &GetTrailers() const
            {
                return mTrailers;
            }
            void SetTrailers(const Manifests &trailers)
            {
                mTrailers = trailers;
            }
            const Maybe<Manifests> &GetFeatures() const
            {
                return mFeatures;
            }
            void SetFeatures(const Manifests &features)
            {
                mFeatures = features;
            }
            virtual BOOL_T InitFromJsonValue(const rapidjson::Value &value, ParseErrors &parseErrors)
            {
                INT32_T productId;
                Manifests trailers;
                Manifests features;
                if (ParseInt(value, "ProductId", true, productId, parseErrors))
                    SetProductId(productId);
                if (ParseObject(value, "Trailers", false, trailers, parseErrors))
                    SetTrailers(trailers);
                if (ParseObject(value, "Features", false, features, parseErrors))
                    SetFeatures(features);
                return !parseErrors;
            }
        private:
            Maybe<int> mProductId;
            Maybe<Manifests> mTrailers;
            Maybe<Manifests> mFeatures;
        };
    }
}
#endif //READY4AIR_PLAY_H

//
// Created by Martin Kero on 12/01/16.
//
#ifndef READY4AIR_PRODUCT_H
#define READY4AIR_PRODUCT_H
namespace ready4air
{
    namespace dto
    {
        class Product : public JsonDeserializable
        {
        public:
            Product()
            {
            }
            virtual ~Product()
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
            const Maybe<BOOL_T> &GetHD() const
            {
                return mHD;
            }
            void SetHD(BOOL_T HD)
            {
                mHD = HD;
            }
            const Maybe<BOOL_T> &GetDubbed() const
            {
                return mDubbed;
            }
            void SetDubbed(BOOL_T dubbed)
            {
                mDubbed = dubbed;
            }
            const Maybe <Link> &GetFullPLay() const
            {
                return mFullPLay;
            }
            void SetFullPLay(const Link &fullPLay)
            {
                mFullPLay = fullPLay;
            }
            const Maybe <Entitlement> &GetEntitlements() const
            {
                return mEntitlements;
            }
            void SetEntitlements(const Entitlement &entitlements)
            {
                mEntitlements = entitlements;
            }
            const Maybe <VECTOR_T<PurchaseItem> > &GetPurchaseItems() const
            {
                return mPurchaseItems;
            }
            void SetPurchaseItems(const VECTOR_T<PurchaseItem> &purchaseItems)
            {
                mPurchaseItems = purchaseItems;
            }
            virtual BOOL_T InitFromJsonValue(const rapidjson::Value &value, ParseErrors &parseErrors)
            {
                INT32_T productId;
                BOOL_T hd;
                BOOL_T dubbed;
                Link fullPLay;
                Entitlement entitlements;
                VECTOR_T<PurchaseItem> purchaseItems;
                if (ParseInt(value, "ProductId", true, productId, parseErrors))
                    SetProductId(productId);
                if (ParseBool(value, "HD", true, hd, parseErrors))
                    SetHD(hd);
                if (ParseBool(value, "Dubbed", true, dubbed, parseErrors))
                    SetDubbed(dubbed);
                if (ParseObject(value, "FullPLay", false, fullPLay, parseErrors))
                    SetFullPLay(fullPLay);
                if (ParseObject(value, "Entitlements", true, entitlements, parseErrors))
                    SetEntitlements(entitlements);
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
                return !parseErrors;
            }
        private:
            Maybe<int> mProductId;
            Maybe<BOOL_T> mHD;
            Maybe<BOOL_T> mDubbed;
            Maybe <Link> mFullPLay;
            Maybe <Entitlement> mEntitlements;
            Maybe <VECTOR_T<PurchaseItem> > mPurchaseItems;
        };
    }
}
#endif //READY4AIR_PRODUCT_H

#ifndef READY4AIR_MEDIAPRODUCT_H
#define READY4AIR_MEDIAPRODUCT_H
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
        protected:
            Maybe<ProductType> mProductType;
        };
    }
}
#endif //READY4AIR_MEDIAPRODUCT_H

#ifndef READY4AIR_SECTION_H
#define READY4AIR_SECTION_H
namespace ready4air
{
    namespace dto
    {
        class Section : public JsonDeserializable
        {
        public:
            Section()
            {
            }
            virtual ~Section()
            {
            }
            const Maybe <STRING_T> &GetTitle() const
            {
                return mTitle;
            }
            void SetTitle(const STRING_T &title)
            {
                mTitle = title;
            }
            const Maybe <Link> &GetAll() const
            {
                return mAll;
            }
            void SetAll(const Link &all)
            {
                mAll = all;
            }
            const Maybe <VECTOR_T<MediaProduct> > &GetMedias() const
            {
                return mMedias;
            }
            void SetMedias(const VECTOR_T<MediaProduct> &medias)
            {
                mMedias = medias;
            }
            virtual BOOL_T InitFromJsonValue(const rapidjson::Value &value, ParseErrors &parseErrors)
            {
                STRING_T title;
                Link all;
                VECTOR_T<MediaProduct> medias;
                if (ParseString(value, "Title", true, title, parseErrors))
                    SetTitle(title);
                if (ParseObject(value, "All", false, all, parseErrors))
                    SetAll(all);
                if (VerifyArray(value, "Medias", true, parseErrors))
                {
                    for (rapidjson::SizeType i = 0; i < value["Medias"].Size(); i += 1)
                    {
                        MediaProduct mediaProduct;
                        if (ParseObject(value["Medias"][i], "", false, mediaProduct, parseErrors))
                            medias.push_back(mediaProduct);
                    }
                    SetMedias(medias);
                }
                return !parseErrors;
            }
        private:
            Maybe <STRING_T> mTitle;
            Maybe <Link> mAll;
            Maybe <VECTOR_T<MediaProduct> > mMedias;
        };
    }
}
#endif //READY4AIR_SECTION_H

#ifndef READY4AIR_TEASER_H
#define READY4AIR_TEASER_H
namespace ready4air
{
    namespace dto
    {
        class Teaser : public JsonDeserializable
        {
        public:
            Teaser()
            {
            }
            virtual ~Teaser()
            {
            }
            const Maybe <VECTOR_T<MediaProduct> > &GetMedias() const
            {
                return mMedias;
            }
            void SetMedias(const VECTOR_T<MediaProduct> &medias)
            {
                mMedias = medias;
            }
            virtual BOOL_T InitFromJsonValue(const rapidjson::Value &value, ParseErrors &parseErrors)
            {
                VECTOR_T<MediaProduct> medias;
                if (VerifyArray(value, "Medias", true, parseErrors))
                {
                    for (rapidjson::SizeType i = 0; i < value["Medias"].Size(); i += 1)
                    {
                        MediaProduct mediaProduct;
                        if (ParseObject(value["Medias"][i], "", false, mediaProduct, parseErrors))
                            medias.push_back(mediaProduct);
                    }
                    SetMedias(medias);
                }
                return !parseErrors;
            }
        private:
            Maybe <VECTOR_T<MediaProduct> > mMedias;
        };
    }
}
#endif //READY4AIR_TEASER_H

#ifndef READY4AIR_EVENT_H
#define READY4AIR_EVENT_H
namespace ready4air
{
    namespace dto
    {
        class Event : public JsonDeserializable
        {
        public:
            Event()
            {
            }
            virtual ~Event()
            {
            }
            const Maybe <STRING_T> &GetStart() const
            {
                return mStart;
            }
            void SetStart(const STRING_T &start)
            {
                mStart = start;
            }
            const Maybe <STRING_T> &GetEnd() const
            {
                return mEnd;
            }
            void SetEnd(const STRING_T &anEnd)
            {
                mEnd = anEnd;
            }
            const Maybe <MediaProduct> &GetMedia() const
            {
                return mMedia;
            }
            void SetMedia(const MediaProduct &media)
            {
                mMedia = media;
            }
            virtual BOOL_T InitFromJsonValue(const rapidjson::Value &value, ParseErrors &parseErrors)
            {
                STRING_T start;
                STRING_T end;
                MediaProduct media;
                if (ParseString(value, "Start", true, start, parseErrors))
                    SetStart(start);
                if (ParseString(value, "End", true, end, parseErrors))
                    SetEnd(end);
                if (ParseObject(value, "Media", true, media, parseErrors))
                    SetMedia(media);
                return !parseErrors;
            }
        private:
            Maybe <STRING_T> mStart;
            Maybe <STRING_T> mEnd;
            Maybe <MediaProduct> mMedia;
        };
    }
}
#endif //READY4AIR_EVENT_H

#ifndef READY4AIR_EPGINFO_H
#define READY4AIR_EPGINFO_H
namespace ready4air
{
    namespace dto
    {
        class EpgInfo : public JsonDeserializable
        {
        public:
            EpgInfo()
            {
            }
            virtual ~EpgInfo()
            {
            }
            const Maybe<Event> &GetNow() const
            {
                return mNow;
            }
            void SetNow(const Event &now)
            {
                mNow = now;
            }
            const Maybe<Event> &GetNext() const
            {
                return mNext;
            }
            void SetNext(const Event &next)
            {
                mNext = next;
            }
            const Maybe<Link> &GetAll() const
            {
                return mAll;
            }
            void SetAll(const Link &all)
            {
                mAll = all;
            }
            virtual BOOL_T InitFromJsonValue(const rapidjson::Value &value, ParseErrors &parseErrors)
            {
                Event now;
                Event next;
                Link all;
                if (ParseObject(value, "Now", false, now, parseErrors))
                    SetNow(now);
                if (ParseObject(value, "Next", true, next, parseErrors))
                    SetNext(next);
                if (ParseObject(value, "All", true, all, parseErrors))
                    SetAll(all);
                return !parseErrors;
            }
        private:
            Maybe<Event> mNow;
            Maybe<Event> mNext;
            Maybe<Link> mAll;
        };
    }
}
#endif //READY4AIR_EPGINFO_H

#ifndef READY4AIR_CHANNEL_H
#define READY4AIR_CHANNEL_H
namespace ready4air
{
    namespace dto
    {
        class Channel : public JsonDeserializable
        {
        public:
            Channel()
            {
            }
            virtual ~Channel()
            {
            }
            const Maybe<STRING_T> &GetId() const
            {
                return mId;
            }
            void SetId(const STRING_T &id)
            {
                mId = id;
            }
            const Maybe<STRING_T> &GetOriginalTitle() const
            {
                return mOriginalTitle;
            }
            void SetOriginalTitle(const STRING_T &originalTitle)
            {
                mOriginalTitle = originalTitle;
            }
            const Maybe<STRING_T> &GetDescription() const
            {
                return mDescription;
            }
            void SetDescription(const STRING_T &description)
            {
                mDescription = description;
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
            const Maybe<VECTOR_T<Image> > &GetImages() const
            {
                return mImages;
            }
            void SetImages(const VECTOR_T<Image> &images)
            {
                mImages = images;
            }
            const Maybe<EpgInfo> &GetEpgInfo() const
            {
                return mEpgInfo;
            }
            void SetEpgInfo(const EpgInfo &epgInfo)
            {
                mEpgInfo = epgInfo;
            }
            const Maybe<Link> &GetSelf() const
            {
                return mSelf;
            }
            void SetSelf(const Link &self)
            {
                mSelf = self;
            }
            virtual BOOL_T InitFromJsonValue(const rapidjson::Value &value, ParseErrors &parseErrors)
            {
                STRING_T id;
                STRING_T originalTitle;
                STRING_T description;
                STRING_T localTitle;
                STRING_T shortTitle;
                STRING_T longSummary;
                STRING_T shortSummary;
                STRING_T sortTitle;
                VECTOR_T<Image> images;
                EpgInfo epgInfo;
                Link self;
                if (ParseString(value, "Id", true, id, parseErrors))
                    SetId(id);
                if (ParseString(value, "OriginalTitle", false, originalTitle, parseErrors))
                    SetOriginalTitle(originalTitle);
                if (ParseString(value, "Description", false, description, parseErrors))
                    SetDescription(description);
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
                if (ParseObject(value, "EpgInfo", true, epgInfo, parseErrors))
                    SetEpgInfo(epgInfo);
                if (ParseObject(value, "Self", false, self, parseErrors))
                    SetSelf(self);
                return !parseErrors;
            }
        private:
            Maybe<STRING_T> mId;
            Maybe<STRING_T> mOriginalTitle;
            Maybe<STRING_T> mDescription;
            Maybe<STRING_T> mLocalTitle;
            Maybe<STRING_T> mShortTitle;
            Maybe<STRING_T> mLongSummary;
            Maybe<STRING_T> mShortSummary;
            Maybe<STRING_T> mSortTitle;
            Maybe<VECTOR_T<Image> > mImages;
            Maybe<EpgInfo> mEpgInfo;
            Maybe<Link> mSelf;
        };
    }
}
#endif //READY4AIR_CHANNEL_H

#ifndef READY4AIR_LIVESECTION_H
#define READY4AIR_LIVESECTION_H
namespace ready4air
{
    namespace dto
    {
        class LiveSection : public JsonDeserializable
        {
        public:
            LiveSection()
            {
            }
            virtual ~LiveSection()
            {
            }
            const Maybe<STRING_T> &GetTitle() const
            {
                return mTitle;
            }
            void SetTitle(const STRING_T &title)
            {
                mTitle = title;
            }
            const Maybe<VECTOR_T<Channel> > &GetChannels() const
            {
                return mChannels;
            }
            void SetChannels(const VECTOR_T<Channel> &channels)
            {
                mChannels = channels;
            }
            const Maybe<Link> &GetAll() const
            {
                return mAll;
            }
            void SetAll(const Link &all)
            {
                mAll = all;
            }
            virtual BOOL_T InitFromJsonValue(const rapidjson::Value &value, ParseErrors &parseErrors)
            {
                STRING_T title;
                VECTOR_T<Channel> channels;
                Link all;
                if (ParseString(value, "Title", true, title, parseErrors))
                    SetTitle(title);
                if (VerifyArray(value, "Channels", true, parseErrors))
                {
                    for (rapidjson::SizeType i = 0; i < value["Channels"].Size(); i += 1)
                    {
                        Channel channel;
                        if (ParseObject(value["Channels"][i], "", false, channel, parseErrors))
                            channels.push_back(channel);
                    }
                    SetChannels(channels);
                }
                if (ParseObject(value, "All", false, all, parseErrors))
                    SetAll(all);
                return !parseErrors;
            }
        private:
            Maybe<STRING_T> mTitle;
            Maybe<VECTOR_T<Channel> > mChannels;
            Maybe<Link> mAll;
        };
    }
}
#endif //READY4AIR_LIVESECTION_H

#ifndef READY4AIR_PROMOTION_H
#define READY4AIR_PROMOTION_H
namespace ready4air
{
    namespace dto
    {
        class Promotion : public JsonDeserializable
        {
        public:
            Promotion()
            {
            }
            virtual ~Promotion()
            {
            }
            const Maybe <Link> &GetImage() const
            {
                return mImage;
            }
            void SetImage(const Link &image)
            {
                mImage = image;
            }
            const Maybe <Link> &GetImageLink() const
            {
                return mImageLink;
            }
            void SetImageLink(const Link &imageLink)
            {
                mImageLink = imageLink;
            }
            const Maybe <Link> &GetExternalSource() const
            {
                return mExternalSource;
            }
            void SetExternalSource(const Link &externalSource)
            {
                mExternalSource = externalSource;
            }
            const Maybe <STRING_T> &GetSource() const
            {
                return mSource;
            }
            void SetSource(const STRING_T &source)
            {
                mSource = source;
            }
            virtual BOOL_T InitFromJsonValue(const rapidjson::Value &value, ParseErrors &parseErrors)
            {
                Link image;
                Link imageLink;
                Link externalSource;
                STRING_T source;
                if (ParseObject(value, "Image", false, image, parseErrors))
                    SetImage(image);
                if (ParseObject(value, "ImageLink", false, imageLink, parseErrors))
                    SetImageLink(imageLink);
                if (ParseObject(value, "ExternalSource", false, externalSource, parseErrors))
                    SetExternalSource(externalSource);
                if (ParseString(value, "Source", false, source, parseErrors))
                    SetSource(source);
                return !parseErrors;
            }
        private:
            Maybe <Link> mImage;
            Maybe <Link> mImageLink;
            Maybe <Link> mExternalSource;
            Maybe <STRING_T> mSource;
        };
    }
}
#endif //READY4AIR_PROMOTION_H

#ifndef READY4AIR_CONTENT_H
#define READY4AIR_CONTENT_H
namespace ready4air
{
    namespace dto
    {
        class Content : public JsonDeserializable
        {
        public:
            Content()
            {
            }
            virtual ~Content()
            {
            }
            const Maybe<VECTOR_T<Button> > &GetButtons() const
            {
                return mButtons;
            }
            void SetButtons(const VECTOR_T<Button> &buttons)
            {
                mButtons = buttons;
            }
            const Maybe<VECTOR_T<MenuItem> > &GetMenuItems() const
            {
                return mMenuItems;
            }
            void SetMenuItems(const VECTOR_T<MenuItem> &menuItems)
            {
                mMenuItems = menuItems;
            }
            const Maybe<VECTOR_T<Section> > &GetSections() const
            {
                return mSections;
            }
            void SetSections(const VECTOR_T<Section> &sections)
            {
                mSections = sections;
            }
            const Maybe<VECTOR_T<Teaser> > &GetTeasers() const
            {
                return mTeasers;
            }
            void SetTeasers(const VECTOR_T<Teaser> &teasers)
            {
                mTeasers = teasers;
            }
            const Maybe<VECTOR_T<Promotion> > &GetPromotions() const
            {
                return mPromotions;
            }
            void SetPromotions(const VECTOR_T<Promotion> &promotions)
            {
                mPromotions = promotions;
            }
            const Maybe<VECTOR_T<LiveSection> > &GetLiveSections() const
            {
                return mLiveSections;
            }
            void SetLiveSections(const VECTOR_T<LiveSection> &liveSections)
            {
                mLiveSections = liveSections;
            }
            const Maybe<Catalogue> &GetCatalogue() const
            {
                return mCatalogue;
            }
            void SetCatalogue(const Catalogue &catalogue)
            {
                mCatalogue = catalogue;
            }
            virtual BOOL_T InitFromJsonValue(const rapidjson::Value &value, ParseErrors &parseErrors)
            {
                VECTOR_T<Button> buttons;
                VECTOR_T<MenuItem> menuItems;
                VECTOR_T<Section> sections;
                VECTOR_T<Teaser> teasers;
                VECTOR_T<Promotion> promotions;
                VECTOR_T<LiveSection> liveSections;
                Catalogue catalogue;
                if (VerifyArray(value, "Buttons", false, parseErrors))
                {
                    for (rapidjson::SizeType i = 0; i < value["Buttons"].Size(); i += 1)
                    {
                        Button button;
                        if (ParseObject(value["Buttons"][i], "", false, button, parseErrors))
                            buttons.push_back(button);
                    }
                    SetButtons(buttons);
                }
                if (VerifyArray(value, "MenuItems", true, parseErrors))
                {
                    for (rapidjson::SizeType i = 0; i < value["MenuItems"].Size(); i += 1)
                    {
                        MenuItem menuItem;
                        if (ParseObject(value["MenuItems"][i], "", false, menuItem, parseErrors))
                            menuItems.push_back(menuItem);
                    }
                    SetMenuItems(menuItems);
                }
                if (VerifyArray(value, "Sections", false, parseErrors))
                {
                    for (rapidjson::SizeType i = 0; i < value["Sections"].Size(); i += 1)
                    {
                        Section section;
                        if (ParseObject(value["Sections"][i], "", false, section, parseErrors))
                            sections.push_back(section);
                    }
                    SetSections(sections);
                }
                if (VerifyArray(value, "Teasers", false, parseErrors))
                {
                    for (rapidjson::SizeType i = 0; i < value["Teasers"].Size(); i += 1)
                    {
                        Teaser teaser;
                        if (ParseObject(value["Teasers"][i], "", false, teaser, parseErrors))
                            teasers.push_back(teaser);
                    }
                    SetTeasers(teasers);
                }
                if (VerifyArray(value, "Promotions", false, parseErrors))
                {
                    for (rapidjson::SizeType i = 0; i < value["Promotions"].Size(); i += 1)
                    {
                        Promotion promotion;
                        if (ParseObject(value["Promotions"][i], "", false, promotion, parseErrors))
                            promotions.push_back(promotion);
                    }
                    SetPromotions(promotions);
                }
                if (VerifyArray(value, "LiveSections", false, parseErrors))
                {
                    for (rapidjson::SizeType i = 0; i < value["LiveSections"].Size(); i += 1)
                    {
                        LiveSection liveSection;
                        if (ParseObject(value["LiveSections"][i], "", false, liveSection, parseErrors))
                            liveSections.push_back(liveSection);
                    }
                    SetLiveSections(liveSections);
                }
                if (ParseObject(value, "Catalogue", true, catalogue, parseErrors))
                    SetCatalogue(catalogue);
                return !parseErrors;
            }
        private:
            Maybe<VECTOR_T<Button> > mButtons;
            Maybe<VECTOR_T<MenuItem> > mMenuItems;
            Maybe<VECTOR_T<Section> > mSections;
            Maybe<VECTOR_T<Teaser> > mTeasers;
            Maybe<VECTOR_T<Promotion> > mPromotions;
            Maybe<VECTOR_T<LiveSection> > mLiveSections;
            Maybe<Catalogue> mCatalogue;
        };
    }
}
#endif //READY4AIR_CONTENT_H

#ifndef READY4AIR_DEVICEAUTHDATA_H
#define READY4AIR_DEVICEAUTHDATA_H
namespace ready4air
{
    namespace dto
    {
        class DeviceAuthData : public JsonDeserializable
        {
        public:
            DeviceAuthData()
            {
            }
            virtual ~DeviceAuthData()
            {
            }
            const Maybe<int> &GetDeviceVersion() const
            {
                return mDeviceVersion;
            }
            void SetDeviceVersion(int deviceVersion)
            {
                mDeviceVersion = deviceVersion;
            }
            const Maybe <STRING_T> &GetCountry() const
            {
                return mCountry;
            }
            void SetCountry(const STRING_T &country)
            {
                mCountry = country;
            }
            const Maybe <STRING_T> &GetLanguage() const
            {
                return mLanguage;
            }
            void SetLanguage(const STRING_T &language)
            {
                mLanguage = language;
            }
            const Maybe <STRING_T> &GetDeviceId() const
            {
                return mDeviceId;
            }
            void SetDeviceId(const STRING_T &deviceId)
            {
                mDeviceId = deviceId;
            }
            const Maybe <STRING_T> &GetToken() const
            {
                return mToken;
            }
            void SetToken(const STRING_T &token)
            {
                mToken = token;
            }
            const Maybe <STRING_T> &GetExpirationDateTime() const
            {
                return mExpirationDateTime;
            }
            void SetExpirationDateTime(const STRING_T &expirationDateTime)
            {
                mExpirationDateTime = expirationDateTime;
            }
            const Maybe <STRING_T> &GetIpAddress() const
            {
                return mIpAddress;
            }
            void SetIpAddress(const STRING_T &ipAddress)
            {
                mIpAddress = ipAddress;
            }
            virtual BOOL_T InitFromJsonValue(const rapidjson::Value &value, ParseErrors &parseErrors)
            {
                INT32_T deviceVersion;
                STRING_T country;
                STRING_T language;
                STRING_T deviceId;
                STRING_T token;
                STRING_T expirationDateTime;
                STRING_T ipAddress;
                if (ParseInt(value, "DeviceVersion", true, deviceVersion, parseErrors))
                    SetDeviceVersion(deviceVersion);
                if (ParseString(value, "Country", true, country, parseErrors))
                    SetCountry(country);
                if (ParseString(value, "Language", false, language, parseErrors))
                    SetLanguage(language);
                if (ParseString(value, "DeviceId", false, deviceId, parseErrors))
                    SetDeviceId(deviceId);
                if (ParseString(value, "Token", false, token, parseErrors))
                    SetToken(token);
                if (ParseString(value, "ExpirationDateTime", false, expirationDateTime, parseErrors))
                    SetExpirationDateTime(expirationDateTime);
                if (ParseString(value, "IpAddress", false, ipAddress, parseErrors))
                    SetIpAddress(ipAddress);
                return !parseErrors;
            }
        private:
            Maybe<int> mDeviceVersion;
            Maybe <STRING_T> mCountry;
            Maybe <STRING_T> mLanguage;
            Maybe <STRING_T> mDeviceId;
            Maybe <STRING_T> mToken;
            Maybe <STRING_T> mExpirationDateTime;
            Maybe <STRING_T> mIpAddress;
        };
    }
}
#endif //READY4AIR_DEVICEAUTHDATA_H

#ifndef READY4AIR_DEVICE_H
#define READY4AIR_DEVICE_H
namespace ready4air
{
    namespace dto
    {
        class Device : public JsonDeserializable
        {
        public:
            Device()
            {
            }
            virtual ~Device()
            {
            }
            const Maybe<STRING_T> &GetId() const
            {
                return mId;
            }
            void SetId(const STRING_T &id)
            {
                mId = id;
            }
            const Maybe<STRING_T> &GetManufacturer() const
            {
                return mManufacturer;
            }
            void SetManufacturer(const STRING_T &manufacturer)
            {
                mManufacturer = manufacturer;
            }
            const Maybe<STRING_T> &GetModel() const
            {
                return mModel;
            }
            void SetModel(const STRING_T &model)
            {
                mModel = model;
            }
            const Maybe<STRING_T> &GetUdId() const
            {
                return mUdId;
            }
            void SetUdId(const STRING_T &udId)
            {
                mUdId = udId;
            }
            const Maybe<STRING_T> &GetDeviceInfo() const
            {
                return mDeviceInfo;
            }
            void SetDeviceInfo(const STRING_T &deviceInfo)
            {
                mDeviceInfo = deviceInfo;
            }
            const Maybe<STRING_T> &GetLastUsedDate() const
            {
                return mLastUsedDate;
            }
            void SetLastUsedDate(const STRING_T &lastUsedDate)
            {
                mLastUsedDate = lastUsedDate;
            }
            const Maybe<STRING_T> &GetLastUsedIP() const
            {
                return mLastUsedIP;
            }
            void SetLastUsedIP(const STRING_T &lastUsedIP)
            {
                mLastUsedIP = lastUsedIP;
            }
            const Maybe<STRING_T> &GetRegistrationDate() const
            {
                return mRegistrationDate;
            }
            void SetRegistrationDate(const STRING_T &registrationDate)
            {
                mRegistrationDate = registrationDate;
            }
            const Maybe<Link> &GetHome() const
            {
                return mHome;
            }
            void SetHome(const Link &home)
            {
                mHome = home;
            }
            const Maybe<Link> &GetHelps() const
            {
                return mHelps;
            }
            void SetHelps(const Link &helps)
            {
                mHelps = helps;
            }
            const Maybe<Link> &GetLiterals() const
            {
                return mLiterals;
            }
            void SetLiterals(const Link &literals)
            {
                mLiterals = literals;
            }
            const Maybe<Link> &GetLogin() const
            {
                return mLogin;
            }
            void SetLogin(const Link &login)
            {
                mLogin = login;
            }
            const Maybe<Form> &GetRegister() const
            {
                return mRegister;
            }
            void SetRegister(const Form &aRegister)
            {
                mRegister = aRegister;
            }
            const Maybe<Form> &GetForgotPassword() const
            {
                return mForgotPassword;
            }
            void SetForgotPassword(const Form &forgotPassword)
            {
                mForgotPassword = forgotPassword;
            }
            const Maybe<VECTOR_T<STRING_T> > &GetAvailablePaymentMethods() const
            {
                return mAvailablePaymentMethods;
            }
            void SetAvailablePaymentMethods(const VECTOR_T<STRING_T> &availablePaymentMethods)
            {
                mAvailablePaymentMethods = availablePaymentMethods;
            }
            const Maybe<Link> &GetSelf() const
            {
                return mSelf;
            }
            void SetSelf(const Link &self)
            {
                mSelf = self;
            }
            const Maybe<Link> &GetSearch() const
            {
                return mSearch;
            }
            void SetSearch(const Link &search)
            {
                mSearch = search;
            }
            const Maybe<Link> &GetSearchAsYouType() const
            {
                return mSearchAsYouType;
            }
            void SetSearchAsYouType(const Link &searchAsYouType)
            {
                mSearchAsYouType = searchAsYouType;
            }
            const Maybe<Link> &GetSearchMovies() const
            {
                return mSearchMovies;
            }
            void SetSearchMovies(const Link &searchMovies)
            {
                mSearchMovies = searchMovies;
            }
            const Maybe<Link> &GetFilterMoviesByAgeGroups() const
            {
                return mFilterMoviesByAgeGroups;
            }
            void SetFilterMoviesByAgeGroups(const Link &filterMoviesByAgeGroups)
            {
                mFilterMoviesByAgeGroups = filterMoviesByAgeGroups;
            }
            const Maybe<Link> &GetSearchSeries() const
            {
                return mSearchSeries;
            }
            void SetSearchSeries(const Link &searchSeries)
            {
                mSearchSeries = searchSeries;
            }
            const Maybe<Link> &GetFilterSeriesByAgeGroups() const
            {
                return mFilterSeriesByAgeGroups;
            }
            void SetFilterSeriesByAgeGroups(const Link &filterSeriesByAgeGroups)
            {
                mFilterSeriesByAgeGroups = filterSeriesByAgeGroups;
            }
            const Maybe<Link> &GetSearchBundles() const
            {
                return mSearchBundles;
            }
            void SetSearchBundles(const Link &searchBundles)
            {
                mSearchBundles = searchBundles;
            }
            const Maybe<Link> &GetAllPublicUserLists() const
            {
                return mAllPublicUserLists;
            }
            void SetAllPublicUserLists(const Link &allPublicUserLists)
            {
                mAllPublicUserLists = allPublicUserLists;
            }
            const Maybe<DeviceAuthData> &GetDeviceAuthData() const
            {
                return mDeviceAuthData;
            }
            void SetDeviceAuthData(const DeviceAuthData &deviceAuthData)
            {
                mDeviceAuthData = deviceAuthData;
            }
            const Maybe<STRING_T> &GetApiVersion() const
            {
                return mApiVersion;
            }
            void SetApiVersion(const STRING_T &apiVersion)
            {
                mApiVersion = apiVersion;
            }
            const Maybe<STRING_T> &GetApiDocumentationLink() const
            {
                return mApiDocumentationLink;
            }
            void SetApiDocumentationLink(const STRING_T &apiDocumentationLink)
            {
                mApiDocumentationLink = apiDocumentationLink;
            }
            const Maybe<Crud> &GetManageFreePages() const
            {
                return mManageFreePages;
            }
            void SetManageFreePages(const Crud &manageFreePages)
            {
                mManageFreePages = manageFreePages;
            }
            const Maybe<Link> &GetSearchMoviesByPerson() const
            {
                return mSearchMoviesByPerson;
            }
            void SetSearchMoviesByPerson(const Link &searchMoviesByPerson)
            {
                mSearchMoviesByPerson = searchMoviesByPerson;
            }
            const Maybe<Link> &GetCreateMppSession() const
            {
                return mCreateMppSession;
            }
            void SetCreateMppSession(const Link &createMppSession)
            {
                mCreateMppSession = createMppSession;
            }
            const Maybe<Link> &GetMppUserExists() const
            {
                return mMppUserExists;
            }
            void SetMppUserExists(const Link &mppUserExists)
            {
                mMppUserExists = mppUserExists;
            }
            const Maybe<Link> &GetAllLists() const
            {
                return mAllLists;
            }
            void SetAllLists(const Link &allLists)
            {
                mAllLists = allLists;
            }
            virtual BOOL_T InitFromJsonValue(const rapidjson::Value &value, ParseErrors &parseErrors)
            {
                STRING_T id;
                STRING_T manufacturer;
                STRING_T model;
                STRING_T udId;
                STRING_T deviceInfo;
                STRING_T lastUsedDate;
                STRING_T lastUsedIP;
                STRING_T registrationDate;
                Link home;
                Link helps;
                Link literals;
                Link login;
                Form aRegister;
                Form forgotPassword;
                VECTOR_T<STRING_T> availablePaymentMethods;
                Link self;
                Link search;
                Link searchAsYouType;
                Link searchMovies;
                Link filterMoviesByAgeGroups;
                Link searchSeries;
                Link filterSeriesByAgeGroups;
                Link searchBundles;
                Link allPublicUserLists;
                DeviceAuthData deviceAuthData;
                STRING_T apiVersion;
                STRING_T apiDocumentationLink;
                Crud manageFreePages;
                Link searchMoviesByPerson;
                Link createMppSession;
                Link mppUserExists;
                Link allLists;
                if (ParseString(value, "Id", true, id, parseErrors))
                    SetId(id);
                if (ParseString(value, "Manufacturer", false, manufacturer, parseErrors))
                    SetManufacturer(manufacturer);
                if (ParseString(value, "Model", false, model, parseErrors))
                    SetModel(model);
                if (ParseString(value, "UdId", true, udId, parseErrors))
                    SetUdId(udId);
                if (ParseString(value, "DeviceInfo", false, deviceInfo, parseErrors))
                    SetDeviceInfo(deviceInfo);
                if (ParseString(value, "LastUsedDate", false, lastUsedDate, parseErrors))
                    SetLastUsedDate(lastUsedDate);
                if (ParseString(value, "LastUsedIP", false, lastUsedIP, parseErrors))
                    SetLastUsedIP(lastUsedIP);
                if (ParseString(value, "RegistrationDate", true, registrationDate, parseErrors))
                    SetRegistrationDate(registrationDate);
                if (ParseObject(value, "Home", true, home, parseErrors))
                    SetHome(home);
                if (ParseObject(value, "Helps", true, helps, parseErrors))
                    SetHelps(helps);
                if (ParseObject(value, "Literals", true, literals, parseErrors))
                    SetLiterals(literals);
                if (ParseObject(value, "Login", true, login, parseErrors))
                    SetLogin(login);
                if (ParseObject(value, "Register", false, aRegister, parseErrors))
                    SetRegister(aRegister);
                if (ParseObject(value, "ForgotPassword", false, forgotPassword, parseErrors))
                    SetForgotPassword(forgotPassword);
                if (VerifyArray(value, "AvailablePaymentMethods", true, parseErrors))
                {
                    for (rapidjson::SizeType i = 0; i < value["AvailablePaymentMethods"].Size(); i += 1)
                    {
                        STRING_T availablePaymentMethod;
                        if (ParseString(value["AvailablePaymentMethods"][i], "", false, availablePaymentMethod,
                                        parseErrors))
                            availablePaymentMethods.push_back(availablePaymentMethod);
                    }
                    SetAvailablePaymentMethods(availablePaymentMethods);
                }
                if (ParseObject(value, "Self", false, self, parseErrors))
                    SetSelf(self);
                if (ParseObject(value, "Search", true, search, parseErrors))
                    SetSearch(search);
                if (ParseObject(value, "SearchAsYouType", true, searchAsYouType, parseErrors))
                    SetSearchAsYouType(searchAsYouType);
                if (ParseObject(value, "SearchMovies", true, searchMovies, parseErrors))
                    SetSearchMovies(searchMovies);
                if (ParseObject(value, "FilterMoviesByAgeGroups", false, filterMoviesByAgeGroups, parseErrors))
                    SetFilterMoviesByAgeGroups(filterMoviesByAgeGroups);
                if (ParseObject(value, "SearchSeries", true, searchSeries, parseErrors))
                    SetSearchSeries(searchSeries);
                if (ParseObject(value, "FilterSeriesByAgeGroups", false, filterSeriesByAgeGroups, parseErrors))
                    SetFilterSeriesByAgeGroups(filterSeriesByAgeGroups);
                if (ParseObject(value, "SearchBundles", true, searchBundles, parseErrors))
                    SetSearchBundles(searchBundles);
                if (ParseObject(value, "AllPublicUserLists", false, allPublicUserLists, parseErrors))
                    SetAllPublicUserLists(allPublicUserLists);
                if (ParseObject(value, "DeviceAuthData", true, deviceAuthData, parseErrors))
                    SetDeviceAuthData(deviceAuthData);
                if (ParseString(value, "ApiVersion", false, apiVersion, parseErrors))
                    SetApiVersion(apiVersion);
                if (ParseString(value, "ApiDocumentationLink", false, apiDocumentationLink, parseErrors))
                    SetApiDocumentationLink(apiDocumentationLink);
                if (ParseObject(value, "ManageFreePages", false, manageFreePages, parseErrors))
                    SetManageFreePages(manageFreePages);
                if (ParseObject(value, "SearchMoviesByPerson", true, searchMoviesByPerson, parseErrors))
                    SetSearchMoviesByPerson(searchMoviesByPerson);
                if (ParseObject(value, "CreateMppSession", false, createMppSession, parseErrors))
                    SetCreateMppSession(createMppSession);
                if (ParseObject(value, "MppUserExists", false, mppUserExists, parseErrors))
                    SetMppUserExists(mppUserExists);
                if (ParseObject(value, "AllLists", false, allLists, parseErrors))
                    SetAllLists(allLists);
                return !parseErrors;
            }
        private:
            Maybe<STRING_T> mId;
            Maybe<STRING_T> mManufacturer;
            Maybe<STRING_T> mModel;
            Maybe<STRING_T> mUdId;
            Maybe<STRING_T> mDeviceInfo;
            Maybe<STRING_T> mLastUsedDate;
            Maybe<STRING_T> mLastUsedIP;
            Maybe<STRING_T> mRegistrationDate;
            Maybe<Link> mHome;
            Maybe<Link> mHelps;
            Maybe<Link> mLiterals;
            Maybe<Link> mLogin;
            Maybe<Form> mRegister;
            Maybe<Form> mForgotPassword;
            Maybe<VECTOR_T<STRING_T> > mAvailablePaymentMethods;
            Maybe<Link> mSelf;
            Maybe<Link> mSearch;
            Maybe<Link> mSearchAsYouType;
            Maybe<Link> mSearchMovies;
            Maybe<Link> mFilterMoviesByAgeGroups;
            Maybe<Link> mSearchSeries;
            Maybe<Link> mFilterSeriesByAgeGroups;
            Maybe<Link> mSearchBundles;
            Maybe<Link> mAllPublicUserLists;
            Maybe<DeviceAuthData> mDeviceAuthData;
            Maybe<STRING_T> mApiVersion;
            Maybe<STRING_T> mApiDocumentationLink;
            Maybe<Crud> mManageFreePages;
            Maybe<Link> mSearchMoviesByPerson;
            Maybe<Link> mCreateMppSession;
            Maybe<Link> mMppUserExists;
            Maybe<Link> mAllLists;
        };
    }
}
#endif //READY4AIR_DEVICE_H

#ifndef READY4AIR_DISPLAY_H
#define READY4AIR_DISPLAY_H
namespace ready4air
{
    namespace dto
    {
        class Display : public JsonDeserializable
        {
        public:
            Display()
            {
            }
            virtual ~Display()
            {
            }
            const Maybe <STRING_T> &GetTitle() const
            {
                return mTitle;
            }
            void SetTitle(const STRING_T &title)
            {
                mTitle = title;
            }
            const Maybe <STRING_T> &GetMessage() const
            {
                return mMessage;
            }
            void SetMessage(const STRING_T &message)
            {
                mMessage = message;
            }
            virtual BOOL_T InitFromJsonValue(const rapidjson::Value &value, ParseErrors &parseErrors)
            {
                STRING_T title;
                STRING_T message;
                if (ParseString(value, "Title", true, title, parseErrors))
                    SetTitle(title);
                if (ParseString(value, "Message", true, message, parseErrors))
                    SetMessage(message);
                return !parseErrors;
            }
        private:
            Maybe <STRING_T> mTitle;
            Maybe <STRING_T> mMessage;
        };
    }
}
#endif //READY4AIR_DISPLAY_H

#ifndef READY4AIR_EPISODE_H
#define READY4AIR_EPISODE_H
namespace ready4air
{
    namespace dto
    {
        class Episode : public MediaProduct
        {
        public:
            Episode()
            {
                mProductType = EpisodeProductType;
            }
            virtual ~Episode()
            {
            }
            const Maybe<int> &GetEpisodeNo() const
            {
                return mEpisodeNo;
            }
            void SetEpisodeNo(int episodeNo)
            {
                mEpisodeNo = episodeNo;
            }
            const Maybe<Link> &GetSerie() const
            {
                return mSerie;
            }
            void SetSerie(const Link &serie)
            {
                mSerie = serie;
            }
            const Maybe<Link> &GetSeason() const
            {
                return mSeason;
            }
            void SetSeason(const Link &season)
            {
                mSeason = season;
            }
            const Maybe<int> &GetSeasonNo() const
            {
                return mSeasonNo;
            }
            void SetSeasonNo(int seasonNo)
            {
                mSeasonNo = seasonNo;
            }
            virtual BOOL_T InitFromJsonValue(const rapidjson::Value &value, ParseErrors &parseErrors)
            {
                INT32_T episodeNo;
                Link serie;
                Link season;
                INT32_T seasonNo;
                // Initialize parent properties
                MediaProduct::InitFromJsonValue(value, parseErrors);
                if (ParseInt(value, "EpisodeNo", true, episodeNo, parseErrors))
                    SetEpisodeNo(episodeNo);
                if (ParseObject(value, "Serie", true, serie, parseErrors))
                    SetSerie(serie);
                if (ParseObject(value, "Season", true, season, parseErrors))
                    SetSeason(season);
                if (ParseInt(value, "SeasonNo", true, seasonNo, parseErrors))
                    SetSeasonNo(seasonNo);
                return !parseErrors;
            }
        private:
            Maybe<int> mEpisodeNo;
            Maybe<Link> mSerie;
            Maybe<Link> mSeason;
            Maybe<int> mSeasonNo;
        };
    }
}
#endif //READY4AIR_EPISODE_H

#ifndef READY4AIR_ERROR_H
#define READY4AIR_ERROR_H
namespace ready4air
{
    namespace dto
    {
        class Error : public JsonDeserializable
        {
        public:
            Error()
            {
            }
            virtual ~Error()
            {
            }
            const Maybe<int> &GetCode() const
            {
                return mCode;
            }
            void SetCode(int code)
            {
                mCode = code;
            }
            const Maybe<STRING_T> &GetMessage() const
            {
                return mMessage;
            }
            void SetMessage(const STRING_T &message)
            {
                mMessage = message;
            }
            const Maybe<Display> &GetDisplay() const
            {
                return mDisplay;
            }
            void SetDisplay(const Display &display)
            {
                mDisplay = display;
            }
            virtual BOOL_T InitFromJsonValue(const rapidjson::Value &value, ParseErrors &parseErrors)
            {
                INT32_T code;
                STRING_T message;
                Display display;
                if (ParseInt(value, "Code", true, code, parseErrors))
                    SetCode(code);
                if (ParseString(value, "Message", false, message, parseErrors))
                    SetMessage(message);
                if (ParseObject(value, "Display", false, display, parseErrors))
                    SetDisplay(display);
                return !parseErrors;
            }
        private:
            Maybe<int> mCode;
            Maybe<STRING_T> mMessage;
            Maybe<Display> mDisplay;
        };
    }
}
#endif //READY4AIR_ERROR_H

#ifndef READY4AIR_ERRORFORM_H
#define READY4AIR_ERRORFORM_H
namespace ready4air
{
    namespace dto
    {
        class ErrorForm : public JsonDeserializable
        {
        public:
            ErrorForm()
            {
            }
            virtual ~ErrorForm()
            {
            }
            const Maybe<Form> &GetForm() const
            {
                return mForm;
            }
            void SetForm(const Form &form)
            {
                mForm = form;
            }
            const Maybe<STRING_T> &GetMessage() const
            {
                return mMessage;
            }
            void SetMessage(const STRING_T &message)
            {
                mMessage = message;
            }
            virtual BOOL_T InitFromJsonValue(const rapidjson::Value &value, ParseErrors &parseErrors)
            {
                Form form;
                STRING_T message;
                if (ParseObject(value, "Form", true, form, parseErrors))
                    SetForm(form);
                if (ParseString(value, "Message", false, message, parseErrors))
                    SetMessage(message);
                return !parseErrors;
            }
        private:
            Maybe<Form> mForm;
            Maybe<STRING_T> mMessage;
        };
    }
}
#endif //READY4AIR_ERRORFORM_H

#ifndef READY4AIR_FREEPAGE_H
#define READY4AIR_FREEPAGE_H
namespace ready4air
{
    namespace dto
    {
        class FreePage : public JsonDeserializable
        {
        public:
            FreePage()
            {
            }
            virtual ~FreePage()
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
            const Maybe <STRING_T> &GetName() const
            {
                return mName;
            }
            void SetName(const STRING_T &name)
            {
                mName = name;
            }
            const Maybe <STRING_T> &GetLanguage() const
            {
                return mLanguage;
            }
            void SetLanguage(const STRING_T &language)
            {
                mLanguage = language;
            }
            const Maybe <STRING_T> &GetContent() const
            {
                return mContent;
            }
            void SetContent(const STRING_T &content)
            {
                mContent = content;
            }
            virtual BOOL_T InitFromJsonValue(const rapidjson::Value &value, ParseErrors &parseErrors)
            {
                STRING_T id;
                STRING_T name;
                STRING_T language;
                STRING_T content;
                if (ParseString(value, "Id", true, id, parseErrors))
                    SetId(id);
                if (ParseString(value, "Name", true, name, parseErrors))
                    SetName(name);
                if (ParseString(value, "Language", true, language, parseErrors))
                    SetLanguage(language);
                if (ParseString(value, "Content", true, content, parseErrors))
                    SetContent(content);
                return !parseErrors;
            }
        private:
            Maybe <STRING_T> mId;
            Maybe <STRING_T> mName;
            Maybe <STRING_T> mLanguage;
            Maybe <STRING_T> mContent; // @NOTE: Type of content is client specific, change appropriately.
        };
    }
}
#endif //READY4AIR_FREEPAGE_H

#ifndef READY4AIR_GENERICPAGE_H
#define READY4AIR_GENERICPAGE_H
#include <exception>
namespace ready4air
{
    namespace dto
    {
        template<class T>
        class GenericPage : public JsonDeserializable
        {
        private:
            class BadType : public std::exception
            {
                virtual const INT8_T *what() const throw()
                {
                    return "Template class T must inherit ready4air::JsonDeserializable";
                }
            } mBadType;
        public:
            GenericPage()
            {
                if (!std::is_base_of<IJsonDeserializable, T>::value) throw mBadType;
            }
            virtual ~GenericPage()
            {
            }
            const Maybe <Link> &GetPrev() const
            {
                return mPrev;
            }
            void SetPrev(const Link &prev)
            {
                mPrev = prev;
            }
            const Maybe <Link> &GetNext() const
            {
                return mNext;
            }
            void SetNext(const Link &next)
            {
                mNext = next;
            }
            const Maybe <VECTOR_T<T> > &GetItems() const
            {
                return mItems;
            }
            void SetItems(const VECTOR_T<T> &items)
            {
                mItems = items;
            }
            virtual BOOL_T InitFromJsonValue(const rapidjson::Value &value, ParseErrors &parseErrors)
            {
                Link prev;
                Link next;
                VECTOR_T<T> items;
                if (ParseObject(value, "Prev", false, prev, parseErrors))
                    SetPrev(prev);
                if (ParseObject(value, "Next", false, next, parseErrors))
                    SetNext(next);
                if (VerifyArray(value, "Items", true, parseErrors))
                {
                    for (rapidjson::SizeType i = 0; i < value["Items"].Size(); i += 1)
                    {
                        T item;
                        IJsonDeserializable *abstractItem = &item;
                        if (abstractItem->InitFromJsonValue(value["Items"][i], parseErrors))
//                        if (ParseObject(value["Items"][i], "", false, item, parseErrors))
                            items.push_back(item);
                    }
                    SetItems(items);
                }
                return !parseErrors;
            }
        private:
            Maybe <Link> mPrev;
            Maybe <Link> mNext;
            Maybe <VECTOR_T<T> > mItems;
        };
    }
}
#endif //READY4AIR_GENERICPAGE_H

#ifndef READY4AIR_HELP_H
#define READY4AIR_HELP_H
namespace ready4air
{
    namespace dto
    {
        class Help : public JsonDeserializable
        {
        public:
            Help()
            {
            }
            virtual ~Help()
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
            const Maybe <STRING_T> &GetTitle() const
            {
                return mTitle;
            }
            void SetTitle(const STRING_T &title)
            {
                mTitle = title;
            }
            const Maybe <STRING_T> &GetBody() const
            {
                return mBody;
            }
            void SetBody(const STRING_T &body)
            {
                mBody = body;
            }
            const Maybe <Link> &GetSelf() const
            {
                return mSelf;
            }
            void SetSelf(const Link &self)
            {
                mSelf = self;
            }
            virtual BOOL_T InitFromJsonValue(const rapidjson::Value &value, ParseErrors &parseErrors)
            {
                STRING_T id;
                STRING_T title;
                STRING_T body;
                Link self;
                if (ParseString(value, "Id", true, id, parseErrors))
                    SetId(id);
                if (ParseString(value, "Title", true, title, parseErrors))
                    SetTitle(title);
                if (ParseString(value, "Body", true, body, parseErrors))
                    SetBody(body);
                if (ParseObject(value, "Self", true, self, parseErrors))
                    SetSelf(self);
                return !parseErrors;
            }
        private:
            Maybe <STRING_T> mId;
            Maybe <STRING_T> mTitle;
            Maybe <STRING_T> mBody;
            Maybe <Link> mSelf;
        };
    }
}
#endif //READY4AIR_HELP_H

#ifndef READY4AIR_LANGUAGE_H
#define READY4AIR_LANGUAGE_H
namespace ready4air
{
    namespace dto
    {
        class Language : public JsonDeserializable
        {
        public:
            Language()
            {
            }
            virtual ~Language()
            {
            }
            const Maybe <STRING_T> &GetCode() const
            {
                return mCode;
            }
            void SetCode(const STRING_T &code)
            {
                mCode = code;
            }
            const Maybe <STRING_T> &GetISO6391Code() const
            {
                return mISO6391Code;
            }
            void SetISO6391Code(const STRING_T &ISO6391Code)
            {
                mISO6391Code = ISO6391Code;
            }
            const Maybe <STRING_T> &GetISO6392Code() const
            {
                return mISO6392Code;
            }
            void SetISO6392Code(const STRING_T &ISO6392Code)
            {
                mISO6392Code = ISO6392Code;
            }
            const Maybe <STRING_T> &GetEnglishName() const
            {
                return mEnglishName;
            }
            void SetEnglishName(const STRING_T &englishName)
            {
                mEnglishName = englishName;
            }
            virtual BOOL_T InitFromJsonValue(const rapidjson::Value &value, ParseErrors &parseErrors)
            {
                STRING_T code;
                STRING_T iso6391Code;
                STRING_T iso6392Code;
                STRING_T englishName;
                if (ParseString(value, "Code", true, code, parseErrors))
                    SetCode(code);
                if (ParseString(value, "ISO6391Code", true, iso6391Code, parseErrors))
                    SetISO6391Code(iso6391Code);
                if (ParseString(value, "ISO6392Code", true, iso6392Code, parseErrors))
                    SetISO6392Code(iso6392Code);
                if (ParseString(value, "EnglishName", true, englishName, parseErrors))
                    SetEnglishName(englishName);
                return !parseErrors;
            }
        private:
            Maybe <STRING_T> mCode;
            Maybe <STRING_T> mISO6391Code;
            Maybe <STRING_T> mISO6392Code;
            Maybe <STRING_T> mEnglishName;
        };
    }
}
#endif //READY4AIR_LANGUAGE_H

#ifndef READY4AIR_LANGUAGELIST_H
#define READY4AIR_LANGUAGELIST_H
namespace ready4air
{
    namespace dto
    {
        class LanguageList : public JsonDeserializable
        {
        public:
            LanguageList()
            {
            }
            virtual ~LanguageList()
            {
            }
            const Maybe<Language> &GetLanguage() const
            {
                return mLanguage;
            }
            void SetLanguage(const Language &language)
            {
                mLanguage = language;
            }
            const Maybe<STRING_T> &GetName() const
            {
                return mName;
            }
            void SetName(const STRING_T &name)
            {
                mName = name;
            }
            const Maybe<STRING_T> &GetDescription() const
            {
                return mDescription;
            }
            void SetDescription(const STRING_T &description)
            {
                mDescription = description;
            }
            const Maybe<BOOL_T> &IsGenre() const
            {
                return mIsGenre;
            }
            void SetIsGenre(BOOL_T isGenre)
            {
                mIsGenre = isGenre;
            }
            virtual BOOL_T InitFromJsonValue(const rapidjson::Value &value, ParseErrors &parseErrors)
            {
                Language language;
                STRING_T name;
                STRING_T description;
                BOOL_T isGenre;
                if (ParseObject(value, "Language", true, language, parseErrors))
                    SetLanguage(language);
                if (ParseString(value, "Name", true, name, parseErrors))
                    SetName(name);
                if (ParseString(value, "Description", true, description, parseErrors))
                    SetDescription(description);
                if (ParseBool(value, "IsGenre", true, isGenre, parseErrors))
                    SetIsGenre(isGenre);
                return !parseErrors;
            }
        private:
            Maybe<Language> mLanguage;
            Maybe<STRING_T> mName;
            Maybe<STRING_T> mDescription;
            Maybe<BOOL_T> mIsGenre;
        };
    }
}
#endif //READY4AIR_LANGUAGELIST_H

#ifndef READY4AIR_LISTMEDIA_H
#define READY4AIR_LISTMEDIA_H
namespace ready4air
{
    namespace dto
    {
        class ListMedia : public JsonDeserializable
        {
        public:
            ListMedia()
            {
            }
            virtual ~ListMedia()
            {
            }
            const Maybe<int> &GetDeviceVersion() const
            {
                return mDeviceVersion;
            }
            void SetDeviceVersion(int deviceVersion)
            {
                mDeviceVersion = deviceVersion;
            }
            const Maybe <STRING_T> &GetCountryCode() const
            {
                return mCountryCode;
            }
            void SetCountryCode(const STRING_T &countryCode)
            {
                mCountryCode = countryCode;
            }
            const Maybe<int> &GetMediaId() const
            {
                return mMediaId;
            }
            void SetMediaId(int mediaId)
            {
                mMediaId = mediaId;
            }
            const Maybe <STRING_T> &GetCurrencyCode() const
            {
                return mCurrencyCode;
            }
            void SetCurrencyCode(const STRING_T &currencyCode)
            {
                mCurrencyCode = currencyCode;
            }
            const Maybe<BOOL_T> &IsMainList() const
            {
                return mIsMainList;
            }
            void SetIsMainList(BOOL_T isMainList)
            {
                mIsMainList = isMainList;
            }
            const Maybe<DOUBLE_T> &GetPrice() const
            {
                return mPrice;
            }
            void SetPrice(DOUBLE_T price)
            {
                mPrice = price;
            }
            const Maybe<int> &GetListOrder() const
            {
                return mListOrder;
            }
            void SetListOrder(int listOrder)
            {
                mListOrder = listOrder;
            }
            virtual BOOL_T InitFromJsonValue(const rapidjson::Value &value, ParseErrors &parseErrors)
            {
                INT32_T deviceVersion;
                STRING_T countryCode;
                INT32_T mediaId;
                STRING_T currencyCode;
                BOOL_T isMainList;
                DOUBLE_T price;
                INT32_T listOrder;
                if (ParseInt(value, "DeviceVersion", true, deviceVersion, parseErrors))
                    SetDeviceVersion(deviceVersion);
                if (ParseString(value, "CountryCode", true, countryCode, parseErrors))
                    SetCountryCode(countryCode);
                if (ParseInt(value, "MediaId", true, mediaId, parseErrors))
                    SetDeviceVersion(mediaId);
                if (ParseString(value, "CurrencyCode", true, currencyCode, parseErrors))
                    SetCurrencyCode(currencyCode);
                if (ParseBool(value, "IsMainList", true, isMainList, parseErrors))
                    SetIsMainList(isMainList);
                if (ParseDouble(value, "Price", true, price, parseErrors))
                    SetPrice(price);
                if (ParseInt(value, "ListOrder", true, listOrder, parseErrors))
                    SetListOrder(listOrder);
                return !parseErrors;
            }
        private:
            Maybe<int> mDeviceVersion;
            Maybe <STRING_T> mCountryCode;
            Maybe<int> mMediaId;
            Maybe <STRING_T> mCurrencyCode;
            Maybe<BOOL_T> mIsMainList;
            Maybe<DOUBLE_T> mPrice;
            Maybe<int> mListOrder;
        };
    }
}
#endif //READY4AIR_LISTMEDIA_H

#ifndef READY4AIR_LIST_H
#define READY4AIR_LIST_H
namespace ready4air
{
    namespace dto
    {
        class List : public JsonDeserializable
        {
        public:
            List()
            {
            }
            virtual ~List()
            {
            }
            const Maybe<int> &GetListId() const
            {
                return mListId;
            }
            void SetListId(int listId)
            {
                mListId = listId;
            }
            const Maybe<int> &GetListType() const
            {
                return mListType;
            }
            void SetListType(int listType)
            {
                mListType = listType;
            }
            const Maybe<STRING_T> &GetName() const
            {
                return mName;
            }
            void SetName(const STRING_T &name)
            {
                mName = name;
            }
            const Maybe<BOOL_T> &IsGenre() const
            {
                return mIsGenre;
            }
            void SetIsGenre(BOOL_T isGenre)
            {
                mIsGenre = isGenre;
            }
            const Maybe<STRING_T> &GetDescription() const
            {
                return mDescription;
            }
            void SetDescription(const STRING_T &description)
            {
                mDescription = description;
            }
            const Maybe<VECTOR_T<Image> > &GetImages() const
            {
                return mImages;
            }
            void SetImages(const VECTOR_T<Image> &images)
            {
                mImages = images;
            }
            const Maybe<MAP_T<STRING_T, STRING_T> > &GetCustom() const
            {
                return mCustom;
            }
            void SetCustom(const MAP_T<STRING_T, STRING_T> &custom)
            {
                mCustom = custom;
            }
            const Maybe<VECTOR_T<LanguageList> > &GetLanguageLists() const
            {
                return mLanguageLists;
            }
            void SetLanguageLists(const VECTOR_T<LanguageList> &languageLists)
            {
                mLanguageLists = languageLists;
            }
            const Maybe<VECTOR_T<ListMedia> > &GetListMedias() const
            {
                return mListMedias;
            }
            void SetListMedias(const VECTOR_T<ListMedia> &listMedias)
            {
                mListMedias = listMedias;
            }
            const Maybe<Link> &GetItems() const
            {
                return mItems;
            }
            void SetItems(const Link &items)
            {
                mItems = items;
            }
            virtual BOOL_T InitFromJsonValue(const rapidjson::Value &value, ParseErrors &parseErrors)
            {
                INT32_T listId;
                INT32_T listType;
                STRING_T name;
                BOOL_T isGenre;
                STRING_T description;
                VECTOR_T<Image> images;
                MAP_T<STRING_T, STRING_T> custom;
                VECTOR_T<LanguageList> languageLists;
                VECTOR_T<ListMedia> listMedias;
                Link items;
                if (ParseInt(value, "ListId", true, listId, parseErrors))
                    SetListId(listId);
                if (ParseInt(value, "ListType", true, listType, parseErrors))
                    SetListType(listType);
                if (ParseString(value, "Name", true, name, parseErrors))
                    SetName(name);
                if (ParseBool(value, "IsGenre", true, isGenre, parseErrors))
                    SetIsGenre(isGenre);
                if (ParseString(value, "Description", false, description, parseErrors))
                    SetDescription(description);
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
                if (VerifyObject(value, "Custom", false, parseErrors))
                {
                    for (rapidjson::Value::ConstMemberIterator itr = value["Custom"].MemberBegin();
                         itr != value["Custom"].MemberEnd(); ++itr)
                    {
                        STRING_T customValue;
                        if (ParseString(itr->value, "", false, customValue, parseErrors))
                            custom[itr->name.GetString()] = customValue;
                    }
                    SetCustom(custom);
                }
                if (VerifyArray(value, "LanguageLists", false, parseErrors))
                {
                    for (rapidjson::SizeType i = 0; i < value["LanguageLists"].Size(); i += 1)
                    {
                        LanguageList languageList;
                        if (ParseObject(value["LanguageLists"][i], "", false, languageList, parseErrors))
                            languageLists.push_back(languageList);
                    }
                    SetLanguageLists(languageLists);
                }
                if (VerifyArray(value, "ListMedias", false, parseErrors))
                {
                    for (rapidjson::SizeType i = 0; i < value["ListMedias"].Size(); i += 1)
                    {
                        ListMedia listMedia;
                        if (ParseObject(value["ListMedias"][i], "", false, listMedia, parseErrors))
                            listMedias.push_back(listMedia);
                    }
                    SetListMedias(listMedias);
                }
                if (ParseObject(value, "Items", true, items, parseErrors))
                    SetItems(items);
                return !parseErrors;
            }
        private:
            Maybe<int> mListId;
            Maybe<int> mListType;
            Maybe<STRING_T> mName;
            Maybe<BOOL_T> mIsGenre;
            Maybe<STRING_T> mDescription;
            Maybe<VECTOR_T<Image> > mImages;
            Maybe<MAP_T<STRING_T, STRING_T> > mCustom;
            Maybe<VECTOR_T<LanguageList> > mLanguageLists;
            Maybe<VECTOR_T<ListMedia> > mListMedias;
            Maybe<Link> mItems;
        };
    }
}
#endif //READY4AIR_LIST_H

#ifndef READY4AIR_LITERAL_H
#define READY4AIR_LITERAL_H
namespace ready4air
{
    namespace dto
    {
        class Literal : public JsonDeserializable
        {
        public:
            Literal()
            {
            }
            virtual ~Literal()
            {
            }
            const Maybe <STRING_T> &GetKey() const
            {
                return mKey;
            }
            void SetKey(const STRING_T &key)
            {
                mKey = key;
            }
            const Maybe <STRING_T> &GetValue() const
            {
                return mValue;
            }
            void SetValue(const STRING_T &value)
            {
                mValue = value;
            }
            const Maybe <STRING_T> &GetLanguage() const
            {
                return mLanguage;
            }
            void SetLanguage(const STRING_T &language)
            {
                mLanguage = language;
            }
            const Maybe <Link> &GetSelf() const
            {
                return mSelf;
            }
            void SetSelf(const Link &self)
            {
                mSelf = self;
            }
            virtual BOOL_T InitFromJsonValue(const rapidjson::Value &value, ParseErrors &parseErrors)
            {
                STRING_T key;
                STRING_T val;
                STRING_T language;
                Link self;
                if (ParseString(value, "Key", true, key, parseErrors))
                    SetKey(key);
                if (ParseString(value, "Value", true, val, parseErrors))
                    SetValue(val);
                if (ParseString(value, "Language", true, language, parseErrors))
                    SetLanguage(language);
                if (ParseObject(value, "Self", true, self, parseErrors))
                    SetSelf(self);
                return !parseErrors;
            }
        private:
            Maybe <STRING_T> mKey;
            Maybe <STRING_T> mValue;
            Maybe <STRING_T> mLanguage;
            Maybe <Link> mSelf;
        };
    }
}
#endif //READY4AIR_LITERAL_H

#ifndef READY4AIR_MOVIE_H
#define READY4AIR_MOVIE_H
namespace ready4air
{
    namespace dto
    {
        class Movie : public MediaProduct
        {
        public:
            Movie()
            {
                mProductType = MovieProductType;
            }
            virtual ~Movie()
            {
            }
        };
    }
}
#endif //READY4AIR_MOVIE_H

#ifndef READY4AIR_PAGE_H
#define READY4AIR_PAGE_H
namespace ready4air
{
    namespace dto
    {
        class Page : public JsonDeserializable
        {
        public:
            Page()
            {
            }
            virtual ~Page()
            {
            }
            const Maybe<STRING_T> &GetID() const
            {
                return mID;
            }
            void SetID(const STRING_T &ID)
            {
                mID = ID;
            }
            const Maybe<STRING_T> &GetTitle() const
            {
                return mTitle;
            }
            void SetTitle(const STRING_T &title)
            {
                mTitle = title;
            }
            const Maybe<STRING_T> &GetDescription() const
            {
                return mDescription;
            }
            void SetDescription(const STRING_T &description)
            {
                mDescription = description;
            }
            const Maybe<STRING_T> &GetVmaMessage() const
            {
                return mVmaMessage;
            }
            void SetVmaMessage(const STRING_T &vmaMessage)
            {
                mVmaMessage = vmaMessage;
            }
            const Maybe<STRING_T> &GetType() const
            {
                return mType;
            }
            void SetType(const STRING_T &type)
            {
                mType = type;
            }
            const Maybe<Content> &GetContent() const
            {
                return mContent;
            }
            void SetContent(const Content &content)
            {
                mContent = content;
            }
            const Maybe<Link> &GetSelf() const
            {
                return mSelf;
            }
            void SetSelf(const Link &self)
            {
                mSelf = self;
            }
            virtual BOOL_T InitFromJsonValue(const rapidjson::Value &value, ParseErrors &parseErrors)
            {
                STRING_T id;
                STRING_T title;
                STRING_T description;
                STRING_T vmaMessage;
                STRING_T type;
                Content content;
                Link self;
                if (ParseString(value, "ID", true, id, parseErrors))
                    SetID(id);
                if (ParseString(value, "Title", false, title, parseErrors))
                    SetTitle(title);
                if (ParseString(value, "Description", false, description, parseErrors))
                    SetDescription(description);
                if (ParseString(value, "VmaMessage", false, vmaMessage, parseErrors))
                    SetVmaMessage(vmaMessage);
                if (ParseString(value, "Type", false, type, parseErrors))
                    SetType(type);
                if (ParseObject(value, "Content", true, content, parseErrors))
                    SetContent(content);
                if (ParseObject(value, "Self", true, self, parseErrors))
                    SetSelf(self);
                return !parseErrors;
            }
        private:
            Maybe<STRING_T> mID;
            Maybe<STRING_T> mTitle;
            Maybe<STRING_T> mDescription;
            Maybe<STRING_T> mVmaMessage;
            Maybe<STRING_T> mType;
            Maybe<Content> mContent;
            Maybe<Link> mSelf;
        };
    }
}
#endif //READY4AIR_PAGE_H

#ifndef READY4AIR_SEASONPRODUCT_H
#define READY4AIR_SEASONPRODUCT_H
namespace ready4air
{
    namespace dto
    {
        class SeasonProduct : public JsonDeserializable
        {
        public:
            SeasonProduct()
            {
                mProductType = SeasonProductType;
            }
            virtual ~SeasonProduct()
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
            const Maybe <ProductType> &GetProductType() const
            {
                return mProductType;
            }
            void SetProductType(const ProductType &productType)
            {
                mProductType = productType;
            }
            const Maybe<DOUBLE_T> &GetPrice() const
            {
                return mPrice;
            }
            void SetPrice(DOUBLE_T price)
            {
                mPrice = price;
            }
            const Maybe <STRING_T> &GetCurrency() const
            {
                return mCurrency;
            }
            void SetCurrency(const STRING_T &currency)
            {
                mCurrency = currency;
            }
            const Maybe <STRING_T> &GetStrPrice() const
            {
                return mStrPrice;
            }
            void SetStrPrice(const STRING_T &strPrice)
            {
                mStrPrice = strPrice;
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
            const Maybe <VECTOR_T<Entitlement> > &GetEntitlements() const
            {
                return mEntitlements;
            }
            void SetEntitlements(const VECTOR_T<Entitlement> &entitlements)
            {
                mEntitlements = entitlements;
            }
            const Maybe <Form> &GetPurchase() const
            {
                return mPurchase;
            }
            void SetPurchase(const Form &purchase)
            {
                mPurchase = purchase;
            }
            const Maybe <VECTOR_T<PurchaseItem> > &GetPurchaseItems() const
            {
                return mPurchaseItems;
            }
            void SetPurchaseItems(const VECTOR_T<PurchaseItem> &purchaseItems)
            {
                mPurchaseItems = purchaseItems;
            }
            virtual BOOL_T InitFromJsonValue(const rapidjson::Value &value, ParseErrors &parseErrors)
            {
                INT32_T productId;
                DOUBLE_T price;
                STRING_T currency;
                STRING_T strPrice;
                BOOL_T hd;
                BOOL_T dubbed;
                VECTOR_T<Entitlement> entitlements;
                Form purchase;
                VECTOR_T<PurchaseItem> purchaseItems;
                if (ParseInt(value, "ProductId", false, productId, parseErrors))
                    SetProductId(productId);
                if (ParseDouble(value, "Price", false, price, parseErrors))
                    SetPrice(price);
                if (ParseString(value, "Currency", false, currency, parseErrors))
                    SetCurrency(currency);
                if (ParseString(value, "StrPrice", false, strPrice, parseErrors))
                    SetStrPrice(strPrice);
                if (ParseBool(value, "HD", false, hd, parseErrors))
                    SetHD(hd);
                if (ParseBool(value, "Dubbed", false, dubbed, parseErrors))
                    SetDubbed(dubbed);
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
                if (ParseObject(value, "Purchase", false, purchase, parseErrors))
                    SetPurchase(purchase);
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
                return !parseErrors;
            }
        private:
            Maybe<int> mProductId;
            Maybe <ProductType> mProductType;
            Maybe<DOUBLE_T> mPrice;
            Maybe <STRING_T> mCurrency;
            Maybe <STRING_T> mStrPrice;
            Maybe<BOOL_T> mHD;
            Maybe<BOOL_T> mDubbed;
            Maybe <VECTOR_T<Entitlement> > mEntitlements;
            Maybe <Form> mPurchase;
            Maybe <VECTOR_T<PurchaseItem> > mPurchaseItems;
        };
    }
}
#endif //READY4AIR_SEASONPRODUCT_H

#ifndef READY4AIR_SEASON_H
#define READY4AIR_SEASON_H
namespace ready4air
{
    namespace dto
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
            virtual BOOL_T InitFromJsonValue(const rapidjson::Value &value, ParseErrors &parseErrors)
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
                    SetYear((INT16_T) year);
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
        };
    }
}
#endif //READY4AIR_SEASON_H

#ifndef READY4AIR_SERIES_H
#define READY4AIR_SERIES_H
namespace ready4air
{
    namespace dto
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
            const Maybe <VECTOR_T<STRING_T> > &GetAgeGroups() const
            {
                return mAgeGroups;
            }
            void SetAgeGroups(const VECTOR_T<STRING_T> &ageGroups)
            {
                mAgeGroups = ageGroups;
            }
            const Maybe <VECTOR_T<Image> > &GetImages() const
            {
                return mImages;
            }
            void SetImages(const VECTOR_T<Image> &images)
            {
                mImages = images;
            }
            const Maybe <VECTOR_T<Cast> > &GetCasts() const
            {
                return mCasts;
            }
            void SetCasts(const VECTOR_T<Cast> &casts)
            {
                mCasts = casts;
            }
            const Maybe <VECTOR_T<Genre> > &GetGenres() const
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
            virtual BOOL_T InitFromJsonValue(const rapidjson::Value &value, ParseErrors &parseErrors)
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
                    SetMinYear((INT16_T) minYear);
                if (ParseInt(value, "MaxYear", true, maxYear, parseErrors))
                    SetMaxYear((INT16_T) maxYear);
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
                        STRING_T ageGroup;
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
            Maybe <VECTOR_T<STRING_T> > mAgeGroups;
            Maybe <VECTOR_T<Image> > mImages;
            Maybe <VECTOR_T<Cast> > mCasts;
            Maybe <VECTOR_T<Genre> > mGenres;
            Maybe <Form> mPurchaseFirstEpisode;
            Maybe <STRING_T> mModified;
            Maybe <Link> mSeasons;
            Maybe <Link> mSelf;
        };
    }
}
#endif //READY4AIR_SERIES_H

#ifndef READY4AIR_USERLISTITEM_H
#define READY4AIR_USERLISTITEM_H
namespace ready4air
{
    namespace dto
    {
        class UserListItem : public JsonDeserializable
        {
        public:
            UserListItem()
            {
            }
            virtual ~UserListItem()
            {
            }
            const Maybe<int> &GetPosition() const
            {
                return mPosition;
            }
            void SetPosition(int position)
            {
                mPosition = position;
            }
            const Maybe <STRING_T> &GetContentId() const
            {
                return mContentId;
            }
            void SetContentId(const STRING_T &contentId)
            {
                mContentId = contentId;
            }
            virtual BOOL_T InitFromJsonValue(const rapidjson::Value &value, ParseErrors &parseErrors)
            {
                INT32_T position;
                STRING_T contentId;
                if (ParseInt(value, "Position", true, position, parseErrors))
                    SetPosition(position);
                if (ParseString(value, "ContentId", true, contentId, parseErrors))
                    SetContentId(contentId);
                return !parseErrors;
            }
        private:
            Maybe<int> mPosition;
            Maybe <STRING_T> mContentId;
        };
    }
}
#endif //READY4AIR_USERLISTITEM_H

#ifndef READY4AIR_USERLIST_H
#define READY4AIR_USERLIST_H
namespace ready4air
{
    namespace dto
    {
        class UserList : public JsonDeserializable
        {
        public:
            UserList()
            {
            }
            virtual ~UserList()
            {
            }
            const Maybe<STRING_T> &GetId() const
            {
                return mId;
            }
            void SetId(const STRING_T &id)
            {
                mId = id;
            }
            const Maybe<STRING_T> &GetName() const
            {
                return mName;
            }
            void SetName(const STRING_T &name)
            {
                mName = name;
            }
            const Maybe<BOOL_T> &IsPublic() const
            {
                return mPublic;
            }
            void SetPublic(BOOL_T aPublic)
            {
                mPublic = aPublic;
            }
            const Maybe<STRING_T> &GetOwner() const
            {
                return mOwner;
            }
            void SetOwner(const STRING_T &owner)
            {
                mOwner = owner;
            }
            const Maybe<int> &GetType() const
            {
                return mType;
            }
            void SetType(int type)
            {
                mType = type;
            }
            const Maybe<STRING_T> &GetListType() const
            {
                return mListType;
            }
            void SetListType(const STRING_T &listType)
            {
                mListType = listType;
            }
            const Maybe<Form> &GetAddItems() const
            {
                return mAddItems;
            }
            void SetAddItems(const Form &addItems)
            {
                mAddItems = addItems;
            }
            const Maybe<Form> &GetItemPosition() const
            {
                return mItemPosition;
            }
            void SetItemPosition(const Form &itemPosition)
            {
                mItemPosition = itemPosition;
            }
            const Maybe<Form> &GetRemoveItems() const
            {
                return mRemoveItems;
            }
            void SetRemoveItems(const Form &removeItems)
            {
                mRemoveItems = removeItems;
            }
            const Maybe<Link> &GetItems() const
            {
                return mItems;
            }
            void SetItems(const Link &items)
            {
                mItems = items;
            }
            const Maybe<VECTOR_T<UserListItem> > &GetExposedItems() const
            {
                return mExposedItems;
            }
            void SetExposedItems(const VECTOR_T<UserListItem> &exposedItems)
            {
                mExposedItems = exposedItems;
            }
            const Maybe<STRING_T> &GetUserId() const
            {
                return mUserId;
            }
            void SetUserId(const STRING_T &userId)
            {
                mUserId = userId;
            }
            const Maybe<STRING_T> &GetDeviceId() const
            {
                return mDeviceId;
            }
            void SetDeviceId(const STRING_T &deviceId)
            {
                mDeviceId = deviceId;
            }
            virtual BOOL_T InitFromJsonValue(const rapidjson::Value &value, ParseErrors &parseErrors)
            {
                STRING_T id;
                STRING_T name;
                BOOL_T aPublic;
                STRING_T owner;
                INT32_T type;
                STRING_T listType;
                Form addItems;
                Form itemPosition;
                Form removeItems;
                Link items;
                VECTOR_T<UserListItem> exposedItems;
                STRING_T userId;
                STRING_T deviceId;
                if (ParseString(value, "Id", true, id, parseErrors))
                    SetId(id);
                if (ParseString(value, "Name", true, name, parseErrors))
                    SetName(name);
                if (ParseBool(value, "Public", true, aPublic, parseErrors))
                    SetPublic(aPublic);
                if (ParseString(value, "Owner", true, owner, parseErrors))
                    SetOwner(owner);
                if (ParseInt(value, "Type", true, type, parseErrors))
                    SetType(type);
                if (ParseString(value, "ListType", true, listType, parseErrors))
                    SetListType(listType);
                if (ParseObject(value, "AddItems", false, addItems, parseErrors))
                    SetAddItems(addItems);
                if (ParseObject(value, "ItemPosition", false, itemPosition, parseErrors))
                    SetItemPosition(itemPosition);
                if (ParseObject(value, "RemoveItems", false, removeItems, parseErrors))
                    SetRemoveItems(removeItems);
                if (ParseObject(value, "Items", false, items, parseErrors))
                    SetItems(items);
                if (VerifyArray(value, "ExposedItems", false, parseErrors))
                {
                    for (rapidjson::SizeType i = 0; i < value["ExposedItems"].Size(); i += 1)
                    {
                        UserListItem userListItem;
                        if (ParseObject(value["ExposedItems"][i], "", false, userListItem, parseErrors))
                            exposedItems.push_back(userListItem);
                    }
                    SetExposedItems(exposedItems);
                }
                if (ParseString(value, "UserId", false, userId, parseErrors))
                    SetUserId(userId);
                if (ParseString(value, "DeviceId", false, deviceId, parseErrors))
                    SetDeviceId(deviceId);
                return !parseErrors;
            }
        private:
            Maybe<STRING_T> mId;
            Maybe<STRING_T> mName;
            Maybe<BOOL_T> mPublic;
            Maybe<STRING_T> mOwner;
            Maybe<int> mType;
            Maybe<STRING_T> mListType;
            Maybe<Form> mAddItems;
            Maybe<Form> mItemPosition;
            Maybe<Form> mRemoveItems;
            Maybe<Link> mItems;
            Maybe<VECTOR_T<UserListItem> > mExposedItems;
            Maybe<STRING_T> mUserId;
            Maybe<STRING_T> mDeviceId;
        };
    }
}
#endif //READY4AIR_USERLIST_H

#ifndef READY4AIR_USERFAVOURITELISTS_H
#define READY4AIR_USERFAVOURITELISTS_H
namespace ready4air
{
    namespace dto
    {
        class UserFavouriteLists : public JsonDeserializable
        {
        public:
            UserFavouriteLists()
            {
            }
            virtual ~UserFavouriteLists()
            {
            }
            const Maybe <Form> &GetAddLists() const
            {
                return mAddLists;
            }
            void SetAddLists(const Form &addLists)
            {
                mAddLists = addLists;
            }
            const Maybe <Form> &GetListPosition() const
            {
                return mListPosition;
            }
            void SetListPosition(const Form &listPosition)
            {
                mListPosition = listPosition;
            }
            const Maybe <Form> &GetRemoveLists() const
            {
                return mRemoveLists;
            }
            void SetRemoveLists(const Form &removeLists)
            {
                mRemoveLists = removeLists;
            }
            const Maybe <Link> &GetLists() const
            {
                return mLists;
            }
            void SetLists(const Link &lists)
            {
                mLists = lists;
            }
            const Maybe <VECTOR_T<STRING_T> > &GetExposedItems() const
            {
                return mExposedItems;
            }
            void SetExposedItems(const VECTOR_T<STRING_T> &exposedItems)
            {
                mExposedItems = exposedItems;
            }
            virtual BOOL_T InitFromJsonValue(const rapidjson::Value &value, ParseErrors &parseErrors)
            {
                Form addLists;
                Form listPosition;
                Form removeLists;
                Link lists;
                VECTOR_T<STRING_T> exposedItems;
                if (ParseObject(value, "AddLists", true, addLists, parseErrors))
                    SetAddLists(addLists);
                if (ParseObject(value, "ListPosition", true, listPosition, parseErrors))
                    SetListPosition(listPosition);
                if (ParseObject(value, "RemoveLists", true, removeLists, parseErrors))
                    SetRemoveLists(removeLists);
                if (ParseObject(value, "Lists", false, lists, parseErrors))
                    SetLists(lists);
                if (VerifyArray(value, "ExposedItems", false, parseErrors))
                {
                    for (rapidjson::SizeType i = 0; i < value["ExposedItems"].Size(); i += 1)
                    {
                        STRING_T exposedItem;
                        if (ParseString(value["ExposedItems"][i], "", false, exposedItem, parseErrors))
                            exposedItems.push_back(exposedItem);
                    }
                    SetExposedItems(exposedItems);
                }
                return !parseErrors;
            }
        private:
            Maybe <Form> mAddLists;
            Maybe <Form> mListPosition;
            Maybe <Form> mRemoveLists;
            Maybe <Link> mLists;
            Maybe <VECTOR_T<STRING_T> > mExposedItems;
        };
    }
}
#endif //READY4AIR_USERFAVOURITELISTS_H

#ifndef READY4AIR_USER_H
#define READY4AIR_USER_H
namespace ready4air
{
    namespace dto
    {
        class User : public JsonDeserializable
        {
        public:
            User()
            {
            }
            virtual ~User()
            {
            }
            const Maybe<STRING_T> &GetID() const
            {
                return mID;
            }
            void SetID(const STRING_T &ID)
            {
                mID = ID;
            }
            const Maybe<STRING_T> &GetAddress() const
            {
                return mAddress;
            }
            void SetAddress(const STRING_T &address)
            {
                mAddress = address;
            }
            const Maybe<STRING_T> &GetCClastfour() const
            {
                return mCClastfour;
            }
            void SetCClastfour(const STRING_T &CClastfour)
            {
                mCClastfour = CClastfour;
            }
            const Maybe<STRING_T> &GetCCreference() const
            {
                return mCCreference;
            }
            void SetCCreference(const STRING_T &CCreference)
            {
                mCCreference = CCreference;
            }
            const Maybe<BOOL_T> &IsCCvalid() const
            {
                return mCCvalid;
            }
            void SetCCvalid(BOOL_T CCvalid)
            {
                mCCvalid = CCvalid;
            }
            const Maybe<STRING_T> &GetCity() const
            {
                return mCity;
            }
            void SetCity(const STRING_T &city)
            {
                mCity = city;
            }
            const Maybe<STRING_T> &GetCountry() const
            {
                return mCountry;
            }
            void SetCountry(const STRING_T &country)
            {
                mCountry = country;
            }
            const Maybe<STRING_T> &GetEmail() const
            {
                return mEmail;
            }
            void SetEmail(const STRING_T &email)
            {
                mEmail = email;
            }
            const Maybe<STRING_T> &GetFirstName() const
            {
                return mFirstName;
            }
            void SetFirstName(const STRING_T &firstName)
            {
                mFirstName = firstName;
            }
            const Maybe<STRING_T> &GetLastName() const
            {
                return mLastName;
            }
            void SetLastName(const STRING_T &lastName)
            {
                mLastName = lastName;
            }
            const Maybe<STRING_T> &GetLastUsedDeviceId() const
            {
                return mLastUsedDeviceId;
            }
            void SetLastUsedDeviceId(const STRING_T &lastUsedDeviceId)
            {
                mLastUsedDeviceId = lastUsedDeviceId;
            }
            const Maybe<STRING_T> &GetMobile() const
            {
                return mMobile;
            }
            void SetMobile(const STRING_T &mobile)
            {
                mMobile = mobile;
            }
            const Maybe<int> &GetNumberOfLogins() const
            {
                return mNumberOfLogins;
            }
            void SetNumberOfLogins(int numberOfLogins)
            {
                mNumberOfLogins = numberOfLogins;
            }
            const Maybe<STRING_T> &GetPostalCode() const
            {
                return mPostalCode;
            }
            void SetPostalCode(const STRING_T &postalCode)
            {
                mPostalCode = postalCode;
            }
            const Maybe<STRING_T> &GetRegistrationDate() const
            {
                return mRegistrationDate;
            }
            void SetRegistrationDate(const STRING_T &registrationDate)
            {
                mRegistrationDate = registrationDate;
            }
            const Maybe<STRING_T> &GetUserName() const
            {
                return mUserName;
            }
            void SetUserName(const STRING_T &userName)
            {
                mUserName = userName;
            }
            const Maybe<STRING_T> &GetMppToken() const
            {
                return mMppToken;
            }
            void SetMppToken(const STRING_T &mppToken)
            {
                mMppToken = mppToken;
            }
            const Maybe<UserList> &GetMyMoviesList() const
            {
                return mMyMoviesList;
            }
            void SetMyMoviesList(const UserList &myMoviesList)
            {
                mMyMoviesList = myMoviesList;
            }
            const Maybe<UserList> &GetMyWishList() const
            {
                return mMyWishList;
            }
            void SetMyWishList(const UserList &myWishList)
            {
                mMyWishList = myWishList;
            }
            const Maybe<VECTOR_T<STRING_T> > &GetAvailablePaymentMethods() const
            {
                return mAvailablePaymentMethods;
            }
            void SetAvailablePaymentMethods(const VECTOR_T<STRING_T> &availablePaymentMethods)
            {
                mAvailablePaymentMethods = availablePaymentMethods;
            }
            const Maybe<Link> &GetSelf() const
            {
                return mSelf;
            }
            void SetSelf(const Link &self)
            {
                mSelf = self;
            }
            const Maybe<Form> &GetUpdatePassword() const
            {
                return mUpdatePassword;
            }
            void SetUpdatePassword(const Form &updatePassword)
            {
                mUpdatePassword = updatePassword;
            }
            const Maybe<Form> &GetUpdate() const
            {
                return mUpdate;
            }
            void SetUpdate(const Form &update)
            {
                mUpdate = update;
            }
            const Maybe<BOOL_T> &IsShowAdult() const
            {
                return mShowAdult;
            }
            void SetShowAdult(BOOL_T showAdult)
            {
                mShowAdult = showAdult;
            }
            const Maybe<VECTOR_T<Bookmark> > &GetBookmarks() const
            {
                return mBookmarks;
            }
            void SetBookmarks(const VECTOR_T<Bookmark> &bookmarks)
            {
                mBookmarks = bookmarks;
            }
            const Maybe<Link> &GetInactiveBookmarks() const
            {
                return mInactiveBookmarks;
            }
            void SetInactiveBookmarks(const Link &inactiveBookmarks)
            {
                mInactiveBookmarks = inactiveBookmarks;
            }
            const Maybe<Crud> &GetManageBookmarks() const
            {
                return mManageBookmarks;
            }
            void SetManageBookmarks(const Crud &manageBookmarks)
            {
                mManageBookmarks = manageBookmarks;
            }
            const Maybe<Crud> &GetManageLists() const
            {
                return mManageLists;
            }
            void SetManageLists(const Crud &manageLists)
            {
                mManageLists = manageLists;
            }
            const Maybe<UserFavouriteLists> &GetUserFavouriteLists() const
            {
                return mUserFavouriteLists;
            }
            void SetUserFavouriteLists(const UserFavouriteLists &userFavouriteLists)
            {
                mUserFavouriteLists = userFavouriteLists;
            }
            const Maybe<Link> &GetMoviesFinishedWatching() const
            {
                return mMoviesFinishedWatching;
            }
            void SetMoviesFinishedWatching(const Link &moviesFinishedWatching)
            {
                mMoviesFinishedWatching = moviesFinishedWatching;
            }
            const Maybe<Link> &GetMoviesCurrentlyWatching() const
            {
                return mMoviesCurrentlyWatching;
            }
            void SetMoviesCurrentlyWatching(const Link &moviesCurrentlyWatching)
            {
                mMoviesCurrentlyWatching = moviesCurrentlyWatching;
            }
            const Maybe<Form> &GetCancelSubscription() const
            {
                return mCancelSubscription;
            }
            void SetCancelSubscription(const Form &cancelSubscription)
            {
                mCancelSubscription = cancelSubscription;
            }
            const Maybe<Form> &GetAddVoucherToSubscription() const
            {
                return mAddVoucherToSubscription;
            }
            void SetAddVoucherToSubscription(const Form &addVoucherToSubscription)
            {
                mAddVoucherToSubscription = addVoucherToSubscription;
            }
            virtual BOOL_T InitFromJsonValue(const rapidjson::Value &value, ParseErrors &parseErrors)
            {
                STRING_T id;
                STRING_T address;
                STRING_T cclastfour;
                STRING_T ccreference;
                BOOL_T ccvalid;
                STRING_T city;
                STRING_T country;
                STRING_T email;
                STRING_T firstName;
                STRING_T lastName;
                STRING_T lastUsedDeviceId;
                STRING_T mobile;
                INT32_T numberOfLogins;
                STRING_T postalCode;
                STRING_T registrationDate;
                STRING_T userName;
                STRING_T mppToken;
                UserList myMoviesList;
                UserList myWishList;
                VECTOR_T<STRING_T> availablePaymentMethods;
                Link self;
                Form updatePassword;
                Form update;
                BOOL_T showAdult;
                VECTOR_T<Bookmark> bookmarks;
                Link inactiveBookmarks;
                Crud manageBookmarks;
                Crud manageLists;
                UserFavouriteLists userFavouriteLists;
                Link moviesFinishedWatching;
                Link moviesCurrentlyWatching;
                Form cancelSubscription;
                Form addVoucherToSubscription;
                if (ParseString(value, "ID", true, id, parseErrors))
                    SetID(id);
                if (ParseString(value, "Address", false, address, parseErrors))
                    SetAddress(address);
                if (ParseString(value, "CClastfour", false, cclastfour, parseErrors))
                    SetCClastfour(cclastfour);
                if (ParseString(value, "CCreference", false, ccreference, parseErrors))
                    SetCCreference(ccreference);
                if (ParseBool(value, "CCvalid", true, ccvalid, parseErrors))
                    SetCCvalid(ccvalid);
                if (ParseString(value, "City", false, city, parseErrors))
                    SetCity(city);
                if (ParseString(value, "Country", false, country, parseErrors))
                    SetCountry(country);
                if (ParseString(value, "Email", false, email, parseErrors))
                    SetEmail(email);
                if (ParseString(value, "FirstName", false, firstName, parseErrors))
                    SetFirstName(firstName);
                if (ParseString(value, "LastName", false, lastName, parseErrors))
                    SetLastName(lastName);
                if (ParseString(value, "LastUsedDeviceId", true, lastUsedDeviceId, parseErrors))
                    SetLastUsedDeviceId(lastUsedDeviceId);
                if (ParseString(value, "Mobile", false, mobile, parseErrors))
                    SetMobile(mobile);
                if (ParseInt(value, "NumberOfLogins", true, numberOfLogins, parseErrors))
                    SetNumberOfLogins(numberOfLogins);
                if (ParseString(value, "PostalCode", false, postalCode, parseErrors))
                    SetPostalCode(postalCode);
                if (ParseString(value, "RegistrationDate", true, registrationDate, parseErrors))
                    SetRegistrationDate(registrationDate);
                if (ParseString(value, "UserName", true, userName, parseErrors))
                    SetUserName(userName);
                if (ParseString(value, "MppToken", false, mppToken, parseErrors))
                    SetMppToken(mppToken);
                if (ParseObject(value, "MyMoviesList", false, myMoviesList, parseErrors))
                    SetMyMoviesList(myMoviesList);
                if (ParseObject(value, "MyWishList", false, myWishList, parseErrors))
                    SetMyWishList(myWishList);
                if (VerifyArray(value, "AvailablePaymentMethods", true, parseErrors))
                {
                    for (rapidjson::SizeType i = 0; i < value["AvailablePaymentMethods"].Size(); i += 1)
                    {
                        STRING_T availablePaymentMethod;
                        if (ParseString(value["AvailablePaymentMethods"][i], "", false, availablePaymentMethod,
                                        parseErrors))
                            availablePaymentMethods.push_back(availablePaymentMethod);
                    }
                    SetAvailablePaymentMethods(availablePaymentMethods);
                }
                if (ParseObject(value, "Self", true, self, parseErrors))
                    SetSelf(self);
                if (ParseObject(value, "UpdatePassword", true, updatePassword, parseErrors))
                    SetUpdatePassword(updatePassword);
                if (ParseObject(value, "Update", true, update, parseErrors))
                    SetUpdate(update);
                if (ParseBool(value, "ShowAdult", true, showAdult, parseErrors))
                    SetShowAdult(showAdult);
                if (VerifyArray(value, "Bookmarks", false, parseErrors))
                {
                    for (rapidjson::SizeType i = 0; i < value["Bookmarks"].Size(); i += 1)
                    {
                        Bookmark bookmark;
                        if (ParseObject(value["Bookmarks"][i], "", false, bookmark, parseErrors))
                            bookmarks.push_back(bookmark);
                    }
                    SetBookmarks(bookmarks);
                }
                if (ParseObject(value, "InactiveBookmarks", false, inactiveBookmarks, parseErrors))
                    SetInactiveBookmarks(inactiveBookmarks);
                if (ParseObject(value, "ManageBookmarks", true, manageBookmarks, parseErrors))
                    SetManageBookmarks(manageBookmarks);
                if (ParseObject(value, "ManageLists", true, manageLists, parseErrors))
                    SetManageLists(manageLists);
                if (ParseObject(value, "UserFavouriteLists", false, userFavouriteLists, parseErrors))
                    SetUserFavouriteLists(userFavouriteLists);
                if (ParseObject(value, "MoviesFinishedWatching", false, moviesFinishedWatching, parseErrors))
                    SetMoviesFinishedWatching(moviesFinishedWatching);
                if (ParseObject(value, "MoviesCurrentlyWatching", false, moviesCurrentlyWatching, parseErrors))
                    SetMoviesCurrentlyWatching(moviesCurrentlyWatching);
                if (ParseObject(value, "CancelSubscription", true, cancelSubscription, parseErrors))
                    SetCancelSubscription(cancelSubscription);
                if (ParseObject(value, "AddVoucherToSubscription", true, addVoucherToSubscription, parseErrors))
                    SetAddVoucherToSubscription(addVoucherToSubscription);
                return !parseErrors;
            }
        private:
            Maybe<STRING_T> mID;
            Maybe<STRING_T> mAddress;
            Maybe<STRING_T> mCClastfour;
            Maybe<STRING_T> mCCreference;
            Maybe<BOOL_T> mCCvalid;
            Maybe<STRING_T> mCity;
            Maybe<STRING_T> mCountry;
            Maybe<STRING_T> mEmail;
            Maybe<STRING_T> mFirstName;
            Maybe<STRING_T> mLastName;
            Maybe<STRING_T> mLastUsedDeviceId;
            Maybe<STRING_T> mMobile;
            Maybe<int> mNumberOfLogins;
            Maybe<STRING_T> mPostalCode;
            Maybe<STRING_T> mRegistrationDate;
            Maybe<STRING_T> mUserName;
            Maybe<STRING_T> mMppToken;
            Maybe<UserList> mMyMoviesList;
            Maybe<UserList> mMyWishList;
            Maybe<VECTOR_T<STRING_T> > mAvailablePaymentMethods;
            Maybe<Link> mSelf;
            Maybe<Form> mUpdatePassword;
            Maybe<Form> mUpdate;
            Maybe<BOOL_T> mShowAdult;
            Maybe<VECTOR_T<Bookmark> > mBookmarks;
            Maybe<Link> mInactiveBookmarks;
            Maybe<Crud> mManageBookmarks;
            Maybe<Crud> mManageLists;
            Maybe<UserFavouriteLists> mUserFavouriteLists;
            Maybe<Link> mMoviesFinishedWatching;
            Maybe<Link> mMoviesCurrentlyWatching;
            Maybe<Form> mCancelSubscription;
            Maybe<Form> mAddVoucherToSubscription;
        };
    }
}
#endif //READY4AIR_USER_H

#ifndef READY4AIR_PURCHASE_H
#define READY4AIR_PURCHASE_H
namespace ready4air
{
    namespace dto
    {
        class Purchase : public JsonDeserializable
        {
        public:
            Purchase()
            {
            }
            virtual ~Purchase()
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
            const Maybe <STRING_T> &GetCpurchaseId() const
            {
                return mCpurchaseId;
            }
            void SetCpurchaseId(const STRING_T &cpurchaseId)
            {
                mCpurchaseId = cpurchaseId;
            }
            const Maybe <STRING_T> &GetCrentalId() const
            {
                return mCrentalId;
            }
            void SetCrentalId(const STRING_T &crentalId)
            {
                mCrentalId = crentalId;
            }
            const Maybe <VECTOR_T<STRING_T> > &GetCValueCodes() const
            {
                return mCValueCodes;
            }
            void SetCValueCodes(const VECTOR_T<STRING_T> &CValueCodes)
            {
                mCValueCodes = CValueCodes;
            }
            const Maybe <STRING_T> &GetCurrency() const
            {
                return mCurrency;
            }
            void SetCurrency(const STRING_T &currency)
            {
                mCurrency = currency;
            }
            const Maybe <STRING_T> &GetIPAddress() const
            {
                return mIPAddress;
            }
            void SetIPAddress(const STRING_T &IPAddress)
            {
                mIPAddress = IPAddress;
            }
            const Maybe <STRING_T> &GetIPCountry() const
            {
                return mIPCountry;
            }
            void SetIPCountry(const STRING_T &IPCountry)
            {
                mIPCountry = IPCountry;
            }
            const Maybe <STRING_T> &GetProductId() const
            {
                return mProductId;
            }
            void SetProductId(const STRING_T &productId)
            {
                mProductId = productId;
            }
            const Maybe<DOUBLE_T> &GetOriginalPrice() const
            {
                return mOriginalPrice;
            }
            void SetOriginalPrice(DOUBLE_T originalPrice)
            {
                mOriginalPrice = originalPrice;
            }
            const Maybe <STRING_T> &GetPaymentMethod() const
            {
                return mPaymentMethod;
            }
            void SetPaymentMethod(const STRING_T &paymentMethod)
            {
                mPaymentMethod = paymentMethod;
            }
            const Maybe <STRING_T> &GetPaymentReference() const
            {
                return mPaymentReference;
            }
            void SetPaymentReference(const STRING_T &paymentReference)
            {
                mPaymentReference = paymentReference;
            }
            const Maybe<DOUBLE_T> &GetPaidPrice() const
            {
                return mPaidPrice;
            }
            void SetPaidPrice(DOUBLE_T paidPrice)
            {
                mPaidPrice = paidPrice;
            }
            const Maybe<DOUBLE_T> &GetRemainingAmount() const
            {
                return mRemainingAmount;
            }
            void SetRemainingAmount(DOUBLE_T remainingAmount)
            {
                mRemainingAmount = remainingAmount;
            }
            const Maybe <STRING_T> &GetTitle() const
            {
                return mTitle;
            }
            void SetTitle(const STRING_T &title)
            {
                mTitle = title;
            }
            const Maybe <STRING_T> &GetTransactionTime() const
            {
                return mTransactionTime;
            }
            void SetTransactionTime(const STRING_T &transactionTime)
            {
                mTransactionTime = transactionTime;
            }
            const Maybe <Link> &GetSelf() const
            {
                return mSelf;
            }
            void SetSelf(const Link &self)
            {
                mSelf = self;
            }
            const Maybe <Form> &GetCommit() const
            {
                return mCommit;
            }
            void SetCommit(const Form &commit)
            {
                mCommit = commit;
            }
            const Maybe <Form> &GetCancel() const
            {
                return mCancel;
            }
            void SetCancel(const Form &cancel)
            {
                mCancel = cancel;
            }
            const Maybe <Form> &GetUpdate() const
            {
                return mUpdate;
            }
            void SetUpdate(const Form &update)
            {
                mUpdate = update;
            }
            const Maybe <DRM> &GetDRM() const
            {
                return mDRM;
            }
            void SetDRM(const DRM &DRM)
            {
                mDRM = DRM;
            }
            const Maybe <STRING_T> &GetSignature() const
            {
                return mSignature;
            }
            void SetSignature(const STRING_T &signature)
            {
                mSignature = signature;
            }
            virtual BOOL_T InitFromJsonValue(const rapidjson::Value &value, ParseErrors &parseErrors)
            {
                STRING_T id;
                STRING_T cpurchaseId;
                STRING_T crentalId;
                VECTOR_T<STRING_T> cValueCodes;
                STRING_T currency;
                STRING_T ipAddress;
                STRING_T ipCountry;
                STRING_T productId;
                DOUBLE_T originalPrice;
                STRING_T paymentMethod;
                STRING_T paymentReference;
                DOUBLE_T paidPrice;
                DOUBLE_T remainingAmount;
                STRING_T title;
                STRING_T transactionTime;
                Link self;
                Form commit;
                Form cancel;
                Form update;
                DRM drm;
                STRING_T signature;
                if (ParseString(value, "Id", true, id, parseErrors))
                    SetId(id);
                if (ParseString(value, "CpurchaseId", false, cpurchaseId, parseErrors))
                    SetCpurchaseId(cpurchaseId);
                if (ParseString(value, "CrentalId", false, crentalId, parseErrors))
                    SetCrentalId(crentalId);
                if (VerifyArray(value, "CValueCodes", false, parseErrors))
                {
                    for (rapidjson::SizeType i = 0; i < value["CValueCodes"].Size(); i += 1)
                    {
                        STRING_T cValueCode;
                        if (ParseString(value["CValueCodes"][i], "", false, cValueCode, parseErrors))
                            cValueCodes.push_back(cValueCode);
                    }
                    SetCValueCodes(cValueCodes);
                }
                if (ParseString(value, "Currency", true, currency, parseErrors))
                    SetCurrency(currency);
                if (ParseString(value, "IPAddress", true, ipAddress, parseErrors))
                    SetIPAddress(ipAddress);
                if (ParseString(value, "IPCountry", true, ipCountry, parseErrors))
                    SetIPCountry(ipCountry);
                if (ParseString(value, "ProductId", true, productId, parseErrors))
                    SetProductId(productId);
                if (ParseDouble(value, "OriginalPrice", true, originalPrice, parseErrors))
                    SetOriginalPrice(originalPrice);
                if (ParseString(value, "PaymentMethod", false, paymentMethod, parseErrors))
                    SetPaymentMethod(paymentMethod);
                if (ParseString(value, "PaymentReference", false, paymentReference, parseErrors))
                    SetPaymentReference(paymentReference);
                if (ParseDouble(value, "PaidPrice", true, paidPrice, parseErrors))
                    SetPaidPrice(paidPrice);
                if (ParseDouble(value, "RemainingAmount", true, remainingAmount, parseErrors))
                    SetRemainingAmount(remainingAmount);
                if (ParseString(value, "Title", false, title, parseErrors))
                    SetTitle(title);
                if (ParseString(value, "TransactionTime", false, transactionTime, parseErrors))
                    SetTransactionTime(transactionTime);
                if (ParseObject(value, "Self", true, self, parseErrors))
                    SetSelf(self);
                if (ParseObject(value, "Commit", false, commit, parseErrors))
                    SetCommit(commit);
                if (ParseObject(value, "Cancel", false, cancel, parseErrors))
                    SetCancel(cancel);
                if (ParseObject(value, "Update", false, update, parseErrors))
                    SetUpdate(update);
                if (ParseObject(value, "DRM", false, drm, parseErrors))
                    SetDRM(drm);
                if (ParseString(value, "Signature", true, signature, parseErrors))
                    SetSignature(signature);
                return !parseErrors;
            }
        private:
            Maybe <STRING_T> mId;
            Maybe <STRING_T> mCpurchaseId;
            Maybe <STRING_T> mCrentalId;
            Maybe <VECTOR_T<STRING_T> > mCValueCodes;
            Maybe <STRING_T> mCurrency;
            Maybe <STRING_T> mIPAddress;
            Maybe <STRING_T> mIPCountry;
            Maybe <STRING_T> mProductId;
            Maybe<DOUBLE_T> mOriginalPrice;
            Maybe <STRING_T> mPaymentMethod;
            Maybe <STRING_T> mPaymentReference;
            Maybe<DOUBLE_T> mPaidPrice;
            Maybe<DOUBLE_T> mRemainingAmount;
            Maybe <STRING_T> mTitle;
            Maybe <STRING_T> mTransactionTime;
            Maybe <Link> mSelf;
            Maybe <Form> mCommit;
            Maybe <Form> mCancel;
            Maybe <Form> mUpdate;
            Maybe <DRM> mDRM;
            Maybe <STRING_T> mSignature;
        };
    }
}
#endif //READY4AIR_PURCHASE_H

#ifndef READY4AIR_PAYMENTDATA_H
#define READY4AIR_PAYMENTDATA_H
namespace ready4air
{
    namespace dto
    {
        class PaymentData : public JsonDeserializable
        {
        public:
            PaymentData()
            {
            }
            virtual ~PaymentData()
            {
            }
            const Maybe <STRING_T> &GetPhoneNumber() const
            {
                return mPhoneNumber;
            }
            void SetPhoneNumber(const STRING_T &phoneNumber)
            {
                mPhoneNumber = phoneNumber;
            }
            const Maybe <STRING_T> &GetReservationNumber() const
            {
                return mReservationNumber;
            }
            void SetReservationNumber(const STRING_T &reservationNumber)
            {
                mReservationNumber = reservationNumber;
            }
            const Maybe<int> &GetPin() const
            {
                return mPin;
            }
            void SetPin(int pin)
            {
                mPin = pin;
            }
            virtual BOOL_T InitFromJsonValue(const rapidjson::Value &value, ParseErrors &parseErrors)
            {
                STRING_T phoneNumber;
                STRING_T reservationNumber;
                INT32_T pin;
                if (ParseString(value, "PhoneNumber", false, phoneNumber, parseErrors))
                    SetPhoneNumber(phoneNumber);
                if (ParseString(value, "ReservationNumber", false, reservationNumber, parseErrors))
                    SetReservationNumber(reservationNumber);
                if (ParseInt(value, "Pin", false, pin, parseErrors))
                    SetPin(pin);
                return !parseErrors;
            }
        private:
            Maybe <STRING_T> mPhoneNumber;
            Maybe <STRING_T> mReservationNumber;
            Maybe<int> mPin;
        };
    }
}
#endif //READY4AIR_PAYMENTDATA_H

#ifndef READY4AIR_PURCHASEINFO_H
#define READY4AIR_PURCHASEINFO_H
namespace ready4air
{
    namespace dto
    {
        class PurchaseInfo : public JsonDeserializable
        {
        public:
            PurchaseInfo()
            {
            }
            virtual ~PurchaseInfo()
            {
            }
            const Maybe<Purchase> &GetPurchase() const
            {
                return mPurchase;
            }
            void SetPurchase(const Purchase &purchase)
            {
                mPurchase = purchase;
            }
            const Maybe<STRING_T> &GetPurchaseType() const
            {
                return mPurchaseType;
            }
            void SetPurchaseType(const STRING_T &purchaseType)
            {
                mPurchaseType = purchaseType;
            }
            const Maybe<PaymentData> &GetPaymentData() const
            {
                return mPaymentData;
            }
            void SetPaymentData(const PaymentData &paymentData)
            {
                mPaymentData = paymentData;
            }
            virtual BOOL_T InitFromJsonValue(const rapidjson::Value &value, ParseErrors &parseErrors)
            {
                Purchase purchase;
                STRING_T purchaseType;
                PaymentData paymentData;
                if (ParseObject(value, "Purchase", true, purchase, parseErrors))
                    SetPurchase(purchase);
                if (ParseString(value, "PurchaseType", true, purchaseType, parseErrors))
                    SetPurchaseType(purchaseType);
                if (ParseObject(value, "PaymentData", false, paymentData, parseErrors))
                    SetPaymentData(paymentData);
                return !parseErrors;
            }
        private:
            Maybe<Purchase> mPurchase;
            Maybe<STRING_T> mPurchaseType;
            Maybe<PaymentData> mPaymentData;
        };
    }
}
#endif //READY4AIR_PURCHASEINFO_H

