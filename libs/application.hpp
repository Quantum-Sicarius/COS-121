#ifndef APPLICATION_H
#define APPLICATION_H

#include "adult.hpp"
#include "complexList.hpp"
#include "developer.hpp"
#include "reservation.hpp"
#include <memory>
#include <menu.h>
#include <ncurses.h>

class Application {
private:
  std::unique_ptr<ComplexList> _complexes;
  std::unique_ptr<std::vector<std::shared_ptr<Reservation>>> _reservations;

public:
  Application() {
    this->_reservations =
        std::make_unique<std::vector<std::shared_ptr<Reservation>>>(
            std::vector<std::shared_ptr<Reservation>>());
    this->_complexes = std::make_unique<ComplexList>(ComplexList());

    std::unique_ptr<Complex> c1(new Complex("Complex 1"));
    std::unique_ptr<Complex> c2(new Complex("Complex 2"));
    std::unique_ptr<Complex> c3(new Complex("Complex 3"));

    this->_complexes->appendComplex(std::move(c1));
    this->_complexes->appendComplex(std::move(c2));
    this->_complexes->appendComplex(std::move(c3));

    std::unique_ptr<Reservation> r(new Reservation("Reservation 1"));

    std::shared_ptr<Person> p(new Adult());
    r->operator<<(p);

    r->reserve(0, this->_complexes->at(0)->at(0));

    this->_reservations->push_back(std::move(r));
  }

  void start();
  void newComplexForm();
  void listComplexes();
  void listReservations();
  void newReservation();
  void listAuditoriums(std::shared_ptr<Complex>);
  void viewComplex(std::shared_ptr<Complex>);
  void viewAuditorium(std::shared_ptr<Auditorium>);
  void viewSeats(std::shared_ptr<Auditorium>);
  void addSeats(std::shared_ptr<Auditorium>);
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

class CommandLineObserver : public Observer {
public:
  CommandLineObserver(Subject *mod, int div) : Observer(mod, div) {}
  void update() { int v = getSubject()->getVal(), d = getDivisor(); }
};

#endif
