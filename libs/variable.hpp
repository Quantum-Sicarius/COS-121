#ifndef VARIABLE_H
#define VARIABLE_H

#include "auditorium.hpp"
#include "dynamicSizedMatrix.hpp"

class Variable : public Auditorium {
private:
  std::unique_ptr<DynamicSizedMatrix> layout;

protected:
  int compareTo(Object const &) const { return 0; }

  void setToSeat() {
    for (size_t i = 0; i < this->layout->size(); i++) {
      for (size_t x = 0; x < (*this->layout)[i]->size(); x++) {
        (*(*this->layout)[i])[x] = std::make_unique<Seat>(Seat());
      }
    }
  }

public:
  Variable(std::string name) : Auditorium(name) {
    std::unique_ptr<DynamicSizedMatrix> newLayout(new DynamicSizedMatrix());
    this->layout = std::move(newLayout);
  }

  void addSeatInRow(int row, int amount) {
    (*this->layout)[row]->grow(amount);
    this->setToSeat();
  }

  void addRow(int i) {
    this->layout->growRow(i);
    this->setToSeat();
  }
  std::shared_ptr<Seat> getSeat(int row, int col) {
    return std::dynamic_pointer_cast<Seat>((*(*this->layout)[row])[col]);
  }

  ~Variable() { this->layout.reset(); }

  bool isNull(void) const { return false; }
  int compare(Object const &) const { return 0; }
  void print(std::ostream & = std::cout) const {}
};
;

#endif
