#ifndef READY4AIR_USER_H
#define READY4AIR_USER_H

#include "../common/Maybe.h"
#include "abstract/JsonDeserializable.h"
#include "UserList.h"
#include "hypermedia/Link.h"
#include "hypermedia/Form.h"
#include "Bookmark.h"
#include "hypermedia/Crud.h"
#include "UserFavouriteLists.h"

namespace ready4air
{
    namespace dto
    {
        class User : public JsonDeserializable
        {
        public:
            User() : TAG("ready4air::dto::User")
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
            const STRING_T TAG;
        };
    }
}

#endif //READY4AIR_USER_H
