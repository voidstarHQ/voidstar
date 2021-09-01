#include "voidstar/size2str.h"

/// 991337 --> "991,337"
std::string size2str(size_t size) {
  std::string str = std::to_string(size);
  auto pos = str.length() - 3;
  while (pos > 0) {
    str.insert(pos, ",");
    pos -= 3;
  }
  return str;
}
