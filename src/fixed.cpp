#include "../libs/fixed.hpp"

int Fixed::compareTo(Object const &) const { return 0; }

void Fixed::setToSeat() {
  for (size_t i = 0; i < this->layout->size(); i++) {
    for (size_t x = 0; x < (*this->layout)[i]->size(); x++) {
      (*(*this->layout)[i])[x] = std::make_unique<Seat>(Seat());
    }
  }
}

Fixed::Fixed(std::string name) : Auditorium(name) {
  std::unique_ptr<FixedSizedMatrix> newLayout(new FixedSizedMatrix());
  this->layout = std::move(newLayout);
}

void Fixed::addRow(int i) {
  this->layout->growRow(i);
  this->setToSeat();
}

int Fixed::getRows() { return this->layout->size(); }
int Fixed::getColSize(int i) { return (*this->layout)[i]->size(); }

void Fixed::addSeatsInRow(int row, int amount) { return; }

std::shared_ptr<Seat> Fixed::getSeat(int row, int col) {
  return std::dynamic_pointer_cast<Seat>((*(*this->layout)[row])[col]);
}

Fixed::~Fixed() { this->layout.reset(); }

bool Fixed::isNull(void) const { return false; }
int Fixed::compare(Object const &) const { return 0; }
void Fixed::print(std::ostream &) const {}
