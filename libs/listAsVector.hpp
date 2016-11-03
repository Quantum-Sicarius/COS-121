#ifndef LIST_AS_VECTOR_H
#define LIST_AS_VECTOR_H

#include "listAsArray.hpp"
#include "nullObject.hpp"
#include "object.hpp"
#include <algorithm>
#include <vector>

class ListAsVector : public ListAsArray {
protected:
  std::unique_ptr<std::vector<std::shared_ptr<Object>>> theList;
  int compareTo(Object const &) const { return 0; }

public:
  ListAsVector() {
    std::unique_ptr<std::vector<std::shared_ptr<Object>>> newList(
        new std::vector<std::shared_ptr<Object>>);
    this->theList = std::move(newList);
  }

  ~ListAsVector() { this->theList.reset(); }

  void insert(std::shared_ptr<Object> o) { this->theList->push_back(o); }
  void remove(std::shared_ptr<Object> o) {
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

  void grow() {
    std::unique_ptr<Object> newNullObject(new NullObject());
    this->insert(std::move(newNullObject));
  }

  void shrink() {
    if (this->theList->size() == 0) {
      return;
    }
    this->theList->resize(this->theList->size() - 1);
  }

  int size() { return this->theList->size(); }

  std::shared_ptr<Object> &operator[](int i) { return this->theList->at(i); }

  void print(std::ostream &o) const {}
};

#endif
