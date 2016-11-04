#ifndef LIST_H
#define LIST_H

#include "container.hpp"
#include <memory>

class List : public Container {
public:
  virtual ~List() = default;
  virtual void insert(std::shared_ptr<Object>) = 0;
  virtual void remove(std::shared_ptr<Object>) = 0;
  virtual void shrink(int amount = 1) = 0;
  virtual void grow(int amount = 1) = 0;
  virtual std::shared_ptr<Object> &operator[](int) = 0;
  virtual int size() = 0;
};

#endif
