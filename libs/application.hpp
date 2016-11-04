#ifndef APPLICATION_H
#define APPLICATION_H

#include "complexList.hpp"
#include <memory>

class Application {
private:
  std::unique_ptr<ComplexList> complexes_;
};

class Subject {
  std::vector<class Observer *> views;
  int value;

public:
  void attach(Observer *obs) { views.push_back(obs); }
  void setVal(int val) {
    value = val;
    notify();
  }
  int getVal() { return value; }
  void notify();
};

class Observer {
  Subject *model;
  int denom;

public:
  Observer(Subject *mod, int div) {
    model = mod;
    denom = div;
    model->attach(this);
  }
  virtual void update() = 0;

protected:
  Subject *getSubject() { return this->model; }
  int getDivisor() { return this->denom; }
};

void Subject::notify() {
  for (int i = 0; i < views.size(); i++)
    this->views[i]->update();
}

class CommandLineObserver : public Observer {
public:
  CommandLineObserver(Subject *mod, int div) : Observer(mod, div) {}
  void update() { int v = getSubject()->getVal(), d = getDivisor(); }
};

#endif
