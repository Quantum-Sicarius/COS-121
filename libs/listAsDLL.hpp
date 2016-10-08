#include "listAsSLL.hpp"

class ListAsDLL : public ListAsSLL {
private:
struct node {
        Object *value;
        struct node *prev;
        struct node *next;
};
protected:
int size;
node* head;
node* tail;
public:
ListAsDLL();
~ListAsDLL();
void insert(Object*&);
void remove(Object*&);
void shrink();
Object& operator[](int);
};
