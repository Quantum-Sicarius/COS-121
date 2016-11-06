#include "../libs/auditorium.hpp"
Auditorium::Auditorium(std::string name) {
  this->state_ = "Empty";
  this->name_ = name;
}
std::string Auditorium::getName() { return this->name_; }

void Auditorium::setName(std::string name) { this->name_ = name; }
std::string Auditorium::getState() { return this->state_; }
void Auditorium::setState(std::string s) { this->state_ = s; }
