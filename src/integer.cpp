#include "../libs/integer.hpp"

Integer::Integer(int i) { this->myInteger = i; }

void Integer::print(std::ostream &os) const {
  os << this->myInteger << std::endl;
}

int Integer::compareTo(const Object &obj) const { return 0; }

Integer::operator int() { return this->myInteger; }
