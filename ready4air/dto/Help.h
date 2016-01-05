#ifndef READY4AIR_HELP_H
#define READY4AIR_HELP_H

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

        const std::string &GetId() const
        {
            return mId;
        }

        void SetId(const std::string &id)
        {
            mId = id;
        }

        const std::string &GetTitle() const
        {
            return mTitle;
        }

        void SetTitle(const std::string &title)
        {
            mTitle = title;
        }

        const std::string &GetBody() const
        {
            return mBody;
        }

        void SetBody(const std::string &body)
        {
            mBody = body;
        }

        const Link &GetSelf() const
        {
            return mSelf;
        }

        void SetSelf(const Link &self)
        {
            mSelf = self;
        }

        virtual bool InitFromJsonValue(const rapidjson::Value &value)
        {
            {
                // Mandatory property
                if (!value.HasMember("Id") || !value["Id"].IsString()) return false;
                SetId(value["Id"].GetString());
            }
            {
                // Mandatory property
                if (!value.HasMember("Title") || !value["Title"].IsString()) return false;
                SetTitle(value["Title"].GetString());
            }
            {
                // Mandatory property
                if (!value.HasMember("Body") || !value["Body"].IsString()) return false;
                SetBody(value["Body"].GetString());
            }
            {
                // Mandatory property
                Link self;
                if (!value.HasMember("Self") || !value["Self"].IsObject() || !self.InitFromJsonValue(value["Self"])) return false;
                SetSelf(self);
            }

            return true;
        }

    private:
        std::string mId;
        std::string mTitle;
        std::string mBody;
        Link mSelf;
    };
}

#endif //READY4AIR_HELP_H
