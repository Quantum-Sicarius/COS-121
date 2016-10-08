#include "../libs/integer.hpp"

Integer::Integer(int i) {
        this->myInteger = i;
}

bool Integer::isNull ( void ) const {
        return false;
}

void Integer::print ( std::ostream& os ) const {
        os << this->myInteger  << std::endl;
}

int Integer::compare ( Object const& b) const {
        return 0;
}


int Integer::compareTo(const Object& obj) const {
        return 0;
}

Integer::operator int(){
        return this->myInteger;
}
