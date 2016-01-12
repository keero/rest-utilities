#ifndef READY4AIR_HELP_H
#define READY4AIR_HELP_H

#include "../maybe/Maybe.h"
#include "abstract/JsonDeserializable.h"
#include "hypermedia/Link.h"

namespace ready4air
{
    class Help : public JsonDeserializable
    {
    public:
        Help()
        {
        }

        virtual ~Help()
        {
        }

        const Maybe <std::string> &GetId() const
        {
            return mId;
        }

        void SetId(const std::string &id)
        {
            mId = id;
        }

        const Maybe <std::string> &GetTitle() const
        {
            return mTitle;
        }

        void SetTitle(const std::string &title)
        {
            mTitle = title;
        }

        const Maybe <std::string> &GetBody() const
        {
            return mBody;
        }

        void SetBody(const std::string &body)
        {
            mBody = body;
        }

        const Maybe <Link> &GetSelf() const
        {
            return mSelf;
        }

        void SetSelf(const Link &self)
        {
            mSelf = self;
        }

        virtual bool InitFromJsonValue(const rapidjson::Value &value, ParseErrors &parseErrors)
        {
            std::string id;
            std::string title;
            std::string body;
            Link self;

            if (ParseString(value, "Id", true, id, parseErrors))
                SetId(id);

            if (ParseString(value, "Title", true, title, parseErrors))
                SetTitle(title);

            if (ParseString(value, "Body", true, body, parseErrors))
                SetBody(body);

            if (ParseObject(value, "Self", true, self, parseErrors))
                SetSelf(self);

            return !parseErrors;
        }

    private:
        Maybe <std::string> mId;
        Maybe <std::string> mTitle;
        Maybe <std::string> mBody;
        Maybe <Link> mSelf;
    };
}

#endif //READY4AIR_HELP_H
