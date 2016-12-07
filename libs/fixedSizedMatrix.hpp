/**
* @Author: Thomas Scholtz <thomas>
* @Date:   2016-11-06T23:26:25+02:00
* @Email:  thomas@quantum-sicarius.za.net
* @Last modified by:   thomas
* @Last modified time: 2016-12-07T19:17:17+02:00
* @License: Attribution-NonCommercial-ShareAlike 4.0 International
*/

#ifndef FIXEDSIZEDMATRIX_H
#define FIXEDSIZEDMATRIX_H

#include "dynamicArrayList.hpp"
#include "listAsArray.hpp"
#include "listAsVector.hpp"
#include "matrix.hpp"

/*
 * Concrete FixedSizedMatrix class.
 * A matrix class using ListAsVector and/or DynamicArrayList lists.
 */
class FixedSizedMatrix : public Matrix {
private:
  int type = 0;

protected:
  int compareTo(Object const &) const;
  std::unique_ptr<ListAsArray> matrix;

public:
  /*
   * Default constructor.
   */
  FixedSizedMatrix(int type = 0);
  /*
   * Constructor.
   * Constructor parsed with the ListAsArray object to use.
   * @param The ListAsArray object
   */
  // FixedSizedMatrix(const ListAsArray **&l) { this->matrix = l; };
  /*
   * Deconstructor.
   * The deconstructor responsible for freeing back memory.
   */
  ~FixedSizedMatrix();
  /*
   * Shrink row.
   * Shrinks the row by a specifide size.
   * @param An integer indicating the number of rows to shrink.
   */
  void shrinkRow(int amount = 1);
  /*
   * Shrink column.
   * Shrinks the column by a specifide size.
   * @param An integer indicating the number of columns to shrink.
   */
  void shrinkColumn(int row = 0, int amount = 1);
  /*
   * Grow row.
   * Grows the row by a specifide size.
   * @param An integer indicating the number of rows to grow.
   */
  void growRow(int amount = 1);
  /*
   * Grow column.
   * Grows the column by a specifide size.
   * @param An integer indicating the number of columns to grow.
   */
  void growColumn(int row = 0, int amount = 1);
  /*
   * Index operator.
   * Returns the object at index.
   * @param An integer indicating the index.
   */
  std::shared_ptr<List> operator[](int i);

  void print(std::ostream & = std::cout) const;
  int size();
};

#endif
