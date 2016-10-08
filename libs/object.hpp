#ifndef OBJECT_H
#define OBJECT_H

#include <iostream>

class Object {
protected:
virtual int compareTo ( Object const&) const = 0;
public:
virtual ~Object ( void ) = default;
virtual bool isNull ( void ) const = 0;
virtual int compare ( Object const&) const = 0;
virtual void print ( std::ostream& = std::cout ) const = 0;
};

#endif
