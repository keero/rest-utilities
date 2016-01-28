#include <iostream>
#include <sstream>
#include <fstream>


#ifndef UNUSED
#define UNUSED(arg)
#endif

//#include <ready4air/services.h>
#include "../../services/Root.h"
#include "HttpClient.h"
#include "AuthDeviceEvent.h"

using namespace std;
using namespace ready4air;
using namespace dto;
using namespace services;


int main(void)
{
    Root root;
    DevicesService<HttpClient, AuthDeviceEvent, EventPayload> devicesService;
//    AuthDeviceEvent authDeviceEvent = devicesService.AuthDeviceEvent;
    root.AuthDevice(&devicesService, "Fake", "Fake", "Fake", "Fake");
    return 0;
}


//void printErrors(const ParseErrors &parseErrors)
//{
//    for (size_t i = 0; i < parseErrors.GetParseErrors().size(); i += 1)
//    {
//        ParseErrors::ParseErrorItem item = parseErrors.GetParseErrors()[i];
//        cout << item.Code << ": " << item.Message << endl;
//    }
//}
//
//typedef enum
//{
//    SERVICE_ROOT_ENDPOINT = 1,
//    PAGES_ENDPOINT,
//    HELPS_ENDPOINT,
//    LITERALS_ENDPOINT
//} EndpointId;
//
//ResponseData DoRequest(EndpointId endpointId, const RequestData &requestData)
//{
//    ResponseData responseData;
//    string source;
//    switch (endpointId)
//    {
//        case SERVICE_ROOT_ENDPOINT:
//            if (requestData.GetMethod() == "GET")
//            {
//                source = "../input/ServiceRootGETResponse.json";
//                responseData.SetStatusCode(ResponseData::HTTP_STATUS_CODE_NOT_FOUND);
//            }
//            else if (requestData.GetMethod() == "POST")
//            {
//                source = "../input/ServiceRootPOSTResponse.json";
//                responseData.SetStatusCode(ResponseData::HTTP_STATUS_CODE_OK);
//            }
//            break;
//
//        case PAGES_ENDPOINT:
//            if (requestData.GetMethod() == "GET")
//            {
//                source = "../input/HomeGETResponse.json";
//                responseData.SetStatusCode(ResponseData::HTTP_STATUS_CODE_OK);
//            }
//            break;
//
//        case HELPS_ENDPOINT:
//            if (requestData.GetMethod() == "GET")
//            {
//                source = "../input/HelpsGETResponse.json";
//                responseData.SetStatusCode(ResponseData::HTTP_STATUS_CODE_OK);
//            }
//            break;
//
//        case LITERALS_ENDPOINT:
//            if (requestData.GetMethod() == "GET")
//            {
//                source = "../input/LiteralsGETResponse.json";
//                responseData.SetStatusCode(ResponseData::HTTP_STATUS_CODE_OK);
//            }
//            break;
//
//        default:
//            break;
//    }
//
//    if (source.length())
//    {
//        ostringstream ss;
//        ifstream fs(source);
//
//        if (fs.is_open())
//        {
//            string content;
//            while (fs >> content)
//            {
//                ss << content;
//            }
//            responseData.SetBody(ss.str());
//        }
//    }
//
//    cout << endl << requestData << endl;
//    cout << responseData << endl;
//
//    return responseData;
//}
//
//void fetchHome (const DevicesService &device, ParseErrors &parseErrors)
//{
//    RequestData requestData;
//    Maybe <PagesService> pageResult;
//
//    requestData = device.CreateHomeRequest("sv");
//
//    pageResult = device.RespHandler.Simple<PagesService>(requestData, DoRequest(PAGES_ENDPOINT, requestData), parseErrors);
//
//    if (pageResult)
//    {
//        PagesService page = pageResult.Just();
//        cout << "Received Page with ID: " << page.GetID() << endl;
//    }
//
//    if (parseErrors)
//        printErrors(parseErrors);
//}
//
//void fetchHelps (const DevicesService &device, ParseErrors &parseErrors)
//{
//    RequestData requestData;
//    Maybe <HelpsService> helpsResult;
//
//    requestData = device.CreateHelpsRequest("sv");
//
//    helpsResult = device.RespHandler.Simple<HelpsService>(requestData, DoRequest(HELPS_ENDPOINT, requestData), parseErrors);
//
//    if (helpsResult)
//    {
//        HelpsService helps = helpsResult.Just();
//        cout << "Received Helps with ID: " << helps.GetId() << endl;
//    }
//
//    if (parseErrors)
//        printErrors(parseErrors);
//}
//
//void fetchLiterals (const DevicesService &device, ParseErrors &parseErrors)
//{
//    RequestData requestData;
//    LiteralsService literals;
//
//    requestData = device.CreateLiteralsRequest("sv");
//
//    literals.SetItems(device.RespHandler.Map<Literal>(requestData, DoRequest(LITERALS_ENDPOINT, requestData), parseErrors));
//
//    if (literals.size() > 0)
//    {
//        cout << "Received Literals: " << literals.size() << endl;
//    }
//
//    if (parseErrors)
//        printErrors(parseErrors);
//}
//
//void fetchRoot (Root &root, ParseErrors &parseErrors)
//{
//    RequestData requestData;
//    AuthDeviceResponse result;
//
//    root.Init();
//    requestData = root.CreateAuthDeviceRequest("apa", "bepa", "cepa", "depa");
//
//    result = root.AuthDeviceResponseHandler(requestData, DoRequest(SERVICE_ROOT_ENDPOINT, requestData), parseErrors);
//
//    if (result.Left())
//        result = root.AuthDeviceResponseHandler(result.Left().Just(), DoRequest(SERVICE_ROOT_ENDPOINT, result.Left().Just()), parseErrors);
//
//    if (result.Right())
//    {
//        DevicesService device = result.Right().Just();
//        cout << "Received Device with Id: " << device.GetId() << endl;
//
//        fetchHome(device, parseErrors);
//        fetchHelps(device, parseErrors);
//        fetchLiterals(device, parseErrors);
//
//        cout << endl << device.CreateRegisterRequest("apa", "bepa") << endl;
//        cout << endl << device.CreateForgotPasswordRequest("apa") << endl;
//    }
//
//    if (parseErrors)
//        printErrors(parseErrors);
//}
//
//int main (void)
//{
//    HttpClient httpClient;
//    Root root;
//    ParseErrors parseErrors;
//
//    fetchRoot(root, parseErrors);
//
//    return 0;
//}