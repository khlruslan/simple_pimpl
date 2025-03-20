#include <iostream>
#include <string>

#include "document.h"
#include "simple_model.h"

namespace draw {
void draw(std::ostream &os, const my_impl::document &d, size_t position) {
  os << std::string(position, ' ') << "<document>\n";
  for (const auto &a : d) {
    a.draw(os, position + kOffset);
  }
  os << std::string(position, ' ') << "</document>\n";
}
} // namespace draw
