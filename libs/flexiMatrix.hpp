#ifndef FLEXIMATRIX_H
#define FLEXIMATRIX_H

#include "matrix.hpp"
#include "listAsDLL.hpp"

/*
 * Concrete FlexiMatrix class.
 * A matrix class using Doubly-Linked lists.
 */

class FlexiMatrix : public Matrix {
protected:
int compareTo ( Object const&) const;
ListAsDLL *matrix;
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
List& operator[](int);

void print ( std::ostream& = std::cout ) const;

};

#endif
