#ifndef READY4AIR_PREDEFINE_H
#define READY4AIR_PREDEFINE_H

#ifndef UNUSED
#define UNUSED(arg)
#endif

#ifndef BOOL_T
#define BOOL_T bool
#endif

#ifndef INT64_T
#define INT64_T long
#endif

#ifndef INT32_T
#define INT32_T int
#endif

#ifndef INT16_T
#define INT16_T short
#endif

#ifndef INT8_T
#define INT8_T char
#endif

#ifndef UINT64_T
#define UINT64_T unsigned long
#endif

#ifndef UINT32_T
#define UINT32_T unsigned int
#endif

#ifndef UINT16_T
#define UINT16_T unsigned short
#endif

#ifndef UINT8_T
#define UINT8_T unsigned char
#endif

#ifndef FLOAT_T
#define FLOAT_T float
#endif

#ifndef DOUBLE_T
#define DOUBLE_T double
#endif

#ifndef STRING_T
#define STRING_T std::string
#endif

#ifndef VECTOR_T
#define VECTOR_T std::vector
#endif

#ifndef MAP_T
#define MAP_T std::map
#endif

#ifndef __LOG_GENERIC__
#define __LOG_GENERIC__(level, tag, message) std::cout << "[" << level << "] " tag << ": " << message << std::endl
#endif

#ifndef LOGD
#define LOGD(tag, message) __LOG_GENERIC__("DEBUG", tag, message)
#endif

#ifndef LOGI
#define LOGI(tag, message) __LOG_GENERIC__("INFO", tag, message)
#endif

#ifndef LOGW
#define LOGW(tag, message) __LOG_GENERIC__("WARN", tag, message)
#endif

#ifndef LOGE
#define LOGE(tag, message) __LOG_GENERIC__("ERROR", tag, message)
#endif

#ifndef LOGF
#define LOGF(tag, message) __LOG_GENERIC__("FATAL", tag, message)
#endif

#endif //READY4AIR_PREDEFINE_H
