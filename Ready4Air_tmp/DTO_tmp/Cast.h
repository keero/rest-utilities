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
