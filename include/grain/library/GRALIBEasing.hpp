// Copyright (c) 2023. CLAYWORK Inc. All rights reserved.

//
// Created by Kentaro Kawai on 2023/07/25.
//

#ifndef ANHR_GRALIBEASING_HPP
#define ANHR_GRALIBEASING_HPP

#include <math.h>
#include "grain/macro.h"
#include "grain/primitive/GRAPRMType.hpp"

class GRALIBEasing
{
public:
  enum class Type
  {
    Linear,

    EaseInSine,
    EaseOutSine,
    EaseInOutSine,

    EaseInQuad,
    EaseOutQuad,
    EaseInOutQuad,

    EaseInCubic,
    EaseOutCubic,
    EaseInOutCubic,

    EaseInQuart,
    EaseOutQuart,
    EaseInOutQuart,

    EaseInQuint,
    EaseOutQuint,
    EaseInOutQuint,

    EaseInExpo,
    EaseOutExpo,
    EaseInOutExpo,

    EaseInCirc,
    EaseOutCirc,
    EaseInOutCirc,

    EaseInBack,
    EaseOutBack,
    EaseInOutBack,

    EaseInElastic,
    EaseOutElastic,
    EaseInOutElastic,

    EaseInBounce,
    EaseOutBounce,
    EaseInOutBounce,

    StepIn,
    StepOut,
    StepInOut,

    kNumberOfItems,

    NONE,
  };

  static GRAFloat EaseInSine(GRAFloat t) {
    return 1 - cos((t * M_PI) / 2);
  }

  static GRAFloat EaseOutSine(GRAFloat t) {
    return sin((t * M_PI) / 2);
  }

  static GRAFloat EaseInOutSine(GRAFloat t) {
    return -(cos(M_PI * t) - 1) / 2;
  }

  static GRAFloat EaseInQuad(GRAFloat t) {
    return t * t;
  }

  static GRAFloat EaseOutQuad(GRAFloat t) {
    return 1 - (1 - t) * (1 - t);
  }

  static GRAFloat EaseInOutQuad(GRAFloat t) {
    return t < 0.5 ? 2 * t * t : 1 - pow(-2 * t + 2, 2) / 2;
  }

  static GRAFloat EaseInCubic(GRAFloat t) {
    return t * t * t;
  }

  static GRAFloat EaseOutCubic(GRAFloat t) {
    return 1 - pow(1 - t, 3);
  }

  static GRAFloat EaseInOutCubic(GRAFloat t) {
    return t < 0.5 ? 4 * t * t * t : 1 - pow(-2 * t + 2, 3) / 2;
  }

  static GRAFloat EaseInQuart(GRAFloat t) {
    return t * t * t * t;
  }

  static GRAFloat EaseOutQuart(GRAFloat t) {
    return 1 - pow(1 - t, 4);
  }

  static GRAFloat EaseInOutQuart(GRAFloat t) {
    return t < 0.5 ? 8 * t * t * t * t : 1 - pow(-2 * t + 2, 4) / 2;
  }

  static GRAFloat EaseInQuint(GRAFloat t) {
    return t * t * t * t * t;
  }

  static GRAFloat EaseOutQuint(GRAFloat t) {
    return 1 - pow(1 - t, 5);
  }

  static GRAFloat EaseInOutQuint(GRAFloat t) {
    return t < 0.5 ? 16 * t * t * t * t * t : 1 - pow(-2 * t + 2, 5) / 2;
  }

  static GRAFloat EaseInExpo(GRAFloat t) {
    return t == 0 ? 0 : pow(2, 10 * t - 10);
  }

  static GRAFloat EaseOutExpo(GRAFloat t) {
    return t == 1 ? 1 : 1 - pow(2, -10 * t);
  }

  static GRAFloat EaseInOutExpo(GRAFloat t) {
    return t == 0
           ? 0
           : t == 1
             ? 1
             : t < 0.5 ? pow(2, 20 * t - 10) / 2
                       : (2 - pow(2, -20 * t + 10)) / 2;
  }

  static GRAFloat EaseInCirc(GRAFloat t) {
    return 1 - sqrt(1 - pow(t, 2));
  }

  static GRAFloat EaseOutCirc(GRAFloat t) {
    return sqrt(1 - pow(t - 1, 2));
  }

  static GRAFloat EaseInOutCirc(GRAFloat t) {
    return t < 0.5
           ? (1 - sqrt(1 - pow(2 * t, 2))) / 2
           : (sqrt(1 - pow(-2 * t + 2, 2)) + 1) / 2;
  }

  static GRAFloat EaseInBack(GRAFloat t) {
    return 2.70158 * t * t * t - 1.70158 * t * t;
  }

  static GRAFloat EaseOutBack(GRAFloat t) {
    return 1 + 2.70158 * pow(t - 1, 3) + 1.70158 * pow(t - 1, 2);
  }

  static GRAFloat EaseInOutBack(GRAFloat t) {
    return t < 0.5
           ? (pow(2 * t, 2) * ((2.59491 + 1) * 2 * t - 2.59491)) / 2
           : (pow(2 * t - 2, 2) * ((2.59491 + 1) * (t * 2 - 2) + 2.59491) + 2) / 2;
  }

  static GRAFloat EaseInElastic(GRAFloat t) {
    return t == 0
           ? 0
           : t == 1
             ? 1
             : -pow(2, 10 * t - 10) * sin((t * 10 - 10.75) * (2 * M_PI) / 3);
  }

  static GRAFloat EaseOutElastic(GRAFloat t) {
    return t == 0
           ? 0
           : t == 1
             ? 1
             : pow(2, -10 * t) * sin((t * 10 - 0.75) * (2 * M_PI) / 3) + 1;
  }

  static GRAFloat EaseInOutElastic(GRAFloat t) {
    return t == 0
           ? 0
           : t == 1
             ? 1
             : t < 0.5
               ? -(pow(2, 20 * t - 10) * sin((20 * t - 11.125) * (2 * M_PI) / 4.5)) / 2
               : (pow(2, -20 * t + 10) * sin((20 * t - 11.125) * (2 * M_PI) / 4.5)) / 2 + 1;
  }

  static GRAFloat EaseOutBounce(GRAFloat t) {
    return t < 1 / 2.75
           ? 7.5625 * t * t
           : t < 2 / 2.75
             ? 7.5625 * (t -= 1.5 / 2.75) * t + 0.75
             : t < 2.5 / 2.75
               ? 7.5625 * (t -= 2.25 / 2.75) * t + 0.9375
               : 7.5625 * (t -= 2.625 / 2.75) * t + 0.984375;
  }

  static GRAFloat EaseInBounce(GRAFloat t) {
    return 1 - EaseOutBounce(1 - t);
  }

  static GRAFloat EaseInOutBounce(GRAFloat t) {
    return t < 0.5
           ? (1 - EaseOutBounce(1 - 2 * t)) / 2
           : (1 + EaseOutBounce(2 * t - 1)) / 2;
  }

  static GRAFloat StepIn(GRAFloat t) {
    return t == 0 ? 0 : 1;
  }

  static GRAFloat StepOut(GRAFloat t) {
    return t == 1 ? 0 : 1;
  }

  static GRAFloat StepInOut(GRAFloat t) {
    return t < 0.5 ? 0 : 1;
  }

  static GRAFloat GetEasing(Type type, GRAFloat t) {
    switch (type) {
      case Type::Linear:           return t;
      case Type::EaseInSine:       return EaseInSine(t);
      case Type::EaseOutSine:      return EaseOutSine(t);
      case Type::EaseInOutSine:    return EaseInOutSine(t);
      case Type::EaseInQuad:       return EaseInQuad(t);
      case Type::EaseOutQuad:      return EaseOutQuad(t);
      case Type::EaseInOutQuad:    return EaseInOutQuad(t);
      case Type::EaseInCubic:      return EaseInCubic(t);
      case Type::EaseOutCubic:     return EaseOutCubic(t);
      case Type::EaseInOutCubic:   return EaseInOutCubic(t);
      case Type::EaseInQuart:      return EaseInQuart(t);
      case Type::EaseOutQuart:     return EaseOutQuart(t);
      case Type::EaseInOutQuart:   return EaseInOutQuart(t);
      case Type::EaseInQuint:      return EaseInQuint(t);
      case Type::EaseOutQuint:     return EaseOutQuint(t);
      case Type::EaseInOutQuint:   return EaseInOutQuint(t);
      case Type::EaseInExpo:       return EaseInExpo(t);
      case Type::EaseOutExpo:      return EaseOutExpo(t);
      case Type::EaseInOutExpo:    return EaseInOutExpo(t);
      case Type::EaseInCirc:       return EaseInCirc(t);
      case Type::EaseOutCirc:      return EaseOutCirc(t);
      case Type::EaseInOutCirc:    return EaseInOutCirc(t);
      case Type::EaseInBack:       return EaseInBack(t);
      case Type::EaseOutBack:      return EaseOutBack(t);
      case Type::EaseInOutBack:    return EaseInOutBack(t);
      case Type::EaseInElastic:    return EaseInElastic(t);
      case Type::EaseOutElastic:   return EaseOutElastic(t);
      case Type::EaseInOutElastic: return EaseInOutElastic(t);
      case Type::EaseInBounce:     return EaseInBounce(t);
      case Type::EaseOutBounce:    return EaseOutBounce(t);
      case Type::EaseInOutBounce:  return EaseInOutBounce(t);
      case Type::StepIn:           return StepIn(t);
      case Type::StepOut:          return StepOut(t);
      case Type::StepInOut:        return StepInOut(t);
      default:
        GRA_ASSERT("Unknown easing type");
    }
  }
};

#endif //ANHR_GRALIBEASING_HPP
