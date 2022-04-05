#ifndef GRAIN_GRAINMACRO_H
#define GRAIN_GRAINMACRO_H

#include <cstdlib>
#include <stdio.h>
#include <stdarg.h>

namespace GRADebug
{
  static const char *kLogFormat = "[%s]%s/%s(%3d) : %s\n";
  static const int kLogBuffer = 1024;

  static void Print(const char *format, ...)
  {
    va_list args;
    va_start(args, format);
    vfprintf(stderr, format, args);
    va_end(args);
  }

  static void Trace(const char *file, const char *func, const int line,
                    const char *format, ...)
  {
    char log[kLogBuffer];
    snprintf(log, kLogBuffer, kLogFormat, "TRACE", file, func, line, format);
    va_list args;
    va_start(args, format);
    vfprintf(stderr, log, args);
    va_end(args);
  }

  static void Assert(const char *file, const char *func, const int line,
                     const char *format, ...)
  {
    char log[kLogBuffer];
    snprintf(log, kLogBuffer, kLogFormat, "ASSERT", file, func, line, format);
    va_list args;
    va_start(args, format);
    vfprintf(stderr, log, args);
    va_end(args);
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

#define GRA_PRINT(...)\
GRADebug::Print(__VA_ARGS__)\

#define GRA_TRACE(...)\
GRADebug::Trace(__FILE__, __FUNCTION__, __LINE__, __VA_ARGS__)

#define GRA_ASSERT(...)\
GRADebug::Assert(__FILE__, __FUNCTION__, __LINE__, __VA_ARGS__)\

#define GRA_DISALLOW_COPY_AND_ASSIGN(aTypeName)\
aTypeName(const aTypeName&);\
void operator=(const aTypeName&)\

#endif // GRAIN_GRAINMACRO_H
