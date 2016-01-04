#ifndef READY4AIR_PROTECTIONDATA_H
#define READY4AIR_PROTECTIONDATA_H

#include "abstract/JsonDeserializable.h"
#include "hypermedia/Link.h"

namespace ready4air
{
    class ProtectionData : public JsonDeserializable
    {
    public:
        ProtectionData()
        {
        }

        virtual ~ProtectionData()
        {
        }

        const std::string &GetKeyId() const
        {
            return mKeyId;
        }

        void SetKeyId(const std::string &keyId)
        {
            mKeyId = keyId;
        }

        const Link &GetPlayReadyLicenser() const
        {
            return mPlayReadyLicenser;
        }

        void SetPlayReadyLicenser(const Link &playReadyLicenser)
        {
            mPlayReadyLicenser = playReadyLicenser;
        }

        const Link &GetWidevineLicenser() const
        {
            return mWidevineLicenser;
        }

        void SetWidevineLicenser(const Link &widevineLicenser)
        {
            mWidevineLicenser = widevineLicenser;
        }

        const std::string &GetWidevinePSSH() const
        {
            return mWidevinePSSH;
        }

        void SetWidevinePSSH(const std::string &widevinePSSH)
        {
            mWidevinePSSH = widevinePSSH;
        }

        virtual bool InitFromJsonValue(const rapidjson::Value &value)
        {
            return false;
        }

    private:
        std::string mKeyId;
        Link mPlayReadyLicenser;
        Link mWidevineLicenser;
        std::string mWidevinePSSH;
    };
}

#endif //READY4AIR_PROTECTIONDATA_H
