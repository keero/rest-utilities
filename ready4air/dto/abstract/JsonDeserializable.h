#ifndef READY4AIR_JSONSERIALIZABLE_H
#define READY4AIR_JSONSERIALIZABLE_H

#include <rapidjson/document.h>
#include <vector>

#define PARSE_ERROR_NOT_FOUND   1
#define PARSE_ERROR_WRONG_TYPE  2

namespace ready4air
{
    class ParseErrors
    {
    public:
        typedef struct {
            int Code;
            std::string Message;
        } ParseErrorItem;

    public:
        ParseErrors()
        {
        }

        virtual ~ParseErrors()
        {
        }

        const std::vector<ParseErrorItem> &GetParseErrors() const
        {
            return mItems;
        }

        void Error(int code, const std::string &message)
        {
            ParseErrorItem item;
            item.Code = code;
            item.Message = message;

            mItems.push_back(item);
        }

        inline operator bool() const
        {
            return mItems.size() > 0;
        }

    private:
        std::vector<ParseErrorItem> mItems;
    };

    static const char* kTypeNames[] = { "Null", "Bool", "Bool", "Object", "Array", "String", "Number" };

    class JsonDeserializable
    {

    public:
        bool InitFromJsonString(const std::string &json, ParseErrors &parseErrors)
        {
            rapidjson::Document d;

            if (d.Parse(json.c_str()).HasParseError() || !d.IsObject()) return false;

            return InitFromJsonValue(d, parseErrors);
        }

        virtual bool InitFromJsonValue(const rapidjson::Value &value, ParseErrors &parseErrors) = 0;

        bool ParseInt(const rapidjson::Value &value, const std::string &key, bool mandatory, int &result, ParseErrors &parseErrors)
        {
            if (value.HasMember(key.c_str()))
            {
                if (value[key.c_str()].IsInt())
                {
                    result = value[key.c_str()].GetInt();
                    return true;
                }
                else
                {
                    parseErrors.Error(PARSE_ERROR_WRONG_TYPE,
                                     "Property " + key + " has wrong type: "
                                     + kTypeNames[value[key.c_str()].GetType()]
                                     + ". Expecting Int.");
                }
            }
            else if (mandatory)
            {
                parseErrors.Error(PARSE_ERROR_NOT_FOUND, "Mandatory property " + key + " is missing.");
            }
            return false;
        }

        bool ParseString(const rapidjson::Value &value, const std::string &key, bool mandatory, std::string &result, ParseErrors &parseErrors)
        {
            if (value.HasMember(key.c_str()))
            {
                if (value[key.c_str()].IsString())
                {
                    result = value[key.c_str()].GetString();
                    return true;
                }
                else
                {
                    parseErrors.Error(PARSE_ERROR_WRONG_TYPE,
                                     "Property " + key + " has wrong type: "
                                     + kTypeNames[value[key.c_str()].GetType()]
                                     + ". Expecting String.");
                }
            }
            else if (mandatory)
            {
                parseErrors.Error(PARSE_ERROR_NOT_FOUND, "Mandatory property " + key + " is missing.");
            }
            return false;
        }

        bool ParseBool(const rapidjson::Value &value, const std::string &key, bool mandatory, bool &result, ParseErrors &parseErrors)
        {
            if (value.HasMember(key.c_str()))
            {
                if (value[key.c_str()].IsBool())
                {
                    result = value[key.c_str()].GetBool();
                    return true;
                }
                else
                {
                    parseErrors.Error(PARSE_ERROR_WRONG_TYPE,
                                     "Property " + key + " has wrong type: "
                                     + kTypeNames[value[key.c_str()].GetType()]
                                     + ". Expecting Bool.");
                }
            }
            else if (mandatory)
            {
                parseErrors.Error(PARSE_ERROR_NOT_FOUND, "Mandatory property " + key + " is missing.");
            }
            return false;
        }

        bool ParseDouble(const rapidjson::Value &value, const std::string &key, bool mandatory, double &result, ParseErrors &parseErrors)
        {
            if (value.HasMember(key.c_str()))
            {
                if (value[key.c_str()].IsDouble())
                {
                    result = value[key.c_str()].GetDouble();
                    return true;
                }
                else
                {
                    parseErrors.Error(PARSE_ERROR_WRONG_TYPE,
                                     "Property " + key + " has wrong type: "
                                     + kTypeNames[value[key.c_str()].GetType()]
                                     + ". Expecting Double.");
                }
            }
            else if (mandatory)
            {
                parseErrors.Error(PARSE_ERROR_NOT_FOUND, "Mandatory property " + key + " is missing.");
            }
            return false;
        }

        bool ParseObject(const rapidjson::Value &value, const std::string &key, bool mandatory, JsonDeserializable &result, ParseErrors &parseErrors)
        {
            if (value.HasMember(key.c_str()))
            {
                if (value[key.c_str()].IsObject())
                {
                    return result.InitFromJsonValue(value[key.c_str()], parseErrors);
                }
                else
                {
                    parseErrors.Error(PARSE_ERROR_WRONG_TYPE,
                                     "Property " + key + " has wrong type: "
                                     + kTypeNames[value[key.c_str()].GetType()]
                                     + ". Expecting Object.");
                }
            }
            else if (mandatory)
            {
                parseErrors.Error(PARSE_ERROR_NOT_FOUND, "Mandatory property " + key + " is missing.");
            }

            return false;
        }
    };
}

#endif //READY4AIR_JSONSERIALIZABLE_H
