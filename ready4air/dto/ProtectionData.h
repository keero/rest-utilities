#ifndef READY4AIR_PROTECTIONDATA_H
#define READY4AIR_PROTECTIONDATA_H

#include "../maybe/Maybe.h"
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

        const Maybe <std::string> &GetKeyId() const
        {
            return mKeyId;
        }

        void SetKeyId(const std::string &keyId)
        {
            mKeyId = keyId;
        }

        const Maybe <Link> &GetPlayReadyLicenser() const
        {
            return mPlayReadyLicenser;
        }

        void SetPlayReadyLicenser(const Link &playReadyLicenser)
        {
            mPlayReadyLicenser = playReadyLicenser;
        }

        const Maybe <Link> &GetWidevineLicenser() const
        {
            return mWidevineLicenser;
        }

        void SetWidevineLicenser(const Link &widevineLicenser)
        {
            mWidevineLicenser = widevineLicenser;
        }

        const Maybe <std::string> &GetWidevinePSSH() const
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
        Maybe <std::string> mKeyId;
        Maybe <Link> mPlayReadyLicenser;
        Maybe <Link> mWidevineLicenser;
        Maybe <std::string> mWidevinePSSH;
    };
}

#endif //READY4AIR_PROTECTIONDATA_H
