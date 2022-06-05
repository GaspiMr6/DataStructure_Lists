
#include <fstream>
#include <vector>
#include <string>
#include <stdio.h>
#include <sstream>
#include <stdlib.h>
#include "Coleccion.h"



Coleccion::Coleccion(){

	//mapa = vector< vector <char> >();
	//localidades = vector<Localidad>();

}

Coleccion::~Coleccion(){

	mapa.clear(); 
	localidades.clear();
	//localidades = vector<Localidad>();
}

//copia
Coleccion::Coleccion(const Coleccion &c){

	mapa = c.mapa;
	localidades = c.localidades;
}

Coleccion & Coleccion::operator=(const Coleccion &c){

	if (this != &c) {

		mapa = c.mapa;
		localidades = c.localidades;
	}
	return *this;
}

void Coleccion::lectura(string f){

	string lin;

	//int tam_cago = f.length();
    //    char cago[tam_cago];
	//strcpy(cago, f.c_str());
	

	ifstream fichero(f.c_str());

	if(!fichero){

		//cerr<<"ERROR en lectura de fichero"<<endl;
		//exit(-1);
	}

	string s;
	string linea;
	
	//getline(fichero,s);

	int cont = 0;
      //  while(s != "<LOCALIDAD>"){
	while(getline(fichero,linea) && linea != "<LOCALIDAD>"){
		vector<char> v;

		int tam = linea.length();
		//char array[tam];
		//strcpy(array, linea.c_str());

		for(int i=0; i<tam; i++){

			v.push_back(linea[i]);
		}

		mapa.push_back(v);
		cont++;
		//getline(fichero,s);
	}
	int ciudades = 0;
	bool cont_ciudades = false;

       
//if (! (fichero.eof()))
	//tengo LOCALIDAD
	while(getline(fichero,s)){

		Localidad l = Localidad(s);
		getline(fichero,s);

		stringstream ss;
		ss.str(s);

		int c1, c2;
		ss >> c1 >> c2;

		int bool_setcor = l.setCoor(c1, c2, mapa);

		if(bool_setcor != -1) {

			localidades.push_back(l);
			cont_ciudades = true;
		}

		getline(fichero,s);
		//tengo <INFO>

		int mu=0, mo=0, ho=0, res=0;
		bool ae = false;
		string top = "";
		bool bo_top = false;

		while (getline(fichero,s) && s != "<LOCALIDAD>"){

			if(cont_ciudades) {

				if(s[0] == '*'){

					bo_top = true;
					top = s;
				}
				else {

					stringstream ss2;
					ss2.str(s);

					string cat;
					int num;
					ss2 >> cat >> num;

					if(cat == "museo") mu=num;
					if(cat == "monumento") mo=num;
					if(cat == "hotel") ho=num;
					if(cat == "restaurante") res=num;
					if(cat == "aeropuerto") ae=true;

				}
			}
		}

		if(cont_ciudades) {

			InfoTur in = InfoTur(mu,mo,ho,res,ae);
			if(bo_top) in.setTop(top);
			localidades[ciudades].setInfo(in);
			ciudades++;
		}

		cont_ciudades = false;
	}
	//fichero.close();
}

vector<vector<char> > &  Coleccion::getMapa(){
	return mapa;
}

vector<Localidad> & Coleccion::getLocalidades(){
	return localidades;
}

char Coleccion::getCoorMapa(Coordenadas c){

	char dev = 'X';
	int fila = c.getFila();
	int columna = c.getColumna();

	unsigned int f = fila;
	unsigned int col = columna;
	//OJO CUANDO VA A SER LA FILA == 0
	if(fila>=0 && columna>=0 && f<mapa.size() && col<mapa[0].size()){

		dev = mapa[fila][columna];
	}

	return dev;
}


ostream & operator<<(ostream &os, const Coleccion &c){


		for(unsigned int i=0; i<c.mapa.size();i++){
			for(unsigned int j=0; j<c.mapa[0].size();j++){

				os<<c.mapa[i][j];
			}
			os<<endl;
		}

		

		if(c.localidades.empty() == false) {

			for(unsigned int i=0; i<c.localidades.size(); i++){

				os << c.localidades[i];
			}
		}

		

		return os;
}


