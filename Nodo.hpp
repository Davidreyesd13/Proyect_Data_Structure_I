#pragma once
#include "Object.h"
#define NULL 0

class Nodo {
public:
    // Constructor y destructor
    Nodo() {
        siguiente = NULL;
        item = NULL;
        anterior = NULL;
    }

    Nodo(Nodo* ant, Object* obj) : anterior(ant), item(obj), siguiente(NULL) {}

    Nodo(Object* obj) : anterior(NULL), item(obj), siguiente(NULL) {}
    ~Nodo() {
        if (siguiente)
            delete siguiente;
        if (item)
            delete item;
    }

    // Getters y Setters
    Nodo* getSiguiente() { return siguiente; }
    Nodo* getAnterior() { return anterior; }
    Object* getItem() { return item; }

    void setSiguiente(Nodo* sig) { siguiente = sig; }
    void setAnterior(Nodo* ant) { anterior = ant; }
    void setItem(Object* obj) { item = obj; }

protected:
    Nodo* siguiente;
    Object* item;
    Nodo* anterior;
};