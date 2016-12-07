/**
* @Author: Thomas Scholtz <thomas>
* @Date:   2016-11-04T15:23:06+02:00
* @Email:  thomas@quantum-sicarius.za.net
* @Last modified by:   thomas
* @Last modified time: 2016-12-07T19:17:08+02:00
* @License: Attribution-NonCommercial-ShareAlike 4.0 International
*/

#ifndef DYNAMICARRAYLIST_H
#define DYNAMICARRAYLIST_H

#include "listAsArray.hpp"
#include "nullObject.hpp"
#include "object.hpp"

class DynamicArrayList : public ListAsArray {
protected:
  int compareTo(Object const &) const { return 0; }
  std::unique_ptr<std::shared_ptr<Object>[]> theList;
  unsigned listSize;

  void resize(unsigned int newSize) {
    std::unique_ptr<std::shared_ptr<Object>[]> newList(
        new std::shared_ptr<Object>[newSize]);
    int newCounter = 0;

    for (size_t i = 0; i < this->listSize; i++) {
      if (this->theList[i] != nullptr) {
        newList[newCounter] = this->theList[i];
        ++newCounter;
      }
    }
    this->listSize = newCounter;

    this->theList.reset();
    this->theList = std::move(newList);
  }

public:
  DynamicArrayList() {
    this->listSize = 0;
    this->theList = nullptr;
  }
  ~DynamicArrayList() { this->theList.reset(); }
  void insert(std::shared_ptr<Object> o) {
    // Grow list.
    this->grow();
    this->theList[this->listSize - 1] = o;
  }

  void remove(std::shared_ptr<Object> o) {
    for (size_t i = 0; i < this->listSize; i++) {
      if (this->theList[i] == o) {
        this->theList[i] = nullptr;
        break;
      }
    }
    this->resize(this->listSize - 1);
  }
  void grow(int amount = 1) {
    // Object **newList = new Object *[(this->listSize + 1)];
    std::unique_ptr<std::shared_ptr<Object>[]> newList(
        new std::shared_ptr<Object>[this->listSize + 1]);

    for (size_t i = 0; i < this->listSize; i++) {
      newList[i] = this->theList[i];
    }
    newList[this->listSize] = std::make_unique<NullObject>(NullObject());

    this->theList.reset();
    ++this->listSize;

    this->theList = std::move(newList);
  }
  void shrink(int amount = 1) {
    if (this->listSize == 0) {
      return;
    }
    --this->listSize;
    // Object **newList = new Object *[this->listSize];
    std::unique_ptr<std::shared_ptr<Object>[]> newList(
        new std::shared_ptr<Object>[this->listSize]);

    for (size_t i = 0; i < this->listSize; i++) {
      newList[i] = this->theList[i];
    }

    this->theList.reset();

    this->theList = std::move(newList);
  }
  int size() { return this->listSize; }

  std::shared_ptr<Object> &operator[](int i) {
    if (i < 0 || (unsigned)i >= this->listSize) {
      throw "Out of Bounds!";
    }
    return this->theList[i];
  }
  void print(std::ostream &o) const {}
};

#endif
