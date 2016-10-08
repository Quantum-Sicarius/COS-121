#ifndef LISTASSLL_H
#define LISTASSLL_H

#include "list.hpp"

class ListAsSLL : public List {
private:
struct node {
        Object *value;
        struct node *next;
};
protected:
int size;
node* head;
public:
ListAsSLL();
~ListAsSLL();
void insert(Object*&);
void remove(Object*&);
void shrink();
Object& operator[](int);
};

#endif
