#ifndef DEVELOPER_H
#define DEVELOPER_H

#include "auditorium.hpp"
#include "auditoriumList.hpp"
#include "fixed.hpp"
#include "variable.hpp"
#include <memory>
#include <vector>

class Builder {
protected:
  std::unique_ptr<Auditorium> _result;

public:
  virtual void addSeatInRow(int, int) = 0;
  virtual void addRow(int) = 0;
  virtual std::unique_ptr<Auditorium> getResult() = 0;
};

class FixedAuditoriumBuilder : public Builder {
public:
  FixedAuditoriumBuilder(std::string name) {
    std::unique_ptr<Fixed> newFixed(new Fixed(name));
    this->_result = std::move(newFixed);
  }
  void addSeatInRow(int row, int amount) { return; }
  void addRow(int i) { this->_result->addRow(i); }
  std::unique_ptr<Auditorium> getResult() { return std::move(this->_result); }
};

class VariableAuditoriumBuilder : public Builder {
public:
  VariableAuditoriumBuilder(std::string name) {
    std::unique_ptr<Variable> newVariable(new Variable(name));
    this->_result = std::move(newVariable);
  }
  void addSeatInRow(int row, int amount) {
    this->_result->addSeatsInRow(row, amount);
  }
  void addRow(int i) { this->_result->addRow(i); }
  std::unique_ptr<Auditorium> getResult() { return std::move(this->_result); }
};

class Developer {
private:
  std::shared_ptr<AuditoriumList> _list;

public:
  Developer(std::shared_ptr<AuditoriumList> list) { this->_list = list; }
  void newFixedAuditorium(int size, std::string name) {
    std::unique_ptr<FixedAuditoriumBuilder> b(new FixedAuditoriumBuilder(name));
    b->addRow(size);
    this->_list->appendAuditorium(b->getResult());
  };
  void newVariableAuditorium(int size, std::string name) {
    std::unique_ptr<VariableAuditoriumBuilder> b(
        new VariableAuditoriumBuilder(name));
    b->addRow(size);
    this->_list->appendAuditorium(b->getResult());
  };
};

#endif
