//
// Created by Martin Kero on 02/01/16.
//

#ifndef REST_UTILITIES_JSONSERIALIZABLE_H
#define REST_UTILITIES_JSONSERIALIZABLE_H

#include <string>
#include <include/rapidjson/document.h>

using namespace std;

class JsonDeserializable
{
public:
    bool InitFromJsonString(const string &json)
    {
        rapidjson::Document d;

        if (d.Parse(json.c_str()).HasParseError() || !d.IsObject()) return false;

        return InitFromJsonValue(d);
    }

    virtual bool InitFromJsonValue(const rapidjson::Value &value)
    {
        return false;
    }

};


#endif //REST_UTILITIES_JSONSERIALIZABLE_H
