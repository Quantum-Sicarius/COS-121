#ifndef AUDITORIUM_LIST_H
#define AUDITORIUM_LIST_H

#include "application.hpp"
#include "list.hpp"
#include <memory>

class AuditoriumList : public Application {
private:
  std::unique_ptr<List> auditoriumList;

public:
};

#endif
