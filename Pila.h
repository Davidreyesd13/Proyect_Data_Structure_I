#pragma once
#ifndef TDAPILA_H
#define TDAPILA_H
#include "Object.h"
class Pila
{
public:
	Pila();
	~Pila();
	virtual void anula() = 0;
	virtual Object* tope() = 0;
	virtual void mete(Object*) = 0;//push
	virtual Object* saca() = 0;//pop
	virtual bool vacia() = 0;
	virtual void imprime_pila() = 0;
	int getSize();
	void setSize(int Size) { size = Size; }

protected:
	int size;
	Object** pila;
	int n = 0;
};

#endif