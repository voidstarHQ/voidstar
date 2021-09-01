#include <cmath>

#include "voidstar/size2str.h"

/// 991337 --> "991,337"
std::string size2str(size_t size) {
  const auto digits = std::ceil(std::log10(size));
  const auto nonits = static_cast<int>(std::ceil(digits / 3) -1);
  std::string str(static_cast<size_t>(digits)+nonits, '*');

  int written = 0;
  for (size_t pos = str.length()-1; pos!=0; pos--) {
    if (written != 0 && written % 3 == 0) {
      str[pos] = '_';
      written = 0;
      continue;
    }
    str[pos] = static_cast<char>('0' + size%10);
    size /= 10;
    written++;
  }
  if (size != 0)
    str[0] = static_cast<char>('0' + size);
  return str;
}
