#ifndef READY4AIR_JSONSERIALIZABLE_H
#define READY4AIR_JSONSERIALIZABLE_H

#include <rapidjson/document.h>
#include <vector>

#define PARSE_ERROR_NOT_FOUND   1
#define PARSE_ERROR_WRONG_TYPE  2

namespace ready4air
{
    namespace dto
    {
        class ParseErrors
        {
        public:
            typedef struct
            {
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

        class IJsonDeserializable
        {
        public:
            virtual bool InitFromJsonValue(const rapidjson::Value &value, ParseErrors &parseErrors) = 0;
        };

        static const std::string kTypeNames[] = {"Null", "Bool", "Bool", "Object", "Array", "String", "Number"};

        class JsonDeserializable : public IJsonDeserializable
        {

        public:
            bool InitFromJsonString(const std::string &json, ParseErrors &parseErrors)
            {
                rapidjson::Document d;

                if (d.Parse(json.c_str()).HasParseError()) return false;

                if (d.IsObject())
                    return InitFromJsonValue(d, parseErrors);
                else if (d.IsArray())
                    return InitFromJsonValue(d[0], parseErrors);
                else
                    return false;
            }

            virtual bool InitFromJsonValue(const rapidjson::Value &value, ParseErrors &parseErrors) = 0;

            bool ParseInt(const rapidjson::Value &value, const std::string &key, bool mandatory, int &result,
                          ParseErrors &parseErrors)
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

            bool ParseString(const rapidjson::Value &value, const std::string &key, bool mandatory, std::string &result,
                             ParseErrors &parseErrors)
            {
                if (key.size() == 0)
                {
                    if (value.IsString())
                    {
                        result = value.GetString();
                        return true;
                    }
                    else
                    {
                        parseErrors.Error(PARSE_ERROR_WRONG_TYPE,
                                          "Array item has wrong type: "
                                          + kTypeNames[value.GetType()]
                                          + ". Expecting String.");
                    }
                }
                else if (value.HasMember(key.c_str()))
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

            bool ParseBool(const rapidjson::Value &value, const std::string &key, bool mandatory, bool &result,
                           ParseErrors &parseErrors)
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

            bool ParseDouble(const rapidjson::Value &value, const std::string &key, bool mandatory, double &result,
                             ParseErrors &parseErrors)
            {
                if (value.HasMember(key.c_str()))
                {
                    if (value[key.c_str()].IsNumber())
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

            bool ParseObject(const rapidjson::Value &value, const std::string &key, bool mandatory,
                             JsonDeserializable &result, ParseErrors &parseErrors)
            {
                if (key.size() == 0)
                {
                    if (value.IsObject())
                    {
                        return result.InitFromJsonValue(value, parseErrors);
                    }
                    else
                    {
                        parseErrors.Error(PARSE_ERROR_WRONG_TYPE,
                                          "Array item has wrong type: "
                                          + kTypeNames[value.GetType()]
                                          + ". Expecting Object.");
                    }
                }
                else if (value.HasMember(key.c_str()))
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

            bool VerifyArray(const rapidjson::Value &value, const std::string &key, bool mandatory,
                             ParseErrors &parseErrors)
            {
                if (value.HasMember(key.c_str()))
                {
                    if (value[key.c_str()].IsArray())
                    {
                        return true;
                    }
                    else
                    {
                        parseErrors.Error(PARSE_ERROR_WRONG_TYPE,
                                          "Property " + key + " has wrong type: "
                                          + kTypeNames[value[key.c_str()].GetType()]
                                          + ". Expecting Array.");
                    }
                }
                else if (mandatory)
                {
                    parseErrors.Error(PARSE_ERROR_NOT_FOUND, "Mandatory property " + key + " is missing.");
                }

                return false;
            }

            bool VerifyObject(const rapidjson::Value &value, const std::string &key, bool mandatory,
                              ParseErrors &parseErrors)
            {
                if (value.HasMember(key.c_str()))
                {
                    if (value[key.c_str()].IsObject())
                    {
                        return true;
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
}
#endif //READY4AIR_JSONSERIALIZABLE_H
