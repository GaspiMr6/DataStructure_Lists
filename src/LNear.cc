#include <vector>
#include <string.h>
#include <stdio.h>
#include <sstream>
#include <stdlib.h>
#include "LNear.h"
#include "Coleccion.h"
#include "Localidad.h"

/*
LNear::NodoL::NodoL(Localidad n){

	localidad = n;
	distancia = -1;
	next = NULL;
	prev = NULL; 
}

LNear::NodoL::NodoL(Localidad n, int d){

	localidad = n;
	distancia = d;
	next = NULL;
	prev = NULL; 
}


LNear::NodoL::~NodoL(){

	localidad = Localidad();
	distancia = -1;
	next = NULL;
	prev = NULL; 
}

//Constructor de copia
LNear::NodoL::NodoL(const NodoL &n){

	localidad = n.localidad;
	distancia = n.distancia;
	next = n.next;
	prev = n.prev; 
}

//operador asignacion
NodoL & LNear::NodoL::operator=(const NodoL &n){	

	if (this != &n) {

		// esta bien o tambien tenemos que hacer que n.next = NULL
		localidad = n.localidad;
		distancia = n.distancia;
		next = n.next;
		prev = n.prev;
	}
	return *this;
}
*/

/*Localidad LNear::NodoL::getLocalidad(){
	return localidad;
}

int LNear::NodoL::getDistancia(){
	return distancia;
}*/

/*
ostream & operator<<(ostream &os, const NodoL &c){

	os << c.localidad.getNombre() << " (" << c.distancia << ")";
	return os;
}
*/

LNear::LNear(){

	//ojo **
	//pr = NULL;
	//ul = NULL;
	pr = ul = NULL;
	error = Localidad();// DIEGO HACE ESO**
	//error nada**
}

//copia
LNear::LNear(const LNear &l){

	NodoL *aux, *aux2;

	aux = l.pr;
	pr = ul = NULL;
	//cout<<"constructor de copia"<<endl;cout.flush();
	while(aux){

		aux2 = new NodoL(aux->localidad, aux->distancia);
		if(pr==NULL) pr = ul = aux2;
		else {

			ul->next = aux2;
			aux2->prev=ul;
			//ul->next->prev = aux2;
			ul = aux2;
		}
		aux = aux-> next;
		
	}

	/*
	pr = l.pr;
	ul = l.ul;
	*/
}

//destructor
LNear::~LNear(){
	
/*	NodoL *aux;

	while(pr){

		aux = pr;
		pr = pr->next;
		delete aux;
	}
	ul = NULL;
*/
	if(!esVacia()){

		NodoL *borrado;
		borrado = pr;
		while(borrado!=NULL){
			pr = pr->next;
			delete borrado;
			borrado=pr;
		}
	}


	/*
	if(pr){
		delete pr;
		pr = NULL;	
	}
	if(ul) {
		delete ul;
		ul = NULL;	
	}
	*/
}


//operador asignacion

LNear & LNear::operator=(const LNear &l){

//eldediego
	/*
	if(this!=&l){

		if(esVacia() == false) {

			//NodoL *aux = pr;
			NodoL *borrar = pr;

			while(borrar != NULL){

				pr = pr->next;
				delete borrar;
				borrar = pr;
			}
		}

        NodoL *aux=l.pr;

        while(aux != NULL){

            insertaLocalidad(aux->localidad, aux->distancia);
            aux=aux->next;
        }
    }
    return *this;
*/

	//recorrer toda la lista liberando la memoria de
	//todos los nodos y copiarle todo lo del objeto	
//cout<<"se asigna la lista"<<endl;cout.flush();
    


    
	if (this != &l) {

		if(esVacia() == false) {

			//NodoL *aux = pr;
			NodoL *borrar = pr;

			while(borrar != NULL){

				pr = pr->next;
				delete borrar;
				borrar = pr;
			}
		}

		NodoL *aux2 = l.pr;
		//NodoL *auxul = pr;

		if(aux2 != NULL) {

			NodoL *n1 = new NodoL(aux2->localidad,aux2->distancia);
			pr = n1;
			ul = n1;
			NodoL *pun1 = n1;
		
			aux2 = aux2 -> next;
			NodoL *pun2 = NULL;
	

			while(aux2 != NULL){

				NodoL *n2 = new NodoL((*aux2).localidad,(*aux2).distancia);
				pun2 = n2;

				pun1->next = pun2;
				pun2->prev = pun1;
				ul=pun2;

				pun1 = pun1 -> next;
				aux2 = aux2 -> next;
			}
			//ul = pun2;
		}
	
	}
	return *this;
}

bool LNear::esVacia(){

	if(pr == NULL && ul == NULL) return true;
	else return false;
}

int LNear::rango(){

	int dev = -1;

	if(!esVacia()){
		
		dev = (*ul).distancia;
	}
	return dev;
}

void LNear::insertaLocalidad(Localidad p, int d){

	//NodoL n(p, d);
	NodoL *nuevo;
	//nuevo = new NodoL(p, d);
	nuevo = new NodoL(p, d);

	if (esVacia()){

		//cout<<"El primero\n";
			pr = ul = nuevo;
	}

	else {

		NodoL *aux = pr;
		int cont=0;
		int iguales=0;
		bool salir = false;
		int dis_repe = -1;
		bool cabeza = false;
		bool cola = false;

		while (aux != NULL && d >= (*aux).distancia && salir == false){

			if(d==(*aux).distancia){
				iguales++;
				dis_repe = d;
				if(p.getNombre() == (*aux).localidad.getNombre()) salir = true;
			}
			aux = aux->next;
			cont++;
		}
		

		if(salir == false) { //si no hay nodos repetidos, lo inserto

			if(iguales == 0 && aux == NULL) cola = true;

			if(iguales > 0){
				
				NodoL *aux3 = pr;
				int cont2 = 0;

				while (aux3 != NULL && (*aux3).distancia != dis_repe){

					 aux3 = aux3 -> next;
					 cont2++;
				}

				while(aux3 != NULL && p.getNombre()>(*aux3).localidad.getNombre() && (*aux3).distancia == dis_repe){

					aux3 = aux3 -> next;
					cont2++;
				}
				if (aux3 == NULL) cola = true;
				cont = cont2;

				//***
				//delete aux3; 
				//aux3=NULL;
				
			}

			if (cont == 0) cabeza = true;
			

			if(cabeza == false && cola == false) {
				
				//cout<<"En medio\n";

				NodoL *aux2 = pr;
				for(int i=0; i<cont-1; i++){
					aux2 = aux2 -> next;
				}

				
				nuevo->next = aux2->next;
				nuevo->prev = aux2;
				aux2->next->prev = nuevo;
				aux2->next = nuevo;
				//aux2 = aux2 -> next;
				//aux2->next->prev = NULL;
			
		
				//aux2->next = NULL;
			
				//delete aux2;
				
				//n.next = aux2->next;
				//n.prev = aux2;
				//  *aux2->next->prev = n;
				//  *aux2->next = n;
				
			}
			else if(cabeza){

				//cout<<"Cabeza\n";
				NodoL *aux4 = pr;
				pr = nuevo;
				nuevo->next = aux4;
				
				aux4 -> prev = nuevo;
				aux4 = NULL;
			
				//delete aux;
				//modificar pr
			}
			else if(cola){

				//cout<<"Cola\n";
				NodoL *aux4 = pr;
				for(int j=0; j<cont-1; j++) { //COMPROBAR SI ES j<cont o j<cont-1 **

					aux4 = aux4 -> next;
				}
				ul = nuevo;
				aux4 -> next = nuevo;
				ul -> prev = aux4;
				//modificar ul
			}
		}
		else { //si no lo inserto

			delete nuevo;
		}
		//delete aux;
		//aux = NULL;
	}
	//delete nuevo;
	//nuevo=NULL;

}


int LNear::borraLocalidad(string s){

	int dev = -1;
	bool cola = false;
	bool cabeza = false;
	bool se_puede_borrar = false;

	NodoL *aux = pr;

	if (esVacia() == false) {

		

		while (aux != NULL && (*aux).localidad.getNombre() != s){
/*
			if ((*aux).localidad.getNombre() == s){

				se_puede_borrar = true;
			}
		*/
			aux = aux -> next;
		}
	}

	if(aux == NULL) se_puede_borrar = false;
	else se_puede_borrar = true;

	if(esVacia() == false && se_puede_borrar) {

		NodoL *aux = pr;

		if (aux == pr && aux == ul){ //solo hay un nodo

			dev = (*aux).distancia;
			delete aux;
			pr = ul = NULL;
		}
		else {

			while (aux != NULL && (*aux).localidad.getNombre() != s){

				aux = aux -> next;
			}

			if(pr == aux) cabeza = true;
			if(ul == aux) cola = true;

			if (cabeza == false && cola == false){

				dev = (*aux).distancia;
				aux->prev->next = aux->next;
				aux -> next -> prev = aux -> prev;
				aux -> prev = NULL;
				aux -> next = NULL;
				delete aux;
				//aux = NULL;
			}
			else if (cabeza){

				dev = (*aux).distancia;
				pr = aux->next;
				aux -> next -> prev = NULL;
				aux -> next = NULL;
				delete aux;
			}
			else if (cola){

				dev = (*aux).distancia;
				ul = aux -> prev;
				aux -> prev -> next = NULL;
				aux -> prev = NULL;
				delete aux;
			}
		}
	}
	return dev;
}


void LNear::borraLocalidades(int k){

	if (esVacia() == false) {

		NodoL *aux = pr;
		//NodoL *meca = pr;
		bool borrar = false;
		bool borrar_todo = false;

		if((*aux).distancia > k) borrar_todo = true;

		if(borrar_todo) {

			NodoL *bor = pr;
			
			while(bor != NULL){

				NodoL *aux3 = NULL;
				aux3 = bor;
				bor = bor -> next;
				delete aux3;
			}

			pr = ul = NULL;
		}
		else {

			int cont = 0;

			while(aux!=NULL && (*aux).distancia <= k){

				aux = aux -> next;
				cont++;
			}
			if (aux == NULL) borrar = false;
			else borrar = true;

			if (borrar) {

				if (aux == pr && aux == ul){ //solo hay un nodo

					NodoL *bor = pr;
					delete bor;
					pr = ul = NULL;

				}
				else {
//cout<<"empiezo a borrar en "<<cont<<endl;cout.flush();
					NodoL *bor = aux;
					ul = aux -> prev;
					ul -> next = NULL;
					aux -> prev = NULL;
					aux = NULL;
//cout<<"llega"<<endl;cout.flush();
					//borrar a partir de cont
					while(bor != NULL){

						NodoL *aux3 = NULL;
						aux3 = bor;
						bor = bor -> next;
						delete aux3;
					}			
					
					//todo lo de delante lo puedo dejar apuntando a cosas?
				}
				
			}
		}
	}
}

void LNear::borra_memoria(int pos){

	int i = 0;
	NodoL *aux = pr;

	while (i < pos){

		aux = aux->next;
		i++;
	}
	delete (*aux).next;
	delete (*aux).prev;
}

Localidad & LNear::getLocalidad(int i){

	if(esVacia() || i < 0) return error;
	else {

		NodoL *aux = pr;
		for(int j=0; aux != NULL && j<i; j++){

			aux = aux -> next;
		}

		if (aux != NULL)
		return (*aux).localidad;
		else return error;

	}
}
/*
Localidad & LNear::getLocalidad( int i ){
	NodoL *aux=pr;
	int cont=0;
	if(i>-1&&esVacia()==false){
		while(aux&&cont!=i){
			aux=aux->next;
			cont++;
		}
		if(cont==i&&aux!=NULL){
			return aux->localidad;
		}
	}

	return error;
}
*/


int LNear::num_nodos(){

	if(esVacia()) return 0;
	else {

		int cont = 0;
		NodoL *aux = pr;
		while(aux != NULL){

			aux = aux -> next;
			cont++;
		}
		return cont;
	}
}

ostream & operator<<(ostream &os, const LNear &c){

//	if (c.pr != NULL && c.ul != NULL){

		LNear::NodoL *aux = c.pr;
		while (aux != NULL) {

			os<<*aux<<endl;
			//os << (*aux).localidad.getNombre() <<" ("<<(*aux).distancia<<")\n";
			aux = aux->next;
		}
//	}

	return os;
}


