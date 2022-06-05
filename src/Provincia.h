#ifndef PROVINCIA_H
#define PROVINCIA_H

#include <iostream>
#include <vector>
#include "Localidad.h"
#include "LNear.h"
#include "Coleccion.h"

class Provincia{

	friend ostream & operator<<(ostream &, const Provincia &);

	private:
		Localidad lc;
		LNear locprox;

	public:
		Provincia();
		Provincia(Localidad l);
		~Provincia();
		Provincia(const Provincia &);
		Provincia & operator=(const Provincia &);
		void calculaCercanas(Coleccion &, int);
		int borraLocalidad(string);
		LNear & getCercanas();
		string getCostera(Coleccion &);
		LNear getCosteras(Coleccion &);
		string getConAeropuerto();
		bool esta_en_coleccion(Localidad &, Coleccion &);
};
#endif