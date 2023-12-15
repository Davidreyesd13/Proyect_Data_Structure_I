#pragma once
#ifndef OBJECT_H
#define OBJECT_H

#include <string>

class Object {
public:
    virtual bool equals(const Object* otro) const = 0;
    virtual std::string toString() const = 0;
    virtual ~Object() {} // Agregar destructor virtual en la clase base

protected:
};

#endif