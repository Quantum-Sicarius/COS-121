/**
* @Author: Thomas Scholtz <thomas>
* @Date:   2016-10-11T15:42:04+02:00
* @Email:  thomas@quantum-sicarius.za.net
* @Last modified by:   thomas
* @Last modified time: 2016-12-07T19:16:45+02:00
* @License: Attribution-NonCommercial-ShareAlike 4.0 International
*/

#include "../libs/object.hpp"

Object::~Object(void) {}
bool Object::isNull(void) const { return false; }
int Object::compare(Object const &) const { return 0; }
