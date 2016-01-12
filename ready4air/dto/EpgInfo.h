#ifndef READY4AIR_EPGINFO_H
#define READY4AIR_EPGINFO_H

#include "../maybe/Maybe.h"
#include "abstract/JsonDeserializable.h"
#include "Event.h"
#include "hypermedia/Link.h"

namespace ready4air
{
    class EpgInfo : public JsonDeserializable
    {
    public:
        EpgInfo()
        {
        }

        virtual ~EpgInfo()
        {
        }

        const Maybe <Event> &GetNow() const
        {
            return mNow;
        }

        void SetNow(const Event &now)
        {
            mNow = now;
        }

        const Maybe <Event> &GetNext() const
        {
            return mNext;
        }

        void SetNext(const Event &next)
        {
            mNext = next;
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
        Maybe <Event> mNow;
        Maybe <Event> mNext;
        Maybe <Link> mAll;

    };
}

#endif //READY4AIR_EPGINFO_H
