#ifndef VARIABLE_H
#define VARIABLE_H

#include "auditorium.hpp"
#include "dynamicSizedMatrix.hpp"

class Variable : public Auditorium {
private:
  std::unique_ptr<DynamicSizedMatrix> layout;

public:
  Variable() {
    std::unique_ptr<DynamicSizedMatrix> newLayout(new DynamicSizedMatrix());
    this->layout = std::move(newLayout);
  }

  ~Variable() { this->layout.reset(); }
};
;

#endif
