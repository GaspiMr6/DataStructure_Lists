#ifndef COLECCION_h
#define COLECCION_h

#include <iostream>
#include <vector>
#include "Localidad.h"


using namespace std;

class Coleccion {

	friend ostream & operator<<(ostream &, const Coleccion &);

	private:
		vector<vector<char> >mapa;
		vector<Localidad> localidades;

	public:
		Coleccion();
		~Coleccion();
		Coleccion(const Coleccion &);
		Coleccion & operator=(const Coleccion &);
		void lectura(string);
		vector<vector<char> > & getMapa();
		vector<Localidad> & getLocalidades();
		char getCoorMapa(Coordenadas);
};
#endif
