#ifndef READY4AIR_CAST_H
#define READY4AIR_CAST_H

#include "../common/Maybe.h"
#include "abstract/JsonDeserializable.h"

namespace ready4air
{
    namespace dto
    {
        class Cast : public JsonDeserializable
        {

        public:
            Cast() : TAG("ready4air::dto::Cast")
            {
            }

            virtual ~Cast()
            {
            }

            const Maybe <STRING_T> &GetId() const
            {
                return mId;
            }

            void SetId(const STRING_T &id)
            {
                mId = id;
            }

            const Maybe<INT16_T> &GetCategoryId() const
            {
                return mCategoryId;
            }

            void SetCategoryId(INT16_T categoryId)
            {
                mCategoryId = categoryId;
            }

            const Maybe <STRING_T> &GetCategoryName() const
            {
                return mCategoryName;
            }

            void SetCategoryName(const STRING_T &categoryName)
            {
                mCategoryName = categoryName;
            }

            const Maybe <STRING_T> &GetFirstName() const
            {
                return mFirstName;
            }

            void SetFirstName(const STRING_T &firstName)
            {
                mFirstName = firstName;
            }

            const Maybe <STRING_T> &GetLastName() const
            {
                return mLastName;
            }

            void SetLastName(const STRING_T &lastName)
            {
                mLastName = lastName;
            }

            const Maybe <STRING_T> &GetMiddleName() const
            {
                return mMiddleName;
            }

            void SetMiddleName(const STRING_T &middleName)
            {
                mMiddleName = middleName;
            }

            const Maybe <STRING_T> &GetFullName() const
            {
                return mFullName;
            }

            void SetFullName(const STRING_T &fullName)
            {
                mFullName = fullName;
            }

            virtual BOOL_T InitFromJsonValue(const rapidjson::Value &value, ParseErrors &parseErrors,
                                             VECTOR_T<STRING_T> &context)
            {
                STRING_T id;
                INT32_T categoryId;
                STRING_T categoryName;
                STRING_T firstName;
                STRING_T lastName;
                STRING_T middleName;
                STRING_T fullName;

                context.push_back(TAG);

                if (ParseString(value, "Id", true, id, parseErrors, context))
                    SetId(id);

                if (ParseInt(value, "CategoryId", true, categoryId, parseErrors, context))
                    SetCategoryId((INT16_T) categoryId);

                if (ParseString(value, "CategoryName", true, categoryName, parseErrors, context))
                    SetCategoryName(categoryName);

                if (ParseString(value, "FirstName", false, firstName, parseErrors, context))
                    SetFirstName(firstName);

                if (ParseString(value, "LastName", false, lastName, parseErrors, context))
                    SetLastName(lastName);

                if (ParseString(value, "MiddleName", false, middleName, parseErrors, context))
                    SetMiddleName(middleName);

                if (ParseString(value, "FullName", true, fullName, parseErrors, context))
                    SetFullName(fullName);

                context.pop_back();
                return !parseErrors;
            }

        private:
            Maybe <STRING_T> mId;
            Maybe<INT16_T> mCategoryId;
            Maybe <STRING_T> mCategoryName;
            Maybe <STRING_T> mFirstName;
            Maybe <STRING_T> mLastName;
            Maybe <STRING_T> mMiddleName;
            Maybe <STRING_T> mFullName;
            STRING_T TAG;
        };
    }
}

#endif //READY4AIR_CAST_H
