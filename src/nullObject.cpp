#include "../libs/nullObject.hpp"
#include <typeinfo>

NullObject::NullObject ( void ) {
}
NullObject::~NullObject ( void ) {
}

int NullObject::compare ( Object const& o ) const {
        if (typeid(o) == typeid(*this)) {
                return 1;
        }
        return 0;
}

bool NullObject::isNull ( void ) const {
        return true;
}
int NullObject::compareTo ( Object const& obj ) const {
        return 0;
}
void NullObject::print ( std::ostream& os ) const {
        os << "NullObject"  << std::endl;
}
