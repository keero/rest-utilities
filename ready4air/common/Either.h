//
// Created by Martin Kero on 13/01/16.
//

#ifndef REST_UTILITIES_EITHER_H
#define REST_UTILITIES_EITHER_H


#include "Maybe.h"

namespace ready4air
{
    template<typename LEFT, typename RIGHT>
    class Either
    {
    public:
        Either()
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

        inline operator bool() const
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

        inline friend bool operator==(const Either &lhs, const Either &rhs)
        {
            return (lhs.Left() == rhs.Left() && lhs.Right() == rhs.Right());
        }

        inline friend bool operator==(const Either <LEFT, RIGHT> &lhs, const LEFT &rhs)
        {
            return (lhs.Left().Just() == rhs);
        }

        inline friend bool operator==(const Either <LEFT, RIGHT> &lhs, const RIGHT &rhs)
        {
            return (lhs.Right().Just() == rhs);
        }

        inline friend bool operator==(const LEFT &lhs, const Either <LEFT, RIGHT> &rhs)
        {
            return rhs == lhs;
        }

        inline friend bool operator==(const RIGHT &lhs, const Either <LEFT, RIGHT> &rhs)
        {
            return rhs == lhs;
        }

        inline friend bool operator!=(const Either &lhs, const Either &rhs)
        {
            return !(lhs == rhs);
        }

        inline friend bool operator!=(const Either <LEFT, RIGHT> &lhs, const LEFT &rhs)
        {
            return !(lhs == rhs);
        }

        inline friend bool operator!=(const Either <LEFT, RIGHT> &lhs, const RIGHT &rhs)
        {
            return !(lhs == rhs);
        }

        inline friend bool operator!=(const LEFT &lhs, const Either <LEFT, RIGHT> &rhs)
        {
            return !(lhs == rhs);
        }

        inline friend bool operator!=(const RIGHT &lhs, const Either <LEFT, RIGHT> &rhs)
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
    };
}

#endif //REST_UTILITIES_EITHER_H
