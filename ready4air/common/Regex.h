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
        static bool Match(const std::string &regex, const std::string &subject, size_t nmatches, std::vector<std::string> &matches)
        {
            bool result = false;
            regex_t re;
            regmatch_t regexmatches[nmatches];
            int reti;
            reti = regcomp(&re, regex.c_str(), REG_EXTENDED);

            if (!reti)
            {
                reti = regexec(&re, subject.c_str(), nmatches, regexmatches, 0);

                if (!reti)
                {
                    for (size_t i = 0; i < nmatches; i += 1)
                    {
                        std::string currMatch(subject.substr((unsigned long) regexmatches[i].rm_so, (unsigned long) regexmatches[i].rm_eo - regexmatches[i].rm_so));
                        matches.push_back(currMatch);
                    }
                    result = true;
                }
            }
            regfree(&re);
            return result;
        }

        static bool Match(const std::string &regex, const std::string &subject)
        {
            std::vector<std::string> _unused;
            return Match(regex, subject, 2, _unused);
        }

        static bool MatchSingle(const std::string &regex, const std::string &subject, std::string &match, std::string &rest)
        {
            bool result = false;
            regex_t re;
            regmatch_t regexmatches[2];
            int reti;
            reti = regcomp(&re, regex.c_str(), REG_EXTENDED);

            if (!reti)
            {
                reti = regexec(&re, subject.c_str(), 2, regexmatches, 0);

                if (!reti)
                {
                    match = subject.substr((unsigned long) regexmatches[1].rm_so, (unsigned long) regexmatches[1].rm_eo - regexmatches[1].rm_so);
                    rest = subject.substr((unsigned long) regexmatches[1].rm_eo);
                    result = true;
                }
            }
            regfree(&re);
            return result;
        }

        static bool Split(const std::string & regex, const std::string &subject, std::vector<std::string> &matches)
        {
            bool result = true;
            regex_t re;
            regmatch_t regexmatches[2];
            int reti;
            reti = regcomp(&re, regex.c_str(), REG_EXTENDED);

            if (!reti)
            {
                std::string subj(subject);

                while(subj.length() > 0 && !regexec(&re, subj.c_str(), 2, regexmatches, 0))
                {
                    matches.push_back(subj.substr(0, (unsigned long) regexmatches[1].rm_so));
                    subj = subj.substr((unsigned long) regexmatches[1].rm_eo);
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
