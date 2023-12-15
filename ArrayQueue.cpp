#include "ArrayQueue.h"
#include <iostream>
//Constructor
ArrayQueue::ArrayQueue() {
    capacidad = 100;
    cola = new Object * [capacidad];
    ic = 0;
    for (int i = 0; i < capacidad; i++) {
        cola[i] = nullptr;
    }
}
//Destructor
ArrayQueue::~ArrayQueue() {
    anula();
    delete[] cola;
}
//Regresar el primer elemento de la cola
Object* ArrayQueue::frente() {
    if (!vacia())
        return cola[ic - 1];
    else {
        cout << "La lista no tiene elementos\n";
        return nullptr;
    }
}
//Imprime las elementos de la cola
void ArrayQueue::imprime_cola() {
    if (!vacia()) {
        cout << "Numero de alumnos registrados : " << ic << endl;
        for (int i = ic - 1; i >= 0; i--) {
            //Imprimir el toString del objeto
            cout << cola[i]->toString() << endl;
        }
    }
    else {
        cout << "La cola esta vacia\n";
    }
}
//Borrar todos los elementos de la cola y liberar memoria
void ArrayQueue::anula() {
    if (!vacia()) {
        for (int i = 0; i < ic; i++) {
            delete cola[i];
            //Liberar la memoria
            cola[i] = nullptr;
        }
        cout << "Se han borrado todos los elementos\n";
        delete[] cola;
        cola = new Object * [capacidad];
        ic = 0;
    }
    else {
        cout << "La lista esta vacia\n";
    }
}
//Sacar el primer objeto en la cola
Object* ArrayQueue::saca_de_cola() {
    Object* obj = nullptr;
    if (!vacia()) {
        obj = cola[ic - 1];
        cola[ic - 1] = nullptr;
        ic--;
        cout << "Se ha sacado de la cola a: ";
        cout << obj->toString() << endl;
    }
    else {
        cout << "La cola esta vacia" << std::endl;
    }
    return obj;
}
//Agregar objeto a la cola
void ArrayQueue::pone_en_cola(Object* obj) {
    const int tam = ic + 1;
    Object** aux = new Object * [tam];
    if (ic == 0) {
        aux[0] = obj;
    }
    else {
        for (int i = 0; i < ic; i++) {
            aux[i + 1] = cola[i];
        }
        aux[0] = obj;
    }
    cout << "Se logro poner en la cola un estudiate\n";
    delete[] cola;
    cola = aux;
    ic++;
}
//Ver si la cola esta vacia
bool ArrayQueue::vacia() {
    if (ic > 0) {
        cout << "La cola contiene " << ic << " elementos\n";
    }
    return ic < 1;
}