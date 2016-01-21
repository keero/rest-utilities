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

            virtual bool InitFromJsonValue(const rapidjson::Value &value, ParseErrors &parseErrors)
            {
                std::string title;
                Link all;
                std::vector<MediaProduct> medias;

                if (ParseString(value, "Title", true, title, parseErrors))
                    SetTitle(title);

                if (ParseObject(value, "All", false, all, parseErrors))
                    SetAll(all);

                if (VerifyArray(value, "Medias", true, parseErrors))
                {
                    for (rapidjson::SizeType i = 0; i < value["Medias"].Size(); i += 1)
                    {
                        MediaProduct mediaProduct;
                        if (ParseObject(value["Medias"][i], "", false, mediaProduct, parseErrors))
                            medias.push_back(mediaProduct);
                    }
                    SetMedias(medias);
                }

                return !parseErrors;
            }

        private:
            Maybe <std::string> mTitle;
            Maybe <Link> mAll;
            Maybe <std::vector<MediaProduct> > mMedias;
        };
    }
}

#endif //READY4AIR_SECTION_H
