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
            {
                // Non-mandatory property
                if (value.HasMember("Smooth"))
                {
                    if (!value["Smooth"].IsArray()) return false;
                    std::vector<Manifest> manifests;
                    for (rapidjson::SizeType i = 0; i < value["Smooth"].Size(); i += 1)
                    {
                        Manifest manifest;
                        if (!value["Smooth"][i].IsObject() || !manifest.InitFromJsonValue(value["Smooth"][i])) return false;
                        manifests.push_back(manifest);
                    }
                    SetSmooth(manifests);
                }
            }
            {
                // Non-mandatory property
                if (value.HasMember("Dash"))
                {
                    if (!value["Dash"].IsArray()) return false;
                    std::vector<Manifest> manifests;
                    for (rapidjson::SizeType i = 0; i < value["Dash"].Size(); i += 1)
                    {
                        Manifest manifest;
                        if (!value["Dash"][i].IsObject() || !manifest.InitFromJsonValue(value["Dash"][i])) return false;
                        manifests.push_back(manifest);
                    }
                    SetDash(manifests);
                }
            }
            {
                // Non-mandatory property
                if (value.HasMember("Hls"))
                {
                    if (!value["Hls"].IsArray()) return false;
                    std::vector<Manifest> manifests;
                    for (rapidjson::SizeType i = 0; i < value["Hls"].Size(); i += 1)
                    {
                        Manifest manifest;
                        if (!value["Hls"][i].IsObject() || !manifest.InitFromJsonValue(value["Hls"][i])) return false;
                        manifests.push_back(manifest);
                    }
                    SetHls(manifests);
                }
            }
            {
                // Non-mandatory property
                if (value.HasMember("Subtitles"))
                {
                    if (!value["Subtitles"].IsArray()) return false;
                    std::vector<PlaySubtitle> subtitles;
                    for (rapidjson::SizeType i = 0; i < value["Subtitles"].Size(); i += 1)
                    {
                        PlaySubtitle playSubtitle;
                        if (!value["Subtitles"][i].IsObject() || !playSubtitle.InitFromJsonValue(value["Subtitles"][i])) return false;
                        subtitles.push_back(playSubtitle);
                    }
                    SetSubtitles(subtitles);
                }
            }
            {
                // Non-mandatory property
                if (value.HasMember("Progressive"))
                {
                    if (!value["Progressive"].IsArray()) return false;
                    std::vector<File> progressives;
                    for (rapidjson::SizeType i = 0; i < value["Progressive"].Size(); i += 1)
                    {
                        File progressive;
                        if (!value["Progressive"][i].IsObject() || !progressive.InitFromJsonValue(value["Progressive"][i])) return false;
                        progressives.push_back(progressive);
                    }
                    SetProgressive(progressives);
                }
            }
            {
                // Non-mandatory property
                if (value.HasMember("Thumbnails"))
                {
                    Link thumbnails;
                    if (!value["Thumbnails"].IsObject() || !thumbnails.InitFromJsonValue(value["Thumbnails"])) return false;
                    SetThumbnails(thumbnails);
                }
            }

            return true;
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
