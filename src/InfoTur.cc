//#include<vector>
#include "InfoTur.h"


InfoTur::InfoTur(int mu, int mo, int ho, int r, bool ae) {

	if(mu<0) mu = 0;
	museo = mu;
	if(mo<0) mo = 0;
	monumento = mo;
	if(ho<0) ho = 0;
	hotel = ho;
	if(r <0) r  = 0;
	restaurante = r;
	aeropuerto = ae;
	//duda**: comprobar que top esta como debe con mains
}


InfoTur::InfoTur(const InfoTur &info) {

	museo = info.museo;
	monumento = info.monumento;
	hotel = info.hotel;
	restaurante = info.restaurante;
	aeropuerto = info.aeropuerto;
	top = info.top;
}


InfoTur::~InfoTur(){

	museo=0;
	monumento=0;
	hotel=0;
	restaurante=0;
	aeropuerto=false;
	top = "";
}


InfoTur & InfoTur::operator=(const InfoTur &t) {

	if(this != &t){

		museo = t.museo;
		monumento = t.monumento;
		hotel = t.hotel;
		restaurante = t.restaurante;
		aeropuerto = t.aeropuerto;
		top = t.top;
	}
	return *this; 
}



bool InfoTur::operator!=(const InfoTur &t) {

	bool dev = true;

	if(t.museo == museo && t.monumento == monumento && t.hotel == hotel && t.restaurante == restaurante && t.aeropuerto == aeropuerto && t.top == top) {

		dev = false;
	}

	return dev;
}


bool InfoTur::operator==(const InfoTur &t){

	bool dev = false;

	if(t.museo == museo && t.monumento == monumento && t.hotel == hotel && t.restaurante == restaurante && t.aeropuerto == aeropuerto && t.top == top) {

		dev = true;
	}

	return dev;

}


vector<int> InfoTur::getInfoTur(){

	/*
	vector<int> dev(5);
	dev[0] = museo;
	dev[1] = monumento;
	dev[2] = hotel;
	dev[3] = restaurante;
	if(aeropuerto==true) dev[4] = 1;
	else dev[4] = 0;
	return dev;
	*/

	vector<int> dev;
	dev.push_back(museo);
	dev.push_back(monumento);
	dev.push_back(hotel);
	dev.push_back(restaurante);

	if(aeropuerto) dev.push_back(1);
	else dev.push_back(0);

	return dev;
}


string InfoTur::getMasFrecuente(){

	string dev = "";
	int pos = 0;

	vector<int> v = getInfoTur();
	vector<int> aux = v;

	v[0] = aux[4];
	v[1] = aux[2];
	v[2] = aux[1];
	v[3] = aux[0];
	v[4] = aux[3];

	for(unsigned int i=0; i<v.size();i++){

		if(v[i] > v[pos]){

			pos = i;
		}
	}

	if (pos == 0) dev = "aeropuerto";
	else if(pos == 1) dev = "hotel";
	else if (pos == 2) dev = "monumento";
	else if (pos == 3) dev = "museo";
	else dev = "restaurante";

	return dev;
}

string InfoTur::getTop() {

	return top;
} 

bool InfoTur::getAeropuerto(){

	return aeropuerto;
}


void InfoTur::setTop(string n) {

	top = n;
}

//**DUDA QUE ES OSTREAM_
//Y LA FUNCION AMIGA ESTA YA HECHA_
ostream & operator<<(ostream &os, const InfoTur &c){

	os << c.museo << " " << c.monumento << " " << c.hotel << 
	" " << c. restaurante << " " << c.aeropuerto << " " << c.top << endl; 

	return os;


} 





