#ifndef READY4AIR_EITHER_H
#define READY4AIR_EITHER_H


#include "Maybe.h"

namespace ready4air
{
    template<typename LEFT, typename RIGHT>
    class Either
    {
    public:
        Either() : TAG("ready4air::Either")
        {
        }

        virtual ~Either()
        {
        }

        const Maybe <LEFT> &Left() const
        {
            return mLeft;
        }

        const Maybe <RIGHT> &Right() const
        {
            return mRight;
        }

        inline operator BOOL_T() const
        {
            return (mLeft || mRight);
        }

        inline Either <LEFT, RIGHT> &operator=(const LEFT &rhs)
        {
            mLeft = rhs;
            mRight.Unset();
            return *this;
        }

        inline Either <LEFT, RIGHT> &operator=(const RIGHT &rhs)
        {
            mRight = rhs;
            mLeft.Unset();
            return *this;
        }

        inline friend BOOL_T operator==(const Either &lhs, const Either &rhs)
        {
            return (lhs.Left() == rhs.Left() && lhs.Right() == rhs.Right());
        }

        inline friend BOOL_T operator==(const Either <LEFT, RIGHT> &lhs, const LEFT &rhs)
        {
            return (lhs.Left().Just() == rhs);
        }

        inline friend BOOL_T operator==(const Either <LEFT, RIGHT> &lhs, const RIGHT &rhs)
        {
            return (lhs.Right().Just() == rhs);
        }

        inline friend BOOL_T operator==(const LEFT &lhs, const Either <LEFT, RIGHT> &rhs)
        {
            return rhs == lhs;
        }

        inline friend BOOL_T operator==(const RIGHT &lhs, const Either <LEFT, RIGHT> &rhs)
        {
            return rhs == lhs;
        }

        inline friend BOOL_T operator!=(const Either &lhs, const Either &rhs)
        {
            return !(lhs == rhs);
        }

        inline friend BOOL_T operator!=(const Either <LEFT, RIGHT> &lhs, const LEFT &rhs)
        {
            return !(lhs == rhs);
        }

        inline friend BOOL_T operator!=(const Either <LEFT, RIGHT> &lhs, const RIGHT &rhs)
        {
            return !(lhs == rhs);
        }

        inline friend BOOL_T operator!=(const LEFT &lhs, const Either <LEFT, RIGHT> &rhs)
        {
            return !(lhs == rhs);
        }

        inline friend BOOL_T operator!=(const RIGHT &lhs, const Either <LEFT, RIGHT> &rhs)
        {
            return !(lhs == rhs);
        }

        inline friend std::ostream &operator<<(std::ostream &str, const Either &rhs)
        {
            return str << rhs.Left() << rhs.Right();
        }

    private:
        Maybe <LEFT> mLeft;
        Maybe <RIGHT> mRight;
        const STRING_T TAG;
    };
}

#endif //READY4AIR_EITHER_H
