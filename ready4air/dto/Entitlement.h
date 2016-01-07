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

        virtual bool InitFromJsonValue(const rapidjson::Value &value)
        {
            {
                // Mandatory property
                if (!value.HasMember("Type") || !value["Type"].IsString()) return false;
                SetType(value["Type"].GetString());
            }
            {
                // Mandatory property
                if (!value.HasMember("EntitledTo") || !value["EntitledTo"].IsString()) return false;
                SetEntitledTo(value["EntitledTo"].GetString());
            }
            {
                // Non-mandatory property
                if (value.HasMember("StartTime"))
                {
                    if (!value["StartTime"].IsString()) return false;
                    SetStartTime(value["StartTime"].GetString());
                }
            }
            {
                // Non-mandatory property
                if (value.HasMember("EndTime"))
                {
                    if (!value["EndTime"].IsString()) return false;
                    SetEndTime(value["EndTime"].GetString());
                }
            }
            {
                // Non-mandatory property
                if (value.HasMember("DRM"))
                {
                    DRM drm;
                    if (!value["DRM"].IsObject() || !drm.InitFromJsonValue(value["DRM"])) return false;
                    SetDRM(drm);
                }
            }
            {
                // Non-mandatory property
                if (value.HasMember("Identifier"))
                {
                    if (!value["Identifier"].IsString()) return false;
                    SetIdentifier(value["Identifier"].GetString());
                }
            }

            return true;
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
