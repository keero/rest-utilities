#ifndef READY4AIR_MOVIE_H
#define READY4AIR_MOVIE_H

#include "MediaProduct.h"

namespace ready4air
{
    namespace dto
    {
        class Movie : public MediaProduct
        {
        public:
            Movie() : TAG("ready4air::dto::Movie")
            {
                mProductType = MovieProductType;
            }

            virtual ~Movie()
            {
            }

        private:
            const STRING_T TAG;
        };
    }
}

#endif //READY4AIR_MOVIE_H
