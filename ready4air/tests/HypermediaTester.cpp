#include <iostream>
#include "../dto/hypermedia/Link.h"
#include "../dto/hypermedia/Form.h"
#include "../dto/abstract/JsonDeserializable.h"

void linkTest()
{
    std::string json = "{\"Href\":\"http://www.example.com/{apa}/somethingelse{?bepa,cepa}\",\"Templated\":true,\"WithCredentials\":false}";
    std::string brokenJson = "{\"Href\":false,\"Templated\":true,\"WithCredentials\":false}";
    ready4air::Link link;
    ready4air::ParseErrors parseErrors;

    link.InitFromJsonString(brokenJson, parseErrors);

    if (parseErrors)
    {
        for (size_t i = 0; i < parseErrors.GetParseErrors().size(); i += 1)
        {
            ready4air::ParseErrors::ParseErrorItem item = parseErrors.GetParseErrors()[i];
            std::cout << item.Code << ": " << item.Message << std::endl;
        }
    }
    else
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
    std::string brokenJson = "{\"Action\": {\"Href\":3,\"Templated\":\"apa\",\"WithCredentials\":7}, \"Method\": {\"apa\": false}}";
    ready4air::Form form;
    ready4air::ParseErrors parseErrors;

    form.InitFromJsonString(json, parseErrors);

    if (parseErrors)
    {
        for (size_t i = 0; i < parseErrors.GetParseErrors().size(); i += 1)
        {
            ready4air::ParseErrors::ParseErrorItem item = parseErrors.GetParseErrors()[i];
            std::cout << item.Code << ": " << item.Message << std::endl;
        }
    }
    else
    {
        ready4air::Link l = form.GetAction().Just();
        l.SetParam("apa", "a");
        l.SetParam("bepa", "b");
        l.SetParam("cepa", "c");
        std::cout << form.GetMethod().Just() << " " << l.GetExpandedUrl() << '\n';
    }

}

int main()
{
    linkTest();
    formTest();
}


