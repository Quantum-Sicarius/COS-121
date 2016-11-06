#ifndef SEAT_H
#define SEAT_H

#include "nullPersonObject.hpp"
#include "object.hpp"
#include "person.hpp"
#include <memory>

class Seat : public Object {
protected:
  std::shared_ptr<Person> seatedPerson;
  int compareTo(Object const &) const;
  bool taken;

public:
  Seat();
  std::shared_ptr<Person> getPerson();
  void setPerson(std::shared_ptr<Person> p);

  void removePerson();

  bool isTaken();

  void print(std::ostream &o = std::cout) const;
};

#endif
