#ifndef READY4AIR_MAYBE_H
#define READY4AIR_MAYBE_H

#include <iostream>
#include "Predefine.h"

namespace ready4air
{
    template<typename T>
    class Maybe
    {
    public:
        Maybe() :
                Just(mJust),
                mNothing(true),
                TAG("ready4air::Maybe")
        {
        }

        Maybe(T item) :
                mJust(item),
                Just(mJust),
                mNothing(false),
                TAG("ready4air::Maybe")
        {
        }

        virtual ~Maybe()
        {
        }

        void Unset()
        {
            mNothing = true;
        }

        inline operator BOOL_T() const
        {
            return !mNothing;
        }

        inline Maybe <T> &operator=(const T &rhs)
        {
            mJust = rhs;
            mNothing = false;
            return *this;
        }

        inline friend BOOL_T operator==(const Maybe &lhs, const Maybe &rhs)
        {
            return (lhs.mNothing && rhs.mNothing)
                || (!lhs.mNothing && !rhs.mNothing && lhs.Just == rhs.Just);
        }

        inline friend BOOL_T operator==(const Maybe<T> &lhs, const T &rhs)
        {
            return (!lhs.mNothing && lhs.Just == rhs);
        }

        inline friend BOOL_T operator==(const T &lhs, const Maybe<T> &rhs)
        {
            return rhs == lhs;
        }

        inline friend BOOL_T operator!=(const Maybe &lhs, const Maybe &rhs)
        {
            return !(lhs == rhs);
        }

        inline friend BOOL_T operator!=(const Maybe<T> &lhs, const T &rhs)
        {
            return !(lhs == rhs);
        }

        inline friend BOOL_T operator!=(const T &lhs, const Maybe<T> &rhs)
        {
            return !(lhs == rhs);
        }

        inline friend std::ostream &operator<<(std::ostream &str, const Maybe &rhs)
        {
            if (!rhs)
                return str;
            else
                return (str << rhs.Just);
        }

    public:
        const T &Just;

    private:
        T mJust;
        BOOL_T mNothing;
        STRING_T TAG;
    };
}

#endif //READY4AIR_MAYBE_H
