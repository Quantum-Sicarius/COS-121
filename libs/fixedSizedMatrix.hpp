#ifndef FIXEDSIZEDMATRIX_H
#define FIXEDSIZEDMATRIX_H

#include "listAsArray.hpp"
#include "listAsVector.hpp"
#include "matrix.hpp"

/*
 * Concrete FixedSizedMatrix class.
 * A matrix class using ListAsVector and/or DynamicArrayList lists.
 */
template <typename T> class FixedSizedMatrix : public Matrix<T> {
protected:
  int compareTo(Object const &) const { return 0; };
  std::unique_ptr<std::vector<std::unique_ptr<ListAsArray<T>>>> matrix;

public:
  /*
   * Default constructor.
   */
  FixedSizedMatrix() {
    std::unique_ptr<std::vector<std::unique_ptr<ListAsArray<T>>>> newMatrix(
        new std::vector<std::unique_ptr<ListAsArray<T>>>);
    this->matrix = std::move(newMatrix);
  };
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
  ~FixedSizedMatrix() { this->matrix.reset(); };
  /*
   * Shrink row.
   * Shrinks the row by a specifide size.
   * @param An integer indicating the number of rows to shrink.
   */
  void shrinkRow(int amount) {
    if (this->matrix->capacity() == 0) {
      return;
    }
    this->matrix->resize(this->matrix->capacity() - amount);

    for (auto &list : *(this->matrix)) // access by reference to avoid copying
    {
      for (size_t i = 0; i < amount; i++) {
        list->shrink();
      }
    }
  }
  /*
   * Shrink column.
   * Shrinks the column by a specifide size.
   * @param An integer indicating the number of columns to shrink.
   */
  void shrinkColumn(int amount) {
    if (this->matrix->capacity() == 0) {
      return;
    }
    this->matrix->resize(this->matrix->capacity() - amount);

    for (auto &list : *(this->matrix)) // access by reference to avoid copying
    {
      for (size_t i = 0; i < amount; i++) {
        list->shrink();
      }
    }
  };
  /*
   * Grow row.
   * Grows the row by a specifide size.
   * @param An integer indicating the number of rows to grow.
   */
  void growRow(int amount) {
    // Grow the rows;
    for (size_t i = 0; i < amount; i++) {
      std::unique_ptr<ListAsVector<T>> newRow(new ListAsVector<T>);
      this->matrix->push_back(std::move(newRow));
    }

    // Grow the columns.
    for (auto &column : *(this->matrix)) // access by reference to avoid copying
    {
      for (size_t i = 0; i < (this->matrix->size() - (column->size() - 1));
           i++) {
        column->grow();
      }
    }
  };
  /*
   * Grow column.
   * Grows the column by a specifide size.
   * @param An integer indicating the number of columns to grow.
   */
  void growColumn(int amount) {
    // Grow the rows;
    for (size_t i = 0; i < amount; i++) {
      std::unique_ptr<ListAsVector<T>> newRow(new ListAsVector<T>);
      this->matrix->push_back(std::move(newRow));
    }

    // Grow the columns.
    for (auto &column : *(this->matrix)) // access by reference to avoid copying
    {
      for (size_t i = 0; i < (this->matrix->size() - (column->size() - 1));
           i++) {
        column->grow();
      }
    }
  };
  /*
   * Index operator.
   * Returns the object at index.
   * @param An integer indicating the index.
   */
  ListAsArray<T> &operator[](int i) { return *this->matrix->at(i); };

  void print(std::ostream & = std::cout) const {};
  int size() { return this->matrix->size(); }
};

#endif
