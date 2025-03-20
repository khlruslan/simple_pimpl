#pragma once

namespace draw {
template <typename T> void draw(std::ostream &os, const T &n, size_t position) {
  os << std::string(position, ' ') << n << '\n';
}
} // namespace draw
