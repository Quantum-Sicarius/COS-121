#ifndef LISTASARRAY_H
#define LISTASARRAY_H

#include "list.hpp"

class ListAsArray : public List {
public:
  virtual void grow() = 0;
  virtual int size() = 0;
  virtual void insert(std::shared_ptr<Object>) = 0;
  virtual void remove(std::shared_ptr<Object>) = 0;
  virtual std::shared_ptr<Object> &operator[](int) = 0;
  virtual void print(std::ostream & = std::cout) const = 0;
};

#endif
