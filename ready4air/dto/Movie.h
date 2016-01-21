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
            Movie()
            {
                mProductType = MovieProductType;
            }

            virtual ~Movie()
            {
            }
        };
    }
}

#endif //READY4AIR_MOVIE_H
