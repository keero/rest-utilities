#ifndef READY4AIR_EVENT_H
#define READY4AIR_EVENT_H

#include "../maybe/Maybe.h"
#include "abstract/JsonDeserializable.h"
#include "MediaProduct.h"

namespace ready4air
{
    class Event : public JsonDeserializable
    {
    public:
        Event()
        {
        }

        virtual ~Event()
        {
        }

        const Maybe <std::string> &GetStart() const
        {
            return mStart;
        }

        void SetStart(const std::string &start)
        {
            mStart = start;
        }

        const Maybe <std::string> &GetEnd() const
        {
            return mEnd;
        }

        void SetEnd(const std::string &anEnd)
        {
            mEnd = anEnd;
        }

        const Maybe <MediaProduct> &GetMedia() const
        {
            return mMedia;
        }

        void SetMedia(const MediaProduct &media)
        {
            mMedia = media;
        }

        virtual bool InitFromJsonValue(const rapidjson::Value &value)
        {
            {
                // Mandatory property
                if (!value.HasMember("Start") || !value["Start"].IsString()) return false;
                SetStart(value["Start"].GetString());
            }
            {
                // Mandatory property
                if (!value.HasMember("End") || !value["End"].IsString()) return false;
                SetEnd(value["End"].GetString());
            }
            {
                // Mandatory property
                MediaProduct media;
                if (!value.HasMember("Media") || !value["Media"].IsObject() || !media.InitFromJsonValue(value["Media"])) return false;
                SetMedia(media);
            }

            return true;
        }

    private:
        Maybe <std::string> mStart;
        Maybe <std::string> mEnd;
        Maybe <MediaProduct> mMedia;
    };
}

#endif //READY4AIR_EVENT_H
