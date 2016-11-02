#ifndef MATRIX_H
#define MATRIX_H

#include "container.hpp"
#include "list.hpp"

/*
 * Abstract Matrix class.
 * The abstract class for all matrices.
 */
template <typename T> class Matrix : public Container<T> {
public:
  /*
   * Virtual Deconstructor.
   * The abstract deconstructor.
   */
  virtual ~Matrix() = default;
  /*
   * Shrink row.
   * Shrinks the row by a specifide size.
   * @param An integer indicating the number of rows to shrink.
   */
  virtual void shrinkRow(int) = 0;
  /*
   * Shrink column.
   * Shrinks the column by a specifide size.
   * @param An integer indicating the number of columns to shrink.
   */
  virtual void shrinkColumn(int) = 0;
  /*
   * Grow row.
   * Grows the row by a specifide size.
   * @param An integer indicating the number of rows to grow.
   */
  virtual void growRow(int) = 0;
  /*
   * Grow column.
   * Grows the column by a specifide size.
   * @param An integer indicating the number of columns to grow.
   */
  virtual void growColumn(int) = 0;
  /*
   * Index operator.
   * Returns the object at index.
   * @param An integer indicating the index.
   */
  virtual List<T> &operator[](int) = 0;
};

#endif
