#ifndef FLEXI_H
#define FLEXI_H

#include "auditorium.hpp"
#include "flexiMatrix.hpp"
#include <memory>

class Flexi : public Auditorium {
private:
  std::unique_ptr<FlexiMatrix> layout;

public:
  Flexi() {
    std::unique_ptr<FlexiMatrix> newLayout(new FlexiMatrix());
    this->layout = std::move(newLayout);
  }

  ~Flexi() { this->layout.reset(); }
};
;

#endif
