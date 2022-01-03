#include <algorithm>

#include "voidstar/size2str.h"

#include "fmt/format.h"

/// 991337 --> "991,337"
std::string size2str(size_t size, const std::string& format) {
  std::string str = fmt::format(format, fmt::group_digits(size));
  std::replace_if(
      std::begin(str), std::end(str),
      [](std::string::value_type v) { return v == ','; }, '_');
  return str;
}
