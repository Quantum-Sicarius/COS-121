/**
* @Author: Thomas Scholtz <thomas>
* @Date:   2016-11-04T15:58:39+02:00
* @Email:  thomas@quantum-sicarius.za.net
* @Last modified by:   thomas
* @Last modified time: 2016-12-07T19:17:32+02:00
* @License: Attribution-NonCommercial-ShareAlike 4.0 International
*/

#ifndef MINOR_H
#define MINOR_H

#include "person.hpp"

class Minor : public Person {
private:
  bool _isChild;

public:
  Minor(bool isChild) { this->_isChild = isChild; }
};

#endif
