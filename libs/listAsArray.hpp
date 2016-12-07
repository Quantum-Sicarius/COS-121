/**
* @Author: Thomas Scholtz <thomas>
* @Date:   2016-11-04T15:18:13+02:00
* @Email:  thomas@quantum-sicarius.za.net
* @Last modified by:   thomas
* @Last modified time: 2016-12-07T19:17:25+02:00
* @License: Attribution-NonCommercial-ShareAlike 4.0 International
*/

#ifndef LISTASARRAY_H
#define LISTASARRAY_H

#include "list.hpp"

class ListAsArray : public List {
public:
  virtual int size() = 0;
  virtual void insert(std::shared_ptr<Object>) = 0;
  virtual void remove(std::shared_ptr<Object>) = 0;
  virtual std::shared_ptr<Object> &operator[](int) = 0;
  virtual void print(std::ostream & = std::cout) const = 0;
};

#endif
