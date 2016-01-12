#include <iostream>
#include <sstream>
#include <fstream>

#include "../dto/Bundle.h"
#include "../dto/Device.h"
#include "../dto/Episode.h"
#include "../dto/Error.h"
#include "../dto/FreePage.h"
#include "../dto/GenericPage.h"
#include "../dto/Help.h"
#include "../dto/List.h"
#include "../dto/Literal.h"
#include "../dto/Movie.h"
#include "../dto/Page.h"
#include "../dto/PurchaseInfo.h"
#include "../dto/Season.h"
#include "../dto/Series.h"
#include "../dto/User.h"


bool TestGenericPage()
{
    std::ostringstream ss;
    std::ifstream fs("../input/GenericPage.json");

    if (fs.is_open())
    {
        std::string content;
        while (fs >> content)
        {
            ss << content;
        }
        std::string json = ss.str();
        ready4air::GenericPage<ready4air::Error> errorPage;
        ready4air::ParseErrors parseErrors;

        if (!errorPage.InitFromJsonString(json, parseErrors)) std::cout << "Unable to parse errorPage." << std::endl;

        if (errorPage.GetItems())
        {
            std::vector<ready4air::Error> items = errorPage.GetItems().Just();
            for (size_t i = 0; i < items.size(); i += 1)
            {
                std::cout << "Error.Code = " <<items[i].GetCode() << std::endl;
            }
        }
    }
    return true;
}

int main()
{
    ready4air::Bundle bundle;
    ready4air::Device device;
    ready4air::Episode episode;
    ready4air::Error error;
    ready4air::FreePage freePage;
    ready4air::GenericPage<ready4air::Movie> genericPage;
    ready4air::Help help;
    ready4air::List list;
    ready4air::Literal literal;
    ready4air::Movie movie;
    ready4air::Page page;
    ready4air::PurchaseInfo purchaseInfo;
    ready4air::Season season;
    ready4air::Series series;
    ready4air::User user;

    std::string json = "{\"Id\": \"apa\", \"ExternalId\": \"bepa\"}";
    ready4air::ParseErrors parseErrors;
    bundle.InitFromJsonString(json, parseErrors);

    std::string id = bundle.GetId() ? bundle.GetId().Just() : "";
    std::string externalId = bundle.GetExternalId() ? bundle.GetExternalId().Just() : "";

    std::cout << id << ' ' << externalId << std::endl;
    TestGenericPage();
    return 0;
}