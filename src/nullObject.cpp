#include "../libs/nullObject.hpp"
#include <typeinfo>

int NullObject::compareTo(Object const &) const { return 0; }

bool NullObject::isNull(void) const { return true; }

void NullObject::print(std::ostream &os) const {
  os << "NullObject" << std::endl;
}
