#ifndef AUDITORIUM_LIST_H
#define AUDITORIUM_LIST_H

#include "auditorium.hpp"
#include <memory>
#include <vector>

class AuditoriumList {
private:
  std::unique_ptr<std::vector<std::shared_ptr<Auditorium>>> auditoriumList_;

public:
  AuditoriumList() {
    this->auditoriumList_ =
        std::make_unique<std::vector<std::shared_ptr<Auditorium>>>(
            std::vector<std::shared_ptr<Auditorium>>());
  }
  void appendAuditorium(std::shared_ptr<Auditorium> a) {
    for (size_t i = 0; i < this->auditoriumList_->size(); i++) {
      if (a->getName() == this->auditoriumList_->at(i)->getName()) {
        throw "You can not have an auditorium with the same name";
      }
    }
    this->auditoriumList_->push_back(std::move(a));
  }
  void deleteAuditorium(int i) {
    this->auditoriumList_->erase(this->auditoriumList_->begin() + i);
  }
  std::shared_ptr<Auditorium> at(int i) { return this->auditoriumList_->at(i); }
  int getSize() { return this->auditoriumList_->size(); }
};

#endif
