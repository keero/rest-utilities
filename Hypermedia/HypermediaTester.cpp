#include <iostream>
#include <string>
#include "Link.h"
#include "Form.h"

void linkTest()
{
    string json = "{\"Href\":\"http://www.example.com/{apa}/somethingelse{?bepa,cepa}\",\"Templated\":true,\"WithCredentials\":false}";
    Link link;
    
    if (Link::CreateFromJsonString(json, link))
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
    Form form;
    
    if (Form::CreateFromJsonString(json, form))
    {
        Link link = form.GetAction();
        link.SetParam("apa", "a");
        link.SetParam("bepa", "b");
        link.SetParam("cepa", "c");
        
        cout << form.GetMethod() << " " << link.GetExpandedUrl() << '\n';
    }

}

int main()
{
    linkTest();
    formTest();
}


