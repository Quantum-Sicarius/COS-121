#ifndef LIST_AS_VECTOR_H
#define LIST_AS_VECTOR_H

#include "listAsArray.hpp"
#include "object.hpp"
#include <algorithm>
#include <vector>

template <typename T> class ListAsVector : public ListAsArray<T> {
protected:
  std::unique_ptr<std::vector<T>> theList;
  int compareTo(Object const &) const { return 0; }

public:
  ListAsVector() {
    std::unique_ptr<std::vector<T>> newList(new std::vector<T>);
    this->theList = std::move(newList);
  }

  ~ListAsVector() { this->theList.reset(); }

  void insert(T o) { this->theList->push_back(o); }
  void remove(T o) {
    for (auto &object :
         *(this->theList)) // access by reference to avoid copying
    {
      if (object == o) {
        this->theList->erase(
            std::remove(this->theList->begin(), this->theList->end(), object),
            this->theList->end());
      }
    }
  }

  void grow() { this->theList->resize(this->theList->size() + 1); }

  void shrink() {
    if (this->theList->size() == 0) {
      return;
    }
    this->theList->resize(this->theList->size() - 1);
  }

  int size() { return this->theList->size(); }

  T &operator[](int i) { return this->theList->at(i); }

  void print(std::ostream &o) const {}
};

#endif
