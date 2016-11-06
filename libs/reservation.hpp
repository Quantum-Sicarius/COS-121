#ifndef RESERVATION_H
#define RESERVATION_H

#include "auditorium.hpp"
#include "person.hpp"
#include <memory>
#include <vector>

class Strategy {
public:
  virtual std::shared_ptr<std::vector<std::pair<int, int>>>
      book(std::shared_ptr<Auditorium>,
           std::shared_ptr<std::vector<std::shared_ptr<Person>>>) = 0;
};

/*
 * Attempt to book all people into auditorium.
 */
class BestFit : public Strategy {
public:
  std::shared_ptr<std::vector<std::pair<int, int>>>
  book(std::shared_ptr<Auditorium> a,
       std::shared_ptr<std::vector<std::shared_ptr<Person>>> p) {

    if (a->getState() == "Fully Booked") {
      throw "Auditorium is fully booked";
    }

    int people_size = p->size();

    if (people_size == 0) {
      throw "No people to book!";
    }

    for (size_t row = 0; row < a->getRows(); row++) {
      for (size_t col = 0; col < a->getColSize(row); col++) {

        if (people_size == 0) {
          break;
        }
        try {
          if (!a->getSeat(row, col)->isTaken()) {
            people_size--;
          }
        } catch (...) {
        }
      }
    }

    if (people_size != 0) {
      throw "Failed to book all persons";
    }

    std::shared_ptr<std::vector<std::pair<int, int>>> points =
        std::make_shared<std::vector<std::pair<int, int>>>(
            std::vector<std::pair<int, int>>());

    people_size = p->size();

    for (size_t row = 0; row < a->getRows(); row++) {
      for (size_t col = 0; col < a->getColSize(row); col++) {
        if (people_size == 0) {
          break;
        }

        if (!a->getSeat(row, col)->isTaken()) {
          a->getSeat(row, col)->setPerson(p->at(people_size - 1));
          people_size--;
          points->push_back(std::pair<int, int>(row, col));
        }
      }
    }

    return points;
  }
};
/*
 * Attempt to book all people close to the screen.
 */
class BestView : public Strategy {
  std::shared_ptr<std::vector<std::pair<int, int>>>
  book(std::shared_ptr<Auditorium> a,
       std::shared_ptr<std::vector<std::shared_ptr<Person>>> p) {
    int people_size = p->size();

    if (people_size == 0) {
      throw "No people to book!";
    }

    if (a->getState() == "Fully Booked") {
      throw "Auditorium is fully booked";
    }

    for (size_t row = a->getRows() - 1; row > 0; row--) {
      for (size_t col = 0; col < a->getColSize(row); col++) {
        if (people_size == 0) {
          break;
        }

        try {
          if (!a->getSeat(row, col)->isTaken()) {
            people_size--;
          }
        } catch (...) {
        }
      }
    }

    if (people_size != 0) {
      throw "Failed to book all persons";
    }
    std::shared_ptr<std::vector<std::pair<int, int>>> points =
        std::make_shared<std::vector<std::pair<int, int>>>(
            std::vector<std::pair<int, int>>());

    people_size = p->size();

    for (size_t row = a->getRows() - 1; row > 0; row--) {
      for (size_t col = 0; col < a->getColSize(row); col++) {
        if (people_size == 0) {
          break;
        }
        if (!a->getSeat(row, col)->isTaken()) {
          a->getSeat(row, col)->setPerson(p->at(people_size - 1));
          people_size--;
          points->push_back(std::pair<int, int>(row, col));
        }
      }
    }
    return points;
  }
};
/*
 * Attempt to book all people in the same row.
 */
class BlockBookFirst : public Strategy {
  std::shared_ptr<std::vector<std::pair<int, int>>>
  book(std::shared_ptr<Auditorium> a,
       std::shared_ptr<std::vector<std::shared_ptr<Person>>> p) {
    int people_size = p->size();

    if (people_size == 0) {
      throw "No people to book!";
    }

    if (a->getState() == "Fully Booked") {
      throw "Auditorium is fully booked";
    }

    for (size_t row = 0; row < a->getRows(); row++) {
      for (size_t col = 0; col < a->getColSize(row); col++) {
        if (people_size == 0) {
          break;
        }
        if (!a->getSeat(row, col)->isTaken()) {
          people_size--;
        }
      }
      if (people_size != 0) {
        people_size = p->size();
      }
    }

    if (people_size != 0) {
      throw "Failed to book all persons";
    }
    std::shared_ptr<std::vector<std::pair<int, int>>> points =
        std::make_shared<std::vector<std::pair<int, int>>>(
            std::vector<std::pair<int, int>>());

    people_size = p->size();

    for (size_t row = 0; row < a->getRows(); row++) {
      for (size_t col = 0; col < a->getColSize(row); col++) {
        if (people_size == 0) {
          break;
        }
        if (!a->getSeat(row, col)->isTaken()) {
          a->getSeat(row, col)->setPerson(p->at(people_size - 1));
          people_size--;
          points->push_back(std::pair<int, int>(row, col));
        }
      }
    }
    return points;
  }
};

class Reservation {
private:
  struct ReservationDetail {
    std::shared_ptr<std::vector<std::shared_ptr<Person>>> _people;
    int _strategy;
    bool _reserved;

    std::shared_ptr<std::vector<std::pair<int, int>>> _booked_coords;

    std::shared_ptr<Auditorium> _auditorium;

    ReservationDetail() {
      this->_reserved = false;
      this->_people = std::make_shared<std::vector<std::shared_ptr<Person>>>(
          std::vector<std::shared_ptr<Person>>());
      this->_strategy = 0;
      this->_booked_coords = std::make_unique<std::vector<std::pair<int, int>>>(
          std::vector<std::pair<int, int>>());
    }
    ReservationDetail(std::shared_ptr<std::vector<std::shared_ptr<Person>>> p,
                      int s, bool b, std::shared_ptr<Auditorium> a) {
      this->_people = p;
      this->_strategy = s;
      this->_reserved = b;
      this->_auditorium = a;
    }
    ReservationDetail(std::shared_ptr<ReservationDetail> detail) {
      this->_people = std::make_shared<std::vector<std::shared_ptr<Person>>>(
          std::vector<std::shared_ptr<Person>>());
      for (size_t i = 0; i < detail->_people->size(); i++) {
        this->_people->push_back(detail->_people->at(i));
      }
      this->_strategy = detail->_strategy;
      this->_reserved = detail->_reserved;
      this->_auditorium = detail->_auditorium;
      this->_booked_coords = std::make_unique<std::vector<std::pair<int, int>>>(
          std::vector<std::pair<int, int>>());
      for (size_t i = 0; i < detail->_booked_coords->size(); i++) {
        this->_booked_coords->push_back(detail->_booked_coords->at(i));
      }
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

  void undoBooking() {
    for (size_t i = 0; i < this->_state->_booked_coords->size(); i++) {
      this->_state->_auditorium
          ->getSeat(this->_state->_booked_coords->at(i).first,
                    this->_state->_booked_coords->at(i).second)
          ->removePerson();
    }
  }

  void redoBooking() {
    int amountPeople = 0;

    if (this->_state->_people->size() == 0) {
      return;
    }

    for (size_t i = 0; i < this->_state->_booked_coords->size(); i++) {
      this->_state->_auditorium
          ->getSeat(this->_state->_booked_coords->at(i).first,
                    this->_state->_booked_coords->at(i).second)
          ->setPerson(this->_state->_people->at(amountPeople));
      amountPeople++;
    }
  }

public:
  Reservation() {
    this->_currentState = 0;
    this->_furthestState = 0;
    this->_changes =
        std::make_unique<std::vector<std::shared_ptr<ReservationDetail>>>(
            std::vector<std::shared_ptr<ReservationDetail>>());
    this->_state = std::make_unique<ReservationDetail>(ReservationDetail());
  }
  Reservation &operator<<(std::shared_ptr<Person> p) {
    this->stateUpdate(this->_state);
    this->_state->_people->push_back(p);
    return *this;
  }

  std::shared_ptr<std::vector<std::shared_ptr<Person>>>
  getReservationPersons() {
    return this->_state->_people;
  }

  int getReservationStrategy() { return this->_state->_strategy; }

  void Undo() {
    if (this->_currentState <= 0) {
      return;
    }
    this->stateUpdate(this->_state);
    this->_currentState -= 2;
    this->undoBooking();
    this->_state = this->_changes->at(this->_currentState);
  }
  void Redo() {
    if (this->_furthestState <= this->_currentState) {
      return;
    }
    this->_currentState++;
    this->_state = this->_changes->at(this->_currentState);

    this->redoBooking();
  }
  void reserve(int strategy, std::shared_ptr<Auditorium> a) {
    this->stateUpdate(this->_state);
    this->_state->_auditorium = a;
    this->_state->_strategy = strategy;
    if (strategy == 1) {
      std::unique_ptr<Strategy> s(new BestView());
      this->_state->_booked_coords =
          s->book(this->_state->_auditorium, this->_state->_people);
      this->_state->_reserved = true;

    } else if (strategy == 2) {
      std::unique_ptr<Strategy> s(new BlockBookFirst());
      this->_state->_booked_coords =
          s->book(this->_state->_auditorium, this->_state->_people);

      this->_state->_reserved = true;

    } else {
      std::unique_ptr<Strategy> s(new BestFit());
      this->_state->_booked_coords =
          s->book(this->_state->_auditorium, this->_state->_people);

      this->_state->_reserved = true;
    }
  }

  bool isReserved() { return this->_state->_reserved; }
};

#endif
