#include "ArrayStack.h"
#include <iostream>
using namespace std;
//Constructor
ArrayStack::ArrayStack() {
    capacidad = 1000;
    Stack = new Object * [capacidad];
    top = 0;
    for (int i = 0; i < capacidad; i++) {
        Stack[i] = nullptr;
    }
}
//Destructor
ArrayStack::~ArrayStack() {
    anula();
    delete[] Stack;
}
//Borrar todos los elementos de la pila
void ArrayStack::anula() {
    if (!vacia()) {
        for (int i = 0; i < top; i++) {
            delete Stack[i];
            //Liberar la memoria
            Stack[i] = nullptr;
        }
        delete[] Stack;
        Stack = new Object * [capacidad];
        top = 0;
        cout << "Se borro con exito" << "\n";
    }
    else {
        cout << "La Pila esta vacia \n";
    }
}
//Ver si la pila esta vacia
bool ArrayStack::vacia() {
    if (top > 0) {
        cout << "La pila contiene " << top << " elementos\n";
    }
    return top < 1;
}
//Sacar elemento de la pila
Object* ArrayStack::saca() {
    Object* elem_borrado = Stack[top - 1];
    const int temp_top = top;
    Object** temp_stack = new Object * [temp_top];
    for (int i = 0; i < top - 1; i++) {
        temp_stack[i] = Stack[i];
    }
    delete[] Stack;
    cout << "Se ha borrado el elemento en tope\n";
    Stack = temp_stack;
    top--;
    return elem_borrado;
}
//Imprimir los elementos de la pila
void ArrayStack::imprime_pila() {
    if (!vacia()) {
        for (int i = top - 1; i >= 0; i--) {
            cout << Stack[i]->toString() << "\n";
        }
    }
    else {
        cout << "La Pila Esta Vacia" << endl;
    }
}
//Meter un nuevo objeto en la pila
void ArrayStack::mete(Object* est) {
    const int temp_top = top + 1;
    Object** temp_stack = new Object * [temp_top];
    if (!vacia()) {
        for (int i = 0; i < top; i++) {
            temp_stack[i] = Stack[i];
        }
    }
    temp_stack[top] = est;
    cout << "Se logro meter el simbolo exitosamente\n";
    delete[] Stack;
    Stack = temp_stack;
    top++;
}
//Regresar el elemento en tope de la pila
Object* ArrayStack::tope() {
    return Stack[top - 1];
}