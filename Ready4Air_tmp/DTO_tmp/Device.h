#ifndef READY4AIR_DEVICE_H
#define READY4AIR_DEVICE_H

#include "abstract/JsonDeserializable.h"
#include "hypermedia/Link.h"
#include "hypermedia/Form.h"
#include "DeviceAuthData.h"
#include "hypermedia/Crud.h"

namespace ready4air
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

        const std::string &GetId() const
        {
            return mId;
        }

        void SetId(const std::string &id)
        {
            mId = id;
        }

        const std::string &GetManufacturer() const
        {
            return mManufacturer;
        }

        void SetManufacturer(const std::string &manufacturer)
        {
            mManufacturer = manufacturer;
        }

        const std::string &GetModel() const
        {
            return mModel;
        }

        void SetModel(const std::string &model)
        {
            mModel = model;
        }

        const std::string &GetUdId() const
        {
            return mUdId;
        }

        void SetUdId(const std::string &udId)
        {
            mUdId = udId;
        }

        const std::string &GetDeviceInfo() const
        {
            return mDeviceInfo;
        }

        void SetDeviceInfo(const std::string &deviceInfo)
        {
            mDeviceInfo = deviceInfo;
        }

        const std::string &GetLastUsedDate() const
        {
            return mLastUsedDate;
        }

        void SetLastUsedDate(const std::string &lastUsedDate)
        {
            mLastUsedDate = lastUsedDate;
        }

        const std::string &GetLastUsedIP() const
        {
            return mLastUsedIP;
        }

        void SetLastUsedIP(const std::string &lastUsedIP)
        {
            mLastUsedIP = lastUsedIP;
        }

        const std::string &GetRegistrationDate() const
        {
            return mRegistrationDate;
        }

        void SetRegistrationDate(const std::string &registrationDate)
        {
            mRegistrationDate = registrationDate;
        }

        const Link &GetHome() const
        {
            return mHome;
        }

        void SetHome(const Link &home)
        {
            mHome = home;
        }

        const Link &GetHelps() const
        {
            return mHelps;
        }

        void SetHelps(const Link &helps)
        {
            mHelps = helps;
        }

        const Link &GetLiterals() const
        {
            return mLiterals;
        }

        void SetLiterals(const Link &literals)
        {
            mLiterals = literals;
        }

        const Link &GetLogin() const
        {
            return mLogin;
        }

        void SetLogin(const Link &login)
        {
            mLogin = login;
        }

        const Form &GetARegister() const
        {
            return mRegister;
        }

        void SetARegister(const Form &aRegister)
        {
            mRegister = aRegister;
        }

        const Form &GetForgotPassword() const
        {
            return mForgotPassword;
        }

        void SetForgotPassword(const Form &forgotPassword)
        {
            mForgotPassword = forgotPassword;
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

        const Link &GetSearch() const
        {
            return mSearch;
        }

        void SetSearch(const Link &search)
        {
            mSearch = search;
        }

        const Link &GetSearchAsYouType() const
        {
            return mSearchAsYouType;
        }

        void SetSearchAsYouType(const Link &searchAsYouType)
        {
            mSearchAsYouType = searchAsYouType;
        }

        const Link &GetSearchMovies() const
        {
            return mSearchMovies;
        }

        void SetSearchMovies(const Link &searchMovies)
        {
            mSearchMovies = searchMovies;
        }

        const Link &GetFilterMoviesByAgeGroups() const
        {
            return mFilterMoviesByAgeGroups;
        }

        void SetFilterMoviesByAgeGroups(const Link &filterMoviesByAgeGroups)
        {
            mFilterMoviesByAgeGroups = filterMoviesByAgeGroups;
        }

        const Link &GetSearchSeries() const
        {
            return mSearchSeries;
        }

        void SetSearchSeries(const Link &searchSeries)
        {
            mSearchSeries = searchSeries;
        }

        const Link &GetFilterSeriesByAgeGroups() const
        {
            return mFilterSeriesByAgeGroups;
        }

        void SetFilterSeriesByAgeGroups(const Link &filterSeriesByAgeGroups)
        {
            mFilterSeriesByAgeGroups = filterSeriesByAgeGroups;
        }

        const Link &GetSearchBundles() const
        {
            return mSearchBundles;
        }

        void SetSearchBundles(const Link &searchBundles)
        {
            mSearchBundles = searchBundles;
        }

        const Link &GetAllPublicUserLists() const
        {
            return mAllPublicUserLists;
        }

        void SetAllPublicUserLists(const Link &allPublicUserLists)
        {
            mAllPublicUserLists = allPublicUserLists;
        }

        const DeviceAuthData &GetDeviceAuthData() const
        {
            return mDeviceAuthData;
        }

        void SetDeviceAuthData(const DeviceAuthData &deviceAuthData)
        {
            mDeviceAuthData = deviceAuthData;
        }

        const std::string &GetApiVersion() const
        {
            return mApiVersion;
        }

        void SetApiVersion(const std::string &apiVersion)
        {
            mApiVersion = apiVersion;
        }

        const std::string &GetApiDocumentationLink() const
        {
            return mApiDocumentationLink;
        }

        void SetApiDocumentationLink(const std::string &apiDocumentationLink)
        {
            mApiDocumentationLink = apiDocumentationLink;
        }

        const Crud &GetManageFreePages() const
        {
            return mManageFreePages;
        }

        void SetManageFreePages(const Crud &manageFreePages)
        {
            mManageFreePages = manageFreePages;
        }

        const Link &GetSearchMoviesByPerson() const
        {
            return mSearchMoviesByPerson;
        }

        void SetSearchMoviesByPerson(const Link &searchMoviesByPerson)
        {
            mSearchMoviesByPerson = searchMoviesByPerson;
        }

        const Link &GetCreateMppSession() const
        {
            return mCreateMppSession;
        }

        void SetCreateMppSession(const Link &createMppSession)
        {
            mCreateMppSession = createMppSession;
        }

        const Link &GetMppUserExists() const
        {
            return mMppUserExists;
        }

        void SetMppUserExists(const Link &mppUserExists)
        {
            mMppUserExists = mppUserExists;
        }

        const Link &GetAllLists() const
        {
            return mAllLists;
        }

        void SetAllLists(const Link &allLists)
        {
            mAllLists = allLists;
        }

    private:
        std::string mId;
        std::string mManufacturer;
        std::string mModel;
        std::string mUdId;
        std::string mDeviceInfo;
        std::string mLastUsedDate;
        std::string mLastUsedIP;
        std::string mRegistrationDate;
        Link mHome;
        Link mHelps;
        Link mLiterals;
        Link mLogin;
        Form mRegister;
        Form mForgotPassword;
        std::vector<std::string> mAvailablePaymentMethods;
        Link mSelf;
        Link mSearch;
        Link mSearchAsYouType;
        Link mSearchMovies;
        Link mFilterMoviesByAgeGroups;
        Link mSearchSeries;
        Link mFilterSeriesByAgeGroups;
        Link mSearchBundles;
        Link mAllPublicUserLists;
        DeviceAuthData mDeviceAuthData;
        std::string mApiVersion;
        std::string mApiDocumentationLink;
        Crud mManageFreePages;
        Link mSearchMoviesByPerson;
        Link mCreateMppSession;
        Link mMppUserExists;
        Link mAllLists;
    };
}

#endif //READY4AIR_DEVICE_H
