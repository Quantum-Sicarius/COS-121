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

public:
  Seat() {
    this->seatedPerson = std::make_unique<NullPersonObject>(NullPersonObject());
  }
  std::shared_ptr<Person> getPerson() { return this->seatedPerson; }
  void setPerson(std::shared_ptr<Person> p) { this->seatedPerson = p; }

  bool isTaken() {
    std::shared_ptr<NullPersonObject> n =
        std::dynamic_pointer_cast<NullPersonObject>(this->seatedPerson);
    if (n) {
      return false;
    }
    return true;
  }

  void print(std::ostream &o = std::cout) const {};
};

#endif
