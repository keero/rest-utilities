#ifndef _FORM_H_
#define _FORM_H_

#include <string>
#include "rapidjson/document.h"

#include "Link.h"

class Form
{
public:

    Form();
    virtual ~Form();
    
    void SetAction(const Link& value) { m_oAction = value; }
    const Link& GetAction() const { return m_oAction; }
    
    void SetMethod(const string& value) { m_oMethod = value; }
    const string& GetMethod() const { return m_oMethod; }
    
    void SetBody(const Link& value) { m_oBody = value; }
    const Link& GetBody() const { return m_oBody; }
    
    static bool CreateFromJsonString(const string& json, Form& form); // @TODO: Add ref obj for parse errors
    static bool CreateFromJson(const rapidjson::Value& value, Form& form); // @TODO: Add ref obj for parse errors
    
private:
    Link            m_oAction;
    string          m_oMethod;
    Link            m_oBody;
};

#endif /* _FORM_H_ */
