#ifndef READY4AIR_LIVESECTION_H
#define READY4AIR_LIVESECTION_H

#include "../maybe/Maybe.h"
#include "abstract/JsonDeserializable.h"
#include "Channel.h"
#include "hypermedia/Link.h"

namespace ready4air
{
    class LiveSection : public JsonDeserializable
    {
    public:
        LiveSection()
        {
        }

        virtual ~LiveSection()
        {
        }

        const Maybe <std::string> &GetTitle() const
        {
            return mTitle;
        }

        void SetTitle(const std::string &title)
        {
            mTitle = title;
        }

        const Maybe <std::vector<Channel> > &GetChannels() const
        {
            return mChannels;
        }

        void SetChannels(const std::vector<Channel> &channels)
        {
            mChannels = channels;
        }

        const Maybe <Link> &GetAll() const
        {
            return mAll;
        }

        void SetAll(const Link &all)
        {
            mAll = all;
        }

        virtual bool InitFromJsonValue(const rapidjson::Value &value)
        {
            {
                // Mandatory property
                if (!value.HasMember("Title") || !value["Title"].IsString()) return false;
                SetTitle(value["Title"].GetString());
            }
            {
                // Mandatory property
                if (!value.HasMember("Channels") || !value["Channels"].IsArray()) return false;
                std::vector<Channel> channels;
                for (rapidjson::SizeType i = 0; i < value["Channels"].Size(); i += 1)
                {
                    Channel channel;
                    if (!value["Channels"][i].IsObject() || !channel.InitFromJsonValue(value["Channels"][i])) return false;
                    channels.push_back(channel);
                }
                SetChannels(channels);
            }
            {
                // Non-mandatory property
                if (value.HasMember("All"))
                {
                    Link all;
                    if (!value["All"].IsObject() || !all.InitFromJsonValue(value["All"])) return false;
                    SetAll(all);
                }
            }

            return true;
        }

    private:
        Maybe <std::string> mTitle;
        Maybe <std::vector<Channel> > mChannels;
        Maybe <Link> mAll;
    };
}

#endif //READY4AIR_LIVESECTION_H
