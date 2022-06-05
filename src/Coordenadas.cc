#include "Coordenadas.h"

Coordenadas::Coordenadas(){

	fila = -1;
	columna = -1;
}

Coordenadas::Coordenadas(int f, int c){

	if(f >= 0 && c >= 0) {

		fila = f;
		columna = c;
	}

	else {
			
		fila = -1;
		columna = -1;
	}
}

Coordenadas::Coordenadas(const Coordenadas &c){

	fila = c.fila;
	columna = c.columna;
}

Coordenadas::~Coordenadas(){

	fila = -1;
	columna = -1;
}

Coordenadas & Coordenadas::operator=(const Coordenadas &c){

	if(this != &c){

		fila = c.fila;
		columna = c.columna;
	}

	return *this;
}

bool Coordenadas::operator==(const Coordenadas &c){

	bool dev = false;

	if(fila==c.fila && columna ==c.columna) {

		dev = true;
	}

	return dev;

}


int Coordenadas::getFila(){

	return fila;
}

int Coordenadas::getColumna(){

  return columna;
}

ostream & operator<<(ostream &os, const Coordenadas &c){

	os << "(" << c.fila << "," << c.columna<< ")";
	
	return os;
}
