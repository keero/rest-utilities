#include "ServiceRoot.h"
#include "FormTest.h"

using namespace std;
using namespace ready4air;
using namespace dto;
using namespace tests;

int main(void)
{
    Device device;
    ServiceRoot::RunTest("../input/ServiceRootPOSTResponse.json", device);

    Form form;
    FormTest::RunTest("/Users/martin.kero/dev/misc/rest-utilities/input/Form.json", form);

    if (form.GetAction())
    {
        dto::Link link = form.GetAction().Just();
        link.SetParam("apa", "a");
        link.SetParam("bepa", "b");
        form.SetAction(link);
        std::cout << form.GetAction().Just().GetExpandedUrl() << std::endl;
    }
    return 0;
}
