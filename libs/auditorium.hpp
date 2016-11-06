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
