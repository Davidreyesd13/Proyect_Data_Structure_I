#include "Cola.h"
#include <iostream>
using namespace std;
#define NULL 0
Cola::Cola() {
	n = 0;
	cola = new Object * [cap];
	for (int i = 0; i < cap; i++)
		cola[i] = NULL;
}
Cola::~Cola() {
	anula();
	delete[] cola;
}
Object* Cola::frente() {
	if (cap == 0) {
		return nullptr; // La cola está vacía
	}
	return cola[cap];
}
void Cola::imprime_cola() {
	for (size_t i = 0; i < cap; i++){
		cout << cola[i]->toString();
	}
}
void Cola::anula() {
	for (size_t i = 0; i < cap; i++)
	{
		delete cola[i];
		cola[i] = nullptr;
	}
	n = 0;
}
Object* Cola::saca_de_cola() {
	Object* salida = nullptr;
	for (int i = cap; i > 0; i--){
		if (i == cap) {
			salida = cola[i];
			cola[i] = cola[i - 1];

		}
		else {
			cola[i] = cola[i - 1];
		}
	}
	return salida;
}
void Cola::pone_en_cola(Object* v) {
	if (n > cap) {
		cout << "No se puede agregar mas; llego a la capacidad maxima";
	}
	else {
		cola[n] = v;
		n++;
	}
}
bool Cola::vacia() {
	return n == 0;
}