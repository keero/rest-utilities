//
// Created by Martin Kero on 05/01/16.
//

#ifndef REST_UTILITIES_MAYBE_H
#define REST_UTILITIES_MAYBE_H

namespace ready4air
{
    template<typename T>
    class Maybe
    {
    public:
        Maybe() :
                mNothing(true)
        {
        }

        virtual ~Maybe()
        {
        }

        void Unset()
        {
            mNothing = true;
        }

        bool Nothing() const
        {
            return mNothing;
        }

        const T &Just() const
        {
            return mJust;
        }

        inline Maybe <T> &operator=(const T &rhs)
        {
            mJust = rhs;
            mNothing = false;
            return *this;
        }

        inline friend bool operator==(const Maybe &lhs, const Maybe &rhs)
        {
            return (lhs.mNothing && rhs.mNothing)
                || (!lhs.mNothing && !rhs.mNothing && lhs.mJust == rhs.mJust);
        }

        inline friend bool operator==(const Maybe<T> &lhs, const T &rhs)
        {
            return (!lhs.mNothing && lhs.mJust == rhs);
        }

        inline friend bool operator==(const T &lhs, const Maybe<T> &rhs)
        {
            return rhs == lhs;
        }

        inline friend bool operator!=(const Maybe &lhs, const Maybe &rhs)
        {
            return !(lhs == rhs);
        }

        inline friend std::ostream &operator<<(std::ostream &str, const Maybe &rhs)
        {
            if (rhs.Nothing())
                return str;
            else
                return (str << rhs.Just());
        }

    private:
        bool mNothing;
        T mJust;
    };
}

#endif //REST_UTILITIES_MAYBE_H
