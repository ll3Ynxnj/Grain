#ifndef GRAIN_GRAINMACRO_H
#define GRAIN_GRAINMACRO_H

#include <cstdlib>
#include <stdio.h>
#include <stdarg.h>

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wunused-function"

namespace GRADebug
{
  static const char *kLogFormat = "[%s]%s/%s(%3d) : %s\n";
  static const int kLogBuffer = 1024;

  static void Print(const char *format, ...)
  {
    va_list args;
    va_start(args, format);
    vfprintf(stdout, format, args);
    va_end(args);
  }

  static void Trace(const char *file, const char *func, const int line,
                    const char *format, ...)
  {
#ifndef NDEBUG
    char log[kLogBuffer];
    snprintf(log, kLogBuffer, kLogFormat, "TRACE", file, func, line, format);
    va_list args;
    va_start(args, format);
    vfprintf(stderr, log, args);
    va_end(args);
#else
    (void)file; (void)func; (void)line; (void)format;
#endif
  }

  static void Debug(const char *format, ...)
  {
#ifndef NDEBUG
    va_list args;
    va_start(args, format);
    fprintf(stderr, "[DEBUG] ");
    vfprintf(stderr, format, args);
    va_end(args);
#else
    (void)format;
#endif
  }

  static void Info(const char *format, ...)
  {
    va_list args;
    va_start(args, format);
    fprintf(stdout, "[INFO] ");
    vfprintf(stdout, format, args);
    va_end(args);
  }

  static void Warning(const char *file, const char *func, const int line,
                      const char *format, ...)
  {
    char log[kLogBuffer];
    snprintf(log, kLogBuffer, kLogFormat, "WARNING", file, func, line, format);
    va_list args;
    va_start(args, format);
    vfprintf(stderr, log, args);
    va_end(args);
  }

  static void Error(const char *file, const char *func, const int line,
                    const char *format, ...)
  {
    char log[kLogBuffer];
    snprintf(log, kLogBuffer, kLogFormat, "ERROR", file, func, line, format);
    va_list args;
    va_start(args, format);
    vfprintf(stderr, log, args);
    va_end(args);
  }

  static void Abort()
  {
    exit(1);
  }
}

#define GRA_DELETE(aPtr)\
{\
    delete (aPtr); (aPtr) = 0;\
}\

#define GRA_DELETE_ARRAY(aPtr)\
{\
    delete[] (aPtr); (aPtr) = 0;\
}\

// Log level macros (ordered by severity: TRACE < DEBUG < INFO < WARNING < ERROR < FATAL)

#define GRA_PRINT(...)\
GRADebug::Print(__VA_ARGS__)

#ifndef NDEBUG
  #define GRA_TRACE(...)\
  GRADebug::Trace(__FILE__, __FUNCTION__, __LINE__, __VA_ARGS__)

  #define GRA_DEBUG(...)\
  GRADebug::Debug(__VA_ARGS__)
#else
  #define GRA_TRACE(...) ((void)0)
  #define GRA_DEBUG(...) ((void)0)
#endif

#define GRA_INFO(...)\
GRADebug::Info(__VA_ARGS__)

#define GRA_WARNING(...)\
GRADebug::Warning(__FILE__, __FUNCTION__, __LINE__, __VA_ARGS__)

#define GRA_ERROR(...)\
GRADebug::Error(__FILE__, __FUNCTION__, __LINE__, __VA_ARGS__)

#define GRA_FATAL(...)\
do {\
  GRADebug::Error(__FILE__, __FUNCTION__, __LINE__, __VA_ARGS__);\
  GRADebug::Abort();\
} while(0)

#define GRA_ASSERT(condition, ...)\
do {\
  if (!(condition)) {\
    GRADebug::Error(__FILE__, __FUNCTION__, __LINE__, __VA_ARGS__);\
    GRADebug::Abort();\
  }\
} while(0)

#ifdef NDEBUG
  // Release build: Compiler optimization hint
  #if defined(__GNUC__) || defined(__clang__)
    #define GRA_UNREACHABLE(...) __builtin_unreachable()
  #elif defined(_MSC_VER)
    #define GRA_UNREACHABLE(...) __assume(0)
  #else
    #define GRA_UNREACHABLE(...) GRA_FATAL(__VA_ARGS__)
  #endif
#else
  // Debug build: Error output and abort
  #define GRA_UNREACHABLE(...) GRA_FATAL(__VA_ARGS__)
#endif

#define GRA_DISALLOW_COPY_AND_ASSIGN(aTypeName)\
aTypeName(const aTypeName&);\
void operator=(const aTypeName&)\

#pragma clang diagnostic pop

#endif // GRAIN_GRAINMACRO_H