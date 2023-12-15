#pragma once
#include "Pila.h"
#include "Object.h"
class ArrayStack : public Pila {
private:
    Object** Stack;
    int top;
    int capacidad;

public:
    ArrayStack();
    ~ArrayStack();
    void anula() override;
    bool vacia() override;
    Object* saca() override;
    void imprime_pila() override;
    void mete(Object* ladrillo) override;
    Object* tope() override;
};