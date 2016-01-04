#ifndef READY4AIR_EVENT_H
#define READY4AIR_EVENT_H

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

        const std::string &GetStart() const
        {
            return mStart;
        }

        void SetStart(const std::string &start)
        {
            mStart = start;
        }

        const std::string &GetEnd() const
        {
            return mEnd;
        }

        void SetEnd(const std::string &anEnd)
        {
            mEnd = anEnd;
        }

        const MediaProduct &GetMedia() const
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
                if (!value.HasMember("Start") || !value["Start"].GetString()) return false;
                SetStart(value["Start"].GetString());
            }
            {
                // Mandatory property
                if (!value.HasMember("End") || !value["End"].GetString()) return false;
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
        std::string mStart;
        std::string mEnd;
        MediaProduct mMedia;
    };
}

#endif //READY4AIR_EVENT_H
