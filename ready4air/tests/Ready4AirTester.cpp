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

using namespace std;
using namespace ready4air;
using namespace dto;

bool TestGenericPage()
{
    ostringstream ss;
    ifstream fs("../input/GenericPage.json");

    if (fs.is_open())
    {
        string content;
        while (fs >> content)
        {
            ss << content;
        }
        string json = ss.str();
        GenericPage<Error> errorPage;
        ParseErrors parseErrors;

        if (!errorPage.InitFromJsonString(json, parseErrors)) cout << "Unable to parse errorPage." << endl;

        if (errorPage.GetItems())
        {
            vector<Error> items = errorPage.GetItems().Just();
            for (size_t i = 0; i < items.size(); i += 1)
            {
                cout << "Error.Code = " <<items[i].GetCode() << endl;
            }
        }
    }
    return true;
}

int main()
{
    Bundle bundle;
    Device device;
    Episode episode;
    Error error;
    FreePage freePage;
    GenericPage<Movie> genericPage;
    Help help;
    List list;
    Literal literal;
    Movie movie;
    Page page;
    PurchaseInfo purchaseInfo;
    Season season;
    Series series;
    User user;

    string json = "{\"Id\": \"apa\", \"ExternalId\": \"bepa\"}";
    ParseErrors parseErrors;
    bundle.InitFromJsonString(json, parseErrors);

    string id = bundle.GetId() ? bundle.GetId().Just() : "";
    string externalId = bundle.GetExternalId() ? bundle.GetExternalId().Just() : "";

    cout << id << ' ' << externalId << endl;
    TestGenericPage();
    return 0;
}