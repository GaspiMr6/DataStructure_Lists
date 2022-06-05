#ifndef COORDENADAS_h
#define COORDENADAS_h

#include <iostream>

using namespace std;

class Coordenadas{

	friend ostream & operator<<(ostream &, const Coordenadas &);

	private:
		int fila, columna;

	public:

		Coordenadas();
		Coordenadas(int n1, int n2);
		~Coordenadas();
		Coordenadas (const Coordenadas &);
		Coordenadas & operator=(const Coordenadas &);
		bool operator==(const Coordenadas &);
		int getFila();
		int getColumna();
};

#endif