#ifndef READY4AIR_CAST_H
#define READY4AIR_CAST_H

#include "abstract/JsonDeserializable.h"

namespace ready4air
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

        const std::string &GetId() const
        {
            return mId;
        }

        void SetId(const std::string &id)
        {
            mId = id;
        }

        short GetCategoryId() const
        {
            return mCategoryId;
        }

        void SetCategoryId(short categoryId)
        {
            mCategoryId = categoryId;
        }

        const std::string &GetCategoryName() const
        {
            return mCategoryName;
        }

        void SetCategoryName(const std::string &categoryName)
        {
            mCategoryName = categoryName;
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

        const std::string &GetMiddleName() const
        {
            return mMiddleName;
        }

        void SetMiddleName(const std::string &middleName)
        {
            mMiddleName = middleName;
        }

        const std::string &GetFullName() const
        {
            return mFullName;
        }

        void SetFullName(const std::string &fullName)
        {
            mFullName = fullName;
        }

        virtual bool InitFromJsonValue(const rapidjson::Value &value)
        {
            // Mandatory property
            if (!value.HasMember("Id") || !value["Id"].IsString()) return false;
            SetId(value["Id"].GetString());

            // Mandatory property
            if (!value.HasMember("CategoryId") || !value["CategoryId"].IsInt()) return false;
            SetCategoryId((short) value["CategoryId"].GetInt());

            // Mandatory property
            if (!value.HasMember("CategoryName") || !value["CategoryName"].GetString()) return false;
            SetCategoryName(value["CategoryName"].GetString());

            // Non-mandatory property
            if (value.HasMember("FirstName"))
            {
                if (!value["FirstName"].IsString()) return false;
                SetFirstName(value["FirstName"].GetString());
            }

            // Non-mandatory property
            if (value.HasMember("LastName"))
            {
                if (!value["LastName"].IsString()) return false;
                SetLastName(value["LastName"].GetString());
            }

            // Non-mandatory property
            if (value.HasMember("MiddleName"))
            {
                if (!value["MiddleName"].IsString()) return false;
                SetMiddleName(value["MiddleName"].GetString());
            }

            // Mandatory property
            if (!value.HasMember("FullName") || !value["FullName"].GetString()) return false;
            SetFullName(value["FullName"].GetString());

            return true;
        }

    private:
        std::string mId;
        short mCategoryId;
        std::string mCategoryName;
        std::string mFirstName;
        std::string mLastName;
        std::string mMiddleName;
        std::string mFullName;
    };
}

#endif //READY4AIR_CAST_H
