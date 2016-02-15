#ifndef READY4AIR_ENTITLEMENT_H
#define READY4AIR_ENTITLEMENT_H

#include "../common/Maybe.h"
#include "abstract/JsonDeserializable.h"
#include "DRM.h"

namespace ready4air
{
    namespace dto
    {
        class Entitlement : public JsonDeserializable
        {
        public:
            Entitlement() : TAG("ready4air::dto::Entitlement")
            {
            }

            virtual ~Entitlement()
            {
            }

            const Maybe<STRING_T> &GetType() const
            {
                return mType;
            }

            void SetType(const STRING_T &type)
            {
                mType = type;
            }

            const Maybe<STRING_T> &GetEntitledTo() const
            {
                return mEntitledTo;
            }

            void SetEntitledTo(const STRING_T &entitledTo)
            {
                mEntitledTo = entitledTo;
            }

            const Maybe<STRING_T> &GetStartTime() const
            {
                return mStartTime;
            }

            void SetStartTime(const STRING_T &startTime)
            {
                mStartTime = startTime;
            }

            const Maybe<STRING_T> &GetEndTime() const
            {
                return mEndTime;
            }

            void SetEndTime(const STRING_T &endTime)
            {
                mEndTime = endTime;
            }

            const Maybe<DRM> &GetDRM() const
            {
                return mDRM;
            }

            void SetDRM(const DRM &DRM)
            {
                mDRM = DRM;
            }

            const Maybe<STRING_T> &GetIdentifier() const
            {
                return mIdentifier;
            }

            void SetIdentifier(const STRING_T &identifier)
            {
                mIdentifier = identifier;
            }

            virtual BOOL_T InitFromJsonValue(const rapidjson::Value &value, ParseErrors &parseErrors,
                                             VECTOR_T<STRING_T> &context)
            {
                STRING_T type;
                STRING_T entitledTo;
                STRING_T startTime;
                STRING_T endTime;
                DRM drm;
                STRING_T identifier;

                context.push_back(TAG);

                if (ParseString(value, "Type", true, type, parseErrors, context))
                    SetType(type);

                if (ParseString(value, "EntitledTo", true, entitledTo, parseErrors, context))
                    SetEntitledTo(entitledTo);

                if (ParseString(value, "StartTime", false, startTime, parseErrors, context))
                    SetStartTime(startTime);

                if (ParseString(value, "EndTime", false, endTime, parseErrors, context))
                    SetEndTime(endTime);

                if (ParseObject(value, "DRM", false, drm, parseErrors, context))
                    SetDRM(drm);

                if (ParseString(value, "Identifier", false, identifier, parseErrors, context))
                    SetIdentifier(identifier);

                context.pop_back();
                return !parseErrors;
            }

        private:
            Maybe<STRING_T> mType;
            Maybe<STRING_T> mEntitledTo;
            Maybe<STRING_T> mStartTime;
            Maybe<STRING_T> mEndTime;
            Maybe<DRM> mDRM;
            Maybe<STRING_T> mIdentifier;
            STRING_T TAG;
        };
    }
}

#endif //READY4AIR_ENTITLEMENT_H
