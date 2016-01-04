#ifndef READY4AIR_LIVESECTION_H
#define READY4AIR_LIVESECTION_H

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

        const std::string &GetTitle() const
        {
            return mTitle;
        }

        void SetTitle(const std::string &title)
        {
            mTitle = title;
        }

        const std::vector<Channel> &GetChannels() const
        {
            return mChannels;
        }

        void SetChannels(const std::vector<Channel> &channels)
        {
            mChannels = channels;
        }

        const Link &GetAll() const
        {
            return mAll;
        }

        void SetAll(const Link &all)
        {
            mAll = all;
        }

    private:
        std::string mTitle;
        std::vector<Channel> mChannels;
        Link mAll;
    };
}

#endif //READY4AIR_LIVESECTION_H
