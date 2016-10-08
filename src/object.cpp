#include "../libs/object.hpp"

Object::~Object ( void ) {

}
bool Object::isNull ( void ) const {
        return false;
}
int Object::compare ( Object const&) const {
        return 0;
}
