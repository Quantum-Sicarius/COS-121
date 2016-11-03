#ifndef PERSON_H
#define PERSON_H

#include "object.hpp"

class Person : public Object {
protected:
  int compareTo(Object const &) const { return 0; };

public:
  bool isNull(void) const { return false; };
  int compare(Object const &) const { return 0; };
  void print(std::ostream & = std::cout) const {};
};

#endif
