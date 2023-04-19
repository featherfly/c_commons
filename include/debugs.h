#ifndef __FF__DEBUGS_H
#define __FF__DEBUGS_H

#ifdef ENABLE_DEBUG
#define D(_code) _code
#else
#define D(_code)
#endif

// #define ENABLE_LOG_TAG 0

// #define LOG_LEVEL_ERROR 0
// #define LOG_LEVEL_WARNING 0
//  #define LOG_LEVEL_INFO 0
// #define LOG_LEVEL_TRACE 0

#ifdef ENABLE_DEBUG

#define _LOG_TAG ""

#if defined(LOG_LEVEL_ERROR)

// #warning "def error log"
#ifdef ENABLE_LOG_TAG
#undef LOG_TAG
#define _LOG_TAG "E:"
#endif
#define E(format, ...) printf(_LOG_TAG format, ##__VA_ARGS__)
// #warning "def warning log"
#ifdef ENABLE_LOG_TAG
#undef LOG_TAG
#define _LOG_TAG "W:"
#endif
#define W(format, ...) printf(_LOG_TAG format, ##__VA_ARGS__)
// #warning "def info log"
#ifdef ENABLE_LOG_TAG
#undef LOG_TAG
#define _LOG_TAG "I:"
#endif
#define I(format, ...) printf(_LOG_TAG format, ##__VA_ARGS__)
// #warning "def trace log"
#ifdef ENABLE_LOG_TAG
#undef LOG_TAG
#define _LOG_TAG "T:"
#endif
#define T(format, ...) printf(_LOG_TAG format, ##__VA_ARGS__)

#elif defined(LOG_LEVEL_WARNING)
// #warning "def warning log"
#ifdef ENABLE_LOG_TAG
#undef LOG_TAG
#define _LOG_TAG "W:"
#endif
#define W(format, ...) printf(_LOG_TAG format, ##__VA_ARGS__)
// #warning "def info log"
#ifdef ENABLE_LOG_TAG
#undef LOG_TAG
#define _LOG_TAG "I:"
#endif
#define I(format, ...) printf(_LOG_TAG format, ##__VA_ARGS__)
// #warning "def trace log"
#ifdef ENABLE_LOG_TAG
#undef LOG_TAG
#define _LOG_TAG "T:"
#endif
#define T(format, ...) printf(_LOG_TAG format, ##__VA_ARGS__)

#elif defined(LOG_LEVEL_INFO)
// #warning "def info log"
#ifdef ENABLE_LOG_TAG
#undef LOG_TAG
#define _LOG_TAG "I:"
#endif
#define I(format, ...) printf(_LOG_TAG format, ##__VA_ARGS__)
// #warning "def trace log"
#ifdef ENABLE_LOG_TAG
#undef LOG_TAG
#define _LOG_TAG "T:"
#endif
#define T(format, ...) printf(_LOG_TAG format, ##__VA_ARGS__)

#elif defined(LOG_LEVEL_TRACE)
// #warning "def trace log"
#ifdef ENABLE_LOG_TAG
#undef LOG_TAG
#define _LOG_TAG "T:"
#endif
#define T(format, ...) printf(_LOG_TAG format, ##__VA_ARGS__)

#endif

#else

#endif

// def not work

#ifndef T

#define T(format, ...)

#endif

#ifndef I

#define I(format, ...)

#endif

#ifndef W

#define W(format, ...)

#endif

#ifndef E

#define E(format, ...)

#endif

#endif