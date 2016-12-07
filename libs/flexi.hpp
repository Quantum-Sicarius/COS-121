/**
* @Author: Thomas Scholtz <thomas>
* @Date:   2016-11-03T20:03:08+02:00
* @Email:  thomas@quantum-sicarius.za.net
* @Last modified by:   thomas
* @Last modified time: 2016-12-07T19:17:19+02:00
* @License: Attribution-NonCommercial-ShareAlike 4.0 International
*/

#ifndef FLEXI_H
#define FLEXI_H

#include "auditorium.hpp"
#include "flexiMatrix.hpp"
#include <memory>

class Flexi : public Auditorium {
private:
  std::unique_ptr<FlexiMatrix> layout;

public:
  Flexi() {
    std::unique_ptr<FlexiMatrix> newLayout(new FlexiMatrix());
    this->layout = std::move(newLayout);
  }

  ~Flexi() { this->layout.reset(); }
};
;

#endif
