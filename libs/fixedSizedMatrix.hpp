#ifndef FIXEDSIZEDMATRIX_H
#define FIXEDSIZEDMATRIX_H

#include "listAsArray.hpp"
#include "matrix.hpp"

/*
 * Concrete FixedSizedMatrix class.
 * A matrix class using ListAsVector and/or DynamicArrayList lists.
 */
template <typename T> class FixedSizedMatrix : public Matrix<T> {
protected:
  int compareTo(Object const &) const;
  ListAsArray<T> *matrix;

public:
  /*
   * Default constructor.
   */
  FixedSizedMatrix();
  /*
   * Constructor.
   * Constructor parsed with the ListAsArray object to use.
   * @param The ListAsArray object
   */
  FixedSizedMatrix(const ListAsArray<T> &);
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
  void shrinkRow(int);
  /*
   * Shrink column.
   * Shrinks the column by a specifide size.
   * @param An integer indicating the number of columns to shrink.
   */
  void shrinkColumn(int);
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
  void growColumn(int);
  /*
   * Index operator.
   * Returns the object at index.
   * @param An integer indicating the index.
   */
  List<T> &operator[](int);

  void print(std::ostream & = std::cout) const;
};

#endif
