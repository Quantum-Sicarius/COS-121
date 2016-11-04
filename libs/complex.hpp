#ifndef COMPLEX_H
#define COMPLEX_H

#include "auditoriumList.hpp"
#include <memory>
#include <vector>

class Complex {
protected:
  std::string name_;
  std::unique_ptr<AuditoriumList> complex_;

public:
  Complex(std::string name) { this->name_ = name; }
  void setName(std::string name) { this->name_ = name; }
  std::string getName() { return this->name_; }
  void addAuditorium(std::shared_ptr<Auditorium> a) {
    this->complex_->insert(a);
  }
  void removeAuditorium() {}
};

#endif
