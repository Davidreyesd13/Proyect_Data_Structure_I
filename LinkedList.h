#pragma once
#ifndef LINKEDLIST_H
#define LINKEDLIST_H
using namespace std;
#include "TDALista.h"
#include "Nodo.hpp"

class LinkedList : public TDALista
{
public:
	LinkedList();
	~LinkedList();
	virtual void anula();
	virtual bool inserta(Object*, int);
	virtual Object* siguiente(int);
	virtual Object* anterior(int);
	virtual void imprimir_lista();
	virtual Object* suprime(int);
	virtual Object* recupera(int);
	virtual void localiza(int cuenta);
	virtual Object* primero();
	virtual bool vacia();

protected:
	Nodo* inicio;
	Nodo* final;
	int n;
};

#endif