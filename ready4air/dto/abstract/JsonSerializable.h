#ifndef READY4AIR_JSONSERIALIZABLE_H
#define READY4AIR_JSONSERIALIZABLE_H

#include "../../common/Predefine.h"
#include <rapidjson/writer.h>
#include <string>
#include <vector>

namespace ready4air
{
    namespace dto
    {
        class IJsonSerializable
        {
        public:
            virtual const STRING_T ToJsonString(void) const = 0;
        };
    }
}
#endif //READY4AIR_JSONSERIALIZABLE_H
