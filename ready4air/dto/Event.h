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

        virtual bool InitFromJsonValue(const rapidjson::Value &value, ParseErrors &parseErrors)
        {
            std::string start;
            std::string end;
            MediaProduct media;

            if (ParseString(value, "Start", true, start, parseErrors))
                SetStart(start);

            if (ParseString(value, "End", true, end, parseErrors))
                SetEnd(end);

            if (ParseObject(value, "Media", true, media, parseErrors))
                SetMedia(media);

            return !parseErrors;
        }

    private:
        Maybe <std::string> mStart;
        Maybe <std::string> mEnd;
        Maybe <MediaProduct> mMedia;
    };
}

#endif //READY4AIR_EVENT_H
