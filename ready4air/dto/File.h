#ifndef READY4AIR_FILE_H
#define READY4AIR_FILE_H

#include "../common/Maybe.h"
#include "abstract/JsonDeserializable.h"
#include "hypermedia/Link.h"
#include "ProtectionData.h"

namespace ready4air
{
    namespace dto
    {
        class File : public JsonDeserializable
        {
        public:
            File() : TAG("ready4air::dto::File")
            {
            }

            virtual ~File()
            {
            }

            const Maybe<int> &GetFileTypeId() const
            {
                return mFileTypeId;
            }

            void SetFileTypeId(int fileTypeId)
            {
                mFileTypeId = fileTypeId;
            }

            const Maybe<STRING_T> &GetFileTypeName() const
            {
                return mFileTypeName;
            }

            void SetFileTypeName(const STRING_T &fileTypeName)
            {
                mFileTypeName = fileTypeName;
            }

            const Maybe<STRING_T> &GetLanguage() const
            {
                return mLanguage;
            }

            void SetLanguage(const STRING_T &language)
            {
                mLanguage = language;
            }

            const Maybe<Link> &GetLink() const
            {
                return mLink;
            }

            void SetLink(const Link &link)
            {
                mLink = link;
            }

            const Maybe<int> &GetBitrate() const
            {
                return mBitrate;
            }

            void SetBitrate(int bitrate)
            {
                mBitrate = bitrate;
            }

            const Maybe<ProtectionData> &GetProtectionData() const
            {
                return mProtectionData;
            }

            void SetProtectionData(const ProtectionData &protectionData)
            {
                mProtectionData = protectionData;
            }

            virtual BOOL_T InitFromJsonValue(const rapidjson::Value &value, ParseErrors &parseErrors)
            {
                INT32_T fileTypeId;
                STRING_T fileTypeName;
                STRING_T language;
                Link link;
                INT32_T bitrate;
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
            Maybe<int> mFileTypeId;
            Maybe<STRING_T> mFileTypeName;
            Maybe<STRING_T> mLanguage;
            Maybe<Link> mLink;
            Maybe<int> mBitrate;
            Maybe<ProtectionData> mProtectionData;
            const STRING_T TAG;
        };
    }
}

#endif //READY4AIR_FILE_H
