#pragma once

#include <cstddef>
#include <cstdint>
#include <stdexcept>

typedef uint8_t u8;
typedef uint32_t u32;

#ifndef __unused
#define __unused __attribute__((unused))
#endif

#define NDEBUG
#include <cassert>
#define assertm(exp, msg) assert((msg __unused, exp))
