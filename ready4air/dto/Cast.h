#ifndef READY4AIR_CAST_H
#define READY4AIR_CAST_H

#include "../maybe/Maybe.h"
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

        const Maybe <std::string> &GetId() const
        {
            return mId;
        }

        void SetId(const std::string &id)
        {
            mId = id;
        }

        const Maybe <short> &GetCategoryId() const
        {
            return mCategoryId;
        }

        void SetCategoryId(short categoryId)
        {
            mCategoryId = categoryId;
        }

        const Maybe <std::string> &GetCategoryName() const
        {
            return mCategoryName;
        }

        void SetCategoryName(const std::string &categoryName)
        {
            mCategoryName = categoryName;
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

        const Maybe <std::string> &GetMiddleName() const
        {
            return mMiddleName;
        }

        void SetMiddleName(const std::string &middleName)
        {
            mMiddleName = middleName;
        }

        const Maybe <std::string> &GetFullName() const
        {
            return mFullName;
        }

        void SetFullName(const std::string &fullName)
        {
            mFullName = fullName;
        }

        virtual bool InitFromJsonValue(const rapidjson::Value &value, ParseErrors &parseErrors)
        {
            std::string id;
            int categoryId;
            std::string categoryName;
            std::string firstName;
            std::string lastName;
            std::string middleName;
            std::string fullName;

            if (ParseString(value, "Id", true, id, parseErrors))
                SetId(id);

            if (ParseInt(value, "CategoryId", true, categoryId, parseErrors))
                SetCategoryId((short) categoryId);

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
        Maybe <std::string> mId;
        Maybe <short> mCategoryId;
        Maybe <std::string> mCategoryName;
        Maybe <std::string> mFirstName;
        Maybe <std::string> mLastName;
        Maybe <std::string> mMiddleName;
        Maybe <std::string> mFullName;
    };
}

#endif //READY4AIR_CAST_H
