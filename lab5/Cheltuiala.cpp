#include "Cheltuiala.h"
#include <string>


//Descr: crearea unei cheltuieli  
//In: -
//Out: o instanta a unei Cheltuieli
Cheltuiala::Cheltuiala() {
	
	this->tip = NULL;
	this->price = 0;
	
}

//Descr: creeaza o cheltuiala
//In: tip pret si zi
//Out: 
Cheltuiala::Cheltuiala(char* n, int p) {
	
	this->tip = new char[strlen(n) + 1];
	strcpy_s(this->tip, strlen(n) + 1, n);
	this->price = p;
	
}

//Descr: crearea unei cheltuieli folosind info din alta cheltuiala
//In: o cheltuiala f
//Out: o instanta a cheltuielii cu info de la f
Cheltuiala::Cheltuiala(const Cheltuiala &f) {
	
	this->tip = new char[strlen(f.tip) + 1];
	strcpy_s(this->tip, strlen(f.tip) + 1, f.tip);
	this->price = f.price;
	
}



//Descr: distrugerea unei cheltuieli 
//In: o cheltuiala 
//Out: - (destructor)
Cheltuiala::~Cheltuiala() {
	if (this->tip != NULL) {
		
		delete[] this->tip;
		this->tip = NULL;
	}
}

//Descr: access pretul unei cheltuieli 
//In: o cheltuiala  
//Out: pret
int Cheltuiala::getPrice() {
	//return price;
	return this->price;
}



//Descr: schimba pretul unei cheltuieli
//In: o cheltuiala si pretul
//Out: cheltuiala cu pretul schimbat
void Cheltuiala::setPrice(int p) {
	this->price = p;
}

//Descr: conversie cheltuiala la string
//In: o cheltuiala 
//Out: un string cu info despre o floare 
char* Cheltuiala::toString() {
	if (this->tip != NULL) {
		int noChars = strlen(this->tip) + 1 + 5 +2;
		char* s = new char[noChars];
		char* aux = new char[5];
		
		strcpy_s(s, noChars, this->tip);
		strcat_s(s, noChars, ";");
		_itoa_s(this->price, aux, 5, 10);
		strcat_s(s, noChars, aux);
		strcat_s(s, noChars, ";");
		
		

		if (aux) {
			delete[] aux;
			aux = NULL;
		}
		
		strcat_s(s, noChars, ";");
		return s;
	}
}

