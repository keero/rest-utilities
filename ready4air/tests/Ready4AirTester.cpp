#include <iostream>
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

    std::cout << "Not implemented yet" << std::endl;
}