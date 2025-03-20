#pragma once
#include <vector>

namespace my_impl {
class model;
using document = std::vector<model>;
} // namespace my_impl

namespace draw {
const size_t kOffset = 2;
void draw(std::ostream &os, const my_impl::document &d, size_t position);
} // namespace draw
