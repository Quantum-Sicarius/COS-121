#include "../libs/fixedSizedMatrix.hpp"
#include "../libs/listAsVector.hpp"
#include "../libs/nullObject.hpp"

FixedSizedMatrix::FixedSizedMatrix() {
        // TODO: SPECIFY whick type of arraylist to use.

        this->matrix = new ListAsVector();
}

FixedSizedMatrix::~FixedSizedMatrix() {
        this->matrix = 0;
}

void FixedSizedMatrix::shrinkRow(int i) {

}

void FixedSizedMatrix::shrinkColumn(int i) {

}

void FixedSizedMatrix::growRow(int amount) {
        for (int i = 0; i < amount; i++) {
                this->matrix->grow();
                //ListAsVector *column = new ListAsVector();
                //this->matrix->insert(column);
        }

        //this->growColumn(amount);
}

void FixedSizedMatrix::growColumn(int i) {
        for (int i = 0; i < this->matrix->size(); i++) {
                ((this->matrix)[i]).grow();
        }
}

List& FixedSizedMatrix::operator[](int i) {
        return this->matrix[i];
}

int FixedSizedMatrix::compareTo ( Object const&) const {
        return 0;
}

void FixedSizedMatrix::print ( std::ostream& o ) const {

}
