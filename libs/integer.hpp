#ifndef INTEGER_H
#define INTEGER_H

#include "object.hpp"

class Integer : public Object {
protected:
  int myInteger;
  int compareTo(Object const &) const;

public:
  Integer(int);
  void print(std::ostream &os) const;
  operator int();
};

#endif
