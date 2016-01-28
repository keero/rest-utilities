#ifndef READY4AIR_EPGINFO_H
#define READY4AIR_EPGINFO_H

#include "../common/Maybe.h"
#include "abstract/JsonDeserializable.h"
#include "Event.h"
#include "hypermedia/Link.h"

namespace ready4air
{
    namespace dto
    {
        class EpgInfo : public JsonDeserializable
        {
        public:
            EpgInfo() : TAG("ready4air::dto::EpgInfo")
            {
            }

            virtual ~EpgInfo()
            {
            }

            const Maybe<Event> &GetNow() const
            {
                return mNow;
            }

            void SetNow(const Event &now)
            {
                mNow = now;
            }

            const Maybe<Event> &GetNext() const
            {
                return mNext;
            }

            void SetNext(const Event &next)
            {
                mNext = next;
            }

            const Maybe<Link> &GetAll() const
            {
                return mAll;
            }

            void SetAll(const Link &all)
            {
                mAll = all;
            }

            virtual BOOL_T InitFromJsonValue(const rapidjson::Value &value, ParseErrors &parseErrors)
            {
                Event now;
                Event next;
                Link all;

                if (ParseObject(value, "Now", false, now, parseErrors))
                    SetNow(now);

                if (ParseObject(value, "Next", true, next, parseErrors))
                    SetNext(next);

                if (ParseObject(value, "All", true, all, parseErrors))
                    SetAll(all);

                return !parseErrors;
            }

        private:
            Maybe<Event> mNow;
            Maybe<Event> mNext;
            Maybe<Link> mAll;
            const STRING_T TAG;
        };
    }
}

#endif //READY4AIR_EPGINFO_H
