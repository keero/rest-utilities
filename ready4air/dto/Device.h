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

        const Form &GetRegister() const
        {
            return mRegister;
        }

        void SetRegister(const Form &aRegister)
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

        virtual bool InitFromJsonValue(const rapidjson::Value &value)
        {
            {
                // Mandatory property
                if (!value.HasMember("Id") || !value["Id"].IsString()) return false;
                SetId(value["Id"].GetString());
            }
            {
                // Non-mandatory property
                if (value.HasMember("Manufacturer"))
                {
                    if (!value["Manufacturer"].IsString()) return false;
                    SetManufacturer(value["Manufacturer"].GetString());
                }
            }
            {
                // Non-mandatory property
                if (value.HasMember("Model"))
                {
                    if (!value["Model"].IsString()) return false;
                    SetModel(value["Model"].GetString());
                }
            }
            {
                // Mandatory property
                if (!value.HasMember("UdId") || !value["UdId"].IsString()) return false;
                SetUdId(value["UdId"].GetString());
            }
            {
                // Non-mandatory property
                if (value.HasMember("DeviceInfo"))
                {
                    if (!value["DeviceInfo"].IsString()) return false;
                    SetDeviceInfo(value["DeviceInfo"].GetString());
                }
            }
            {
                // Mandatory property
                if (!value.HasMember("LastUsedDate") || !value["LastUsedDate"].IsString()) return false;
                SetLastUsedDate(value["LastUsedDate"].GetString());
            }
            {
                // Non-mandatory property
                if (value.HasMember("LastUsedIP"))
                {
                    if (!value["LastUsedIP"].IsString()) return false;
                    SetLastUsedIP(value["LastUsedIP"].GetString());
                }
            }
            {
                // Mandatory property
                if (!value.HasMember("RegistrationDate") || !value["RegistrationDate"].IsString()) return false;
                SetRegistrationDate(value["RegistrationDate"].GetString());
            }
            {
                // Mandatory property
                Link home;
                if (!value.HasMember("Home") || !value["Home"].IsObject() || !home.InitFromJsonValue(value["Home"])) return false;
                SetHome(home);
            }
            {
                // Mandatory property
                Link helps;
                if (!value.HasMember("Helps") || !value["Helps"].IsObject() || !helps.InitFromJsonValue(value["Helps"])) return false;
                SetHelps(helps);
            }
            {
                // Mandatory property
                Link literals;
                if (!value.HasMember("Literals") || !value["Literals"].IsObject() || !literals.InitFromJsonValue(value["Literals"])) return false;
                SetLiterals(literals);
            }
            {
                // Mandatory property
                Link login;
                if (!value.HasMember("Login") || !value["Login"].IsObject() || !login.InitFromJsonValue(value["Login"])) return false;
                SetLogin(login);
            }
            {
                // Non-mandatory property
                if (value.HasMember("Register"))
                {
                    Form aRegister;
                    if (!value["Register"].IsObject() || !aRegister.InitFromJsonValue(value["Register"])) return false;
                    SetRegister(aRegister);
                }
            }
            {
                // Non-mandatory property
                if (value.HasMember("ForgotPassword"))
                {
                    Form forgotPassword;
                    if (!value["ForgotPassword"].IsObject() || !forgotPassword.InitFromJsonValue(value["ForgotPassword"])) return false;
                    SetForgotPassword(forgotPassword);
                }
            }
            {
                // Mandatory property
                if (!value.HasMember("AvailablePaymentMethods") || !value["AvailablePaymentMethods"].IsArray()) return false;
                std::vector<std::string> availablePaymentMethods;
                for (rapidjson::SizeType i = 0; i < value["AvailablePaymentMethods"].Size(); i += 1)
                {
                    if (!value["AvailablePaymentMethods"][i].IsString()) return false;
                    availablePaymentMethods.push_back(value["AvailablePaymentMethods"][i].GetString());
                }
                SetAvailablePaymentMethods(availablePaymentMethods);
            }
            {
                // Non-mandatory property
                if (value.HasMember("Self"))
                {
                    Link self;
                    if (!value["Self"].IsObject() || !self.InitFromJsonValue(value["Self"])) return false;
                    SetSelf(self);
                }
            }
            {
                // Mandatory property
                Link search;
                if (!value.HasMember("Search") || !value["Search"].IsObject() || !search.InitFromJsonValue(value["Search"])) return false;
                SetSearch(search);
            }
            {
                // Mandatory property
                Link searchAsYouType;
                if (!value.HasMember("SearchAsYouType") || !value["SearchAsYouType"].IsObject() || !searchAsYouType.InitFromJsonValue(value["SearchAsYouType"])) return false;
                SetSearchAsYouType(searchAsYouType);
            }
            {
                // Mandatory property
                Link searchMovies;
                if (!value.HasMember("SearchMovies") || !value["SearchMovies"].IsObject() || !searchMovies.InitFromJsonValue(value["SearchMovies"])) return false;
                SetSearchMovies(searchMovies);
            }
            {
                // Mandatory property
                Link filterMoviesByAgeGroups;
                if (!value.HasMember("FilterMoviesByAgeGroups") || !value["FilterMoviesByAgeGroups"].IsObject() || !filterMoviesByAgeGroups.InitFromJsonValue(value["FilterMoviesByAgeGroups"])) return false;
                SetFilterMoviesByAgeGroups(filterMoviesByAgeGroups);
            }
            {
                // Mandatory property
                Link searchSeries;
                if (!value.HasMember("SearchSeries") || !value["SearchSeries"].IsObject() || !searchSeries.InitFromJsonValue(value["SearchSeries"])) return false;
                SetSearchSeries(searchSeries);
            }
            {
                // Mandatory property
                Link filterSeriesByAgeGroups;
                if (!value.HasMember("FilterSeriesByAgeGroups") || !value["FilterSeriesByAgeGroups"].IsObject() || !filterSeriesByAgeGroups.InitFromJsonValue(value["FilterSeriesByAgeGroups"])) return false;
                SetFilterSeriesByAgeGroups(filterSeriesByAgeGroups);
            }
            {
                // Mandatory property
                Link searchBundles;
                if (!value.HasMember("SearchBundles") || !value["SearchBundles"].IsObject() || !searchBundles.InitFromJsonValue(value["SearchBundles"])) return false;
                SetSearchBundles(searchBundles);
            }
            {
                // Non-mandatory property
                if (value.HasMember("AllPublicUserLists"))
                {
                    Link allPublicUserLists;
                    if (!value["AllPublicUserLists"].IsObject() || !allPublicUserLists.InitFromJsonValue(value["AllPublicUserLists"])) return false;
                    SetAllPublicUserLists(allPublicUserLists);
                }
            }
            {
                // Mandatory property
                DeviceAuthData deviceAuthData;
                if (!value.HasMember("DeviceAuthData") || !value["DeviceAuthData"].IsObject() || !deviceAuthData.InitFromJsonValue(value["DeviceAuthData"])) return false;
                SetDeviceAuthData(deviceAuthData);
            }
            {
                // Non-mandatory property
                if (value.HasMember("ApiVersion"))
                {
                    if (!value["ApiVersion"].IsString()) return false;
                    SetApiVersion(value["ApiVersion"].GetString());
                }
            }
            {
                // Non-mandatory property
                if (value.HasMember("ApiDocumentationLink"))
                {
                    if (!value["ApiDocumentationLink"].IsString()) return false;
                    SetApiDocumentationLink(value["ApiDocumentationLink"].GetString());
                }
            }
            {
                // Non-mandatory property
                if (value.HasMember("ManageFreePages"))
                {
                    Crud manageFreePages;
                    if (!value["ManageFreePages"].IsObject() || !manageFreePages.InitFromJsonValue(value["ManageFreePages"])) return false;
                    SetManageFreePages(manageFreePages);
                }
            }
            {
                // Mandatory property
                Link searchMoviesByPerson;
                if (!value.HasMember("SearchMoviesByPerson") || !value["SearchMoviesByPerson"].IsObject() || !searchMoviesByPerson.InitFromJsonValue(value["SearchMoviesByPerson"])) return false;
                SetSearchMoviesByPerson(searchMoviesByPerson);
            }
            {
                // Non-mandatory property
                if (value.HasMember("CreateMppSession"))
                {
                    Link createMppSession;
                    if (!value["CreateMppSession"].IsObject() || !createMppSession.InitFromJsonValue(value["CreateMppSession"])) return false;
                    SetCreateMppSession(createMppSession);
                }
            }
            {
                // Non-mandatory property
                if (value.HasMember("MppUserExists"))
                {
                    Link mppUserExists;
                    if (!value["MppUserExists"].IsObject() || !mppUserExists.InitFromJsonValue(value["MppUserExists"])) return false;
                    SetMppUserExists(mppUserExists);
                }
            }
            {
                // Non-mandatory property
                if (value.HasMember("AllLists"))
                {
                    Link allLists;
                    if (!value["AllLists"].IsObject() || !allLists.InitFromJsonValue(value["AllLists"])) return false;
                    SetAllLists(allLists);
                }
            }

            return true;
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
