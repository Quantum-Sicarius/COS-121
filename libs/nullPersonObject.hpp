/**
* @Author: Thomas Scholtz <thomas>
* @Date:   2016-11-04T14:24:38+02:00
* @Email:  thomas@quantum-sicarius.za.net
* @Last modified by:   thomas
* @Last modified time: 2016-12-07T19:17:34+02:00
* @License: Attribution-NonCommercial-ShareAlike 4.0 International
*/

#ifndef NULLPERSONOBJECT_H
#define NULLPERSONOBJECT_H

#include "nullObject.hpp"
#include "object.hpp"
#include "person.hpp"

class NullPersonObject : public Person {
protected:
  int compareTo(Object const &) const { return 0; };

public:
  bool isNull(void) const { return true; };
  int compare(Object const &) const { return 0; };
  void print(std::ostream & = std::cout) const {};
};

#endif
