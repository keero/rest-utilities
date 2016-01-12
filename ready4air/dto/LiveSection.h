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

        virtual bool InitFromJsonValue(const rapidjson::Value &value, ParseErrors &parseErrors)
        {
            std::string title;
            std::vector<Channel> channels;
            Link all;

            if (ParseString(value, "Title", true, title, parseErrors))
                SetTitle(title);

            if (VerifyArray(value, "Channels", true, parseErrors))
            {
                for (rapidjson::SizeType i = 0; i < value["Channels"].Size(); i += 1)
                {
                    Channel channel;
                    if (ParseObject(value["Channels"][i], "", false, channel, parseErrors))
                        channels.push_back(channel);
                }
                SetChannels(channels);
            }

            if (ParseObject(value, "All", false, all, parseErrors))
                SetAll(all);

            return !parseErrors;
        }

    private:
        Maybe <std::string> mTitle;
        Maybe <std::vector<Channel> > mChannels;
        Maybe <Link> mAll;
    };
}

#endif //READY4AIR_LIVESECTION_H
