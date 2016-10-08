#ifndef LIST_H
#define LIST_H

#include "container.hpp"
#include "object.hpp"

class List : public Container {
public:
virtual ~List() = default;
virtual void insert(Object*&) = 0;
virtual void remove(Object*&) = 0;
virtual void shrink() = 0;
virtual Object& operator[](int) = 0;
};

#endif
