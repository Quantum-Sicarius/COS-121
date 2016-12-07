/**
* @Author: Thomas Scholtz <thomas>
* @Date:   2016-11-06T23:35:01+02:00
* @Email:  thomas@quantum-sicarius.za.net
* @Last modified by:   thomas
* @Last modified time: 2016-12-07T19:17:38+02:00
* @License: Attribution-NonCommercial-ShareAlike 4.0 International
*/

#ifndef PERSON_H
#define PERSON_H

#include "object.hpp"

class Person : public Object {
protected:
  int compareTo(Object const &) const;

public:
  bool isNull(void) const;
  int compare(Object const &) const;
  void print(std::ostream & = std::cout) const;
};

#endif
