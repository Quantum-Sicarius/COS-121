#ifndef LISTASARRAY_H
#define LISTASARRAY_H

#include "list.hpp"

class ListAsArray : public List {
public:
  virtual void grow() = 0;
  virtual int size() = 0;
};

#endif
