/**
* @Author: Thomas Scholtz <thomas>
* @Date:   2016-10-11T15:42:34+02:00
* @Email:  thomas@quantum-sicarius.za.net
* @Last modified by:   thomas
* @Last modified time: 2016-12-07T19:17:21+02:00
* @License: Attribution-NonCommercial-ShareAlike 4.0 International
*/

#ifndef INTEGER_H
#define INTEGER_H

#include "object.hpp"

class Integer : public Object {
protected:
  int myInteger;
  int compareTo(Object const &) const;

public:
  Integer(int);
  void print(std::ostream &os) const;
  operator int();
};

#endif
