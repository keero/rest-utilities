#ifndef READY4AIR_SECTION_H
#define READY4AIR_SECTION_H

#include "../maybe/Maybe.h"
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

        const Maybe <std::string> &GetTitle() const
        {
            return mTitle;
        }

        void SetTitle(const std::string &title)
        {
            mTitle = title;
        }

        const Maybe <Link> &GetAll() const
        {
            return mAll;
        }

        void SetAll(const Link &all)
        {
            mAll = all;
        }

        const Maybe <std::vector<MediaProduct> > &GetMedias() const
        {
            return mMedias;
        }

        void SetMedias(const std::vector<MediaProduct> &medias)
        {
            mMedias = medias;
        }

        virtual bool InitFromJsonValue(const rapidjson::Value &value)
        {
            return false;
        }

    private:
        Maybe <std::string> mTitle;
        Maybe <Link> mAll;
        Maybe <std::vector<MediaProduct> > mMedias;
    };
}

#endif //READY4AIR_SECTION_H
