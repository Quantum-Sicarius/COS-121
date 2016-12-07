/**
* @Author: Thomas Scholtz <thomas>
* @Date:   2016-11-06T22:57:03+02:00
* @Email:  thomas@quantum-sicarius.za.net
* @Last modified by:   thomas
* @Last modified time: 2016-12-07T19:17:44+02:00
* @License: Attribution-NonCommercial-ShareAlike 4.0 International
*/

#ifndef VARIABLE_H
#define VARIABLE_H

#include "auditorium.hpp"
#include "dynamicSizedMatrix.hpp"

class Variable : public Auditorium {
private:
  std::unique_ptr<DynamicSizedMatrix> layout;

protected:
  int compareTo(Object const &) const;

public:
  Variable(std::string);
  /*
   * Adds seats into row from 0.
   */
  void addSeatsInRow(int row, int amount);
  /*
   * Add a seat at any Row/Col fill empty spaces with NullObjects.
   */
  void addSeat(int row, int col);

  void removeSeat(int row, int col);

  void addRow(int i);
  std::shared_ptr<Seat> getSeat(int row, int col);

  int getRows();
  int getColSize(int i);

  ~Variable();

  bool isNull(void) const;
  int compare(Object const &) const;
  void print(std::ostream & = std::cout) const;
};

#endif
