#include "Arraylist.h"
#include <iostream>
#define NULL 0
using namespace std;
//Constructor
ArrayList::ArrayList() {
	n = 0;
	capacidad = 100;
	array = new Object * [capacidad];
	for (int i = 0; i < capacidad; i++)
		array[i] = NULL;
}
//Destructor
ArrayList::~ArrayList() {
	anula();
	delete[] array;
}
//Borrar todo el ArrayList
void ArrayList::anula() {
	for (int i = 0; i < capacidad; i++) {
		delete array[i];
		//Assignar nullptr a array[i] asegura que no habra problemas con la memoria
		array[i] = nullptr;
	}
	n = 0;
}
//Inserter Estudiante en la posicion especificada
bool ArrayList::inserta(Object* obj, int pos) {
	if (pos < 0 || n >= capacidad) {
		return false; // No se puede insertar en la posición especificada
	}
	// Inserta el nuevo elemento en la posición especificada
	array[pos] = obj;
	n++;
	return true;
}
//Demuestra el siguiente elemento en la lista despues de la posicion especificada
Object* ArrayList::siguiente(int pos) {
	if (pos < 0 || pos >= capacidad - 1) {
		return nullptr; // No hay elemento siguiente
	}
	return array[pos + 1];
}
//Demuestra el elemento anterior en la lista despues de la posicion especificada
Object* ArrayList::anterior(int pos) {
	if (pos <= 0 || pos >= capacidad) {
		return nullptr; 
		// No hay elemento anterior
	}
	return array[pos - 1];
}
//Imprimir los elementos dentro de la lista
void ArrayList::imprimir_lista() {
	for (int i = 0; i < capacidad; i++) {
		if (array[i] == NULL) {
		}
		else {
			//Llama el metodo toString del objeto Alumno
			cout << array[i]->toString() << " \n";
		}
	}
	cout << endl;
}
//Borrar el elemento en la posicion especificada
Object* ArrayList::suprime(int pos) {
	if (pos < 0 || pos >= capacidad) {
		cout << "No se pudo borrar lo pedido \n";
		return nullptr; // No se puede suprimir en la posición especificada
	}
	Object* eliminado = array[pos];
	cout << "El objeto ha sido eliminado\n";
	// Desplaza los elementos a la izquierda para llenar el espacio vacío
	for (int i = pos; i < capacidad - 1; i++) {
		array[i] = array[i + 1];
	}
	n--;
	return eliminado;
}
//Regresar el elemento en la posicion especificada
Object* ArrayList::recupera(int pos) {
	if (pos < 0 || pos >= n) {
		return nullptr; // Posición fuera de rango
	}
	return array[pos];
}
//Encontrar el elemento por numero de cuenta especificada
void ArrayList::localiza(int cuenta) {
	int posicion = -1;
	for (int i = 0; i < capacidad; i++) {
		Alumno* alumno = dynamic_cast<Alumno*>(array[i]);
		if (alumno && alumno->getCuenta() == cuenta) {
			posicion = i;
			cout << "Se encontro un alumno con ese numero de cuenta en la posicion: " << posicion << endl;
			cout << alumno->toString() << endl;
			break;  // Termina la búsqueda una vez encontrado el primer alumno
		}
	}

	if (posicion == -1) {
		cout << "No se encontro un alumno con ese numero de cuenta" << endl;
	}

}
Object* ArrayList::obtenerElementoEnPosicion(int pos) const {
	if (pos >= 0 && pos < capacidad) {
		return array[pos];
	}
	else {
		return nullptr; // Posicion invalida
	}
}
//Regresa el primer elemento en la lista
Object* ArrayList::primero() {
	if (n == 0) {
		return nullptr; // La lista está vacía
	}
	return array[0];
}
//Ver si la lista esta vacia
bool ArrayList::vacia() {
	if (n > 0) {
		cout << "La lista contiene " << n << " elemento(s)\n";
	}
	return n == 0;
}