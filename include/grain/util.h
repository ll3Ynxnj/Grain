#ifndef GRAIN_GRAINUTIL_H
#define GRAIN_GRAINUTIL_H

#include <string>
#include <vector>

namespace grautil
{
//-- Surrogate until clang supports std::format. --/////////////////////////////
  template<typename ... GRAUTLFormatArgs>
  static std::string format(const std::string &fmt, GRAUTLFormatArgs ... args)
  {
    size_t len = std::snprintf(nullptr, 0, fmt.c_str(), args ...);
    std::vector<char> buf(len + 1);
    std::snprintf(&buf[0], len + 1, fmt.c_str(), args ...);
    return std::string(&buf[0], &buf[0] + len);
  }
}

#endif //GRAIN_GRAINUTIL_H
