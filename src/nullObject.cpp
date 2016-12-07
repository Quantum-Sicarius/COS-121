/**
* @Author: Thomas Scholtz <thomas>
* @Date:   2016-10-11T15:42:01+02:00
* @Email:  thomas@quantum-sicarius.za.net
* @Last modified by:   thomas
* @Last modified time: 2016-12-07T19:16:44+02:00
* @License: Attribution-NonCommercial-ShareAlike 4.0 International
*/

#include "../libs/nullObject.hpp"
#include <typeinfo>

int NullObject::compareTo(Object const &) const { return 0; }

bool NullObject::isNull(void) const { return true; }

void NullObject::print(std::ostream &os) const {
  os << "NullObject" << std::endl;
}
