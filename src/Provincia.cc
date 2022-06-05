#include "LNear.h"
#include "Coleccion.h"
#include "Localidad.h"
#include "Provincia.h"

//es necesario el constructor por defecto?*
Provincia::Provincia(){

	lc = Localidad();
	locprox = LNear();
}

Provincia::Provincia(Localidad l){

	lc = l;
	locprox = LNear();
}

Provincia::Provincia(const Provincia &p){

	lc = p.lc;
	locprox = p.locprox;
}

Provincia::~Provincia(){

	lc = Localidad();
	locprox = LNear();
}

Provincia & Provincia::operator=(const Provincia &p){

	if (this != &p) {

		lc = p.lc;
		locprox = p.locprox;
	}
	return *this;
}


void Provincia::calculaCercanas(Coleccion &c, int n){

	int x1 = lc.getCoor().getFila();
	int y1 = lc.getCoor().getColumna();
	

	if(!locprox.esVacia()) locprox.borraLocalidades(-1);

	for(unsigned int i=0; i<c.getLocalidades().size();i++){

		int x2 = c.getLocalidades()[i].getCoor().getFila();
		int y2 = c.getLocalidades()[i].getCoor().getColumna();

		if( (abs(x1-x2) + abs(y1-y2)) <= n ){ //< o <=  ? ** 

			int dist = (abs(x1-x2) + abs(y1-y2));

			if(x1 != x2 || y1 != y2)
				locprox.insertaLocalidad(c.getLocalidades()[i],dist);
		}
	}
}


int Provincia::borraLocalidad(string s){

	//si hay varias con el mismo nombre solo la primera, no?
	int dev = locprox.borraLocalidad(s);

	return dev;
}

LNear & Provincia::getCercanas(){

	return locprox;
	//if(locprox.esVacia() == false) return locprox;
	//else return LNear();
	//es asi? o puedo devolver locprox?
}

string Provincia::getCostera(Coleccion &c){

	string dev = "no hay ninguna localidad costera";
	//int corx = -1; 
	//int corj = -1;
	//int dis_min = locprox.rango() + 1; //mal**
	//int n1 = 0, n2 = 0 ;


	//si hay 2 a la misma distancia la primera ordenada alfabeticamente?

	int n1 = -1; 
	int n2 = -1;
	bool salir = false;
	bool meterme=true;
	
	/*
	for(unsigned int i=0; i<c.getLocalidades().size();i++){
		//if(lc.getCoor().getFila() == c.getLocalidades()[i].getCoor().getFila() && lc.getCoor().getColumna() == c.getLocalidades()[i].getCoor().getColumna()){
		if(lc == c.getLocalidades()[i]){
			meterme = true;
		}
		
	}
	*/
	//cout<<endl<<"meterme: "<<meterme<<endl;
	if(meterme){

		unsigned int filasmax = c.getMapa().size()-1;
		unsigned int columnasmax = c.getMapa()[0].size()-1;

		for(int k=0; k<locprox.num_nodos() && salir == false;k++){

			n1 = locprox.getLocalidad(k).getCoor().getFila();
			n2 = locprox.getLocalidad(k).getCoor().getColumna();
			
			unsigned u1 = n1;
			unsigned u2 = n2;

			if((n1>0 && c.getMapa()[n1-1][n2] == 'M') || (u1<filasmax && c.getMapa()[n1+1][n2] == 'M')|| (u2<columnasmax && c.getMapa()[n1][n2+1] == 'M')|| (n2>0 && c.getMapa()[n1][n2-1]== 'M')){

				salir = true;
				dev = locprox.getLocalidad(k).getNombre();	
			} 
		}
	}
	return dev;
}

bool Provincia::esta_en_coleccion(Localidad &l, Coleccion &c){

	bool salir = false;

	for(unsigned int i=0; i<c.getLocalidades().size() && salir == false; i++){

		if(l == c.getLocalidades()[i]) salir = true;
	}
	return salir;
}

LNear Provincia::getCosteras(Coleccion &c){

	LNear dev;

	int n1 = -1; 
	int n2 = -1;
	int cont_costeras = 0;
	bool meterme = true;

	/*
	for(unsigned int i=0; i<c.getLocalidades().size();i++){

		if(lc.getCoor().getFila() == c.getLocalidades()[i].getCoor().getFila() && lc.getCoor().getColumna() == c.getLocalidades()[i].getCoor().getColumna()){

			meterme = true;
		}
	}
	*/
	if(meterme){ //si lc no esta en el array de localidades de Coleccion

		unsigned int filasmax = c.getMapa().size()-1;
		unsigned int columnasmax = c.getMapa()[0].size()-1;

		for(int k=0; k<locprox.num_nodos(); k++){

			n1 = locprox.getLocalidad(k).getCoor().getFila();
			n2 = locprox.getLocalidad(k).getCoor().getColumna();
			
			unsigned u1 = n1;
			unsigned u2 = n2;

			if((n1>0 && c.getMapa()[n1-1][n2] == 'M') || (u1<filasmax && c.getMapa()[n1+1][n2] == 'M')|| (u2<columnasmax && c.getMapa()[n1][n2+1] == 'M')|| (n2>0 && c.getMapa()[n1][n2-1]== 'M')){
			//if((n1>0 && c.getMapa()[n1-1][n2] == 'M') || c.getMapa()[n1+1][n2] == 'M'|| c.getMapa()[n1][n2+1] == 'M'|| c.getMapa()[n1][n2-1]== 'M'){

				int dist = (abs(n1 - lc.getCoor().getFila()) + abs(n2-lc.getCoor().getColumna()));
				dev.insertaLocalidad(locprox.getLocalidad(k), dist);
				cont_costeras++;
			} 
		}
	}

	return dev;
}


string Provincia::getConAeropuerto(){

	string dev = "";

	if(lc.getInfo().getAeropuerto()) dev = "propio";
	else {

		bool salir = false;
		for(int k=0; k<locprox.num_nodos() && salir == false; k++){

			if(locprox.getLocalidad(k).getInfo().getAeropuerto()){

				salir = true;
				dev = locprox.getLocalidad(k).getNombre();
			}
		}

		if(salir == false){

			dev = "sin aeropuerto";
		}
	}

	return dev;
}

ostream & operator<<(ostream &os, const Provincia &p){

	os <<p.lc.getNombre()<<endl<<p.locprox;
	return os;
}
