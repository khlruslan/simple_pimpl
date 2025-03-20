#include <algorithm>
#include <iostream>

#include "simple_model.h"

#include "document.h"
#include "my_class.h"

int main() {
  my_impl::document d;
  d.reserve(100);
  d.push_back(1);
  d.push_back(my_class());
  d.push_back(2);
  d.push_back(std::string("Hello, world!"));
  d.push_back(d);
  d.push_back(std::string("Last push_back"));
  std::cout << std::string(10, '=') << "Document" << std::string(10, '=')
            << '\n';

  draw::draw(std::cout, d, 0);

  std::cout << std::string(28, '=') << '\n';

  std::cout << std::string(5, '=') << "Reversed document" << std::string(6, '=')
            << '\n';
  std::reverse(d.begin(), d.end());
  draw::draw(std::cout, d, 0);

  std::cout << std::string(28, '=') << '\n';
}
