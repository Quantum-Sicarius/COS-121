#include "../libs/listAsVector.hpp"

int ListAsVector::compareTo(Object const &) const { return 0; }

ListAsVector::ListAsVector() {
  std::unique_ptr<std::vector<std::shared_ptr<Object>>> newList(
      new std::vector<std::shared_ptr<Object>>);
  this->theList = std::move(newList);
}

ListAsVector::~ListAsVector() { this->theList.reset(); }

void ListAsVector::insert(std::shared_ptr<Object> o) {
  this->theList->push_back(o);
}
void ListAsVector::remove(std::shared_ptr<Object> o) {
  for (auto &object : *(this->theList)) // access by reference to avoid copying
  {
    if (object == o) {
      this->theList->erase(
          std::remove(this->theList->begin(), this->theList->end(), object),
          this->theList->end());
    }
  }
}

void ListAsVector::grow(int amount = 1) {
  for (size_t i = 0; i < amount; i++) {
    std::unique_ptr<Object> newNullObject(new NullObject());
    this->insert(std::move(newNullObject));
  }
}

void ListAsVector::shrink(int amount = 1) {
  for (size_t i = 0; i < amount; i++) {
    if (this->theList->size() == 0) {
      return;
    }
    this->theList->resize(this->theList->size() - 1);
  }
}

int ListAsVector::size() { return this->theList->size(); }

std::shared_ptr<Object> &ListAsVector::operator[](int i) {
  return this->theList->at(i);
}

void ListAsVector::print(std::ostream &o) const {}
