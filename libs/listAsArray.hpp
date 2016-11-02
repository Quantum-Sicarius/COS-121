#ifndef LISTASARRAY_H
#define LISTASARRAY_H

#include "list.hpp"

template <typename T> class ListAsArray : public List<T> {
public:
  virtual void grow() = 0;
  virtual int size() = 0;
};

#endif
