#pragma once

#include <cstddef>
#include <cstdint>
#include <stdexcept>

#include "voidstar/flags.h"

typedef uint8_t u8;
typedef uint32_t u32;

#define UNUSED(var) /*empty*/

#define NDEBUG
#include <cassert>
#define assertm(exp, msg) assert((UNUSED(msg), exp))
