/**
* @Author: Thomas Scholtz <thomas>
* @Date:   2016-11-06T23:52:38+02:00
* @Email:  thomas@quantum-sicarius.za.net
* @Last modified by:   thomas
* @Last modified time: 2016-12-07T19:16:22+02:00
* @License: Attribution-NonCommercial-ShareAlike 4.0 International
*/

#include "../libs/developer.hpp"

Developer::Developer(std::shared_ptr<AuditoriumList> list) {
  this->_list = list;
}
void Developer::newFixedAuditorium(int size, std::string name) {
  std::unique_ptr<FixedAuditoriumBuilder> b(new FixedAuditoriumBuilder(name));
  b->addRow(size);
  this->_list->appendAuditorium(b->getResult());
};
void Developer::newVariableAuditorium(int size, std::string name) {
  std::unique_ptr<VariableAuditoriumBuilder> b(
      new VariableAuditoriumBuilder(name));
  b->addRow(size);
  this->_list->appendAuditorium(b->getResult());
};
