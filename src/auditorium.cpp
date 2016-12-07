/**
* @Author: Thomas Scholtz <thomas>
* @Date:   2016-11-06T23:03:39+02:00
* @Email:  thomas@quantum-sicarius.za.net
* @Last modified by:   thomas
* @Last modified time: 2016-12-07T19:16:16+02:00
* @License: Attribution-NonCommercial-ShareAlike 4.0 International
*/

#include "../libs/auditorium.hpp"
Auditorium::Auditorium(std::string name) {
  this->state_ = "Empty";
  this->name_ = name;
}
std::string Auditorium::getName() { return this->name_; }

void Auditorium::setName(std::string name) { this->name_ = name; }
std::string Auditorium::getState() { return this->state_; }
void Auditorium::setState(std::string s) { this->state_ = s; }
