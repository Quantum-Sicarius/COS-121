/**
* @Author: Thomas Scholtz <thomas>
* @Date:   2016-10-11T15:42:46+02:00
* @Email:  thomas@quantum-sicarius.za.net
* @Last modified by:   thomas
* @Last modified time: 2016-12-07T19:17:33+02:00
* @License: Attribution-NonCommercial-ShareAlike 4.0 International
*/

#ifndef NULLOBJECT_H
#define NULLOBJECT_H

#include "object.hpp"

class NullObject : public Object {
protected:
  int compareTo(Object const &) const;

public:
  bool isNull(void) const;
  void print(std::ostream & = std::cout) const;
};

#endif
