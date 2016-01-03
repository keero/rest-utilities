#ifndef READY4AIR_JSONSERIALIZABLE_H
#define READY4AIR_JSONSERIALIZABLE_H

#include <rapidjson/document.h>

namespace ready4air
{
    class JsonDeserializable
    {
    public:
        bool InitFromJsonString(const std::string &json)
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
}

#endif //READY4AIR_JSONSERIALIZABLE_H
