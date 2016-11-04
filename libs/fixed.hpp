#ifndef FIXED_H
#define FIXED_H

#include "auditorium.hpp"
#include "fixedSizedMatrix.hpp"
#include "seat.hpp"
#include <memory>

class Fixed : public Auditorium {
private:
  std::unique_ptr<FixedSizedMatrix> layout;

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
  Fixed(std::string name) : Auditorium(name) {
    std::unique_ptr<FixedSizedMatrix> newLayout(new FixedSizedMatrix());
    this->layout = std::move(newLayout);
  }

  void addRow(int i) {
    this->layout->growRow(i);
    this->setToSeat();
  }

  void addSeatInRow(int row, int amount) { return; }

  std::shared_ptr<Seat> getSeat(int row, int col) {
    return std::dynamic_pointer_cast<Seat>((*(*this->layout)[row])[col]);
  }

  ~Fixed() { this->layout.reset(); }

  bool isNull(void) const { return false; }
  int compare(Object const &) const { return 0; }
  void print(std::ostream & = std::cout) const {}
};

#endif
