/**
* @Author: Thomas Scholtz <thomas>
* @Date:   2016-11-06T23:19:04+02:00
* @Email:  thomas@quantum-sicarius.za.net
* @Last modified by:   thomas
* @Last modified time: 2016-12-07T19:17:15+02:00
* @License: Attribution-NonCommercial-ShareAlike 4.0 International
*/

#ifndef FIXED_H
#define FIXED_H

#include "auditorium.hpp"
#include "fixedSizedMatrix.hpp"
#include "seat.hpp"
#include <memory>

class Fixed : public Auditorium {
private:
  std::unique_ptr<FixedSizedMatrix> layout;

protected:
  int compareTo(Object const &) const;

  void setToSeat();

public:
  Fixed(std::string name);

  void addRow(int i);

  int getRows();
  int getColSize(int i);
  void addSeatsInRow(int row, int amount);
  std::shared_ptr<Seat> getSeat(int row, int col);

  ~Fixed();

  bool isNull(void) const;
  int compare(Object const &) const;
  void print(std::ostream & = std::cout) const;
};

#endif
