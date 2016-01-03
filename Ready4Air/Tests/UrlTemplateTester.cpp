#include <iostream>
#include "../urltemplate/UrlTemplate.h"

int main()
{
    UrlTemplate urlTemplate;
    
    urlTemplate.SetUrl("http://www.example.com/{apa}/somethingelse{?bepa,cepa}");
    urlTemplate.SetParam("apa", "a");
    urlTemplate.SetParam("bepa", "b");
    urlTemplate.SetParam("cepa", "c");
    
    std::cout << urlTemplate.Expand() << std::endl;
}