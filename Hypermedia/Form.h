#ifndef REST_UTILITIES_HYPERMEDIA_FORM_H
#define REST_UTILITIES_HYPERMEDIA_FORM_H

#include <string>
#include "rapidjson/document.h"

#include "Link.h"

class Form
{
public:

    Form()
    {
    }

    virtual ~Form()
    {
    }


    const Link &GetAction() const
    {
        return mAction;
    }

    void SetAction(const Link &action)
    {
        mAction = action;
    }

    const string &GetMethod() const
    {
        return mMethod;
    }

    void SetMethod(const string &method)
    {
        mMethod = method;
    }

    const Link &GetBody() const
    {
        return mBody;
    }

    void SetBody(const Link &body)
    {
        mBody = body;
    }

    static bool CreateFromJsonString(const string &json, Form &form); // @TODO: Add ref obj for parse errors
    static bool CreateFromJson(const rapidjson::Value &value, Form &form); // @TODO: Add ref obj for parse errors

private:
    Link mAction;
    string mMethod;
    Link mBody;
};

#endif //REST_UTILITIES_HYPERMEDIA_FORM_H
