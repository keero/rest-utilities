#include <iostream>
#include "../common/Regex.h"

int main(void)
{
    VECTOR_T<STRING_T> matches;
    STRING_T exprRegex = "^\\{([^\\{\\}]+)\\}";
    STRING_T literalRegex = "([^\\{\\}]+)";

    STRING_T subject = "https://pp.sfkids.com/Neonstingray.Nettv4.RestApi/api/{country}/{device}/lists{?language,take,skip}&genres=Include&listType=-1";

    STRING_T match;
    STRING_T rest;

    while (subject.length() > 0)
    {
        if (ready4air::Regex::MatchSingle(exprRegex, subject, match, rest))
        {
            std::cout << "Found expression: " << match << std::endl;
        }
        else if (ready4air::Regex::MatchSingle(literalRegex, subject, match, rest))
        {
            std::cout << "Found literal: " << match << std::endl;
        }
        else
        {
            std::cout << "Failed to parse/match regex against subject: " << subject << std::endl;
            break;
        }
        //std::cout << "Rest is: " << rest << std::endl;
        subject = rest;
    }

    VECTOR_T<STRING_T> items;
    ready4air::Regex::Split("(%[[:xdigit:]]{2})", "a,b,c,d", items);

    for (size_t i = 0; i < items.size(); i += 1)
    {
        std::cout << "\"" << items[i] << "\"" << std::endl;
    }
//    BOOL_T exprMatch = ready4air::Regex::MatchSingle(exprRegex, )
//    while (ready4air::Regex::MatchSingle(exprRegex))
//    BOOL_T result = ready4air::Regex::Match("\\{([^\\{\\}]+)\\}.*$", "https://pp.sfkids.com/Neonstingray.Nettv4.RestApi/api/se/19/lists{?language,take,skip}&genres=Include&listType=-1", 2, matches);
//
//    if (result)
//    {
//        std::cout << "Successfully matched following:" << std::endl;
//        for(size_t i = 0; i < matches.size(); i += 1)
//        {
//            std::cout << matches[i] << std::endl;
//        }
//    }
//    else
//    {
//        std::cout << "Failed to parse/match regex against subject." << std::endl;
//    }
    return 0;
}