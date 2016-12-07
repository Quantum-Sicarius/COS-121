/**
* @Author: Thomas Scholtz <thomas>
* @Date:   2016-11-06T17:57:53+02:00
* @Email:  thomas@quantum-sicarius.za.net
* @Last modified by:   thomas
* @Last modified time: 2016-12-07T19:16:59+02:00
* @License: Attribution-NonCommercial-ShareAlike 4.0 International
*/

#ifndef ADULT_H
#define ADULT_H

#include "person.hpp"

class Adult : public Person {
protected:
  int compareTo(Object const &) const { return 0; };

public:
  bool isNull(void) const { return false; };
  int compare(Object const &) const { return 0; };
  void print(std::ostream & = std::cout) const {};
};

#endif
