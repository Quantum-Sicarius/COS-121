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
