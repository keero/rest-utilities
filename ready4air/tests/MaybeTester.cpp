#include <iostream>
#include "../maybe/Maybe.h"

int main()
{
    ready4air::Maybe<std::string> maybeString, maybeString2, maybeString3;
    std::cout << "maybeString = " << (maybeString.Nothing() ? "Nothing" : maybeString.Just()) << std::endl;
    maybeString.Set("Apa");
    std::cout << "maybeString = " << (maybeString.Nothing() ? "Nothing" : maybeString.Just()) << std::endl;
    maybeString.Unset();
    std::cout << "maybeString = " << (maybeString.Nothing() ? "Nothing" : maybeString.Just()) << std::endl;

    std::cout << "maybeString2 " << (maybeString2 == maybeString3 ? "==" : "!=") << " maybeString3" << std::endl;
    maybeString2.Set("Bepa");
    std::cout << "maybeString2 " << (maybeString2 == maybeString3 ? "==" : "!=") << " maybeString3" << std::endl;
    maybeString3.Set("Bepa");
    std::cout << "maybeString2 " << (maybeString2 != maybeString3 ? "!=" : "==") << " maybeString3" << std::endl;
    maybeString3.Set("Cepa");
    std::cout << "maybeString2 " << (maybeString2 != maybeString3 ? "!=" : "==") << " maybeString3" << std::endl;

    std::cout << "maybeString2 " << (maybeString2 == "Cepa" ? "!=" : "==") << " \"Cepa\"" << std::endl;
    std::cout << "\"Cepa\" " << ("Cepa" == maybeString2 ? "!=" : "==") << " maybeString2" << std::endl;

    return 0;
}