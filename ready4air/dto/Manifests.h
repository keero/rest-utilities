#ifndef READY4AIR_MANIFESTS_H
#define READY4AIR_MANIFESTS_H

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

        const std::vector<Manifest> &GetSmooth() const
        {
            return mSmooth;
        }

        void SetSmooth(const std::vector<Manifest> &smooth)
        {
            mSmooth = smooth;
        }

        const std::vector<Manifest> &GetDash() const
        {
            return mDash;
        }

        void SetDash(const std::vector<Manifest> &dash)
        {
            mDash = dash;
        }

        const std::vector<Manifest> &GetHls() const
        {
            return mHls;
        }

        void SetHls(const std::vector<Manifest> &hls)
        {
            mHls = hls;
        }

        const std::vector<PlaySubtitle> &GetSubtitles() const
        {
            return mSubtitles;
        }

        void SetSubtitles(const std::vector<PlaySubtitle> &subtitles)
        {
            mSubtitles = subtitles;
        }

        const std::vector<File> &GetProgressive() const
        {
            return mProgressive;
        }

        void SetProgressive(const std::vector<File> &progressive)
        {
            mProgressive = progressive;
        }

        const Link &GetThumbnails() const
        {
            return mThumbnails;
        }

        void SetThumbnails(const Link &thumbnails)
        {
            mThumbnails = thumbnails;
        }

    private:
        std::vector<Manifest> mSmooth;
        std::vector<Manifest> mDash;
        std::vector<Manifest> mHls;
        std::vector<PlaySubtitle> mSubtitles;
        std::vector<File> mProgressive;
        Link mThumbnails;
    };
}

#endif //READY4AIR_MANIFESTS_H
