#pragma once
#ifndef TDACOLA_H
#define TDACOLA_H
#include <iostream>
#include "Alumno.h"
using namespace std;
class Cola
{
public:
	Cola();
	~Cola();
	virtual Object* frente() = 0;

	virtual void imprime_cola() = 0;

	virtual void anula() = 0;

	//Dequeue
	virtual Object* saca_de_cola() = 0;

	//Queue
	virtual void pone_en_cola(Object*) = 0;

	virtual bool vacia() = 0;
	int getCap() { return cap; }
	void setCap(int Cap) { cap = Cap; }
protected:
	Object** cola;
	int cap;
	int n;
};

#endif

