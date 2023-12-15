#pragma once
#include "Cola.h"
#include "Nodo.hpp"

class LinkedQueue : public Cola {
private:
    Nodo* inicio;
    Nodo* final;
    int n;

public:
    LinkedQueue();
    ~LinkedQueue();
    void pone_en_cola(Object* obj);
    Object* saca_de_cola();
    Object* frente();
    bool vacia() override;
    void anula() override;
    void imprime_cola();
};