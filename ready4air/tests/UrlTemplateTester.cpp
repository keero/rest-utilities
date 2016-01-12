#include <iostream>
#include "../urltemplate/UrlTemplate.h"

int main()
{
    ready4air::UrlTemplate urlTemplate;
    
    urlTemplate.SetUrl("https://pp.sfkids.com/Neonstingray.Nettv4.RestApi/api/se/19/lists{?language,take,skip}&genres=Include&listType=-1");
    urlTemplate.SetParam("apa", "a");
    urlTemplate.SetParam("bepa", "b");
    urlTemplate.SetParam("cepa", "c");
    
    std::cout << urlTemplate.Expand() << std::endl;
}