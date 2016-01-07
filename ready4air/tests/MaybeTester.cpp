#include <iostream>
#include "../maybe/Maybe.h"

int main()
{
    ready4air::Maybe<std::string> maybeString, maybeString2, maybeString3, maybeString4;
    ready4air::Maybe<int> maybeInt;
    std::cout << "maybeString = " << (!maybeString ? "Nothing" : maybeString.Just()) << std::endl;
    maybeString = "Apa";
    std::cout << "maybeString = " << (!maybeString ? "Nothing" : maybeString.Just()) << std::endl;
    maybeString.Unset();
    std::cout << "maybeString = " << (!maybeString ? "Nothing" : maybeString.Just()) << std::endl;

    std::cout << "maybeString2 " << (maybeString2 == maybeString3 ? "==" : "!=") << " maybeString3" << std::endl;
    maybeString2 = "Bepa";
    std::cout << "maybeString2 " << (maybeString2 == maybeString3 ? "==" : "!=") << " maybeString3" << std::endl;
    maybeString3 = "Bepa";
    std::cout << "maybeString2 " << (maybeString2 != maybeString3 ? "!=" : "==") << " maybeString3" << std::endl;
    maybeString3 = "Cepa";
    std::cout << "maybeString2 " << (maybeString2 != maybeString3 ? "!=" : "==") << " maybeString3" << std::endl;

    std::cout << "maybeString2 " << (maybeString2 == "Cepa" ? "!=" : "==") << " \"Cepa\"" << std::endl;
    std::cout << "\"Cepa\" " << ("Cepa" == maybeString2 ? "!=" : "==") << " maybeString2" << std::endl;

    std::cout << "maybeString2 = " << maybeString2 << std::endl;
    std::cout << "maybeString4 = " << maybeString4 << std::endl;
    std::cout << "maybeInt = " << maybeInt << std::endl;
    maybeInt = 1234;
    std::cout << "maybeInt = " << maybeInt << std::endl;

    return 0;
}