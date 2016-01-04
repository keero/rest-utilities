#include <iostream>
#include "../dto/hypermedia/Link.h"
#include "../dto/hypermedia/Form.h"

void linkTest()
{
    std::string json = "{\"Href\":\"http://www.example.com/{apa}/somethingelse{?bepa,cepa}\",\"Templated\":true,\"WithCredentials\":false}";
    ready4air::Link link;
    
    if (link.InitFromJsonString(json))
    {
        link.SetParam("apa", "a");
        link.SetParam("bepa", "b");
        link.SetParam("cepa", "c");
        
        std::cout << link.GetExpandedUrl() << '\n';
    }

}

void formTest()
{
    std::string json = "{\"Action\": {\"Href\":\"http://www.example.com/{apa}/somethingelse{?bepa,cepa}\",\"Templated\":true,\"WithCredentials\":false}, \"Method\": \"POST\"}";
    ready4air::Form form;
    
    if (form.InitFromJsonString(json))
    {
        ready4air::Link link = form.GetAction();
        link.SetParam("apa", "a");
        link.SetParam("bepa", "b");
        link.SetParam("cepa", "c");
        
        std::cout << form.GetMethod() << " " << link.GetExpandedUrl() << '\n';
    }

}

int main()
{
    linkTest();
    formTest();
}


