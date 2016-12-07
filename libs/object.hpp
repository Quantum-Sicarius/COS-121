/**
* @Author: Thomas Scholtz <thomas>
* @Date:   2016-11-06T23:26:31+02:00
* @Email:  thomas@quantum-sicarius.za.net
* @Last modified by:   thomas
* @Last modified time: 2016-12-07T19:17:36+02:00
* @License: Attribution-NonCommercial-ShareAlike 4.0 International
*/

#ifndef OBJECT_H
#define OBJECT_H

#include <iostream>

class Object {
protected:
  virtual int compareTo(Object const &) const = 0;

public:
  virtual ~Object(void);
  virtual bool isNull(void) const;
  virtual int compare(Object const &) const;
  virtual void print(std::ostream & = std::cout) const = 0;
};

#endif
