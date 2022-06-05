#ifndef LOCALIDAD_h
#define LOCALIDAD_h

#include <iostream>
#include <vector>
#include "Coordenadas.h"
#include "InfoTur.h"


using namespace std;

class Localidad {

	friend ostream & operator<<(ostream &, const Localidad &);

	private:
		string nombre;
		Coordenadas coor;
		InfoTur info;
		int id;

	public:
		Localidad();
		Localidad(string);
		Localidad(const Localidad &);
		~Localidad();
		Localidad & operator=(const Localidad &);
		bool operator==(const Localidad &);
		int setCoor(int, int, vector<vector<char> > &);
		//int setCoor(int, int, const vector<vector<char> > &);
		void setInfo(InfoTur);
		string getNombre();
		string getNombre() const;
		Coordenadas getCoor();
		InfoTur getInfo();
		int getId();
		bool esCostera(vector<vector<char> >);
		int distancia(Localidad);
		int distancia(int, int);
};

#endif
