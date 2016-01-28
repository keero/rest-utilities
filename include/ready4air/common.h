#include "predefs.h"
#ifndef READY4AIR_REGEX_H
#define READY4AIR_REGEX_H
#include <regex.h>
#include <string>
#include <vector>
namespace ready4air
{
    class Regex
    {
    public:
        static BOOL_T Match(const STRING_T &regex, const STRING_T &subject, size_t nmatches, VECTOR_T<STRING_T> &matches)
        {
            BOOL_T result = false;
            regex_t re;
            regmatch_t regexmatches[nmatches];
            INT32_T reti;
            reti = regcomp(&re, regex.c_str(), REG_EXTENDED);
            if (!reti)
            {
                reti = regexec(&re, subject.c_str(), nmatches, regexmatches, 0);
                if (!reti)
                {
                    for (size_t i = 0; i < nmatches; i += 1)
                    {
                        STRING_T currMatch(subject.substr((UINT64_T) regexmatches[i].rm_so, (UINT64_T) regexmatches[i].rm_eo - regexmatches[i].rm_so));
                        matches.push_back(currMatch);
                    }
                    result = true;
                }
            }
            regfree(&re);
            return result;
        }
        static BOOL_T Match(const STRING_T &regex, const STRING_T &subject)
        {
            VECTOR_T<STRING_T> _unused;
            return Match(regex, subject, 2, _unused);
        }
        static BOOL_T MatchSingle(const STRING_T &regex, const STRING_T &subject, STRING_T &match, STRING_T &rest)
        {
            BOOL_T result = false;
            regex_t re;
            regmatch_t regexmatches[2];
            INT32_T reti;
            reti = regcomp(&re, regex.c_str(), REG_EXTENDED);
            if (!reti)
            {
                reti = regexec(&re, subject.c_str(), 2, regexmatches, 0);
                if (!reti)
                {
                    match = subject.substr((UINT64_T) regexmatches[1].rm_so, (UINT64_T) regexmatches[1].rm_eo - regexmatches[1].rm_so);
                    rest = subject.substr((UINT64_T) regexmatches[1].rm_eo);
                    result = true;
                }
            }
            regfree(&re);
            return result;
        }
        static BOOL_T Split(const STRING_T & regex, const STRING_T &subject, VECTOR_T<STRING_T> &matches)
        {
            BOOL_T result = true;
            regex_t re;
            regmatch_t regexmatches[2];
            INT32_T reti;
            reti = regcomp(&re, regex.c_str(), REG_EXTENDED);
            if (!reti)
            {
                STRING_T subj(subject);
                while(subj.length() > 0 && !regexec(&re, subj.c_str(), 2, regexmatches, 0))
                {
                    matches.push_back(subj.substr(0, (UINT64_T) regexmatches[1].rm_so));
                    subj = subj.substr((UINT64_T) regexmatches[1].rm_eo);
                }
                if (subj.length() > 0)
                {
                    matches.push_back(subj);
                }
            }
            regfree(&re);
            return result;
        }
    };
}
#endif //REST_UTILITIES_REGEX_H

#ifndef READY4AIR_MAYBE_H
#define READY4AIR_MAYBE_H
#include <iostream>
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
        const T &Just() const
        {
            return mJust;
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
                || (!lhs.mNothing && !rhs.mNothing && lhs.mJust == rhs.mJust);
        }
        inline friend BOOL_T operator==(const Maybe<T> &lhs, const T &rhs)
        {
            return (!lhs.mNothing && lhs.mJust == rhs);
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
                return (str << rhs.Just());
        }
    private:
        BOOL_T mNothing;
        T mJust;
    };
}
#endif //READY4AIR_MAYBE_H

#ifndef READY4AIR_EITHER_H
#define READY4AIR_EITHER_H
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
    };
}
#endif //READY4AIR_EITHER_H

