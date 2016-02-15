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
            Manifests() : TAG("ready4air::dto::Manifests")
            {
            }

            virtual ~Manifests()
            {
            }

            const Maybe<VECTOR_T<Manifest> > &GetSmooth() const
            {
                return mSmooth;
            }

            void SetSmooth(const VECTOR_T<Manifest> &smooth)
            {
                mSmooth = smooth;
            }

            const Maybe<VECTOR_T<Manifest> > &GetDash() const
            {
                return mDash;
            }

            void SetDash(const VECTOR_T<Manifest> &dash)
            {
                mDash = dash;
            }

            const Maybe<VECTOR_T<Manifest> > &GetHls() const
            {
                return mHls;
            }

            void SetHls(const VECTOR_T<Manifest> &hls)
            {
                mHls = hls;
            }

            const Maybe<VECTOR_T<PlaySubtitle> > &GetSubtitles() const
            {
                return mSubtitles;
            }

            void SetSubtitles(const VECTOR_T<PlaySubtitle> &subtitles)
            {
                mSubtitles = subtitles;
            }

            const Maybe<VECTOR_T<File> > &GetProgressive() const
            {
                return mProgressive;
            }

            void SetProgressive(const VECTOR_T<File> &progressive)
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

            virtual BOOL_T InitFromJsonValue(const rapidjson::Value &value, ParseErrors &parseErrors,
                                             VECTOR_T<STRING_T> &context)
            {
                VECTOR_T<Manifest> smooth;
                VECTOR_T<Manifest> dash;
                VECTOR_T<Manifest> hls;
                VECTOR_T<PlaySubtitle> subtitles;
                VECTOR_T<File> progressive;
                Link thumbnails;

                context.push_back(TAG);

                if (VerifyArray(value, "Smooth", false, parseErrors, context))
                {
                    for (rapidjson::SizeType i = 0; i < value["Smooth"].Size(); i += 1)
                    {
                        Manifest manifest;
                        if (ParseObject(value["Smooth"][i], "", false, manifest, parseErrors, context))
                            smooth.push_back(manifest);
                    }
                    SetSmooth(smooth);
                }

                if (VerifyArray(value, "Dash", false, parseErrors, context))
                {
                    for (rapidjson::SizeType i = 0; i < value["Dash"].Size(); i += 1)
                    {
                        Manifest manifest;
                        if (ParseObject(value["Dash"][i], "", false, manifest, parseErrors, context))
                            dash.push_back(manifest);
                    }
                    SetDash(dash);
                }

                if (VerifyArray(value, "Hls", false, parseErrors, context))
                {
                    for (rapidjson::SizeType i = 0; i < value["Hls"].Size(); i += 1)
                    {
                        Manifest manifest;
                        if (ParseObject(value["Hls"][i], "", false, manifest, parseErrors, context))
                            hls.push_back(manifest);
                    }
                    SetHls(hls);
                }

                if (VerifyArray(value, "Subtitles", false, parseErrors, context))
                {
                    for (rapidjson::SizeType i = 0; i < value["Subtitles"].Size(); i += 1)
                    {
                        PlaySubtitle playSubtitle;
                        if (ParseObject(value["Subtitles"][i], "", false, playSubtitle, parseErrors, context))
                            subtitles.push_back(playSubtitle);
                    }
                    SetSubtitles(subtitles);
                }

                if (VerifyArray(value, "Progressive", false, parseErrors, context))
                {
                    for (rapidjson::SizeType i = 0; i < value["Progressive"].Size(); i += 1)
                    {
                        File file;
                        if (ParseObject(value["Progressive"][i], "", false, file, parseErrors, context))
                            progressive.push_back(file);
                    }
                    SetProgressive(progressive);
                }

                if (ParseObject(value, "Thumbnails", false, thumbnails, parseErrors, context))
                    SetThumbnails(thumbnails);

                context.pop_back();
                return !parseErrors;
            }

        private:
            Maybe<VECTOR_T<Manifest> > mSmooth;
            Maybe<VECTOR_T<Manifest> > mDash;
            Maybe<VECTOR_T<Manifest> > mHls;
            Maybe<VECTOR_T<PlaySubtitle> > mSubtitles;
            Maybe<VECTOR_T<File> > mProgressive;
            Maybe<Link> mThumbnails;
            STRING_T TAG;
        };
    }
}

#endif //READY4AIR_MANIFESTS_H
