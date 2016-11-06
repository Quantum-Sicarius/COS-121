#ifndef LIST_AS_VECTOR_H
#define LIST_AS_VECTOR_H

#include "listAsArray.hpp"
#include "nullObject.hpp"
#include "object.hpp"
#include <algorithm>
#include <vector>

class ListAsVector : public ListAsArray {
protected:
  std::unique_ptr<std::vector<std::shared_ptr<Object>>> theList;
  int compareTo(Object const &) const;

public:
  ListAsVector();

  ~ListAsVector();

  void insert(std::shared_ptr<Object> o);
  void remove(std::shared_ptr<Object> o);

  void grow(int);
  void shrink(int);

  int size();
  std::shared_ptr<Object> &operator[](int i);
  void print(std::ostream &o) const;
};

#endif
