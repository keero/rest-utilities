#ifndef READY4AIR_MANIFESTS_H
#define READY4AIR_MANIFESTS_H

#include "../maybe/Maybe.h"
#include "abstract/JsonDeserializable.h"
#include "Manifest.h"
#include "PlaySubtitle.h"
#include "File.h"
#include "hypermedia/Link.h"

namespace ready4air
{
    class Manifests : public JsonDeserializable
    {
    public:
        Manifests()
        {
        }

        virtual ~Manifests()
        {
        }

        const Maybe <std::vector<Manifest> > &GetSmooth() const
        {
            return mSmooth;
        }

        void SetSmooth(const std::vector<Manifest> &smooth)
        {
            mSmooth = smooth;
        }

        const Maybe <std::vector<Manifest> > &GetDash() const
        {
            return mDash;
        }

        void SetDash(const std::vector<Manifest> &dash)
        {
            mDash = dash;
        }

        const Maybe <std::vector<Manifest> > &GetHls() const
        {
            return mHls;
        }

        void SetHls(const std::vector<Manifest> &hls)
        {
            mHls = hls;
        }

        const Maybe <std::vector<PlaySubtitle> > &GetSubtitles() const
        {
            return mSubtitles;
        }

        void SetSubtitles(const std::vector<PlaySubtitle> &subtitles)
        {
            mSubtitles = subtitles;
        }

        const Maybe <std::vector<File> > &GetProgressive() const
        {
            return mProgressive;
        }

        void SetProgressive(const std::vector<File> &progressive)
        {
            mProgressive = progressive;
        }

        const Maybe <Link> &GetThumbnails() const
        {
            return mThumbnails;
        }

        void SetThumbnails(const Link &thumbnails)
        {
            mThumbnails = thumbnails;
        }

        virtual bool InitFromJsonValue(const rapidjson::Value &value)
        {
            return false;
        }

    private:
        Maybe <std::vector<Manifest> > mSmooth;
        Maybe <std::vector<Manifest> > mDash;
        Maybe <std::vector<Manifest> > mHls;
        Maybe <std::vector<PlaySubtitle> > mSubtitles;
        Maybe <std::vector<File> > mProgressive;
        Maybe <Link> mThumbnails;
    };
}

#endif //READY4AIR_MANIFESTS_H
