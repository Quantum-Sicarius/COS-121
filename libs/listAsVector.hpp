#ifndef LIST_AS_VECTOR_H
#define LIST_AS_VECTOR_H

#include "listAsArray.hpp"
#include "object.hpp"
#include <vector>

class ListAsVector : public ListAsArray {
protected:
std::vector<Object*> *theList;
public:
ListAsVector();
~ListAsVector();
void insert(Object*&);
void remove(Object*&);
void grow();
void shrink();
Object& operator[](int);
};

#endif
