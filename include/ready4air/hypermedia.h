#include "urltemplate.h"
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
                INT32_T Code;
                STRING_T Message;
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
            void Error(int code, const STRING_T &message)
            {
                ParseErrorItem item;
                item.Code = code;
                item.Message = message;
                mItems.push_back(item);
            }
            inline operator BOOL_T() const
            {
                return mItems.size() > 0;
            }
        private:
            VECTOR_T<ParseErrorItem> mItems;
        };
        class IJsonDeserializable
        {
        public:
            virtual BOOL_T InitFromJsonValue(const rapidjson::Value &value, ParseErrors &parseErrors) = 0;
        };
        static const STRING_T kTypeNames[] = {"Null", "Bool", "Bool", "Object", "Array", "String", "Number"};
        class JsonDeserializable : public IJsonDeserializable
        {
        public:
            BOOL_T InitFromJsonString(const STRING_T &json, ParseErrors &parseErrors)
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
            virtual BOOL_T InitFromJsonValue(const rapidjson::Value &value, ParseErrors &parseErrors) = 0;
            BOOL_T ParseInt(const rapidjson::Value &value, const STRING_T &key, BOOL_T mandatory, INT32_T &result,
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
            BOOL_T ParseString(const rapidjson::Value &value, const STRING_T &key, BOOL_T mandatory, STRING_T &result,
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
            BOOL_T ParseBool(const rapidjson::Value &value, const STRING_T &key, BOOL_T mandatory, BOOL_T &result,
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
            BOOL_T ParseDouble(const rapidjson::Value &value, const STRING_T &key, BOOL_T mandatory, DOUBLE_T &result,
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
            BOOL_T ParseObject(const rapidjson::Value &value, const STRING_T &key, BOOL_T mandatory,
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
            BOOL_T VerifyArray(const rapidjson::Value &value, const STRING_T &key, BOOL_T mandatory,
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
            BOOL_T VerifyObject(const rapidjson::Value &value, const STRING_T &key, BOOL_T mandatory,
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

#ifndef READY4AIR_HYPERMEDIA_LINK_H
#define READY4AIR_HYPERMEDIA_LINK_H
namespace ready4air
{
    namespace dto
    {
        class Link : public JsonDeserializable
        {
        public:
            Link()
            {
            }
            virtual ~Link()
            {
            }
            void SetHref(const STRING_T &value)
            {
                mUrlTemplate.SetUrl(value);
            }
            const Maybe<STRING_T> &GetHref() const
            {
                return mUrlTemplate.GetUrl();
            }
            void SetTemplated(BOOL_T value)
            {
                mTemplated = value;
            }
            Maybe<BOOL_T> GetTemplated() const
            {
                return mTemplated;
            }
            void SetWithCredentials(BOOL_T value)
            {
                mWithCredentials = value;
            }
            Maybe<BOOL_T> GetWithCredentials() const
            {
                return mWithCredentials;
            }
            void SetParam(const STRING_T &key, const STRING_T &value)
            {
                mUrlTemplate.SetParam(key, value);
            }
            const STRING_T &GetParam(const STRING_T &key) const
            {
                return mUrlTemplate.GetParam(key);
            }
            void UnsetParam(const STRING_T &key)
            {
                mUrlTemplate.UnsetParam(key);
            }
            void ClearParams()
            {
                mUrlTemplate.ClearParams();
            }
            const STRING_T GetExpandedUrl() const
            {
                return mUrlTemplate.Expand();
            }
            virtual BOOL_T InitFromJsonValue(const rapidjson::Value &value, ParseErrors &parseErrors)
            {
                STRING_T href;
                BOOL_T templated;
                BOOL_T withCredentials;
                if (ParseString(value, "Href", true, href, parseErrors))
                    SetHref(href);
                if (ParseBool(value, "Templated", false, templated, parseErrors))
                    SetTemplated(templated);
                if (ParseBool(value, "WithCredentials", false, withCredentials, parseErrors))
                    SetWithCredentials(withCredentials);
                return !parseErrors;
            }
        private:
            Maybe<BOOL_T> mTemplated;
            Maybe<BOOL_T> mWithCredentials;
            UrlTemplate mUrlTemplate;
        };
    }
}
#endif //READY4AIR_HYPERMEDIA_LINK_H

#ifndef READY4AIR_HYPERMEDIA_FORM_H
#define READY4AIR_HYPERMEDIA_FORM_H
namespace ready4air
{
    namespace dto
    {
        class Form : public JsonDeserializable
        {
        public:
            Form()
            {
            }
            virtual ~Form()
            {
            }
            const Maybe <Link> &GetAction() const
            {
                return mAction;
            }
            void SetAction(const Link &action)
            {
                mAction = action;
            }
            const Maybe <STRING_T> &GetMethod() const
            {
                return mMethod;
            }
            void SetMethod(const STRING_T &method)
            {
                mMethod = method;
            }
            const Maybe <Link> &GetBody() const
            {
                return mBody;
            }
            void SetBody(const Link &body)
            {
                mBody = body;
            }
            virtual BOOL_T InitFromJsonValue(const rapidjson::Value &value, ParseErrors &parseErrors)
            {
                Link actionLink;
                STRING_T method;
                Link bodyLink;
                if (ParseObject(value, "Action", true, actionLink, parseErrors))
                    SetAction(actionLink);
                if (ParseString(value, "Method", true, method, parseErrors))
                    SetMethod(method);
                if (ParseObject(value, "Body", false, bodyLink, parseErrors))
                    SetBody(bodyLink);
                return !parseErrors;
            }
        private:
            Maybe <Link> mAction;
            Maybe <STRING_T> mMethod;
            Maybe <Link> mBody;
        };
    }
}
#endif //READY4AIR_HYPERMEDIA_FORM_H

#ifndef READY4AIR_HYPERMEDIA_CRUD_H
#define READY4AIR_HYPERMEDIA_CRUD_H
namespace ready4air
{
    namespace dto
    {
        class Crud : public JsonDeserializable
        {
        public:
            Crud()
            {
            }
            virtual ~Crud()
            {
            }
            const Maybe <Form> &GetCreateOrUpdate() const
            {
                return mCreateOrUpdate;
            }
            void SetCreateOrUpdate(const Form &createOrUpdate)
            {
                mCreateOrUpdate = createOrUpdate;
            }
            const Maybe <Link> &GetRead() const
            {
                return mRead;
            }
            void SetRead(const Link &read)
            {
                mRead = read;
            }
            const Maybe <Form> &GetDelete() const
            {
                return mDelete;
            }
            void SetDelete(const Form &aDelete)
            {
                mDelete = aDelete;
            }
            virtual BOOL_T InitFromJsonValue(const rapidjson::Value &value, ParseErrors &parseErrors)
            {
                Form createOrUpdateForm;
                Link readLink;
                Form deleteForm;
                if (ParseObject(value, "CreateOrUpdate", false, createOrUpdateForm, parseErrors))
                    SetCreateOrUpdate(createOrUpdateForm);
                if (ParseObject(value, "Read", false, readLink, parseErrors))
                    SetRead(readLink);
                if (ParseObject(value, "Delete", false, deleteForm, parseErrors))
                    SetDelete(deleteForm);
                return !parseErrors;
            }
        private:
            Maybe <Form> mCreateOrUpdate;
            Maybe <Link> mRead;
            Maybe <Form> mDelete;
        };
    }
}
#endif //READY4AIR_HYPERMEDIA_CRUD_H

