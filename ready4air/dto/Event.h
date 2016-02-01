#ifndef READY4AIR_EVENT_H
#define READY4AIR_EVENT_H

#include "../common/Maybe.h"
#include "abstract/JsonDeserializable.h"
#include "MediaProduct.h"

namespace ready4air
{
    namespace dto
    {
        class Event : public JsonDeserializable
        {
        public:
            Event() : TAG("ready4air::dto::Event")
            {
            }

            virtual ~Event()
            {
            }

            const Maybe <STRING_T> &GetStart() const
            {
                return mStart;
            }

            void SetStart(const STRING_T &start)
            {
                mStart = start;
            }

            const Maybe <STRING_T> &GetEnd() const
            {
                return mEnd;
            }

            void SetEnd(const STRING_T &anEnd)
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

            virtual BOOL_T InitFromJsonValue(const rapidjson::Value &value, ParseErrors &parseErrors)
            {
                STRING_T start;
                STRING_T end;
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
            Maybe <STRING_T> mStart;
            Maybe <STRING_T> mEnd;
            Maybe <MediaProduct> mMedia;
            STRING_T TAG;
        };
    }
}

#endif //READY4AIR_EVENT_H
