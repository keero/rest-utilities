#ifndef READY4AIR_LIVESECTION_H
#define READY4AIR_LIVESECTION_H

#include "../common/Maybe.h"
#include "abstract/JsonDeserializable.h"
#include "Channel.h"
#include "hypermedia/Link.h"

namespace ready4air
{
    namespace dto
    {
        class LiveSection : public JsonDeserializable
        {
        public:
            LiveSection() : TAG("ready4air::dto::LiveSection")
            {
            }

            virtual ~LiveSection()
            {
            }

            const Maybe<STRING_T> &GetTitle() const
            {
                return mTitle;
            }

            void SetTitle(const STRING_T &title)
            {
                mTitle = title;
            }

            const Maybe<VECTOR_T<Channel> > &GetChannels() const
            {
                return mChannels;
            }

            void SetChannels(const VECTOR_T<Channel> &channels)
            {
                mChannels = channels;
            }

            const Maybe<Link> &GetAll() const
            {
                return mAll;
            }

            void SetAll(const Link &all)
            {
                mAll = all;
            }

            virtual BOOL_T InitFromJsonValue(const rapidjson::Value &value, ParseErrors &parseErrors,
                                             VECTOR_T<STRING_T> &context)
            {
                STRING_T title;
                VECTOR_T<Channel> channels;
                Link all;

                context.push_back(TAG);

                if (ParseString(value, "Title", true, title, parseErrors, context))
                    SetTitle(title);

                if (VerifyArray(value, "Channels", true, parseErrors, context))
                {
                    for (rapidjson::SizeType i = 0; i < value["Channels"].Size(); i += 1)
                    {
                        Channel channel;
                        if (ParseObject(value["Channels"][i], "", false, channel, parseErrors, context))
                            channels.push_back(channel);
                    }
                    SetChannels(channels);
                }

                if (ParseObject(value, "All", false, all, parseErrors, context))
                    SetAll(all);

                context.pop_back();
                return !parseErrors;
            }

        private:
            Maybe<STRING_T> mTitle;
            Maybe<VECTOR_T<Channel> > mChannels;
            Maybe<Link> mAll;
            STRING_T TAG;
        };
    }
}

#endif //READY4AIR_LIVESECTION_H
