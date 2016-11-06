#ifndef DYNAMICSIZEDMATRIX_H
#define DYNAMICSIZEDMATRIX_H

#include "listAsDLL.hpp"
#include "listAsSLL.hpp"
#include "matrix.hpp"
#include "nullObject.hpp"

/*
 * Concrete DynamicSizedMatrix class.
 * A matrix class using Linked and/or Doubly-Linked lists.
 */
class DynamicSizedMatrix : public Matrix {
private:
  int type = 0;

protected:
  int compareTo(Object const &) const;
  std::unique_ptr<ListAsSLL> matrix;

public:
  /*
   * Default constructor.
   */
  DynamicSizedMatrix(int type = 0);
  /*
   * Deconstructor.
   * The deconstructor responsible for freeing back memory.
   */
  ~DynamicSizedMatrix();
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
  void shrinkColumn(int, int);
  /*
   * Grow row.
   * Grows the row by a specifide size.
   * @param An integer indicating the number of rows to grow.
   */
  void growRow(int);
  /*
   * Grow column.
   * Grows the column by a specifide size.
   * @param An integer indicating the number of columns to grow.
   */
  void growColumn(int, int);
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
