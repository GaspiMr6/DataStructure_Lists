#ifndef LNEAR_h
#define LNEAR_h

#include <iostream>
#include <vector>
#include "Coleccion.h"

class LNear{

friend ostream & operator<<(ostream &, const LNear &);
//friend class NodoL;

private: 
	class NodoL;
	NodoL *pr;
	NodoL *ul;
	Localidad error;

public: 
	LNear();
	~LNear();
	LNear(const LNear &);
	LNear & operator=(const LNear &);
	bool esVacia();
	int rango();
	void insertaLocalidad(Localidad,int);
	int borraLocalidad(string);
	void borraLocalidades(int);
	int num_nodos();
	Localidad & getLocalidad(int);
	void borra_memoria(int);

};


class LNear::NodoL{

	//ostream & operator<<(ostream &, const NodoL &);
	friend ostream & operator<<(ostream &os, const NodoL &c){

		os << c.localidad.getNombre() << " (" << c.distancia << ")";
		return os;
	}


	
	/*private: 
	Localidad localidad;
	int distancia;
	NodoL *next;
	NodoL *prev;
	*/

	public: 
	//NodoL(); hay?
	Localidad localidad;
	int distancia;
	NodoL *next;
	NodoL *prev;

	NodoL(Localidad n){

		localidad = n;
		distancia = -1;
		//deberia estar bien next = NULL
		next = NULL;
		prev = NULL;
		//next = new NodoL;
		//prev = new NodoL; 
	}
	
	NodoL(Localidad n, int d){

		localidad = n;
		distancia = d;
		//deberia estar bien next = NULL
		next = NULL;
		prev = NULL;
		//next = new NodoL;
		//prev = new NodoL;
	}

	~NodoL(){

		localidad = Localidad();
		distancia = -1;
		next = NULL;
		prev = NULL;	
	}

	NodoL(const NodoL &n){

		localidad = n.localidad;
		distancia = n.distancia;
		next = n.next;
		prev = n.prev; 
	}

	NodoL & operator=(const NodoL &n){

		if (this != &n) {

			//if(next != NULL) delete next;
			//if(prev != NULL) delete prev; no creo
			//if(n.next != NULL)

			//* esta bien o tambien tenemos que hacer que n.next = NULL
			localidad = n.localidad;
			distancia = n.distancia;
			next = n.next;
			prev = n.prev;
		}
		return *this;
	}
	/*
	Localidad getLocalidad(){

		return localidad;
	}
	int getDistancia(){

		return distancia;
	}
	*/

};


#endif