#include "Simbolo.h"
Simbolo::Simbolo() {}
Simbolo::~Simbolo() {}
Simbolo::Simbolo(char simbolo) {
	this->simbolo = simbolo;
}
bool Simbolo::equals(const Object* otro) const{
	const Simbolo* otroSimbolo = dynamic_cast<const Simbolo*>(otro);
	if (otroSimbolo) {
		return simbolo == otroSimbolo->simbolo;
	}
	return false;
}
string Simbolo::toString() const {
	string message = "| ";
	message += simbolo;
	message += " |";
	return message;
}
