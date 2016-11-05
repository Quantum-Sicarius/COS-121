#ifndef COMPLEX_H
#define COMPLEX_H

#include "auditoriumList.hpp"
#include "developer.hpp"
#include <memory>
class Complex {
protected:
  std::string name_;
  std::shared_ptr<AuditoriumList> complex_;
  std::unique_ptr<std::string> _id;

public:
  Complex(std::string name) {
    this->name_ = name;
    std::shared_ptr<AuditoriumList> list(new AuditoriumList());
    this->complex_ = list;

    std::unique_ptr<Developer> d(new Developer(complex_));

    d->newFixedAuditorium(5, "Fixed Auditorium 1");
    d->newFixedAuditorium(5, "Fixed Auditorium 2");
    d->newVariableAuditorium(5, "Variable Auditorium 1");
  }
  void setName(std::string name) { this->name_ = name; }
  std::string getName() { return this->name_; }
  void addAuditorium(std::shared_ptr<Auditorium> a) {
    this->complex_->appendAuditorium(a);
  }
  std::shared_ptr<Auditorium> at(int i) { return this->complex_->at(i); }
  int getSize() { return this->complex_->getSize(); }
  void removeAuditorium() {}
};

#endif
