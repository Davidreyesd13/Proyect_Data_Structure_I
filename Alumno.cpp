#include "Alumno.h"
Alumno::Alumno() {
}
Alumno::~Alumno() {

}

Alumno::Alumno(string nombre, int cuenta) {
	this->nombre = nombre;
	this->cuenta = cuenta;
}
string Alumno::getNombre() {
	return nombre;
}
int Alumno::getCuenta() {
	return cuenta;
}
bool Alumno::equals(const Object* otro) const {
    const Alumno* otroAlumno = dynamic_cast<const Alumno*>(otro);
    if (otroAlumno) {
        // Compara el nombre y el número de cuenta del otroAlumno
        return nombre == otroAlumno->nombre && cuenta == otroAlumno->cuenta;
    }
    return false; // No es un objeto Alumno
}

string Alumno::toString() const {
    return "Nombre: " + nombre + "| Numero de Cuenta: " + to_string(cuenta) + "|";
}
