#ifndef NULLPERSONOBJECT_H
#define NULLPERSONOBJECT_H

#include "nullObject.hpp"
#include "object.hpp"
#include "person.hpp"

class NullObjectPerson : public Person {
protected:
  int compareTo(Object const &) const { return 0; };

public:
  bool isNull(void) const { return false; };
  int compare(Object const &) const { return 0; };
  void print(std::ostream & = std::cout) const {};
};

#endif
