#include "../libs/listAsDLL.hpp"

ListAsDLL::ListAsDLL() {
  this->head = 0;
  this->tail = 0;
  this->size = 0;
}

ListAsDLL::~ListAsDLL() {
  this->head = 0;
  this->tail = 0;
  this->size = 0;
}

void ListAsDLL::insert(Object *&o) {
  node *last_Node = this->tail;

  node *current_Node = new node;
  current_Node->value = o;
  current_Node->next = 0;
  if (last_Node) {
    current_Node->prev = last_Node;
  } else {
    current_Node->prev = 0;
  }

  if (this->head == 0) {
    this->head = current_Node;
  }
  if (this->tail == 0) {
    this->tail = current_Node;
  } else {
    last_Node->next = current_Node;
    this->tail = current_Node;
  }

  ++this->size;
}

void ListAsDLL::remove(Object *&o) {
  // If list empty just return.
  if (!this->head) {
    return;
  }

  node *current_Node = this->head;
  node *prev_Node = 0;
  node *next_Node = 0;
  bool found = false;

  if (current_Node && current_Node->value == o) {
    found = true;
  }

  // Traverse till we find the object;
  while (current_Node && current_Node->next != 0) {
    // If found exit loop.
    if (current_Node->value == o) {
      found = true;
      break;
    }

    prev_Node = current_Node;
    current_Node = current_Node->next;
    next_Node = current_Node->next;
  }

  if (!found) {
    return;
  }

  // If the current node is the head we must repoint the head.
  if (current_Node == this->head) {
    this->head = current_Node->next;
  }

  // Delete current_Node.
  current_Node->next = 0;
  delete current_Node;

  // Fix pointers.
  if (prev_Node) {
    prev_Node->next = next_Node;
  }

  if (next_Node) {
    next_Node->prev = prev_Node;
  }

  if (this->size != 0) {
    --this->size;
  }
}

void ListAsDLL::shrink() {
  // If list empty just return.
  if (!this->head) {
    return;
  }

  node *last_Node = this->head;
  node *prev_Node = 0;

  // Traverse entire list to the end.
  while (last_Node && last_Node->next != 0) {
    // Save the previous node.
    prev_Node = last_Node;
    last_Node = last_Node->next;
  }

  if (last_Node) {
    // Point previous node to 0;
    if (prev_Node) {
      prev_Node->next = 0;

      last_Node->next = 0;
      // Delete the last node.
      delete last_Node;
    } else {
      this->head->next = 0;
      delete this->head;
      this->head = 0;
    }
  }

  if (this->size != 0) {
    --this->size;
  }
}

Object &ListAsDLL::operator[](int i) {
  if (i < 0) {
    throw "Out of bounds!";
  }

  int start = 0;
  node *current_Node = this->head;

  while (start != i && start <= this->size && current_Node &&
         current_Node->next != 0) {
    current_Node = current_Node->next;
    start++;
  }

  if (start == i && current_Node) {
    return *(current_Node->value);
  } else {
    throw "Node not found!";
  }
}

int ListAsDLL::compareTo(Object const &) const { return 0; }

void ListAsDLL::print(std::ostream &o) const {}
