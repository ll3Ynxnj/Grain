#ifndef GRAIN_PLATYPE_HPP
#define GRAIN_PLATYPE_HPP

#include <cstdint>

//-- Boolean value --///////////////////////////////////////////////////////////
using GRABool = bool;

//-- Signed integer value --////////////////////////////////////////////////////
using GRAByte = int_fast8_t;
static const GRAByte kGRAByteMin = INT_FAST8_MIN;
static const GRAByte kGRAByteMax = INT_FAST8_MAX;
static const GRAByte kGRAByteUndefined = kGRAByteMin;

using GRAInt = int_fast64_t;
static const GRAInt kGRAIntMin = INT_FAST64_MIN;
static const GRAInt kGRAIntMax = INT_FAST64_MAX;
static const GRAInt kGRAIntUndefined = kGRAIntMin;

using GRAInt8 = int_least8_t;
static const GRAInt8 kGRAInt8Min = INT_LEAST8_MIN;
static const GRAInt8 kGRAInt8Max = INT_LEAST8_MAX;
static const GRAInt8 kGRAInt8Undefined = kGRAInt8Min;

using GRAInt16 = int_least16_t;
static const GRAInt16 kGRAInt16Min = INT_LEAST16_MIN;
static const GRAInt16 kGRAInt16Max = INT_LEAST16_MAX;
static const GRAInt16 kGRAInt16Undefined = kGRAInt16Min;

using GRAInt32 = int_least32_t;
static const GRAInt32 kGRAInt32Min = INT_LEAST32_MIN;
static const GRAInt32 kGRAInt32Max = INT_LEAST32_MAX;
static const GRAInt32 kGRAInt32Undefined = kGRAInt32Min;

using GRAInt64 = int_least64_t;
static const GRAInt64 kGRAInt64Min = INT_LEAST64_MIN;
static const GRAInt64 kGRAInt64Max = INT_LEAST64_MAX;
static const GRAInt64 kGRAInt64Undefined = kGRAInt64Min;

//-- Unsigned integer value --//////////////////////////////////////////////////
using GRAUByte = uint_fast8_t;
static const GRAUByte kGRAUByteMax = UINT_FAST8_MAX;
static const GRAUByte kGRAUByteUndefined = kGRAUByteMax;

using GRAUInt = uint_fast64_t;
static const GRAUInt kGRAUIntMax = UINT_FAST64_MAX;
static const GRAUInt kGRAUIntUndefined = kGRAUIntMax;

using GRAUInt8 = uint_least8_t;
static const GRAUInt8 kGRAUInt8Max = UINT_LEAST8_MAX;
static const GRAUInt8 kGRAUInt8Undefined = kGRAUInt8Max;

using GRAUInt16 = uint_least16_t;
static const GRAUInt16 kGRAUInt16Max = UINT_LEAST16_MAX;
static const GRAUInt16 kGRAUInt16Undefined = kGRAUInt16Max;

using GRAUInt32 = uint_least32_t;
static const GRAUInt32 kGRAUInt32Max = UINT_LEAST32_MAX;
static const GRAUInt32 kGRAUInt32Undefined = kGRAUInt32Max;

using GRAUInt64 = uint_least64_t;
static const GRAUInt64 kGRAUInt64Max = UINT_LEAST64_MAX;
static const GRAUInt64 kGRAUInt64Undefined = kGRAUInt64Max;

//-- Floating point value --////////////////////////////////////////////////////
using GRAFloat = float_t;
static const GRAFloat kGRAFloatMax = MAXFLOAT;
static const GRAFloat kGRAFloatUndefined = kGRAFloatMax;

using GRADouble = double_t;
static const GRADouble kGRADoubleMax = MAXFLOAT;
static const GRADouble kGRADoubleUndefined = kGRADoubleMax;

//-- Size value --//////////////////////////////////////////////////////////////
using GRASize = size_t;
static const GRASize kGRASizeMax = SIZE_MAX;
static const GRASize kGRASizeUndefined = kGRASizeMax;

//-- Character Value --/////////////////////////////////////////////////////////
using GRAChar = GRAUByte;
static const GRAChar kGRACharMax = kGRAUByteMax;
static const GRAChar kGRACharUndefined = kGRACharMax;

//-- StringValue --/////////////////////////////////////////////////////////////
using GRAString = std::string;
static const char *kGRAStrUndefined  = " == UNDEFINED == ";

//-- ArrayValue --//////////////////////////////////////////////////////////////
//-- ListValue --///////////////////////////////////////////////////////////////
//-- MapValue --////////////////////////////////////////////////////////////////
//-- StackValue --//////////////////////////////////////////////////////////////
//-- QueueValue --//////////////////////////////////////////////////////////////

//-- OtherValue --//////////////////////////////////////////////////////////////
using GRATimeInterval = GRADouble;
static const GRATimeInterval kGRATimeIntervalMax = kGRADoubleMax;
static const GRATimeInterval kGRATimeIntervalUndefined = kGRATimeIntervalMax;

//-- Identifier --//////////////////////////////////////////////////////////////
using GRAId = GRASize;
static const GRAId kGRAIdMax = kGRASizeMax;
static const GRAId kGRAIdUndefined = kGRAIdMax;

#endif //GRAIN_PLATYPE_HPP
