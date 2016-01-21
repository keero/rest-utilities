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
            User()
            {
            }

            virtual ~User()
            {
            }

            const Maybe<std::string> &GetID() const
            {
                return mID;
            }

            void SetID(const std::string &ID)
            {
                mID = ID;
            }

            const Maybe<std::string> &GetAddress() const
            {
                return mAddress;
            }

            void SetAddress(const std::string &address)
            {
                mAddress = address;
            }

            const Maybe<std::string> &GetCClastfour() const
            {
                return mCClastfour;
            }

            void SetCClastfour(const std::string &CClastfour)
            {
                mCClastfour = CClastfour;
            }

            const Maybe<std::string> &GetCCreference() const
            {
                return mCCreference;
            }

            void SetCCreference(const std::string &CCreference)
            {
                mCCreference = CCreference;
            }

            const Maybe<bool> &IsCCvalid() const
            {
                return mCCvalid;
            }

            void SetCCvalid(bool CCvalid)
            {
                mCCvalid = CCvalid;
            }

            const Maybe<std::string> &GetCity() const
            {
                return mCity;
            }

            void SetCity(const std::string &city)
            {
                mCity = city;
            }

            const Maybe<std::string> &GetCountry() const
            {
                return mCountry;
            }

            void SetCountry(const std::string &country)
            {
                mCountry = country;
            }

            const Maybe<std::string> &GetEmail() const
            {
                return mEmail;
            }

            void SetEmail(const std::string &email)
            {
                mEmail = email;
            }

            const Maybe<std::string> &GetFirstName() const
            {
                return mFirstName;
            }

            void SetFirstName(const std::string &firstName)
            {
                mFirstName = firstName;
            }

            const Maybe<std::string> &GetLastName() const
            {
                return mLastName;
            }

            void SetLastName(const std::string &lastName)
            {
                mLastName = lastName;
            }

            const Maybe<std::string> &GetLastUsedDeviceId() const
            {
                return mLastUsedDeviceId;
            }

            void SetLastUsedDeviceId(const std::string &lastUsedDeviceId)
            {
                mLastUsedDeviceId = lastUsedDeviceId;
            }

            const Maybe<std::string> &GetMobile() const
            {
                return mMobile;
            }

            void SetMobile(const std::string &mobile)
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

            const Maybe<std::string> &GetPostalCode() const
            {
                return mPostalCode;
            }

            void SetPostalCode(const std::string &postalCode)
            {
                mPostalCode = postalCode;
            }

            const Maybe<std::string> &GetRegistrationDate() const
            {
                return mRegistrationDate;
            }

            void SetRegistrationDate(const std::string &registrationDate)
            {
                mRegistrationDate = registrationDate;
            }

            const Maybe<std::string> &GetUserName() const
            {
                return mUserName;
            }

            void SetUserName(const std::string &userName)
            {
                mUserName = userName;
            }

            const Maybe<std::string> &GetMppToken() const
            {
                return mMppToken;
            }

            void SetMppToken(const std::string &mppToken)
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

            const Maybe<std::vector<std::string> > &GetAvailablePaymentMethods() const
            {
                return mAvailablePaymentMethods;
            }

            void SetAvailablePaymentMethods(const std::vector<std::string> &availablePaymentMethods)
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

            const Maybe<bool> &IsShowAdult() const
            {
                return mShowAdult;
            }

            void SetShowAdult(bool showAdult)
            {
                mShowAdult = showAdult;
            }

            const Maybe<std::vector<Bookmark> > &GetBookmarks() const
            {
                return mBookmarks;
            }

            void SetBookmarks(const std::vector<Bookmark> &bookmarks)
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

            virtual bool InitFromJsonValue(const rapidjson::Value &value, ParseErrors &parseErrors)
            {
                std::string id;
                std::string address;
                std::string cclastfour;
                std::string ccreference;
                bool ccvalid;
                std::string city;
                std::string country;
                std::string email;
                std::string firstName;
                std::string lastName;
                std::string lastUsedDeviceId;
                std::string mobile;
                int numberOfLogins;
                std::string postalCode;
                std::string registrationDate;
                std::string userName;
                std::string mppToken;
                UserList myMoviesList;
                UserList myWishList;
                std::vector<std::string> availablePaymentMethods;
                Link self;
                Form updatePassword;
                Form update;
                bool showAdult;
                std::vector<Bookmark> bookmarks;
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
                        std::string availablePaymentMethod;
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
            Maybe<std::string> mID;
            Maybe<std::string> mAddress;
            Maybe<std::string> mCClastfour;
            Maybe<std::string> mCCreference;
            Maybe<bool> mCCvalid;
            Maybe<std::string> mCity;
            Maybe<std::string> mCountry;
            Maybe<std::string> mEmail;
            Maybe<std::string> mFirstName;
            Maybe<std::string> mLastName;
            Maybe<std::string> mLastUsedDeviceId;
            Maybe<std::string> mMobile;
            Maybe<int> mNumberOfLogins;
            Maybe<std::string> mPostalCode;
            Maybe<std::string> mRegistrationDate;
            Maybe<std::string> mUserName;
            Maybe<std::string> mMppToken;
            Maybe<UserList> mMyMoviesList;
            Maybe<UserList> mMyWishList;
            Maybe<std::vector<std::string> > mAvailablePaymentMethods;
            Maybe<Link> mSelf;
            Maybe<Form> mUpdatePassword;
            Maybe<Form> mUpdate;
            Maybe<bool> mShowAdult;
            Maybe<std::vector<Bookmark> > mBookmarks;
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
