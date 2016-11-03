#ifndef LISTASDLL_H
#define LISTASDLL_H

#include "listAsSLL.hpp"

class ListAsDLL : public ListAsSLL {
private:
  int listSize = 0;

  struct Node {
    std::shared_ptr<Object> value;
    std::unique_ptr<Node> next;
    Node *prev;

    Node(std::shared_ptr<Object> v, std::unique_ptr<Node> n, Node *p) {
      value = v;
      next = std::move(n);
      prev = p;
    }

    ~Node() {}
  };

protected:
  int compareTo(Object const &) const { return 0; }
  std::unique_ptr<Node> head;
  // std::unique_ptr<Node> tail;

public:
  ListAsDLL() {
    this->head = nullptr;
    // this->tail = nullptr;
    this->listSize = 0;
  }
  ~ListAsDLL() {
    this->head.reset();
    // this->tail.reset();
    this->listSize = 0;
  }
  void insert(std::shared_ptr<Object> o) {
    auto last_Node = this->head.get();

    // Traverse entire list to the end.
    while (last_Node && last_Node->next != nullptr) {
      last_Node = last_Node->next.get();
    }

    if (this->head == nullptr) {
      this->head.reset(new Node(o, nullptr, nullptr));
    } else {
      last_Node->next.reset(new Node(o, nullptr, last_Node));
    }
    ++this->listSize;
  }

  void remove(std::shared_ptr<Object> o) {
    // If list empty just return.
    if (!this->head) {
      return;
    }

    // If list empty just return.
    if (this->head == nullptr) {
      return;
    }

    auto current_Node = this->head.get();
    auto prev_Node = current_Node;
    auto next_Node = current_Node;
    bool found = false;

    if (current_Node->value == o) {
      found = true;
    }

    // Traverse till we find the object;
    while (current_Node->next != nullptr) {
      // If found exit loop.
      if (current_Node->value == o) {
        found = true;
        break;
      }

      prev_Node = current_Node;
      current_Node = current_Node->next.get();
      next_Node = current_Node->next.get();
    }

    if (!found) {
      return;
    }

    // If the current node is the head we must repoint the head.
    if (current_Node == this->head.get()) {
      this->head = std::move(current_Node->next);
    }

    // Fix pointers.
    if (prev_Node != nullptr) {
      next_Node->prev = prev_Node;
      prev_Node->next = std::move(current_Node->next);
    }

    // Delete current_Node.
    current_Node = nullptr;

    if (this->listSize != 0) {
      --this->listSize;
    }
  }

  void shrink() {
    // If list empty just return.
    if (this->head == nullptr) {
      return;
    }

    auto last_Node = this->head.get();
    auto prev_Node = last_Node;

    // Traverse entire list to the end.
    while (last_Node->next != nullptr) {
      // Save the previous node.
      prev_Node = last_Node;
      last_Node = last_Node->next.get();
    }

    prev_Node->next.reset();
    if (prev_Node == this->head.get()) {
      this->head.reset();
    }

    if (this->listSize != 0) {
      --this->listSize;
    }
  }
  int size() { return this->listSize; }

  std::shared_ptr<Object> &operator[](int i) {
    if (i < 0) {
      throw "Out of bounds!";
    }

    int start = 0;
    auto current_Node = this->head.get();

    while (start != i && start <= this->listSize &&
           current_Node->next != nullptr) {
      current_Node = current_Node->next.get();
      start++;
    }

    if (start == i && current_Node) {
      return current_Node->value;
    } else {
      throw "Node not found!";
    }
  }
  void print(std::ostream &o) const {}
};
#endif
