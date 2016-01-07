#ifndef READY4AIR_HLSMANIFEST_H
#define READY4AIR_HLSMANIFEST_H

#include "../maybe/Maybe.h"
#include "FileBase.h"
#include "hypermedia/Link.h"

namespace ready4air
{
    class HlsManifest : public FileBase
    {
    public:
        HlsManifest()
        {
        }

        const Maybe <std::string> &GetLanguage() const
        {
            return mLanguage;
        }

        void SetLanguage(const std::string &language)
        {
            mLanguage = language;
        }

        const Maybe <short> &GetBandwidth() const
        {
            return mBandwidth;
        }

        void SetBandwidth(short bandwidth)
        {
            mBandwidth = bandwidth;
        }

        const Maybe <int> &GetManifestTypeId() const
        {
            return mManifestTypeId;
        }

        void SetManifestTypeId(int manifestTypeId)
        {
            mManifestTypeId = manifestTypeId;
        }

        const Maybe <std::string> &GetManifestTypeName() const
        {
            return mManifestTypeName;
        }

        void SetManifestTypeName(const std::string &manifestTypeName)
        {
            mManifestTypeName = manifestTypeName;
        }

        const Maybe <int> &GetLocation() const
        {
            return mLocation;
        }

        void SetLocation(int location)
        {
            mLocation = location;
        }

        const Maybe <Link> &GetMmsLink() const
        {
            return mMmsLink;
        }

        void SetMmsLink(const Link &mmsLink)
        {
            mMmsLink = mmsLink;
        }

        virtual bool InitFromJsonValue(const rapidjson::Value &value)
        {
            // Initialize parent properties
            if (!FileBase::InitFromJsonValue(value)) return false;

            {
                // Non-mandatory property
                if (value.HasMember("Language"))
                {
                    if (!value["Language"].IsString()) return false;
                    SetLanguage(value["Language"].GetString());
                }
            }
            {
                // Mandatory property
                if (!value.HasMember("Bandwidth") || !value["Bandwidth"].IsInt()) return false;
                SetBandwidth((short) value["Bandwidth"].GetInt());
            }
            {
                // Non-mandatory property
                if (value.HasMember("ManifestTypeId"))
                {
                    if (!value["ManifestTypeId"].IsInt()) return false;
                    SetManifestTypeId(value["ManifestTypeId"].GetInt());
                }
            }
            {
                // Non-mandatory property
                if (value.HasMember("ManifestTypeName"))
                {
                    if (!value["ManifestTypeName"].IsString()) return false;
                    SetManifestTypeName(value["ManifestTypeName"].GetString());
                }
            }
            {
                // Mandatory property
                if (!value.HasMember("Location") || !value["Location"].IsInt()) return false;
                SetLocation(value["Location"].GetInt());
            }
            {
                // Non-mandatory property
                if (value.HasMember("MmsLink"))
                {
                    Link mmsLink;
                    if (!value["MmsLink"].IsObject() || !mmsLink.InitFromJsonValue(value["MmsLink"])) return false;
                    SetMmsLink(mmsLink);
                }
            }

            return true;
        }

    private:
        Maybe <std::string> mLanguage;
        Maybe <short> mBandwidth;
        Maybe <int> mManifestTypeId;
        Maybe <std::string> mManifestTypeName;
        Maybe <int> mLocation;
        Maybe <Link> mMmsLink;
    };
}

#endif //READY4AIR_HLSMANIFEST_H
