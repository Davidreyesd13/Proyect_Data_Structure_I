#include "LinkedQueue.h"
#include <iostream>
//Constructor
LinkedQueue::LinkedQueue() {
    inicio = new Nodo();
    final = new Nodo();
    inicio->setAnterior(final);
    final->setSiguiente(inicio);
    n = 0;
}
//Destructor
LinkedQueue::~LinkedQueue() {
    anula();
}
//Agregar elemento en la cola
void LinkedQueue::pone_en_cola(Object* obj) {
    Nodo* nuevo = new Nodo();
    nuevo->setItem(obj);
    if (n == 0) {
        inicio->setItem(nuevo->getItem());
        n++;
    }
    else if (n == 1) {
        final->setItem(nuevo->getItem());
        n++;
    }
    else {
        nuevo->setSiguiente(final);
        final->setAnterior(nuevo);
        Nodo* temp = new Nodo();
        temp = nuevo;
        nuevo = final;
        final = temp;
        n++;
    }
    cout << "Se ha ingresado el estudiante\n";
}
//Quitar alumno de la cola enfrente
Object* LinkedQueue::saca_de_cola() {
    Object* obj = nullptr;
    if (!vacia()) {
        obj = inicio->getItem();
        if (n == 1) {
            inicio = nullptr;
            n--;
        }
        else {
            inicio = inicio->getAnterior();
            n--;
        }
        cout << "Se ha sacado de la cola a: ";
        cout << obj->toString() << endl;
    }
    else {
        cout << "La cola esta vacia\n";
    }
    obj = nullptr;
    return obj;
}
//Regresar el primer elemento en la cola
Object* LinkedQueue::frente() {
    if (!vacia())
        return inicio->getItem();
    else
        cout << "La cola esta vacia\n"; 
    return nullptr;
}
//Verificar si la cola contiene alumnos
bool LinkedQueue::vacia() {
    if (n > 0) {
        cout << "La cola contiene " << n << " elementos\n";
    }
    return n < 1;
}
//Borrar todos los elementos de la cola
void LinkedQueue::anula() {
    if (!vacia()) {
        while (!vacia()) {
            Object* obj = saca_de_cola(); // Sacar elementos de la cola hasta que esté vacía
            delete obj; // Liberar la memoria de cada objeto
        }
        inicio = new Nodo(); // Restablecer el nodo de inicio y final
        final = new Nodo();
        inicio->setAnterior(final);
        final->setSiguiente(inicio);
        n = 0; // Establecer la cantidad de elementos en cero
        cout << "La cola ha sido anulada\n";
    }
    else {
        cout << "La cola esta ya esta vacia; no se requiere anular\n";
    }
}
//Imprimir todos los elementos no nulos de la cola
void LinkedQueue::imprime_cola() {
    Nodo* temp = inicio;
    for (int i = 0; i < n; i++) {
        cout << temp->getItem()->toString() << endl;
        temp = temp->getAnterior();
    }
}