#ifndef INFOTUR_h
#define INFOTUR_h

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class InfoTur {

	friend ostream & operator<<(ostream &, const InfoTur &);

	private:
		 int museo, monumento, hotel, restaurante;
		 bool aeropuerto;
		 string top;

	public: InfoTur() {museo=0; monumento=0; hotel=0; restaurante=0;
						 aeropuerto=false; top = "";}

			InfoTur(int mu, int mo, int ho, int r, bool ae);

			InfoTur(const InfoTur &);

			~InfoTur();

			InfoTur & operator= (const InfoTur &);

			bool operator!=(const InfoTur &); //Duda no se pone InfoTur?

			bool operator==(const InfoTur &);

			vector<int> getInfoTur(); 

			string getMasFrecuente(); 

			void setTop(string n); 

			string getTop(); 

			bool getAeropuerto(); 

};

#endif
