#pragma once

// See also /variables.bzl

// clang-format off
#if defined(__clang__)

# if !defined(_FORTIFY_SOURCE)
#  define _FORTIFY_SOURCE 2
# endif

#elif defined(__GNUC__)

# if !defined(_FORTIFY_SOURCE)
#  define _FORTIFY_SOURCE 2
# endif

# if __GNUC__ >= 10
#  pragma GCC diagnostic error "-Warith-conversion"
# endif

# pragma GCC diagnostic error "-Wformat-overflow=2"
# pragma GCC diagnostic error "-Wformat-truncation=2"
# pragma GCC diagnostic error "-Wtrampolines"
# pragma GCC diagnostic error "-Warray-bounds=2"
# pragma GCC diagnostic error "-Wimplicit-fallthrough=3"
# pragma GCC diagnostic error "-Wshift-overflow=2"
# pragma GCC diagnostic error "-Wstringop-overflow=4"
# pragma GCC diagnostic error "-Wlogical-op"
# pragma GCC diagnostic error "-Wduplicated-cond"
# pragma GCC diagnostic error "-Wduplicated-branches"
# pragma GCC diagnostic error "-Wformat-signedness"
# pragma GCC diagnostic error "-Wstack-usage=1000000"
# pragma GCC diagnostic error "-Wcast-align=strict"

// TODO: "not an option that controls warnings"
// # pragma GCC diagnostic error "-fstack-clash-protection"
// # pragma GCC diagnostic error "-Wl,-z,relro"
// # pragma GCC diagnostic error "-Wl,-z,now"
// # pragma GCC diagnostic error "-Wl,-z,noexecstack"
// # pragma GCC diagnostic error "-Wl,-z,separate-code"

#elif defined(_MSC_VER)

# if !defined(_FORTIFY_SOURCE)
#  define _FORTIFY_SOURCE 2
# endif

#else

# if !defined(_FORTIFY_SOURCE)
#  define _FORTIFY_SOURCE 2
# endif

#endif
// clang-format on
