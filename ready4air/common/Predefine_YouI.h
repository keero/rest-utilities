#ifndef READY4AIR_PREDEFINEYOUI_H
#define READY4AIR_PREDEFINEYOUI_H

#ifndef UNUSED
#define UNUSED(arg) YI_UNUSED(arg)
#endif

#ifndef BOOL_T
#define BOOL_T YI_BOOL
#endif

#ifndef INT64_T
#define INT64_T YI_INT64
#endif

#ifndef INT32_T
#define INT32_T YI_INT32
#endif

#ifndef INT16_T
#define INT16_T YI_INT16
#endif

#ifndef INT8_T
#define INT8_T YI_INT8
#endif

#ifndef UINT64_T
#define UINT64_T YI_UINT64
#endif

#ifndef UINT32_T
#define UINT32_T YI_UINT32
#endif

#ifndef UINT16_T
#define UINT16_T YI_UINT16
#endif

#ifndef UINT8_T
#define UINT8_T YI_UINT8
#endif

#ifndef FLOAT_T
#define FLOAT_T YI_FLOAT
#endif

#ifndef DOUBLE_T
#define DOUBLE_T YI_DOUBLE
#endif

#ifndef STRING_T
#define STRING_T CYIString
#endif

#ifndef VECTOR_T
#define VECTOR_T std::vector
#endif

#ifndef MAP_T
#define MAP_T std::map
#endif

#ifndef LOGD
#define LOGD(tag, message) YI_LOGD(tag, message)
#endif

#ifndef LOGI
#define LOGI(tag, message) YI_LOGI(tag, message)
#endif

#ifndef LOGW
#define LOGW(tag, message) YI_LOGW(tag, message)
#endif

#ifndef LOGE
#define LOGE(tag, message) YI_LOGE(tag, message)
#endif

#ifndef LOGF
#define LOGF(tag, message) YI_LOGF(tag, message)
#endif

#endif //READY4AIR_PREDEFINEYOUI_H
