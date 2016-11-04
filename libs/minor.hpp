#ifndef MINOR_H
#define MINOR_H

#include "person.hpp"

class Minor : public Person {
private:
  bool _isChild;

public:
  Minor(bool isChild) { this->_isChild = isChild; }
};

#endif
