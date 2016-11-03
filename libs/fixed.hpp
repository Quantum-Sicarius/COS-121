#ifndef FIXED_H
#define FIXED_H

#include "auditorium.hpp"
#include "fixedSizedMatrix.hpp"
#include <memory>

class Fixed : public Auditorium {
private:
  std::unique_ptr<FixedSizedMatrix> layout;

public:
  Fixed() {
    std::unique_ptr<FixedSizedMatrix> newLayout(new FixedSizedMatrix());
    this->layout = std::move(newLayout);
  }

  ~Fixed() { this->layout.reset(); }
};

#endif
