#ifndef READY4AIR_USER_H
#define READY4AIR_USER_H

#include "../maybe/Maybe.h"
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

        const Maybe <std::string> &GetID() const
        {
            return mID;
        }

        void SetID(const std::string &ID)
        {
            mID = ID;
        }

        const Maybe <std::string> &GetAddress() const
        {
            return mAddress;
        }

        void SetAddress(const std::string &address)
        {
            mAddress = address;
        }

        const Maybe <std::string> &GetCClastfour() const
        {
            return mCClastfour;
        }

        void SetCClastfour(const std::string &CClastfour)
        {
            mCClastfour = CClastfour;
        }

        const Maybe <std::string> &GetCCreference() const
        {
            return mCCreference;
        }

        void SetCCreference(const std::string &CCreference)
        {
            mCCreference = CCreference;
        }

        const Maybe <bool> &IsCCvalid() const
        {
            return mCCvalid;
        }

        void SetCCvalid(bool CCvalid)
        {
            mCCvalid = CCvalid;
        }

        const Maybe <std::string> &GetCity() const
        {
            return mCity;
        }

        void SetCity(const std::string &city)
        {
            mCity = city;
        }

        const Maybe <std::string> &GetCountry() const
        {
            return mCountry;
        }

        void SetCountry(const std::string &country)
        {
            mCountry = country;
        }

        const Maybe <std::string> &GetEmail() const
        {
            return mEmail;
        }

        void SetEmail(const std::string &email)
        {
            mEmail = email;
        }

        const Maybe <std::string> &GetFirstName() const
        {
            return mFirstName;
        }

        void SetFirstName(const std::string &firstName)
        {
            mFirstName = firstName;
        }

        const Maybe <std::string> &GetLastName() const
        {
            return mLastName;
        }

        void SetLastName(const std::string &lastName)
        {
            mLastName = lastName;
        }

        const Maybe <std::string> &GetLastUsedDeviceId() const
        {
            return mLastUsedDeviceId;
        }

        void SetLastUsedDeviceId(const std::string &lastUsedDeviceId)
        {
            mLastUsedDeviceId = lastUsedDeviceId;
        }

        const Maybe <std::string> &GetMobile() const
        {
            return mMobile;
        }

        void SetMobile(const std::string &mobile)
        {
            mMobile = mobile;
        }

        const Maybe <int> &GetNumberOfLogins() const
        {
            return mNumberOfLogins;
        }

        void SetNumberOfLogins(int numberOfLogins)
        {
            mNumberOfLogins = numberOfLogins;
        }

        const Maybe <std::string> &GetPostalCode() const
        {
            return mPostalCode;
        }

        void SetPostalCode(const std::string &postalCode)
        {
            mPostalCode = postalCode;
        }

        const Maybe <std::string> &GetRegistrationDate() const
        {
            return mRegistrationDate;
        }

        void SetRegistrationDate(const std::string &registrationDate)
        {
            mRegistrationDate = registrationDate;
        }

        const Maybe <std::string> &GetUserName() const
        {
            return mUserName;
        }

        void SetUserName(const std::string &userName)
        {
            mUserName = userName;
        }

        const Maybe <std::string> &GetMppToken() const
        {
            return mMppToken;
        }

        void SetMppToken(const std::string &mppToken)
        {
            mMppToken = mppToken;
        }

        const Maybe <UserList> &GetMyMoviesList() const
        {
            return mMyMoviesList;
        }

        void SetMyMoviesList(const UserList &myMoviesList)
        {
            mMyMoviesList = myMoviesList;
        }

        const Maybe <UserList> &GetMyWishList() const
        {
            return mMyWishList;
        }

        void SetMyWishList(const UserList &myWishList)
        {
            mMyWishList = myWishList;
        }

        const Maybe <std::vector<std::string> > &GetAvailablePaymentMethods() const
        {
            return mAvailablePaymentMethods;
        }

        void SetAvailablePaymentMethods(const std::vector<std::string> &availablePaymentMethods)
        {
            mAvailablePaymentMethods = availablePaymentMethods;
        }

        const Maybe <Link> &GetSelf() const
        {
            return mSelf;
        }

        void SetSelf(const Link &self)
        {
            mSelf = self;
        }

        const Maybe <Form> &GetUpdatePassword() const
        {
            return mUpdatePassword;
        }

        void SetUpdatePassword(const Form &updatePassword)
        {
            mUpdatePassword = updatePassword;
        }

        const Maybe <Form> &GetUpdate() const
        {
            return mUpdate;
        }

        void SetUpdate(const Form &update)
        {
            mUpdate = update;
        }

        const Maybe <bool> &IsShowAdult() const
        {
            return mShowAdult;
        }

        void SetShowAdult(bool showAdult)
        {
            mShowAdult = showAdult;
        }

        const Maybe <std::vector<Bookmark> > &GetBookmarks() const
        {
            return mBookmarks;
        }

        void SetBookmarks(const std::vector<Bookmark> &bookmarks)
        {
            mBookmarks = bookmarks;
        }

        const Maybe <Link> &GetInactiveBookmarks() const
        {
            return mInactiveBookmarks;
        }

        void SetInactiveBookmarks(const Link &inactiveBookmarks)
        {
            mInactiveBookmarks = inactiveBookmarks;
        }

        const Maybe <Crud> &GetManageBookmarks() const
        {
            return mManageBookmarks;
        }

        void SetManageBookmarks(const Crud &manageBookmarks)
        {
            mManageBookmarks = manageBookmarks;
        }

        const Maybe <Crud> &GetManageLists() const
        {
            return mManageLists;
        }

        void SetManageLists(const Crud &manageLists)
        {
            mManageLists = manageLists;
        }

        const Maybe <UserFavouriteLists> &GetUserFavouriteLists() const
        {
            return mUserFavouriteLists;
        }

        void SetUserFavouriteLists(const UserFavouriteLists &userFavouriteLists)
        {
            mUserFavouriteLists = userFavouriteLists;
        }

        const Maybe <Link> &GetMoviesFinishedWatching() const
        {
            return mMoviesFinishedWatching;
        }

        void SetMoviesFinishedWatching(const Link &moviesFinishedWatching)
        {
            mMoviesFinishedWatching = moviesFinishedWatching;
        }

        const Maybe <Link> &GetMoviesCurrentlyWatching() const
        {
            return mMoviesCurrentlyWatching;
        }

        void SetMoviesCurrentlyWatching(const Link &moviesCurrentlyWatching)
        {
            mMoviesCurrentlyWatching = moviesCurrentlyWatching;
        }

        const Maybe <Form> &GetCancelSubscription() const
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
        Maybe <std::string> mID;
        Maybe <std::string> mAddress;
        Maybe <std::string> mCClastfour;
        Maybe <std::string> mCCreference;
        Maybe <bool> mCCvalid;
        Maybe <std::string> mCity;
        Maybe <std::string> mCountry;
        Maybe <std::string> mEmail;
        Maybe <std::string> mFirstName;
        Maybe <std::string> mLastName;
        Maybe <std::string> mLastUsedDeviceId;
        Maybe <std::string> mMobile;
        Maybe <int> mNumberOfLogins;
        Maybe <std::string> mPostalCode;
        Maybe <std::string> mRegistrationDate;
        Maybe <std::string> mUserName;
        Maybe <std::string> mMppToken;
        Maybe <UserList> mMyMoviesList;
        Maybe <UserList> mMyWishList;
        Maybe <std::vector<std::string> > mAvailablePaymentMethods;
        Maybe <Link> mSelf;
        Maybe <Form> mUpdatePassword;
        Maybe <Form> mUpdate;
        Maybe <bool> mShowAdult;
        Maybe <std::vector<Bookmark> > mBookmarks;
        Maybe <Link> mInactiveBookmarks;
        Maybe <Crud> mManageBookmarks;
        Maybe <Crud> mManageLists;
        Maybe <UserFavouriteLists> mUserFavouriteLists;
        Maybe <Link> mMoviesFinishedWatching;
        Maybe <Link> mMoviesCurrentlyWatching;
        Maybe <Form> mCancelSubscription;
    };
}

#endif //READY4AIR_USER_H
