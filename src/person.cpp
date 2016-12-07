/**
* @Author: Thomas Scholtz <thomas>
* @Date:   2016-11-06T23:35:10+02:00
* @Email:  thomas@quantum-sicarius.za.net
* @Last modified by:   thomas
* @Last modified time: 2016-12-07T19:16:46+02:00
* @License: Attribution-NonCommercial-ShareAlike 4.0 International
*/

#include "../libs/person.hpp"

int Person::compareTo(Object const &) const { return 0; };

bool Person::isNull(void) const { return false; };
int Person::compare(Object const &) const { return 0; };
void Person::print(std::ostream &) const {};
