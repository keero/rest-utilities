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

        virtual bool InitFromJsonValue(const rapidjson::Value &value, ParseErrors &parseErrors)
        {
            int fileTypeId;
            std::string fileTypeName;
            std::string language;
            Link link;
            int bitrate;
            ProtectionData protectionData;

            if (ParseInt(value, "FileTypeId", true, fileTypeId, parseErrors))
                SetFileTypeId(fileTypeId);

            if (ParseString(value, "FileTypeName", true, fileTypeName, parseErrors))
                SetFileTypeName(fileTypeName);

            if (ParseString(value, "Language", true, language, parseErrors))
                SetLanguage(language);

            if (ParseObject(value, "Link", true, link, parseErrors))
                SetLink(link);

            if (ParseInt(value, "Bitrate", true, bitrate, parseErrors))
                SetBitrate(bitrate);

            if (ParseObject(value, "ProtectionData", false, protectionData, parseErrors))
                SetProtectionData(protectionData);

            return !parseErrors;
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
