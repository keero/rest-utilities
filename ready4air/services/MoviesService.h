#ifndef READY4AIR_SERVICES_MOVIESSERVICE_H
#define READY4AIR_SERVICES_MOVIESSERVICE_H

#include "MediasService.h"

namespace ready4air
{
    namespace services
    {
        template <typename HTTP_CLIENT_TYPE, typename EVENT_TYPE>
        class MoviesService : public MediasService <HTTP_CLIENT_TYPE, EVENT_TYPE>
        {
        };
    }
}

#endif //READY4AIR_SERVICES_MOVIESSERVICE_H
