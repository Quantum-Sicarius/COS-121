#ifndef COMPLEX_LIST_H
#define COMPLEX_LIST_H

#include "complex.hpp"
#include <memory>
#include <vector>

class ComplexList {
protected:
  std::unique_ptr<std::vector<std::shared_ptr<Complex>>> _complexList;

public:
  ComplexList() {
    this->_complexList =
        std::make_unique<std::vector<std::shared_ptr<Complex>>>(
            std::vector<std::shared_ptr<Complex>>());
  }
  void appendComplex(std::shared_ptr<Complex> c) {
    for (size_t i = 0; i < this->_complexList->size(); i++) {
      if (c->getName() == this->_complexList->at(i)->getName()) {
        throw "You can not have a complex with the same name";
      }
    }

    this->_complexList->push_back(std::move(c));
  }
  void deleteComplex(int i) {
    this->_complexList->erase(this->_complexList->begin() + i);
  }
  int size() { return this->_complexList->size(); }
  std::shared_ptr<Complex> at(int i) { return this->_complexList->at(i); }
};

#endif
