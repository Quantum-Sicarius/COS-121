#ifndef LIST_H
#define LIST_H

#include "container.hpp"
#include <memory>

template <typename T> class List : public Container<T> {
public:
  virtual ~List() = default;
  virtual void insert(T) = 0;
  virtual void remove(T) = 0;
  virtual void shrink() = 0;
  virtual T &operator[](int) = 0;
};

#endif
