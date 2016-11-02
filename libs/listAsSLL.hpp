#ifndef LISTASSLL_H
#define LISTASSLL_H

#include "list.hpp"

template <typename T> class ListAsSLL : public List<T> {
private:
  struct Node {
    T value;
    std::unique_ptr<Node> next;

    Node(T v, std::unique_ptr<Node> n) {
      value = v;
      next = std::move(n);
    }
  };

protected:
  int compareTo(Object const &) const { return 0; }
  int size;
  std::unique_ptr<Node> head;

public:
  ListAsSLL() {
    this->head = nullptr;
    this->size = 0;
  }

  ~ListAsSLL() {
    this->head.reset();
    this->size = 0;
  }

  void insert(T o) {
    auto last_Node = this->head.get();

    // Traverse entire list to the end.
    while (last_Node && last_Node->next != nullptr) {
      last_Node = last_Node->next.get();
    }

    if (this->head == nullptr) {
      this->head.reset(new Node(o, nullptr));
    } else {
      last_Node->next.reset(new Node(o, nullptr));
    }
    ++this->size;
  }

  void remove(T o) {
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
      prev_Node->next = std::move(current_Node->next);
    }

    // Delete current_Node.
    // current_Node.reset();

    if (this->size != 0) {
      --this->size;
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

    if (this->size != 0) {
      --this->size;
    }
  }

  T &operator[](int i) {
    if (i < 0) {
      throw "Out of bounds!";
    }

    int start = 0;
    auto current_Node = this->head.get();

    while (start != i && start <= this->size && current_Node->next != nullptr) {
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
