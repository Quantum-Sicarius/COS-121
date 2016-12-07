/**
* @Author: Thomas Scholtz <thomas>
* @Date:   2016-11-06T23:07:25+02:00
* @Email:  thomas@quantum-sicarius.za.net
* @Last modified by:   thomas
* @Last modified time: 2016-12-07T19:17:01+02:00
* @License: Attribution-NonCommercial-ShareAlike 4.0 International
*/

#ifndef AUDITORIUM_H
#define AUDITORIUM_H

#include "object.hpp"
#include "seat.hpp"
#include <memory>
#include <string>

class Auditorium : public Object {
protected:
  std::string state_;
  std::string name_;

public:
  Auditorium(std::string);
  std::string getName();

  void setName(std::string);
  std::string getState();
  void setState(std::string);

  virtual void addRow(int) = 0;
  virtual void addSeatsInRow(int row, int amount) = 0;
  virtual int getRows() = 0;
  virtual int getColSize(int) = 0;
  virtual std::shared_ptr<Seat> getSeat(int row, int col) = 0;
};

#endif
