/**
* @Author: Thomas Scholtz <thomas>
* @Date:   2016-11-06T23:14:05+02:00
* @Email:  thomas@quantum-sicarius.za.net
* @Last modified by:   thomas
* @Last modified time: 2016-12-07T19:16:24+02:00
* @License: Attribution-NonCommercial-ShareAlike 4.0 International
*/

#include "../libs/dynamicSizedMatrix.hpp"

int DynamicSizedMatrix::compareTo(Object const &) const { return 0; };

/*
 * Default constructor.
 */
DynamicSizedMatrix::DynamicSizedMatrix(int type) {
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
DynamicSizedMatrix::~DynamicSizedMatrix(){};
/*
 * Shrink row.
 * Shrinks the row by a specifide size.
 * @param An integer indicating the number of rows to shrink.
 */
void DynamicSizedMatrix::shrinkRow(int amount = 1) {
  if (this->matrix->size() == 0) {
    return;
  }
  for (size_t i = 0; i < amount; i++) {
    this->matrix->shrink(1);
  }
}
/*
 * Shrink column.
 * Shrinks the column by a specifide size.
 * @param An integer indicating the number of columns to shrink.
 */
void DynamicSizedMatrix::shrinkColumn(int row = 0, int amount = 1) {
  if (this->matrix->size() == 0) {
    return;
  }
  std::shared_ptr<ListAsSLL> list =
      std::dynamic_pointer_cast<ListAsSLL>((*this->matrix)[row]);
  for (size_t x = 0; x < amount; x++) {
    list->shrink(1);
  }
};
/*
 * Grow row.
 * Grows the row by a specifide size.
 * @param An integer indicating the number of rows to grow.
 */
void DynamicSizedMatrix::growRow(int amount = 1) {
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
void DynamicSizedMatrix::growColumn(int row = 0, int amount = 1) {
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
std::shared_ptr<List> DynamicSizedMatrix::operator[](int i) {
  return std::static_pointer_cast<List>((*this->matrix)[i]);
};

void DynamicSizedMatrix::print(std::ostream &) const {};
int DynamicSizedMatrix::size() { return this->matrix->size(); }
