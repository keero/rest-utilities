#ifndef READY4AIR_EPGINFO_H
#define READY4AIR_EPGINFO_H

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

        const Event &GetNow() const
        {
            return mNow;
        }

        void SetNow(const Event &now)
        {
            mNow = now;
        }

        const Event &GetNext() const
        {
            return mNext;
        }

        void SetNext(const Event &next)
        {
            mNext = next;
        }

        const Link &GetAll() const
        {
            return mAll;
        }

        void SetAll(const Link &all)
        {
            mAll = all;
        }

        virtual bool InitFromJsonValue(const rapidjson::Value &value)
        {
            {
                // Non-mandatory property
                if (value.HasMember("Now"))
                {
                    Event now;
                    if (!value["Now"].IsObject() || !now.InitFromJsonValue(value["Now"])) return false;
                    SetNow(now);
                }
            }
            {
                // Mandatory property
                Event next;
                if (!value.HasMember("Next") || !value["Next"].IsObject() || !next.InitFromJsonValue(value["Next"])) return false;
                SetNext(next);
            }
            {
                // Mandatory property
                Link all;
                if (!value.HasMember("All") || !value["All"].IsObject() || !all.InitFromJsonValue(value["All"])) return false;
                SetAll(all);
            }

            return true;
        }

    private:
        Event mNow;
        Event mNext;
        Link mAll;

    };
}

#endif //READY4AIR_EPGINFO_H
