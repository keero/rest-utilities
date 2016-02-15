#ifndef READY4AIR_SECTION_H
#define READY4AIR_SECTION_H

#include "../common/Maybe.h"
#include "abstract/JsonDeserializable.h"
#include "hypermedia/Link.h"
#include "MediaProduct.h"

namespace ready4air
{
    namespace dto
    {
        class Section : public JsonDeserializable
        {
        public:
            Section() : TAG("ready4air::dto::Section")
            {
            }

            virtual ~Section()
            {
            }

            const Maybe<STRING_T> &GetTitle() const
            {
                return mTitle;
            }

            void SetTitle(const STRING_T &title)
            {
                mTitle = title;
            }

            const Maybe<Link> &GetAll() const
            {
                return mAll;
            }

            void SetAll(const Link &all)
            {
                mAll = all;
            }

            const Maybe<VECTOR_T<MediaProduct> > &GetMedias() const
            {
                return mMedias;
            }

            void SetMedias(const VECTOR_T<MediaProduct> &medias)
            {
                mMedias = medias;
            }

            virtual BOOL_T InitFromJsonValue(const rapidjson::Value &value, ParseErrors &parseErrors,
                                             VECTOR_T<STRING_T> &context)
            {
                STRING_T title;
                Link all;
                VECTOR_T<MediaProduct> medias;

                context.push_back(TAG);

                if (ParseString(value, "Title", true, title, parseErrors, context))
                    SetTitle(title);

                if (ParseObject(value, "All", false, all, parseErrors, context))
                    SetAll(all);

                if (VerifyArray(value, "Medias", true, parseErrors, context))
                {
                    for (rapidjson::SizeType i = 0; i < value["Medias"].Size(); i += 1)
                    {
                        MediaProduct mediaProduct;
                        if (ParseObject(value["Medias"][i], "", false, mediaProduct, parseErrors, context))
                            medias.push_back(mediaProduct);
                    }
                    SetMedias(medias);
                }

                context.pop_back();
                return !parseErrors;
            }

        private:
            Maybe<STRING_T> mTitle;
            Maybe<Link> mAll;
            Maybe<VECTOR_T<MediaProduct> > mMedias;
            STRING_T TAG;
        };
    }
}

#endif //READY4AIR_SECTION_H
