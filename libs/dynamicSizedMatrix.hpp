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
  int compareTo(Object const &) const { return 0; };
  std::unique_ptr<ListAsSLL> matrix;

public:
  /*
   * Default constructor.
   */
  DynamicSizedMatrix(int type = 0) {
    this->type = type;

    if (type == 1) {
      std::unique_ptr<ListAsSLL> newMatrix(new ListAsDLL());
      this->matrix = std::move(newMatrix);
    } else {
      std::unique_ptr<ListAsSLL> newMatrix(new ListAsSLL());
      this->matrix = std::move(newMatrix);
    }
  };
  /*
   * Deconstructor.
   * The deconstructor responsible for freeing back memory.
   */
  ~DynamicSizedMatrix(){};
  /*
   * Shrink row.
   * Shrinks the row by a specifide size.
   * @param An integer indicating the number of rows to shrink.
   */
  void shrinkRow(int amount = 1) {
    if (this->matrix->size() == 0) {
      return;
    }
    for (size_t i = 0; i < amount; i++) {
      this->matrix->shrink();
    }
  }
  /*
   * Shrink column.
   * Shrinks the column by a specifide size.
   * @param An integer indicating the number of columns to shrink.
   */
  void shrinkColumn(int row = 0, int amount = 1) {
    if (this->matrix->size() == 0) {
      return;
    }
    std::shared_ptr<ListAsSLL> list =
        std::dynamic_pointer_cast<ListAsSLL>((*this->matrix)[row]);
    for (size_t x = 0; x < amount; x++) {
      list->shrink();
    }
  };
  /*
   * Grow row.
   * Grows the row by a specifide size.
   * @param An integer indicating the number of rows to grow.
   */
  void growRow(int amount = 1) {
    // Grow the rows;
    for (size_t i = 0; i < amount; i++) {
      if (type == 1) {
        std::unique_ptr<ListAsSLL> newRow(new ListAsDLL());
        this->matrix->insert(std::move(newRow));
      } else {
        std::unique_ptr<ListAsSLL> newRow(new ListAsSLL());
        this->matrix->insert(std::move(newRow));
      }
    }
  };
  /*
   * Grow column.
   * Grows the column by a specifide size.
   * @param An integer indicating the number of columns to grow.
   */
  void growColumn(int row = 0, int amount = 1) {
    // Grow the columns.
    std::shared_ptr<ListAsSLL> list =
        std::dynamic_pointer_cast<ListAsSLL>((*this->matrix)[row]);
    for (size_t x = 0; x < (amount); x++) {
      std::unique_ptr<Object> newNullObject(new NullObject());
      list->insert(std::move(newNullObject));
    }
  };
  /*
   * Index operator.
   * Returns the object at index.
   * @param An integer indicating the index.
   */
  std::shared_ptr<List> operator[](int i) {
    return std::static_pointer_cast<List>((*this->matrix)[i]);
  };

  void print(std::ostream & = std::cout) const {};
  int size() { return this->matrix->size(); }
};

#endif
