#ifndef READY4AIR_REGEX_H
#define READY4AIR_REGEX_H

#include "Predefine.h"
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
