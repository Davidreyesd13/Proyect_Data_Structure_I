#pragma once
#include <string>
#include "Object.h"
using namespace std;
class Alumno : public Object
{
protected:
	string nombre;
	int cuenta;
public:
	Alumno();
	Alumno(string nombre, int cuenta);
	~Alumno();
	string getNombre();
	int getCuenta();
	bool equals(const Object* otro) const override;
	string toString() const override;

};

