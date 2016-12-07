/**
* @Author: Thomas Scholtz <thomas>
* @Date:   2016-11-06T22:52:23+02:00
* @Email:  thomas@quantum-sicarius.za.net
* @Last modified by:   thomas
* @Last modified time: 2016-12-07T19:17:23+02:00
* @License: Attribution-NonCommercial-ShareAlike 4.0 International
*/

#ifndef LIST_H
#define LIST_H

#include "container.hpp"
#include <memory>

class List : public Container {
public:
  virtual void insert(std::shared_ptr<Object>) = 0;
  virtual void remove(std::shared_ptr<Object>) = 0;
  virtual void shrink(int amount = 1) = 0;
  virtual void grow(int amount = 1) = 0;
  virtual std::shared_ptr<Object> &operator[](int) = 0;
  virtual int size() = 0;
};

#endif
