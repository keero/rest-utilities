#ifndef READY4AIR_SECTION_H
#define READY4AIR_SECTION_H

#include "abstract/JsonDeserializable.h"
#include "hypermedia/Link.h"
#include "MediaProduct.h"

namespace ready4air
{
    class Section : public JsonDeserializable
    {
    public:
        Section()
        {
        }

        virtual ~Section()
        {
        }

        const std::string &GetTitle() const
        {
            return mTitle;
        }

        void SetTitle(const std::string &title)
        {
            mTitle = title;
        }

        const Link &GetAll() const
        {
            return mAll;
        }

        void SetAll(const Link &all)
        {
            mAll = all;
        }

        const std::vector<MediaProduct> &GetMedias() const
        {
            return mMedias;
        }

        void SetMedias(const std::vector<MediaProduct> &medias)
        {
            mMedias = medias;
        }

    private:
        std::string mTitle;
        Link mAll;
        std::vector<MediaProduct> mMedias;
    };
}

#endif //READY4AIR_SECTION_H
