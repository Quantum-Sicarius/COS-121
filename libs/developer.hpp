#ifndef DEVELOPER_H
#define DEVELOPER_H

#include "auditorium.hpp"
#include "auditoriumList.hpp"
#include "fixed.hpp"
#include <memory>
#include <vector>

class Builder {
protected:
  std::unique_ptr<Auditorium> _result;

public:
  virtual void modifyColumn(int, int) = 0;
  virtual void addRow(int) = 0;
  virtual std::unique_ptr<Auditorium> getResult() = 0;
};

class FixedAuditoriumBuilder : public Builder {
public:
  FixedAuditoriumBuilder(std::string name) {
    std::unique_ptr<Fixed> newFixed(new Fixed(name));
    this->_result = std::move(newFixed);
  }
  void modifyColumn(int row, int amount) { return; }
  void addRow(int i) { this->_result->addRow(i); }
  std::unique_ptr<Auditorium> getResult() { return std::move(this->_result); }
};

class VariableAuditoriumBuilder : public Builder {};

class Developer {
private:
  std::shared_ptr<AuditoriumList> _list;

public:
  Developer(std::shared_ptr<AuditoriumList> list) { this->_list = list; }
  void newFixedAuditorium(int size, std::string name) {
    FixedAuditoriumBuilder *b = new FixedAuditoriumBuilder(name);
    b->addRow(5);
    this->_list->appendAuditorium(b->getResult());
    // delete b;
  };
  void newVariableAuditorium(){};
};

#endif
