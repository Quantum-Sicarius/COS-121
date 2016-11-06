#ifndef ADULT_H
#define ADULT_H

#include "person.hpp"

class Adult : public Person {
protected:
  int compareTo(Object const &) const { return 0; };

public:
  bool isNull(void) const { return false; };
  int compare(Object const &) const { return 0; };
  void print(std::ostream & = std::cout) const {};
};

#endif
