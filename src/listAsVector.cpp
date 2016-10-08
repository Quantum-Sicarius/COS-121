#include "../libs/listAsVector.hpp"
#include <algorithm>

ListAsVector::ListAsVector() {
        this->theList = new std::vector<Object*>();
}

ListAsVector::~ListAsVector() {
        delete [] this->theList;
}

void ListAsVector::insert(Object*& o) {
        this->theList->push_back(o);
}

void ListAsVector::remove(Object*& o) {
        for (auto &object : *(this->theList)) // access by reference to avoid copying
        {
                if (object == o)
                {
                        this->theList->erase(std::remove(this->theList->begin(), this->theList->end(), object), this->theList->end());
                }
        }
}

void ListAsVector::grow() {
        return;
}

void ListAsVector::shrink() {
        if (this->theList->size() == 0) {
                return;
        }
        this->theList->resize(this->theList->size() - 1);
}

int ListAsVector::size() {
        return this->theList->size();
}

Object& ListAsVector::operator[](int i) {
        return *this->theList->at(i);
}

int ListAsVector::compareTo ( Object const&) const {
        return 0;
}

void ListAsVector::print ( std::ostream& o ) const {

}
