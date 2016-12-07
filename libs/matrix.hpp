/**
* @Author: Thomas Scholtz <thomas>
* @Date:   2016-11-06T23:43:37+02:00
* @Email:  thomas@quantum-sicarius.za.net
* @Last modified by:   thomas
* @Last modified time: 2016-12-07T19:17:30+02:00
* @License: Attribution-NonCommercial-ShareAlike 4.0 International
*/

#ifndef MATRIX_H
#define MATRIX_H

#include "container.hpp"
#include "list.hpp"

/*
 * Abstract Matrix class.
 * The abstract class for all matrices.
 */
class Matrix : public Container {
public:
  /*
   * Shrink row.
   * Shrinks the row by a specifide size.
   * @param An integer indicating the number of rows to shrink.
   */
  virtual void shrinkRow(int) = 0;
  /*
   * Shrink column.
   * Shrinks the column by a specifide size.
   * @param row An integer indicating the row.
   * @param amount An integer indicating the number of columns to shrink.
   */
  virtual void shrinkColumn(int, int) = 0;
  /*
   * Grow row.
   * Grows the row by a specifide size.
   * @param An integer indicating the number of rows to grow.
   */
  virtual void growRow(int) = 0;
  /*
   * Grow column.
   * Grows the column by a specifide size.
   * @param row An integer indicating the row.
   * @param An integer indicating the number of columns to grow.
   */
  virtual void growColumn(int, int) = 0;
  /*
   * Index operator.
   * Returns the object at index.
   * @param An integer indicating the index.
   */
  virtual std::shared_ptr<List> operator[](int) = 0;
};

#endif
