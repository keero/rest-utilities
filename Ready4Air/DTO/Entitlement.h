#ifndef READY4AIR_ENTITLEMENT_H
#define READY4AIR_ENTITLEMENT_H

#include "abstract/JsonDeserializable.h"
#include "DRM.h"

namespace ready4air
{
    class Entitlement : public JsonDeserializable
    {
    public:
        Entitlement()
        {
        }

        virtual ~Entitlement()
        {
        }

        const std::string &GetType() const
        {
            return mType;
        }

        void SetType(const std::string &type)
        {
            mType = type;
        }

        const std::string &GetEntitledTo() const
        {
            return mEntitledTo;
        }

        void SetEntitledTo(const std::string &entitledTo)
        {
            mEntitledTo = entitledTo;
        }

        const std::string &GetStartTime() const
        {
            return mStartTime;
        }

        void SetStartTime(const std::string &startTime)
        {
            mStartTime = startTime;
        }

        const std::string &GetEndTime() const
        {
            return mEndTime;
        }

        void SetEndTime(const std::string &endTime)
        {
            mEndTime = endTime;
        }

        const DRM &GetDRM() const
        {
            return mDRM;
        }

        void SetDRM(const DRM &DRM)
        {
            mDRM = DRM;
        }

        const std::string &GetIdentifier() const
        {
            return mIdentifier;
        }

        void SetIdentifier(const std::string &identifier)
        {
            mIdentifier = identifier;
        }

    private:
        std::string mType;
        std::string mEntitledTo;
        std::string mStartTime;
        std::string mEndTime;
        DRM mDRM;
        std::string mIdentifier;
    };
}

#endif //READY4AIR_ENTITLEMENT_H
