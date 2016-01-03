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

        const std::string &GetAnEnd() const
        {
            return mEnd;
        }

        void SetAnEnd(const std::string &anEnd)
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

    private:
        std::string mStart;
        std::string mEnd;
        MediaProduct mMedia;
    };
}

#endif //READY4AIR_EVENT_H
