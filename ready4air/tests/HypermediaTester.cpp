#include <iostream>
#include "../dto/hypermedia/Link.h"
#include "../dto/hypermedia/Form.h"

using namespace std;
using namespace ready4air;
using namespace dto;

void linkTest()
{
    string json = "{\"Href\":\"http://www.example.com/{apa}/somethingelse{?bepa,cepa}\",\"Templated\":true,\"WithCredentials\":false}";
    string brokenJson = "{\"Href\":false,\"Templated\":true,\"WithCredentials\":false}";
    Link link;
    ParseErrors parseErrors;

    link.InitFromJsonString(brokenJson, parseErrors);

    if (parseErrors)
    {
        for (size_t i = 0; i < parseErrors.GetParseErrors().size(); i += 1)
        {
            ParseErrors::ParseErrorItem item = parseErrors.GetParseErrors()[i];
            cout << item.Code << ": " << item.Message << endl;
        }
    }
    else
    {
        link.SetParam("apa", "a");
        link.SetParam("bepa", "b");
        link.SetParam("cepa", "c");
        
        cout << link.GetExpandedUrl() << '\n';
    }

}

void formTest()
{
    string json = "{\"Action\": {\"Href\":\"http://www.example.com/{apa}/somethingelse{?bepa,cepa}\",\"Templated\":true,\"WithCredentials\":false}, \"Method\": \"POST\"}";
    string brokenJson = "{\"Action\": {\"Href\":3,\"Templated\":\"apa\",\"WithCredentials\":7}, \"Method\": {\"apa\": false}}";
    Form form;
    ParseErrors parseErrors;

    form.InitFromJsonString(json, parseErrors);

    if (parseErrors)
    {
        for (size_t i = 0; i < parseErrors.GetParseErrors().size(); i += 1)
        {
            ParseErrors::ParseErrorItem item = parseErrors.GetParseErrors()[i];
            cout << item.Code << ": " << item.Message << endl;
        }
    }
    else
    {
        Link l = form.GetAction().Just();
        l.SetParam("apa", "a");
        l.SetParam("bepa", "b");
        l.SetParam("cepa", "c");
        cout << form.GetMethod().Just() << " " << l.GetExpandedUrl() << '\n';
    }

}

int main()
{
    linkTest();
    formTest();
}


