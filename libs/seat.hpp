/**
* @Author: Thomas Scholtz <thomas>
* @Date:   2016-11-06T23:33:18+02:00
* @Email:  thomas@quantum-sicarius.za.net
* @Last modified by:   thomas
* @Last modified time: 2016-12-07T19:17:41+02:00
* @License: Attribution-NonCommercial-ShareAlike 4.0 International
*/

#ifndef SEAT_H
#define SEAT_H

#include "nullPersonObject.hpp"
#include "object.hpp"
#include "person.hpp"
#include <memory>

class Seat : public Object {
protected:
  std::shared_ptr<Person> seatedPerson;
  int compareTo(Object const &) const;
  bool taken;

public:
  Seat();
  std::shared_ptr<Person> getPerson();
  void setPerson(std::shared_ptr<Person> p);

  void removePerson();

  bool isTaken();

  void print(std::ostream &o = std::cout) const;
};

#endif
