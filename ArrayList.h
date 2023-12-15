#pragma once
#ifndef ARRAYLIST_H
#define ARRAYLIST_H

#include "TDALista.h"
#include "Alumno.h"
class ArrayList : public TDALista
{
public:
	ArrayList();
	~ArrayList();
	virtual void anula();
	virtual bool inserta(Object*, int);
	virtual Object* siguiente(int);
	virtual Object* anterior(int);
	virtual void imprimir_lista();
	virtual Object* suprime(int);
	virtual Object* recupera(int);
	virtual void localiza(int);
	virtual Object* primero();
	virtual bool vacia();
	Object* obtenerElementoEnPosicion(int pos)const;

protected:
	Object** array;
	int capacidad;
	int n;
};

#endif