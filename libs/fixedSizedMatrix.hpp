#ifndef FIXEDSIZEDMATRIX_H
#define FIXEDSIZEDMATRIX_H

#include "listAsArray.hpp"
#include "listAsVector.hpp"
#include "matrix.hpp"

/*
 * Concrete FixedSizedMatrix class.
 * A matrix class using ListAsVector and/or DynamicArrayList lists.
 */
class FixedSizedMatrix : public Matrix {
protected:
  int compareTo(Object const &) const { return 0; };
  std::unique_ptr<ListAsArray> matrix;

public:
  /*
   * Default constructor.
   */
  FixedSizedMatrix() {
    std::unique_ptr<ListAsArray> newMatrix(new ListAsVector());
    this->matrix = std::move(newMatrix);
  };
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
  ~FixedSizedMatrix(){};
  /*
   * Shrink row.
   * Shrinks the row by a specifide size.
   * @param An integer indicating the number of rows to shrink.
   */
  void shrinkRow(int amount) {
    if (this->matrix->size() == 0) {
      return;
    }
    for (size_t i = 0; i < amount; i++) {
      this->matrix->shrink();
    }
    for (size_t i = 0; i < amount; i++) {
      std::shared_ptr<ListAsArray> list =
          std::dynamic_pointer_cast<ListAsArray>((*this->matrix)[i]);
      for (size_t x = 0; x < amount; x++) {
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
    if (this->matrix->size() == 0) {
      return;
    }
    for (size_t i = 0; i < amount; i++) {
      this->matrix->shrink();
    }
    for (size_t i = 0; i < amount; i++) {
      std::shared_ptr<ListAsArray> list =
          std::dynamic_pointer_cast<ListAsArray>((*this->matrix)[i]);
      for (size_t x = 0; x < amount; x++) {
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
      std::unique_ptr<ListAsVector> newRow(new ListAsVector());
      this->matrix->insert(std::move(newRow));
    }

    // Grow the columns.
    for (size_t i = 0; i < this->size(); i++) {
      std::shared_ptr<ListAsArray> list =
          std::dynamic_pointer_cast<ListAsArray>((*this->matrix)[i]);
      for (size_t x = 0; x < (this->size() - (list->size() - 1)); x++) {
        list->grow();
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
      std::unique_ptr<ListAsVector> newRow(new ListAsVector());
      // std::shared_ptr<ListAsVector> newRow(new ListAsVector);
      this->matrix->insert(std::move(newRow));
    }

    // Grow the columns.
    for (size_t i = 0; i < this->size(); i++) {
      std::shared_ptr<ListAsArray> list =
          std::dynamic_pointer_cast<ListAsArray>((*this->matrix)[i]);
      for (size_t x = 0; x < (this->size() - (list->size() - 1)); x++) {
        list->grow();
      }
    }
  };
  /*
   * Index operator.
   * Returns the object at index.
   * @param An integer indicating the index.
   */
  std::shared_ptr<List> operator[](int i) {
    // std::shared_ptr<List> l =
    //    std::dynamic_pointer_cast<List>((*this->matrix)[i]);
    // return l;
    return std::static_pointer_cast<List>((*this->matrix)[i]);
  };

  void print(std::ostream & = std::cout) const {};
  int size() { return this->matrix->size(); }
};

#endif
