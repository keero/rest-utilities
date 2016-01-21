#include "ServiceRoot.h"

using namespace std;
using namespace ready4air;
using namespace dto;
using namespace tests;

int main(void)
{
    Device device;
    ServiceRoot::RunTest("../input/ServiceRootPOSTResponse.json", device);
    return 0;
}
