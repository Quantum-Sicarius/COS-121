/**
* @Author: Thomas Scholtz <thomas>
* @Date:   2016-10-11T15:41:38+02:00
* @Email:  thomas@quantum-sicarius.za.net
* @Last modified by:   thomas
* @Last modified time: 2016-12-07T19:16:33+02:00
* @License: Attribution-NonCommercial-ShareAlike 4.0 International
*/

#include "../libs/integer.hpp"

Integer::Integer(int i) { this->myInteger = i; }

void Integer::print(std::ostream &os) const {
  os << this->myInteger << std::endl;
}

int Integer::compareTo(const Object &obj) const { return 0; }

Integer::operator int() { return this->myInteger; }
