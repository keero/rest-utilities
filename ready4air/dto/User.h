#ifndef READY4AIR_USER_H
#define READY4AIR_USER_H

#include "abstract/JsonDeserializable.h"
#include "UserList.h"
#include "hypermedia/Link.h"
#include "hypermedia/Form.h"
#include "Bookmark.h"
#include "hypermedia/Crud.h"
#include "UserFavouriteLists.h"

namespace ready4air
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

        const std::string &GetID() const
        {
            return mID;
        }

        void SetID(const std::string &ID)
        {
            mID = ID;
        }

        const std::string &GetAddress() const
        {
            return mAddress;
        }

        void SetAddress(const std::string &address)
        {
            mAddress = address;
        }

        const std::string &GetCClastfour() const
        {
            return mCClastfour;
        }

        void SetCClastfour(const std::string &CClastfour)
        {
            mCClastfour = CClastfour;
        }

        const std::string &GetCCreference() const
        {
            return mCCreference;
        }

        void SetCCreference(const std::string &CCreference)
        {
            mCCreference = CCreference;
        }

        bool IsCCvalid() const
        {
            return mCCvalid;
        }

        void SetCCvalid(bool CCvalid)
        {
            mCCvalid = CCvalid;
        }

        const std::string &GetCity() const
        {
            return mCity;
        }

        void SetCity(const std::string &city)
        {
            mCity = city;
        }

        const std::string &GetCountry() const
        {
            return mCountry;
        }

        void SetCountry(const std::string &country)
        {
            mCountry = country;
        }

        const std::string &GetEmail() const
        {
            return mEmail;
        }

        void SetEmail(const std::string &email)
        {
            mEmail = email;
        }

        const std::string &GetFirstName() const
        {
            return mFirstName;
        }

        void SetFirstName(const std::string &firstName)
        {
            mFirstName = firstName;
        }

        const std::string &GetLastName() const
        {
            return mLastName;
        }

        void SetLastName(const std::string &lastName)
        {
            mLastName = lastName;
        }

        const std::string &GetLastUsedDeviceId() const
        {
            return mLastUsedDeviceId;
        }

        void SetLastUsedDeviceId(const std::string &lastUsedDeviceId)
        {
            mLastUsedDeviceId = lastUsedDeviceId;
        }

        const std::string &GetMobile() const
        {
            return mMobile;
        }

        void SetMobile(const std::string &mobile)
        {
            mMobile = mobile;
        }

        int GetNumberOfLogins() const
        {
            return mNumberOfLogins;
        }

        void SetNumberOfLogins(int numberOfLogins)
        {
            mNumberOfLogins = numberOfLogins;
        }

        const std::string &GetPostalCode() const
        {
            return mPostalCode;
        }

        void SetPostalCode(const std::string &postalCode)
        {
            mPostalCode = postalCode;
        }

        const std::string &GetRegistrationDate() const
        {
            return mRegistrationDate;
        }

        void SetRegistrationDate(const std::string &registrationDate)
        {
            mRegistrationDate = registrationDate;
        }

        const std::string &GetUserName() const
        {
            return mUserName;
        }

        void SetUserName(const std::string &userName)
        {
            mUserName = userName;
        }

        const std::string &GetMppToken() const
        {
            return mMppToken;
        }

        void SetMppToken(const std::string &mppToken)
        {
            mMppToken = mppToken;
        }

        const UserList &GetMyMoviesList() const
        {
            return mMyMoviesList;
        }

        void SetMyMoviesList(const UserList &myMoviesList)
        {
            mMyMoviesList = myMoviesList;
        }

        const UserList &GetMyWishList() const
        {
            return mMyWishList;
        }

        void SetMyWishList(const UserList &myWishList)
        {
            mMyWishList = myWishList;
        }

        const std::vector<std::string> &GetAvailablePaymentMethods() const
        {
            return mAvailablePaymentMethods;
        }

        void SetAvailablePaymentMethods(const std::vector<std::string> &availablePaymentMethods)
        {
            mAvailablePaymentMethods = availablePaymentMethods;
        }

        const Link &GetSelf() const
        {
            return mSelf;
        }

        void SetSelf(const Link &self)
        {
            mSelf = self;
        }

        const Form &GetUpdatePassword() const
        {
            return mUpdatePassword;
        }

        void SetUpdatePassword(const Form &updatePassword)
        {
            mUpdatePassword = updatePassword;
        }

        const Form &GetUpdate() const
        {
            return mUpdate;
        }

        void SetUpdate(const Form &update)
        {
            mUpdate = update;
        }

        bool IsShowAdult() const
        {
            return mShowAdult;
        }

        void SetShowAdult(bool showAdult)
        {
            mShowAdult = showAdult;
        }

        const std::vector<Bookmark> &GetBookmarks() const
        {
            return mBookmarks;
        }

        void SetBookmarks(const std::vector<Bookmark> &bookmarks)
        {
            mBookmarks = bookmarks;
        }

        const Link &GetInactiveBookmarks() const
        {
            return mInactiveBookmarks;
        }

        void SetInactiveBookmarks(const Link &inactiveBookmarks)
        {
            mInactiveBookmarks = inactiveBookmarks;
        }

        const Crud &GetManageBookmarks() const
        {
            return mManageBookmarks;
        }

        void SetManageBookmarks(const Crud &manageBookmarks)
        {
            mManageBookmarks = manageBookmarks;
        }

        const Crud &GetManageLists() const
        {
            return mManageLists;
        }

        void SetManageLists(const Crud &manageLists)
        {
            mManageLists = manageLists;
        }

        const UserFavouriteLists &GetUserFavouriteLists() const
        {
            return mUserFavouriteLists;
        }

        void SetUserFavouriteLists(const UserFavouriteLists &userFavouriteLists)
        {
            mUserFavouriteLists = userFavouriteLists;
        }

        const Link &GetMoviesFinishedWatching() const
        {
            return mMoviesFinishedWatching;
        }

        void SetMoviesFinishedWatching(const Link &moviesFinishedWatching)
        {
            mMoviesFinishedWatching = moviesFinishedWatching;
        }

        const Link &GetMoviesCurrentlyWatching() const
        {
            return mMoviesCurrentlyWatching;
        }

        void SetMoviesCurrentlyWatching(const Link &moviesCurrentlyWatching)
        {
            mMoviesCurrentlyWatching = moviesCurrentlyWatching;
        }

        const Form &GetCancelSubscription() const
        {
            return mCancelSubscription;
        }

        void SetCancelSubscription(const Form &cancelSubscription)
        {
            mCancelSubscription = cancelSubscription;
        }

        virtual bool InitFromJsonValue(const rapidjson::Value &value)
        {
            return false;
        }

    private:
        std::string mID;
        std::string mAddress;
        std::string mCClastfour;
        std::string mCCreference;
        bool mCCvalid;
        std::string mCity;
        std::string mCountry;
        std::string mEmail;
        std::string mFirstName;
        std::string mLastName;
        std::string mLastUsedDeviceId;
        std::string mMobile;
        int mNumberOfLogins;
        std::string mPostalCode;
        std::string mRegistrationDate;
        std::string mUserName;
        std::string mMppToken;
        UserList mMyMoviesList;
        UserList mMyWishList;
        std::vector<std::string> mAvailablePaymentMethods;
        Link mSelf;
        Form mUpdatePassword;
        Form mUpdate;
        bool mShowAdult;
        std::vector<Bookmark> mBookmarks;
        Link mInactiveBookmarks;
        Crud mManageBookmarks;
        Crud mManageLists;
        UserFavouriteLists mUserFavouriteLists;
        Link mMoviesFinishedWatching;
        Link mMoviesCurrentlyWatching;
        Form mCancelSubscription;
    };
}

#endif //READY4AIR_USER_H
