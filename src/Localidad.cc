#include <vector>
#include "Localidad.h"


Localidad::Localidad(){

	nombre = "";
	coor = Coordenadas();
	info = InfoTur();
	id = -1;
}


Localidad::Localidad(string s){

	nombre = s;
	coor = Coordenadas();
	info = InfoTur();
	id = -1;
}

Localidad::Localidad(const Localidad &l){

	nombre = l.nombre;
	coor = l.coor;
	info = l.info;
	id = l.id;
}

Localidad::~Localidad(){

	nombre = ""; 
	coor = Coordenadas();
	info = InfoTur();
	id = -1;
}

Localidad & Localidad::operator=(const Localidad &l){

	if (this != &l) {

		nombre = l.nombre;
		coor = l.coor;
		info = l.info;
		id = l.id;
	}
	return *this;
}

bool Localidad::operator==(const Localidad &l){

	if (nombre == l.nombre && coor == l.coor && info == l.info && id == l.id){

		return true;
	}
	return false;
}


//bool Localidad::esCostera(Coleccion c){
bool Localidad::esCostera(vector<vector<char> > c){

	int x = getCoor().getFila();
	int y = getCoor().getColumna();

	//if(c.getMapa()[x-1][y] == 'M' || c.getMapa()[x+1][y] == 'M' || c.getMapa()[x][y-1] == 'M' || c.getMapa()[x][y+1] == 'M')
	if(c[x-1][y] == 'M' || c[x+1][y] == 'M' || c[x][y-1] == 'M' || c[x][y+1] == 'M')
		return true;

	else return false;
}

int Localidad::distancia(Localidad l){

	int n1 = getCoor().getFila();
	int n2 = getCoor().getColumna();

	int dist = (abs(n1 - l.getCoor().getFila()) + abs(n2-l.getCoor().getColumna()));
	return dist;
}

int Localidad::distancia(int x1, int x2){

	int n1 = getCoor().getFila();
	int n2 = getCoor().getColumna();

	int dist = (abs(n1 - x1) + abs(n2-x2));
	return dist;
}

int Localidad::setCoor(int n1, int n2,  vector<vector<char> > &m){
//int Localidad::setCoor(int n1, int n2, const vector<vector<char> > &m){


	int dev = -1;

	unsigned int valor1 = n1;
	unsigned int valor2 = n2;

	if(coor.getFila() == -1 && coor.getColumna() == -1 &&  valor1 < m.size() &&  valor2 < m[0].size() && m[n1][n2] == 'T'){

		coor = Coordenadas(n1, n2);
		m[n1][n2] = 'L';
		dev = m[0].size() * n1 + n2;
		id = dev;
	}
	return dev;
}


void Localidad::setInfo(InfoTur i){

	info = i;
}

string Localidad::getNombre(){

	return nombre;
}

string Localidad::getNombre() const{

	return nombre;
}

Coordenadas Localidad::getCoor(){

	return coor;
}

InfoTur Localidad::getInfo(){

	return info;
}

int Localidad::getId(){

	return id;
}


ostream & operator<<(ostream &os, const Localidad &l) {

	os << l.id << "-" << l.nombre << "-" << l.coor << endl << l.info;

	return os;
}



