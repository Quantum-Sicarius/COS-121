#ifndef DYNAMICARRAYLIST_H
#define DYNAMICARRAYLIST_H

#include "listAsArray.hpp"
#include "object.hpp"

class DynamicArrayList : public ListAsArray {
protected:
  int compareTo(Object const &) const;
  Object **theList;
  unsigned listSize;
  void resize(unsigned int);

public:
  DynamicArrayList();
  ~DynamicArrayList();
  void insert(Object *&);
  void remove(Object *&);
  void grow();
  void shrink();
  int size();
  Object &operator[](int);

  void print(std::ostream & = std::cout) const;
};

#endif
