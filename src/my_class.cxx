#include <iostream>
#include <string>

#include "my_class.h"

namespace draw {
void draw(std::ostream &os, const my_class &, size_t position) {
  os << std::string(position, ' ') << "my_class" << '\n';
}
} // namespace draw
