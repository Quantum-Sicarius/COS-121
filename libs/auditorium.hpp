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
  Auditorium(std::string name) {
    this->state_ = "Empty";
    this->name_ = name;
  }
  std::string getName() { return this->name_; }

  void setName(std::string name) { this->name_ = name; }
  std::string getState() { return this->state_; }
  void setState(std::string s) { this->state_ = s; }

  virtual void addRow(int) = 0;
  virtual void addSeatInRow(int row, int amount) = 0;
  virtual std::shared_ptr<Seat> getSeat(int row, int col) = 0;
};

#endif
