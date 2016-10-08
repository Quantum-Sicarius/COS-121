#ifndef DYNAMICARRAYLIST_H
#define DYNAMICARRAYLIST_H

#include "listAsArray.hpp"
#include "object.hpp"

class DynamicArrayList : public ListAsArray {
protected:
Object **theList;
unsigned listSize;
void resize(unsigned int);
public:
DynamicArrayList();
~DynamicArrayList();
void insert(Object*&);
void remove(Object*&);
void grow();
void shrink();
Object& operator[](int);
};

#endif
