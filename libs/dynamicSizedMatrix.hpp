#ifndef DYNAMICSIZEDMATRIX_H
#define DYNAMICSIZEDMATRIX_H

#include "listAsSLL.hpp"
#include "matrix.hpp"

/*
 * Concrete DynamicSizedMatrix class.
 * A matrix class using Linked and/or Doubly-Linked lists.
 */

class DynamicSizedMatrix : public Matrix {
protected:
  int compareTo(Object const &) const;
  ListAsSLL *matrix;

public:
  /*
   * Shrink row.
   * Shrinks the row by a specifide size.
   * @param An integer indicating the number of rows to shrink.
   */
  void shrinkRow(int);
  /*
   * Shrink column.
   * Shrinks the column by a specifide size.
   * @param An integer indicating the number of columns to shrink.
   */
  void shrinkColumn(int);
  /*
   * Index operator.
   * Returns the object at index.
   * @param An integer indicating the index.
   */
  List &operator[](int);

  void print(std::ostream & = std::cout) const;
};

#endif
