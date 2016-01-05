#include <iostream>
#include <maybe/Maybe.h>

int main()
{
    Maybe<std::string> maybeString;
    std::cout << "maybeString = " << (maybeString.Nothing() ? "Nothing" : maybeString.Just()) << std::endl;
    maybeString.Set("Apa");
    std::cout << "maybeString = " << (maybeString.Nothing() ? "Nothing" : maybeString.Just()) << std::endl;
    maybeString.Unset();
    std::cout << "maybeString = " << (maybeString.Nothing() ? "Nothing" : maybeString.Just()) << std::endl;

    return 0;
}