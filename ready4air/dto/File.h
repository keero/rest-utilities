#ifndef READY4AIR_FILE_H
#define READY4AIR_FILE_H

#include "../maybe/Maybe.h"
#include "abstract/JsonDeserializable.h"
#include "hypermedia/Link.h"
#include "ProtectionData.h"

namespace ready4air
{
    class File : public JsonDeserializable
    {
    public:
        File()
        {
        }

        virtual ~File()
        {
        }

        const Maybe <int> &GetFileTypeId() const
        {
            return mFileTypeId;
        }

        void SetFileTypeId(int fileTypeId)
        {
            mFileTypeId = fileTypeId;
        }

        const Maybe <std::string> &GetFileTypeName() const
        {
            return mFileTypeName;
        }

        void SetFileTypeName(const std::string &fileTypeName)
        {
            mFileTypeName = fileTypeName;
        }

        const Maybe <std::string> &GetLanguage() const
        {
            return mLanguage;
        }

        void SetLanguage(const std::string &language)
        {
            mLanguage = language;
        }

        const Maybe <Link> &GetLink() const
        {
            return mLink;
        }

        void SetLink(const Link &link)
        {
            mLink = link;
        }

        const Maybe <int> &GetBitrate() const
        {
            return mBitrate;
        }

        void SetBitrate(int bitrate)
        {
            mBitrate = bitrate;
        }

        const Maybe <ProtectionData> &GetProtectionData() const
        {
            return mProtectionData;
        }

        void SetProtectionData(const ProtectionData &protectionData)
        {
            mProtectionData = protectionData;
        }

        virtual bool InitFromJsonValue(const rapidjson::Value &value)
        {
            {
                // Mandatory property
                if (!value.HasMember("FileTypeId") || !value["FileTypeId"].IsInt()) return false;
                SetFileTypeId(value["FileTypeId"].GetInt());
            }
            {
                // Mandatory property
                if (!value.HasMember("FileTypeName") || !value["FileTypeName"].IsString()) return false;
                SetFileTypeName(value["FileTypeName"].GetString());
            }
            {
                // Mandatory property
                if (!value.HasMember("Language") || !value["Language"].IsString()) return false;
                SetLanguage(value["Language"].GetString());
            }
            {
                // Mandatory property
                Link link;
                if (!value.HasMember("Link") || !value["Link"].IsObject() || !link.InitFromJsonValue(value["Link"])) return false;
                SetLink(link);
            }
            {
                // Mandatory property
                if (!value.HasMember("Bitrate") || !value["Bitrate"].IsInt()) return false;
                SetBitrate(value["Bitrate"].GetInt());
            }
            {
                // Non-mandatory property
                if (value.HasMember("ProtectionData"))
                {
                    ProtectionData protectionData;
                    if (!value["ProtectionData"].IsObject() || !protectionData.InitFromJsonValue(value["ProtectionData"])) return false;
                    SetProtectionData(protectionData);
                }
            }

            return true;
        }

    private:
        Maybe <int> mFileTypeId;
        Maybe <std::string> mFileTypeName;
        Maybe <std::string> mLanguage;
        Maybe <Link> mLink;
        Maybe <int> mBitrate;
        Maybe <ProtectionData> mProtectionData;
    };
}

#endif //READY4AIR_FILE_H
