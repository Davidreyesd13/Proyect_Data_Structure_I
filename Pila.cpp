#include "Pila.h"
#include <iostream>
using namespace std;
int Pila::getSize() { 
	return size;
}
Pila::Pila() {
	int n = 0;//variable de control de acceso
	pila = new Object * [size];//se crea la pila
	for (int i = 0; i < Pila::getSize(); i++)
		pila[i] = NULL;
}
Pila::~Pila() {
	anula();
	delete[] pila;
}
void Pila::anula() {
	for (size_t i = 0; i < Pila::getSize(); i++)
	{
		delete pila[i];
		pila[i] = nullptr;
	}
	n = 0;
}

Object* Pila::tope() {
	return pila[Pila::getSize()];
}
void Pila::mete(Object* o) {
	if (n < Pila::getSize()) {
		//se ingresa la pila y se incrementa para que vaya cambiando la posicion siempre va en incremento
		pila[n] = o;
		n++;
	}
	else {
		cout << "Capacidad Maxima de la pila";
	}
}
bool Pila::vacia() {
	return size == 0;
}
void Pila::imprime_pila() {
	for (size_t i = Pila::getSize(); i > 0; i--)
	{
		cout << pila[i] << "\n";
	}
}