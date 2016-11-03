#ifndef SEAT_H
#define SEAT_H

#include "object.hpp"
#include "person.hpp"

class Seat : public Object {
protected:
  Person seatedPerson;

public:
  Person getPerson() { return this->seatedPerson; }
  void setPerson(Person p) { this->seatedPerson = p; }
};

#endif
