#ifndef RESERVATION_H
#define RESERVATION_H

#include "person.hpp"
#include <memory>
#include <vector>

class Strategy {};

class BestFit : public Strategy {};
class BestView : public Strategy {};
class BlockBookFirst : public Strategy {};

class Reservation {
private:
  struct ReservationDetail {
    std::shared_ptr<std::vector<Person>> _people;
    std::shared_ptr<Strategy> _strategy;

    ReservationDetail() {
      this->_people =
          std::make_shared<std::vector<Person>>(std::vector<Person>());
      this->_strategy = std::make_shared<Strategy>(BestFit());
    }
  };

  int _numChanges = 0;
  std::unique_ptr<ReservationDetail> _back;
  std::unique_ptr<ReservationDetail> _forward;

  std::unique_ptr<ReservationDetail> _state;

public:
  Reservation() {
    this->_state = std::make_unique<ReservationDetail>(ReservationDetail());
  }
  Reservation &operator<<(Person p) {
    this->_state->_people->push_back(p);
    return *this;
  }

  std::shared_ptr<std::vector<Person>> getReservationPersons() {
    return this->_state->_people;
  }

  std::shared_ptr<Strategy> getReservationStrategy() {
    return this->_state->_strategy;
  }

  void Undo() { this->_numChanges++; }
  void Redo() { this->_numChanges++; }
  void reserve(int strategy) {}
};

#endif
