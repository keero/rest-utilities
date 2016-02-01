#ifndef READY4AIR_DEVICE_H
#define READY4AIR_DEVICE_H

#include "../common/Maybe.h"
#include "abstract/JsonDeserializable.h"
#include "hypermedia/Link.h"
#include "hypermedia/Form.h"
#include "DeviceAuthData.h"
#include "hypermedia/Crud.h"

namespace ready4air
{
    namespace dto
    {
        class Device : public JsonDeserializable
        {
        public:
            Device() : TAG("ready4air::dto::Device")
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
            STRING_T TAG;
        };
    }
}

#endif //READY4AIR_DEVICE_H
