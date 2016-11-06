#include "../libs/seat.hpp"

int Seat::compareTo(Object const &) const { return 0; };

Seat::Seat() {
  this->taken = false;
  this->seatedPerson = std::make_unique<NullPersonObject>(NullPersonObject());
}
std::shared_ptr<Person> Seat::getPerson() { return this->seatedPerson; }
void Seat::setPerson(std::shared_ptr<Person> p) {
  if (this->taken) {
    throw "This seat is taken!";
  }
  this->seatedPerson = p;
  this->taken = true;
}

void Seat::removePerson() {
  this->seatedPerson = std::make_unique<NullPersonObject>(NullPersonObject());
  this->taken = false;
}

bool Seat::isTaken() { return this->taken; }

void Seat::print(std::ostream &o) const {};
