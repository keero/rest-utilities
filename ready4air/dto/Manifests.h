#ifndef READY4AIR_MANIFESTS_H
#define READY4AIR_MANIFESTS_H

#include "../common/Maybe.h"
#include "abstract/JsonDeserializable.h"
#include "Manifest.h"
#include "PlaySubtitle.h"
#include "File.h"
#include "hypermedia/Link.h"

namespace ready4air
{
    namespace dto
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

            const Maybe<std::vector<Manifest> > &GetSmooth() const
            {
                return mSmooth;
            }

            void SetSmooth(const std::vector<Manifest> &smooth)
            {
                mSmooth = smooth;
            }

            const Maybe<std::vector<Manifest> > &GetDash() const
            {
                return mDash;
            }

            void SetDash(const std::vector<Manifest> &dash)
            {
                mDash = dash;
            }

            const Maybe<std::vector<Manifest> > &GetHls() const
            {
                return mHls;
            }

            void SetHls(const std::vector<Manifest> &hls)
            {
                mHls = hls;
            }

            const Maybe<std::vector<PlaySubtitle> > &GetSubtitles() const
            {
                return mSubtitles;
            }

            void SetSubtitles(const std::vector<PlaySubtitle> &subtitles)
            {
                mSubtitles = subtitles;
            }

            const Maybe<std::vector<File> > &GetProgressive() const
            {
                return mProgressive;
            }

            void SetProgressive(const std::vector<File> &progressive)
            {
                mProgressive = progressive;
            }

            const Maybe<Link> &GetThumbnails() const
            {
                return mThumbnails;
            }

            void SetThumbnails(const Link &thumbnails)
            {
                mThumbnails = thumbnails;
            }

            virtual bool InitFromJsonValue(const rapidjson::Value &value, ParseErrors &parseErrors)
            {
                std::vector<Manifest> smooth;
                std::vector<Manifest> dash;
                std::vector<Manifest> hls;
                std::vector<PlaySubtitle> subtitles;
                std::vector<File> progressive;
                Link thumbnails;

                if (VerifyArray(value, "Smooth", false, parseErrors))
                {
                    for (rapidjson::SizeType i = 0; i < value["Smooth"].Size(); i += 1)
                    {
                        Manifest manifest;
                        if (ParseObject(value["Smooth"][i], "", false, manifest, parseErrors))
                            smooth.push_back(manifest);
                    }
                    SetSmooth(smooth);
                }

                if (VerifyArray(value, "Dash", false, parseErrors))
                {
                    for (rapidjson::SizeType i = 0; i < value["Dash"].Size(); i += 1)
                    {
                        Manifest manifest;
                        if (ParseObject(value["Dash"][i], "", false, manifest, parseErrors))
                            dash.push_back(manifest);
                    }
                    SetDash(dash);
                }

                if (VerifyArray(value, "Hls", false, parseErrors))
                {
                    for (rapidjson::SizeType i = 0; i < value["Hls"].Size(); i += 1)
                    {
                        Manifest manifest;
                        if (ParseObject(value["Hls"][i], "", false, manifest, parseErrors))
                            hls.push_back(manifest);
                    }
                    SetHls(hls);
                }

                if (VerifyArray(value, "Subtitles", false, parseErrors))
                {
                    for (rapidjson::SizeType i = 0; i < value["Subtitles"].Size(); i += 1)
                    {
                        PlaySubtitle playSubtitle;
                        if (ParseObject(value["Subtitles"][i], "", false, playSubtitle, parseErrors))
                            subtitles.push_back(playSubtitle);
                    }
                    SetSubtitles(subtitles);
                }

                if (VerifyArray(value, "Progressive", false, parseErrors))
                {
                    for (rapidjson::SizeType i = 0; i < value["Progressive"].Size(); i += 1)
                    {
                        File file;
                        if (ParseObject(value["Progressive"][i], "", false, file, parseErrors))
                            progressive.push_back(file);
                    }
                    SetProgressive(progressive);
                }

                if (ParseObject(value, "Thumbnails", false, thumbnails, parseErrors))
                    SetThumbnails(thumbnails);

                return !parseErrors;
            }

        private:
            Maybe<std::vector<Manifest> > mSmooth;
            Maybe<std::vector<Manifest> > mDash;
            Maybe<std::vector<Manifest> > mHls;
            Maybe<std::vector<PlaySubtitle> > mSubtitles;
            Maybe<std::vector<File> > mProgressive;
            Maybe<Link> mThumbnails;
        };
    }
}

#endif //READY4AIR_MANIFESTS_H
