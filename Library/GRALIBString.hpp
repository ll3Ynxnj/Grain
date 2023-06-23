// Copyright (c) 2023. CLAYWORK Inc. All rights reserved.

//
// Created by Kentaro Kawai on 2023/06/22.
//

#ifndef ANHR_GRALIBSTRING_HPP
#define ANHR_GRALIBSTRING_HPP

#include <string>
#include <sstream>
#include <vector>

#include "Grain/Primitive/GRAPRMType.hpp"

// GRAStringがstd::stringのラッパークラスとなった場合、ここで示されている静的メソッドは、
// GRAStringの定義に含めることとする。

// If GRAString is a wrapper class of std::string, the static methods shown here
// are included in the definition of GRAString.

class GRALIBString
{
  static std::vector <std::string> Split(std::string aString, char aDelimiter)
  {
    std::vector <std::string> result;
    std::istringstream ss(aString);
    std::string token;

    while (std::getline(ss, token, aDelimiter))
    {
      result.push_back(token);
    }

    return result;
  };
};

#endif //ANHR_GRALIBSTRING_HPP
