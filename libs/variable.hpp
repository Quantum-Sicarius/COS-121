#ifndef VARIABLE_H
#define VARIABLE_H

#include "auditorium.hpp"
#include "dynamicSizedMatrix.hpp"

class Variable : public Auditorium {
private:
  std::unique_ptr<DynamicSizedMatrix> layout;

protected:
  int compareTo(Object const &) const { return 0; }

public:
  Variable(std::string name) : Auditorium(name) {
    std::unique_ptr<DynamicSizedMatrix> newLayout(new DynamicSizedMatrix());
    this->layout = std::move(newLayout);
  }

  /*
   * Adds seats into row from 0.
   */
  void addSeatsInRow(int row, int amount) {
    // Save the old size.
    int oldSize = (*this->layout)[row]->size();
    // Grow the amount.
    (*this->layout)[row]->grow(amount);
    // Make all object from previous size to new size seats.
    for (size_t col = oldSize; col < (*this->layout)[row]->size(); col++) {
      (*(*this->layout)[row])[col] = std::make_unique<Seat>(Seat());
    }
  }

  /*
   * Add a seat at any Row/Col fill empty spaces with NullObjects.
   */
  void addSeat(int row, int col) {
    // Save old size.
    int oldSize = this->layout->size();
    // Grow missing space.
    if (oldSize == 0) {
      this->layout->growRow(row + 1);
    } else if ((row - oldSize) > 0) {
      this->layout->growRow((row + 1) - oldSize);
    }

    // Save old column size.
    int oldColSize = (*this->layout)[row]->size();
    // Grow missing space.
    if (oldColSize == 0) {
      (*this->layout)[row]->grow(col + 1);
    } else if ((col - oldColSize) > 0) {
      (*this->layout)[row]->grow((col + 1) - oldColSize);
    }

    // Add seat.
    (*(*this->layout)[row])[col] = std::make_unique<Seat>(Seat());
  }

  void removeSeat(int row, int col) {
    (*(*this->layout)[row])[col] = std::make_unique<NullObject>(NullObject());
  }

  void addRow(int i) {
    this->layout->growRow(i);
    // this->setToSeat();
  }
  std::shared_ptr<Seat> getSeat(int row, int col) {
    std::shared_ptr<Seat> seat =
        std::dynamic_pointer_cast<Seat>((*(*this->layout)[row])[col]);
    if (seat) {
      return seat;
    } else {
      std::string err = "There is no seat at: ";
      err += row;
      err += ", ";
      err += col;
      throw err;
    }
  }

  ~Variable() { this->layout.reset(); }

  bool isNull(void) const { return false; }
  int compare(Object const &) const { return 0; }
  void print(std::ostream & = std::cout) const {}
};
;

#endif
