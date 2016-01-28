#ifndef READY4AIR_PROTECTIONDATA_H
#define READY4AIR_PROTECTIONDATA_H

#include "../common/Maybe.h"
#include "abstract/JsonDeserializable.h"
#include "hypermedia/Link.h"

namespace ready4air
{
    namespace dto
    {
        class ProtectionData : public JsonDeserializable
        {
        public:
            ProtectionData() : TAG("ready4air::dto::ProtectionData")
            {
            }

            virtual ~ProtectionData()
            {
            }

            const Maybe<STRING_T> &GetKeyId() const
            {
                return mKeyId;
            }

            void SetKeyId(const STRING_T &keyId)
            {
                mKeyId = keyId;
            }

            const Maybe<Link> &GetPlayReadyLicenser() const
            {
                return mPlayReadyLicenser;
            }

            void SetPlayReadyLicenser(const Link &playReadyLicenser)
            {
                mPlayReadyLicenser = playReadyLicenser;
            }

            const Maybe<Link> &GetWidevineLicenser() const
            {
                return mWidevineLicenser;
            }

            void SetWidevineLicenser(const Link &widevineLicenser)
            {
                mWidevineLicenser = widevineLicenser;
            }

            const Maybe<STRING_T> &GetWidevinePSSH() const
            {
                return mWidevinePSSH;
            }

            void SetWidevinePSSH(const STRING_T &widevinePSSH)
            {
                mWidevinePSSH = widevinePSSH;
            }

            virtual BOOL_T InitFromJsonValue(const rapidjson::Value &value, ParseErrors &parseErrors)
            {
                STRING_T keyId;
                Link playReadyLicenser;
                Link widevineLicenser;
                STRING_T widevinePSSH;

                if (ParseString(value, "KeyId", true, keyId, parseErrors))
                    SetKeyId(keyId);

                if (ParseObject(value, "PlayReadyLicenser", true, playReadyLicenser, parseErrors))
                    SetPlayReadyLicenser(playReadyLicenser);

                if (ParseObject(value, "WidevineLicenser", true, widevineLicenser, parseErrors))
                    SetWidevineLicenser(widevineLicenser);

                if (ParseString(value, "WidevinePSSH", true, widevinePSSH, parseErrors))
                    SetWidevinePSSH(widevinePSSH);

                return !parseErrors;
            }

        private:
            Maybe<STRING_T> mKeyId;
            Maybe<Link> mPlayReadyLicenser;
            Maybe<Link> mWidevineLicenser;
            Maybe<STRING_T> mWidevinePSSH;
            const STRING_T TAG;
        };
    }
}

#endif //READY4AIR_PROTECTIONDATA_H
