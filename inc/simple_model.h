#pragma once
#include <iostream>
#include <memory>
#include <string>
#include <vector>

#include "document.h"
#include "draw.h"
#include "my_class.h"

namespace my_impl {

class model {
public:
  void draw(std::ostream &os, size_t position) const {
    data_->draw(os, position);
  }

  template <typename T>
  model(T t) : data_(std::make_unique<impl<T>>(std::move(t))) {
#ifdef my_debug
    std::cerr << "ctor\n";
#endif
  }

  model(const model &t) : data_(t.data_->copy()) {
#ifdef my_debug
    std::cerr << "copy\n";
#endif
  };

  model(model &&t) noexcept = default;

  model &operator=(const model &t) {
    model temp(t);
    swap(temp);
    return *this;
  }

  model &operator=(model &&t) noexcept = default;

private:
  void swap(model &t) { std::swap(data_, t.data_); }

  struct concept_t {
    virtual ~concept_t() = default;
    virtual void draw(std::ostream &, size_t) const = 0;
    // virtual concept_t* copy() const = 0;
    virtual std::unique_ptr<concept_t> copy() const = 0;
  };

  template <typename T> struct impl : concept_t {
    T data_;
    impl(T t) : data_(std::move(t)) {}
    void draw(std::ostream &os, size_t position) const override {
      draw::draw(os, data_, position);
    }
    // concept_t* copy() const override{
    std::unique_ptr<concept_t> copy() const override {
      return std::make_unique<impl>(*this);
    }
  };
  std::unique_ptr<concept_t> data_;
};

} // namespace my_impl
