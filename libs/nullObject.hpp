#ifndef NULLOBJECT_H
#define NULLOBJECT_H

#include "object.hpp"

class NullObject : public Object {
protected:
int compareTo ( Object const&) const;
public:
NullObject ( void );
~NullObject ( void );
int compare ( Object const& ) const;
bool isNull ( void ) const;
void print ( std::ostream& = std::cout ) const;
};

#endif