#include "../libs/dynamicArrayList.hpp"

DynamicArrayList::DynamicArrayList() {
        this->listSize = 0;
        this->theList = 0;
}

DynamicArrayList::~DynamicArrayList() {
        delete [] this->theList;
}

void DynamicArrayList::insert(Object*& o) {
        // Grow list.
        this->grow();
        this->theList[this->listSize - 1] = o;
}

void DynamicArrayList::resize(unsigned int newSize) {
        Object **newList =  new Object*[newSize];
        int newCounter = 0;

        for (size_t i = 0; i < this->listSize; i++) {
                if (this->theList[i] != NULL) {
                        newList[newCounter] = this->theList[i];
                        ++newCounter;
                }
        }
        this->listSize = newCounter;

        delete [] this->theList;
        this->theList = newList;
}

void DynamicArrayList::remove(Object*& o) {
        for (size_t i = 0; i < this->listSize; i++) {
                if (this->theList[i] == o) {
                        this->theList[i] = NULL;
                        break;
                }
        }

        this->resize(this->listSize - 1);
}

void DynamicArrayList::grow() {
        Object **newList =  new Object*[(this->listSize + 1)];

        for (size_t i = 0; i < this->listSize; i++) {
                newList[i] = this->theList[i];
        }

        delete [] this->theList;
        ++this->listSize;

        this->theList = newList;
}

void DynamicArrayList::shrink() {
        if (this->listSize == 0) {
                return;
        }
        --this->listSize;
        Object **newList =  new Object*[this->listSize];

        for (size_t i = 0; i < this->listSize; i++) {
                newList[i] = this->theList[i];
        }

        delete [] this->theList;

        this->theList = newList;
}

Object& DynamicArrayList::operator[](int i) {
        if (i < 0 || (unsigned)i >= this->listSize) {
                throw "Out of Bounds!";
        }
        return *this->theList[i];
}
