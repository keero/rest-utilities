#ifndef READY4AIR_ENTITLEMENT_H
#define READY4AIR_ENTITLEMENT_H

#include "../maybe/Maybe.h"
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

        const Maybe <std::string> &GetType() const
        {
            return mType;
        }

        void SetType(const std::string &type)
        {
            mType = type;
        }

        const Maybe <std::string> &GetEntitledTo() const
        {
            return mEntitledTo;
        }

        void SetEntitledTo(const std::string &entitledTo)
        {
            mEntitledTo = entitledTo;
        }

        const Maybe <std::string> &GetStartTime() const
        {
            return mStartTime;
        }

        void SetStartTime(const std::string &startTime)
        {
            mStartTime = startTime;
        }

        const Maybe <std::string> &GetEndTime() const
        {
            return mEndTime;
        }

        void SetEndTime(const std::string &endTime)
        {
            mEndTime = endTime;
        }

        const Maybe <DRM> &GetDRM() const
        {
            return mDRM;
        }

        void SetDRM(const DRM &DRM)
        {
            mDRM = DRM;
        }

        const Maybe <std::string> &GetIdentifier() const
        {
            return mIdentifier;
        }

        void SetIdentifier(const std::string &identifier)
        {
            mIdentifier = identifier;
        }

        virtual bool InitFromJsonValue(const rapidjson::Value &value, ParseErrors &parseErrors)
        {
            std::string type;
            std::string entitledTo;
            std::string startTime;
            std::string endTime;
            DRM drm;
            std::string identifier;

            if (ParseString(value, "Type", true, type, parseErrors))
                SetType(type);

            if (ParseString(value, "EntitledTo", true, entitledTo, parseErrors))
                SetEntitledTo(entitledTo);

            if (ParseString(value, "StartTime", false, startTime, parseErrors))
                SetStartTime(startTime);

            if (ParseString(value, "EndTime", false, endTime, parseErrors))
                SetEndTime(endTime);

            if (ParseObject(value, "DRM", false, drm, parseErrors))
                SetDRM(drm);

            if (ParseString(value, "Identifier", false, identifier, parseErrors))
                SetIdentifier(identifier);

            return !parseErrors;
        }

    private:
        Maybe <std::string> mType;
        Maybe <std::string> mEntitledTo;
        Maybe <std::string> mStartTime;
        Maybe <std::string> mEndTime;
        Maybe <DRM> mDRM;
        Maybe <std::string> mIdentifier;
    };
}

#endif //READY4AIR_ENTITLEMENT_H
