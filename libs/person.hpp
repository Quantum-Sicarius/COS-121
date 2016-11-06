#ifndef PERSON_H
#define PERSON_H

#include "object.hpp"

class Person : public Object {
protected:
  int compareTo(Object const &) const;

public:
  bool isNull(void) const;
  int compare(Object const &) const;
  void print(std::ostream & = std::cout) const;
};

#endif
