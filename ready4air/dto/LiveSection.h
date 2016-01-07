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
            return false;
        }

    private:
        Maybe <std::string> mTitle;
        Maybe <std::vector<Channel> > mChannels;
        Maybe <Link> mAll;
    };
}

#endif //READY4AIR_LIVESECTION_H
