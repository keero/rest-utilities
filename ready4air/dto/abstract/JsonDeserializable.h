#ifndef READY4AIR_JSONDESERIALIZABLE_H
#define READY4AIR_JSONDESERIALIZABLE_H

#include "../../common/Predefine.h"
#include <rapidjson/document.h>
#include <vector>
#include <sstream>

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
                INT32_T Code;
                STRING_T Message;
                STRING_T Context;
            } ParseErrorItem;

        public:
            ParseErrors()
            {
            }

            virtual ~ParseErrors()
            {
            }

            const VECTOR_T<ParseErrorItem> &GetParseErrors() const
            {
                return mItems;
            }

            void Error(int code, const STRING_T &message, const VECTOR_T<STRING_T> &context)
            {
                ParseErrorItem item;
                item.Code = code;
                item.Message = message;
                item.Context = JoinContext(context);

                mItems.push_back(item);
            }

            inline operator BOOL_T() const
            {
                return mItems.size() > 0;
            }

        private:
            static STRING_T JoinContext(const VECTOR_T<STRING_T> &context)
            {
                std::ostringstream result;

                for (int i = 0; i < context.size(); i += 1)
                {
                    if (i > 0) result << '.';

                    result << context[i];
                }

                return STRING_T(result.str());
            }

        private:
            VECTOR_T<ParseErrorItem> mItems;
        };

        class IJsonDeserializable
        {
        public:
            virtual BOOL_T InitFromJsonValue(const rapidjson::Value &value, ParseErrors &parseErrors, VECTOR_T<STRING_T> &context) = 0;
        };

        static const STRING_T kTypeNames[] = {"Null", "Bool", "Bool", "Object", "Array", "String", "Number"};

        class JsonDeserializable : public IJsonDeserializable
        {

        public:
            BOOL_T InitFromJsonString(const STRING_T &json, ParseErrors &parseErrors, VECTOR_T<STRING_T> &context)
            {
                OriginalJsonString = json;

                rapidjson::Document d;

                if (d.Parse(json.c_str()).HasParseError()) return false;

                if (d.IsObject())
                    return InitFromJsonValue(d, parseErrors, context);
                else if (d.IsArray())
                    return InitFromJsonValue(d[0], parseErrors, context);
                else
                    return false;
            }

            virtual BOOL_T InitFromJsonValue(const rapidjson::Value &value, ParseErrors &parseErrors, VECTOR_T<STRING_T> &context) = 0;

            BOOL_T ParseInt(const rapidjson::Value &value, const STRING_T &key, BOOL_T mandatory, INT32_T &result,
                                        ParseErrors &parseErrors, const VECTOR_T<STRING_T> &context)
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
                        parseErrors.Error(PARSE_ERROR_WRONG_TYPE, "Property " + key + " has wrong type: "
                                                                  + kTypeNames[value[key.c_str()].GetType()]
                                                                  + ". Expecting Int.", context);
                    }
                }
                else if (mandatory)
                {
                    parseErrors.Error(PARSE_ERROR_NOT_FOUND, "Mandatory property " + key + " is missing.",
                                      context);
                }
                return false;
            }

            BOOL_T ParseString(const rapidjson::Value &value, const STRING_T &key, BOOL_T mandatory, STRING_T &result,
                                           ParseErrors &parseErrors, const VECTOR_T<STRING_T> &context)
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
                        parseErrors.Error(PARSE_ERROR_WRONG_TYPE, "Array item has wrong type: "
                                                                  + kTypeNames[value.GetType()]
                                                                  + ". Expecting String.", context);
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
                        parseErrors.Error(PARSE_ERROR_WRONG_TYPE, "Property " + key + " has wrong type: "
                                                                  + kTypeNames[value[key.c_str()].GetType()]
                                                                  + ". Expecting String.", context);
                    }
                }
                else if (mandatory)
                {
                    parseErrors.Error(PARSE_ERROR_NOT_FOUND, "Mandatory property " + key + " is missing.",
                                      context);
                }
                return false;
            }

            BOOL_T ParseBool(const rapidjson::Value &value, const STRING_T &key, BOOL_T mandatory, BOOL_T &result,
                                         ParseErrors &parseErrors, const VECTOR_T<STRING_T> &context)
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
                        parseErrors.Error(PARSE_ERROR_WRONG_TYPE, "Property " + key + " has wrong type: "
                                                                  + kTypeNames[value[key.c_str()].GetType()]
                                                                  + ". Expecting Bool.", context);
                    }
                }
                else if (mandatory)
                {
                    parseErrors.Error(PARSE_ERROR_NOT_FOUND, "Mandatory property " + key + " is missing.",
                                      context);
                }
                return false;
            }

            BOOL_T ParseDouble(const rapidjson::Value &value, const STRING_T &key, BOOL_T mandatory, DOUBLE_T &result,
                                           ParseErrors &parseErrors, const VECTOR_T<STRING_T> &context)
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
                        parseErrors.Error(PARSE_ERROR_WRONG_TYPE, "Property " + key + " has wrong type: "
                                                                  + kTypeNames[value[key.c_str()].GetType()]
                                                                  + ". Expecting Double.", context);
                    }
                }
                else if (mandatory)
                {
                    parseErrors.Error(PARSE_ERROR_NOT_FOUND, "Mandatory property " + key + " is missing.",
                                      context);
                }
                return false;
            }

            BOOL_T ParseObject(const rapidjson::Value &value, const STRING_T &key, BOOL_T mandatory, JsonDeserializable &result,
                                           ParseErrors &parseErrors, VECTOR_T<STRING_T> &context)
            {
                if (key.size() == 0)
                {
                    if (value.IsObject())
                    {
                        return result.InitFromJsonValue(value, parseErrors, context);
                    }
                    else
                    {
                        parseErrors.Error(PARSE_ERROR_WRONG_TYPE, "Array item has wrong type: "
                                                                  + kTypeNames[value.GetType()]
                                                                  + ". Expecting Object.", context);
                    }
                }
                else if (value.HasMember(key.c_str()))
                {
                    if (value[key.c_str()].IsObject())
                    {
                        return result.InitFromJsonValue(value[key.c_str()], parseErrors, context);
                    }
                    else
                    {
                        parseErrors.Error(PARSE_ERROR_WRONG_TYPE, "Property " + key + " has wrong type: "
                                                                  + kTypeNames[value[key.c_str()].GetType()]
                                                                  + ". Expecting Object.", context);
                    }
                }
                else if (mandatory)
                {
                    parseErrors.Error(PARSE_ERROR_NOT_FOUND, "Mandatory property " + key + " is missing.",
                                      context);
                }

                return false;
            }

            BOOL_T VerifyArray(const rapidjson::Value &value, const STRING_T &key, BOOL_T mandatory, ParseErrors &parseErrors,
                                           const VECTOR_T<STRING_T> &context)
            {
                if (value.HasMember(key.c_str()))
                {
                    if (value[key.c_str()].IsArray())
                    {
                        return true;
                    }
                    else
                    {
                        parseErrors.Error(PARSE_ERROR_WRONG_TYPE, "Property " + key + " has wrong type: "
                                                                  + kTypeNames[value[key.c_str()].GetType()]
                                                                  + ". Expecting Array.", context);
                    }
                }
                else if (mandatory)
                {
                    parseErrors.Error(PARSE_ERROR_NOT_FOUND, "Mandatory property " + key + " is missing.",
                                      context);
                }

                return false;
            }

            BOOL_T VerifyObject(const rapidjson::Value &value, const STRING_T &key, BOOL_T mandatory, ParseErrors &parseErrors,
                                            const VECTOR_T<STRING_T> &context)
            {
                if (value.HasMember(key.c_str()))
                {
                    if (value[key.c_str()].IsObject())
                    {
                        return true;
                    }
                    else
                    {
                        parseErrors.Error(PARSE_ERROR_WRONG_TYPE, "Property " + key + " has wrong type: "
                                                                  + kTypeNames[value[key.c_str()].GetType()]
                                                                  + ". Expecting Object.", context);
                    }
                }
                else if (mandatory)
                {
                    parseErrors.Error(PARSE_ERROR_NOT_FOUND, "Mandatory property " + key + " is missing.",
                                      context);
                }

                return false;
            }

        protected:
            Maybe <STRING_T> OriginalJsonString;
        };
    }
}
#endif //READY4AIR_JSONDESERIALIZABLE_H
