#ifndef READY4AIR_IMAGE_H
#define READY4AIR_IMAGE_H

#include "../common/Maybe.h"
#include "FileBase.h"
#include "hypermedia/Link.h"

namespace ready4air
{
    namespace dto
    {
        class Image : public FileBase
        {
        public:
            Image() : TAG("ready4air::dto::Image")
            {
            }

            virtual ~Image()
            {
            }

            const Maybe<Link> &GetSecureLink() const
            {
                return mSecureLink;
            }

            void SetSecureLink(const Link &secureLink)
            {
                mSecureLink = secureLink;
            }

            virtual BOOL_T InitFromJsonValue(const rapidjson::Value &value, ParseErrors &parseErrors,
                                             VECTOR_T<STRING_T> &context)
            {
                Link secureLink;

                context.push_back(TAG);

                // Initialize parent properties
                FileBase::InitFromJsonValue(value, parseErrors, context);

                if (ParseObject(value, "SecureLink", false, secureLink, parseErrors, context))
                    SetSecureLink(secureLink);

                context.pop_back();
                return !parseErrors;
            }

        private:
            Maybe<Link> mSecureLink;
            STRING_T TAG;
        };
    }
}

#endif //READY4AIR_IMAGE_H
