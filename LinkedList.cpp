#include "LinkedList.h"
#include <iostream>
#include "Alumno.h"

using namespace std;

#define NULL 0
//Constructor
LinkedList::LinkedList() {
	Nodo* inicio = nullptr;
	int n = 0;
}
//Destructor
LinkedList::~LinkedList() {
	if (!vacia()) {
		delete inicio;
		inicio = nullptr;
		n = 0;
	}
}
//Borra todos los elementos de la lista
void LinkedList::anula() {
	if (!vacia()) {
		delete inicio;
		inicio = nullptr;
		n = 0;
	}
	else { 
		cout << "La lista esta vacia.\n"; 
	}
}

//Inserta un elemento en la posicion especificada
bool LinkedList::inserta(Object* obj, int pos) {
	if (obj != nullptr && pos >= 1 && pos <= n + 1) {
		if (!inicio && pos == 1) {
			// Agregar a la lista cuando esta vacia
			inicio = new Nodo(nullptr, obj);
		}
		else {
			Nodo* aux = inicio, * nuevo = new Nodo(obj);
			if (pos == n + 1) {
				// Agregar al final de la lista
				while (aux->getSiguiente())
					aux = aux->getSiguiente();
				aux->setSiguiente(nuevo);
				nuevo->setAnterior(aux);
			}
			else {
				// Agregar en una posicion ocupada
				int i = 0;
				while (aux) {
					i++;
					if (i == pos) {
						nuevo->setSiguiente(aux);
						if (i == 1) {
							nuevo->setAnterior(NULL);
							inicio = nuevo;
						}
						if (aux->getAnterior())
							aux->getAnterior()->setSiguiente(nuevo);
						nuevo->setAnterior(aux->getAnterior());
						aux->setAnterior(nuevo);
						break;
					}
					aux = aux->getSiguiente();
				}
			}
		}
		n++;
	}
	return (obj != nullptr && pos >= 1 && pos <= n + 1);
}

//Retorna el elemento siguiente de la posicion especeficada
Object* LinkedList::siguiente(int pos) {
	if (!vacia()) {
		if (pos >= 1 && pos <= n - 1) {
			Nodo* aux = inicio;
			int i = 0;
			while (aux) {
				i++;
				if (i == pos + 1)
					return aux->getItem();
				aux = aux->getSiguiente();
			}
		}
	}
	return nullptr;
}

//Retorna el elemento anterior de la posicion especeficada
Object* LinkedList::anterior(int pos) {
	if (!vacia() && pos >= 2 && pos <= n) {
		Nodo* aux = inicio;
		int i = 0;
		while (aux) {
			i++;
			if (i == pos - 1)
				return aux->getItem();
			aux = aux->getSiguiente();
		}
	}
	return nullptr;
}

void append(Object* obj) {
	//Este metodo solo existe para hacer nada
}

//Imprimir todos los elementos de la lista
void LinkedList::imprimir_lista() {
	if (!vacia()) {
		Nodo* aux = inicio;
		while (aux) {
			cout << aux->getItem()->toString() << endl;
			aux = aux->getSiguiente();
		}
	}
	else { 
		cout << "La lista esta vacia.\n"; 
	}
}

//Elimina un elemento de la lista
Object* LinkedList::suprime(int pos) {
	if (!vacia()) {
		if (pos >= 1 && pos <= n) {
			Nodo* aux = inicio;
			int i = 0;
			while (aux) {
				i++;
				if (i == pos) {
					if (pos == 1 && n == 1)
						// Si el unico elemento es el inicio y se pide a borrar
						inicio = NULL;
					if (aux->getAnterior())
						aux->getAnterior()->setSiguiente(aux->getSiguiente());
					if (aux->getSiguiente())
						aux->getSiguiente()->setAnterior(aux->getAnterior());
					n--;
					return aux->getItem();
					cout << "Se ha eliminado el objeto\n";
				}
				aux = aux->getSiguiente();
			}
		}
	}
	else { 
		cout << "La lista esta vacia.\n"; 
	}
	return nullptr;
}

//Retorna el objeto en la posicion especeficada
Object* LinkedList::recupera(int pos) {
	if (!vacia() && pos >= 1 && pos <= n) {
		Nodo* aux = inicio;
		int i = 0;
		while (aux) {
			i++;
			if (i == pos)
				return aux->getItem();
			aux = aux->getSiguiente();
		}
	}
	return nullptr;
}

//Retorna la posicion del objeto ingresado
void LinkedList::localiza(int cuenta) {
	int posicion = 1; 
	Nodo* actual = inicio; 
	while (actual != nullptr) {
		Alumno* alumno = dynamic_cast<Alumno*>(actual->getItem()); 
		if (alumno != nullptr && alumno->getCuenta() == cuenta) {
			cout << "Alumno encontrado en la posición " << posicion << ":\n" ;
			cout << alumno->toString() << endl;
			return; // Terminamos la búsqueda una vez encontrado el primer alumno
		}
		actual = actual->getSiguiente();
		posicion++;
	}
	// Si no se encontró el alumno
	cout << "Alumno con número de cuenta " << cuenta << " no encontrado en la lista\n";

}
//Regresar el primer objeto de la lista
Object* LinkedList::primero() {
	if (!vacia())
		return inicio->getItem();
	else
		cout << "La lista no tiene elementos\n";
	return nullptr;
	return nullptr;
}

bool LinkedList::vacia() {
	if (n > 0) {
		cout << "La lista contiene " << n << " elemento(s)\n";
	}
	return n < 1;
}