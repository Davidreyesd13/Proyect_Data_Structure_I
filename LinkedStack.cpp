#include "LinkedStack.h"
#include <iostream>
using namespace std;
//Constructor
LinkedStack::LinkedStack() {
    inicio = nullptr;
    top = 0;
}
//Destructor
LinkedStack::~LinkedStack() {
    anula();
}
//Borrar tope de la pila
void LinkedStack::anula() {
    delete inicio;
    top = 0;
}
//Ver si la pila esta vacia
bool LinkedStack::vacia() {
    if (top > 0) {
        cout << "La pila contiene " << top << " elementos\n";
    }
    return top < 1;
}
//Quitar elemento en tope de la pila
Object* LinkedStack::saca() {
    if (top > 1) {
        Nodo* tempstack = inicio;
        Nodo* regresa = inicio;
        tempstack = tempstack->getSiguiente();
        inicio = tempstack;
        inicio->setAnterior(nullptr);
        top--;
        return regresa->getItem();
        cout << "Se ha borrado el elemento\n";
    }
    else {
        Nodo* regresa = inicio;
        inicio = nullptr;
        top--;
        return regresa->getItem();
    }
}
//Imprimir todos los elementos de la pila
void LinkedStack::imprime_pila() {
    Nodo* temp = inicio;
    for (int i = 0; i < top; i++) {
        cout << temp->getItem()->toString() << endl;
        temp = temp->getSiguiente();
    }
}
//Meter objeto en la pila
void LinkedStack::mete(Object* bloquee) {
    if (vacia()) {
        inicio = new Nodo(bloquee);
    }
    else {
        Nodo* temporal = inicio;
        inicio = new Nodo(bloquee);
        inicio->setSiguiente(temporal);
    }
    top++;
    cout << "Se logro ingresar el elemento\n";
}
//Regresar el elemento en tope
Object* LinkedStack::tope() {
    Nodo* tempstack = inicio;
    return tempstack->getItem();
}