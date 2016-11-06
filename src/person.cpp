#include "../libs/person.hpp"

int Person::compareTo(Object const &) const { return 0; };

bool Person::isNull(void) const { return false; };
int Person::compare(Object const &) const { return 0; };
void Person::print(std::ostream &) const {};
