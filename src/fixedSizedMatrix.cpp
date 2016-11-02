#include "../libs/fixedSizedMatrix.hpp"
#include "../libs/listAsVector.hpp"
#include "../libs/nullObject.hpp"

template <typename T> FixedSizedMatrix<T>::FixedSizedMatrix() {
  // TODO: SPECIFY whick type of arraylist to use.

  this->matrix = new ListAsVector<T>();
}
template <typename T> FixedSizedMatrix<T>::~FixedSizedMatrix() {
  this->matrix = 0;
}
template <typename T> void FixedSizedMatrix<T>::shrinkRow(int i) {}
template <typename T> void FixedSizedMatrix<T>::shrinkColumn(int i) {}
template <typename T> void FixedSizedMatrix<T>::growRow(int amount) {
  for (int i = 0; i < amount; i++) {
    this->matrix->grow();
    // ListAsVector *column = new ListAsVector();
    // this->matrix->insert(column);
  }

  // this->growColumn(amount);
}
template <typename T> void FixedSizedMatrix<T>::growColumn(int i) {
  for (int i = 0; i < this->matrix->size(); i++) {
    ((this->matrix)[i]).grow();
  }
}
template <typename T> List<T> &FixedSizedMatrix<T>::operator[](int i) {
  return this->matrix[i];
}
template <typename T> int FixedSizedMatrix<T>::compareTo(Object const &) const {
  return 0;
}
template <typename T> void FixedSizedMatrix<T>::print(std::ostream &o) const {}
