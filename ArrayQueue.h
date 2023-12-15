#pragma once
#include "Cola.h"

class ArrayQueue : public Cola {
private:
    Object** cola;
    int ic;
    int capacidad;

public:
    ArrayQueue();
    ~ArrayQueue();

    Object* frente();
    void imprime_cola();
    void anula();
    Object* saca_de_cola();
    void pone_en_cola(Object* obj);
    bool vacia();
};