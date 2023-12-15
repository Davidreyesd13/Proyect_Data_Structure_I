#pragma once
#include "Pila.h"
#include "Nodo.hpp"

class LinkedStack : public Pila {
private:
    Nodo* inicio;
    int top;

public:
    LinkedStack();
    ~LinkedStack();
    void anula() override;
    bool vacia() override;
    Object* saca() override;
    void imprime_pila() override;
    void mete(Object* bloquee) override;
    Object* tope() override;
};