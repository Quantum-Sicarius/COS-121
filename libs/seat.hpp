#ifndef SEAT_H
#define SEAT_H

#include "nullPersonObject.hpp"
#include "object.hpp"
#include "person.hpp"
#include <memory>

class Seat : public Object {
protected:
  std::shared_ptr<Person> seatedPerson;
  int compareTo(Object const &) const { return 0; };
  bool taken;

public:
  Seat() {
    this->taken = false;
    this->seatedPerson = std::make_unique<NullPersonObject>(NullPersonObject());
  }
  std::shared_ptr<Person> getPerson() { return this->seatedPerson; }
  void setPerson(std::shared_ptr<Person> p) {
    if (this->taken) {
      throw "This seat is taken!";
    }
    this->seatedPerson = p;
    this->taken = true;
  }

  void removePerson() {
    this->seatedPerson = std::make_unique<NullPersonObject>(NullPersonObject());
    this->taken = false;
  }

  bool isTaken() { return this->taken; }

  void print(std::ostream &o = std::cout) const {};
};

#endif
