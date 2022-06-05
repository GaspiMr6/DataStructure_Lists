#include "LNear.h"
#include "Coleccion.h"
#include "Provincia.h"

using namespace std;

static void muestra_lista(LNear l){

	cout<<"Muestro Lista: \n"<<l<<endl;
}

static void muestra_provincia(Provincia p){

	cout<<"Muestro Provincia: \n"<<p<<endl;
}


int main(int args, char *argv[]){

	LNear lis1=LNear();
	LNear lis2=LNear();
	LNear lis3=LNear();
	LNear lis4=LNear();
	LNear copia1;
	LNear copia2;

	cout<<"La lista esta vacia: "<<lis1.esVacia()<<endl;
	cout<<"La lista esta vacia: "<<copia1.esVacia()<<endl;

	Localidad l1=Localidad("aa");
	Localidad l2=Localidad("bb");
	Localidad l23=Localidad("bc");
	Localidad l3=Localidad("cc");
	Localidad l4=Localidad("dd");
	Localidad l5=Localidad("ee");

	InfoTur i1(1,1,1,1,true);
	InfoTur i2(2,2,2,2,false);
	InfoTur i3(3,3,3,3,true);
	InfoTur i4(2,0,1,1,false);
	i1.setTop("SoyEl1");
	i3.setTop("SoyEl3");

	l1.setInfo(i1);
	l2.setInfo(i2);
	l3.setInfo(i3);
	l4.setInfo(i4);
	l5.setInfo(i1);

	lis1.insertaLocalidad(l1,10);
	lis1.insertaLocalidad(l3,10);
	lis1.insertaLocalidad(l2,10);
	lis1.insertaLocalidad(l4,10);
	lis1.insertaLocalidad(l2,15);
	lis1.insertaLocalidad(l1,15);
	lis1.insertaLocalidad(l3,15);
	lis1.insertaLocalidad(l5,10);
	lis1.insertaLocalidad(l23,10);

	copia1 = lis1;
	copia2 = lis2;
	cout<<"La lista esta vacia: "<<copia1.esVacia()<<endl;


	muestra_lista(lis1);
	muestra_lista(copia1);

	cout<<"Direccion primera: "<<&lis1<<endl;
	cout<<"Direccion segunda: "<<&copia1<<endl;

	lis2.insertaLocalidad(l4,10);
	lis2.insertaLocalidad(l2,10);
	lis2.insertaLocalidad(l3,10);
	lis2.insertaLocalidad(l1,10);
	lis2.insertaLocalidad(l2,5);
	lis2.insertaLocalidad(l3,5);
	lis2.insertaLocalidad(l1,5);
	lis2.insertaLocalidad(l5,10);
	lis2.insertaLocalidad(l23,10);
	lis2.insertaLocalidad(l4,0);
	lis2.insertaLocalidad(l4,0);
	lis2.insertaLocalidad(l4,-10);

	cout<<endl<<"Lista 2"<<endl;
	muestra_lista(lis2);

	cout<<"Borro: "<<lis2.borraLocalidad("")<<endl;
	cout<<"Borro: "<<lis2.borraLocalidad("aa")<<endl;
	cout<<"Borro: "<<lis2.borraLocalidad("bb")<<endl;
	cout<<"Borro: "<<lis2.borraLocalidad("bb")<<endl;
	cout<<"Borro: "<<lis2.borraLocalidad("bb")<<endl;
	cout<<"Borro: "<<lis2.borraLocalidad("bc")<<endl;
	cout<<"Borro: "<<lis2.borraLocalidad("ee")<<endl;
	cout<<"Borro: "<<lis2.borraLocalidad("bc")<<endl;
	cout<<"Borro: "<<lis2.borraLocalidad("dd")<<endl;
	cout<<"Borro: "<<lis2.borraLocalidad("dd")<<endl;
	cout<<"Borro: "<<lis2.borraLocalidad("dd")<<endl;
	cout<<"Borro: "<<lis2.borraLocalidad("cc")<<endl;
	cout<<"Borro: "<<lis2.borraLocalidad("aa")<<endl;
	cout<<"Borro: "<<lis2.borraLocalidad("cc")<<endl;

	cout<<endl<<"Muestro lista 2: "<<endl<<lis2;
	cout<<"Muestro copia2: "<<copia2<<endl;
	cout<<"La lis2 esta vacia: "<<lis2.esVacia()<<endl;
	cout<<"La copia2 esta vacia: "<<copia2.esVacia()<<endl<<endl;


	muestra_lista(lis2);
	cout<<"Borro todas las localidades: "<<endl;
	lis2.borraLocalidades(-100);
	muestra_lista(copia2);	


	lis3.insertaLocalidad(l4,10);
	lis3.insertaLocalidad(l2,10);
	lis3.insertaLocalidad(l3,10);
	lis3.insertaLocalidad(l1,10);
	lis3.insertaLocalidad(l2,15);
	lis3.insertaLocalidad(l3,15);
	lis3.insertaLocalidad(l1,15);
	lis3.insertaLocalidad(l5,15);
	lis3.insertaLocalidad(l23,11);
	lis3.insertaLocalidad(l4,11);
	lis3.insertaLocalidad(l4,-700);
	lis3.insertaLocalidad(l4,-0);

	cout<<endl<<"LISTA 3:"<<lis3<<endl;
	cout<<"Borro a partir de 20"<<endl;
	lis3.borraLocalidades(20);
	muestra_lista(lis3);
	cout<<"Borro a partir de 10"<<endl;
	lis3.borraLocalidades(10);
	muestra_lista(lis3);
	cout<<"Borro a partir de 10"<<endl;
	lis3.borraLocalidades(10);
	muestra_lista(lis3);
	cout<<"Borro a partir de -800"<<endl;
	lis3.borraLocalidades(-800);
	muestra_lista(lis3);
	cout<<"La lis3 esta vacia: "<<lis3.esVacia()<<endl;
	cout<<"Borro a partir de -1000"<<endl;
	lis3.borraLocalidades(-1000);
	muestra_lista(lis3);

	cout<<endl<<endl<<"-------------LISTA 4------------"<<endl;
	lis4.insertaLocalidad(l1,10);
	lis4.insertaLocalidad(l2,10);
	lis4.insertaLocalidad(l3,10);
	lis4.insertaLocalidad(l4,10);

	Localidad lo1 = lis4.getLocalidad(-1);
	cout<<lo1<<endl;

	Localidad lo2 = lis4.getLocalidad(0);
	cout<<lo2<<" --> "<<lo2.getNombre()<<endl;


	cout<<"Lista 4 antes del cambio pop: "<<endl<<lis4<<endl;
	Localidad lpop("PARIS");
	InfoTur ipop(66,66,66,66,true);
	ipop.setTop("pop");
	lpop.setInfo(ipop);
	lo2 = lpop;
	cout<<"Lista 4 despues del cambio pop: "<<endl<<lis4<<endl;
	cout<<lis4.getLocalidad(0)<<" -> "<<lis4.getLocalidad(0).getNombre()<<endl;

	
	cout<<endl<<"---PROVINCIA---\n";
	Provincia p1(l1);
	Provincia copiap1(lo2);
	muestra_provincia(p1);


	copiap1 = p1;
	muestra_provincia(copiap1);


	Coleccion c1;

	c1.lectura("readFiles/ent.txt");
	p1.calculaCercanas(c1,100);
	muestra_provincia(p1);
	copiap1 = p1;
	muestra_provincia(p1);

	Coleccion c2;
	c2.lectura("readFiles/ent2.txt");
	Provincia p2(c2.getLocalidades()[0]);
	p2.calculaCercanas(c1,100);
	muestra_provincia(p2);

	p2.calculaCercanas(c1,4);
	muestra_provincia(p2);

	p2.calculaCercanas(c1,2);
	muestra_provincia(p2);

	p2.calculaCercanas(c1,1);
	muestra_provincia(p2);
	
	p2.calculaCercanas(c2,100);
	muestra_provincia(p2);

	cout<<"Borro Betis: "<<p2.borraLocalidad("Betis")<<endl;
	muestra_provincia(p2);

	cout<<"Borro Betis2: "<<p2.borraLocalidad("Betis2")<<endl;
	muestra_provincia(p2);

	cout<<"Borro Betis1: "<<p2.borraLocalidad("Betis1")<<endl;
	muestra_provincia(p2);

	cout<<"Borro Betis3: "<<p2.borraLocalidad("Betis3")<<endl;
	muestra_provincia(p2);

	LNear cercanas;
	cercanas = p2.getCercanas();
	cout<<"Cercanas: \n"<<cercanas<<endl;




	cout<<"-----------------------------------\n";

		cout<<"Provincia 1: \n"<<p1<<endl;
		cout<<"Provincia 2: \n"<<p2<<endl;
		cout<<"Coleccion 1: \n"<<c1<<endl;
		cout<<"Coleccion 2: \n"<<c2<<endl;

	cout<<"-----------------------------------\n";


	cout<<"Costera p1,c1 --> "<<p1.getCostera(c1)<<endl;
	cout<<"Costera p2,c2 --> "<<p2.getCostera(c2)<<endl;
	cout<<"Costera p1,c2 --> "<<p1.getCostera(c2)<<endl;
	cout<<"Costera p2,c1 --> "<<p2.getCostera(c1)<<endl;






	Coleccion c3;
	c3.lectura("readFiles/ent3.txt");
	Provincia p3(c3.getLocalidades()[0]);
	p3.calculaCercanas(c3,100);

	cout<<"Provincia p3"<<endl;
	cout<<p3;

	LNear cercanas3;
	cercanas = p3.getCercanas();
	cout<<"Costera p3,c3 --> "<<p3.getCostera(c3)<<endl;


	cout<<endl;
	Coleccion c4;
	c4.lectura("readFiles/ent4.txt");
	Provincia p4(c4.getLocalidades()[0]);
	p4.calculaCercanas(c4,100);

	cout<<"Provincia p4"<<endl;
	cout<<p4;

	LNear cercanas4;
	cercanas = p4.getCercanas();
	cout<<"Costera p4,c4 --> "<<p4.getCostera(c4)<<endl;

	LNear costeras4;
	costeras4 = p4.getCosteras(c4);
	cout<<endl<<"Las costeras4 son: "<<endl<<costeras4<<endl;

	LNear costeras3;
	costeras3 = p3.getCosteras(c3);
	cout<<endl<<"Las costeras3 son: "<<endl<<costeras3<<endl;

	LNear costeras1;
	costeras1 = p1.getCosteras(c1);
	cout<<endl<<"Las costeras1 son: "<<endl<<costeras1<<endl;

	LNear costeras2;
	costeras2 = p2.getCosteras(c2);
	cout<<endl<<"Las costeras2 son: "<<endl<<costeras2<<endl;

	cout<<"PROVINCIA1: "<<p1.getConAeropuerto()<<endl;
	cout<<"PROVINCIA2: "<<p2.getConAeropuerto()<<endl;
	cout<<"PROVINCIA3: "<<p3.getConAeropuerto()<<endl;
	cout<<"PROVINCIA4: "<<p4.getConAeropuerto()<<endl;
	


	return 0;
}
