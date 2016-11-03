#ifndef LISTASARRAY_H
#define LISTASARRAY_H

#include "list.hpp"

template <typename T> class ListAsArray : public List<T> {
public:
  virtual void grow() = 0;
  virtual int size() = 0;
  virtual void insert(T) = 0;
  virtual void remove(T) = 0;
  virtual T &operator[](int) = 0;
  virtual void print(std::ostream & = std::cout) const = 0;
};

#endif
