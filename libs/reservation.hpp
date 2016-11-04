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
    std::shared_ptr<std::vector<std::shared_ptr<Person>>> _people;
    std::shared_ptr<Strategy> _strategy;
    bool _reserved;

    ReservationDetail() {
      this->_reserved = false;
      this->_people = std::make_shared<std::vector<std::shared_ptr<Person>>>(
          std::vector<std::shared_ptr<Person>>());
      this->_strategy = std::make_shared<Strategy>(BestFit());
    }
    ReservationDetail(std::shared_ptr<std::vector<std::shared_ptr<Person>>> p,
                      std::shared_ptr<Strategy> s, bool b) {
      this->_people = p;
      this->_strategy = s;
      this->_reserved = b;
    }
    ReservationDetail(std::shared_ptr<ReservationDetail> detail) {
      // for (size_t i = 0; i < detail->_people->size(); i++) {
      //  this->_people->push_back(detail->_people->at(i));
      //}
      this->_people = detail->_people;
      this->_strategy = detail->_strategy;
      this->_reserved = detail->_reserved;
    }
  };

  int _currentState;
  int _furthestState;
  std::shared_ptr<ReservationDetail> _state;
  std::unique_ptr<std::vector<std::shared_ptr<ReservationDetail>>> _changes;

  // Not very efficient.
  void stateUpdate(std::shared_ptr<ReservationDetail> state) {
    this->_currentState++;
    this->_furthestState++;
    this->_changes->push_back(state);
    this->_state =
        std::make_shared<ReservationDetail>(ReservationDetail(state));
  }

public:
  Reservation() {
    this->_currentState = 0;
    this->_changes =
        std::make_unique<std::vector<std::shared_ptr<ReservationDetail>>>(
            std::vector<std::shared_ptr<ReservationDetail>>());
    this->_changes->push_back(
        std::make_unique<ReservationDetail>(ReservationDetail()));
  }
  Reservation &operator<<(std::shared_ptr<Person> p) {
    this->stateUpdate(std::move(this->_state));
    this->_state->_people->push_back(p);
    return *this;
  }

  std::shared_ptr<std::vector<std::shared_ptr<Person>>>
  getReservationPersons() {
    return this->_state->_people;
  }

  std::shared_ptr<Strategy> getReservationStrategy() {
    return this->_state->_strategy;
  }

  void Undo() {
    if (this->_currentState == 0) {
      return;
    }
    this->_currentState--;
    this->_state = this->_changes->at(this->_currentState);
  }
  void Redo() {
    if (this->_furthestState == this->_currentState) {
      return;
    }
    this->_currentState++;
    this->_state = this->_changes->at(this->_currentState);
  }
  void reserve(int strategy) {}

  bool isReserved() { return this->_state->_reserved; }
};

#endif
