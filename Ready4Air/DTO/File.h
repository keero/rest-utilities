#ifndef READY4AIR_FILE_H
#define READY4AIR_FILE_H

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

        int GetFileTypeId() const
        {
            return mFileTypeId;
        }

        void SetFileTypeId(int fileTypeId)
        {
            mFileTypeId = fileTypeId;
        }

        const std::string &GetFileTypeName() const
        {
            return mFileTypeName;
        }

        void SetFileTypeName(const std::string &fileTypeName)
        {
            mFileTypeName = fileTypeName;
        }

        const std::string &GetLanguage() const
        {
            return mLanguage;
        }

        void SetLanguage(const std::string &language)
        {
            mLanguage = language;
        }

        const Link &GetLink() const
        {
            return mLink;
        }

        void SetLink(const Link &link)
        {
            mLink = link;
        }

        int GetBitrate() const
        {
            return mBitrate;
        }

        void SetBitrate(int bitrate)
        {
            mBitrate = bitrate;
        }

        const ProtectionData &GetProtectionData() const
        {
            return mProtectionData;
        }

        void SetProtectionData(const ProtectionData &protectionData)
        {
            mProtectionData = protectionData;
        }

    private:
        int mFileTypeId;
        std::string mFileTypeName;
        std::string mLanguage;
        Link mLink;
        int mBitrate;
        ProtectionData mProtectionData;
    };
}

#endif //READY4AIR_FILE_H
