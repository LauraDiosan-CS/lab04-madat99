#include "Cheltuiala.h"
#include <string>


//Descr: crearea unei cheltuieli  
//In: -
//Out: o instanta a unei Cheltuieli
Cheltuiala::Cheltuiala() {
	
	this->tip = NULL;
	this->price = 0;
	this->zi = 0;
}

//Descr: creeaza o cheltuiala
//In: tip pret si zi
//Out: 
Cheltuiala::Cheltuiala(int zi, char* n, int p) {
	
	this->tip = new char[strlen(n) + 1];
	strcpy_s(this->tip, strlen(n) + 1, n);
	this->price = p;
	this-> zi = zi;
	
}

//Descr: crearea unei cheltuieli folosind info din alta cheltuiala
//In: o cheltuiala f
//Out: o instanta a cheltuielii cu info de la f
Cheltuiala::Cheltuiala(const Cheltuiala &f) {
	this->zi = f.zi;
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

}int Cheltuiala::getZi() {
	return this->zi;
}
char* Cheltuiala::getTip() {
	return tip;
}

//Descr: schimba pretul unei cheltuieli
//In: o cheltuiala si pretul
//Out: cheltuiala cu pretul schimbat
void Cheltuiala::setPrice(int p) {
	this->price = p;
}
void Cheltuiala::setZi(int zi) {
	this->zi = zi;
}

void Cheltuiala::setTip(char* t) {
	delete[] this->tip;
	this->tip = new char[strlen(tip) + 1];
	strcpy_s(this->tip, strlen(tip) + 1, tip);
}

Cheltuiala& Cheltuiala::operator=(const Cheltuiala& c)
{
	//cout << "Operator =" << endl;
	if (this != &c)
	{

		

		zi = c.zi;
		price =c.price;
		setTip(c.tip);
	}
	return *this;
}

//Descr: conversie cheltuiala la string
//In: o cheltuiala 
//Out: un string cu info despre o floare 
char* Cheltuiala::toString() {
	if (this->tip != NULL) {
		int noChars = strlen(this->tip) + 5 + 5 + 3 + 1;
		char* s = new char[noChars];
		char* aux = new char[5];
		char* aux2 = new char[5];
		strcpy_s(s, noChars, this->tip);
		strcat_s(s, noChars, ";");
		_itoa_s(this->zi, aux2, 5, 10);
		_itoa_s(this->price, aux, 5, 10);
		strcat_s(s, noChars, aux2);
		strcat_s(s, noChars, ";");
		strcat_s(s, noChars, aux);
		if (aux) {
			delete[] aux;
			aux = NULL;
		}
		strcat_s(s, noChars, ";");
		return s;
	}
	else
	{
		char* x = new char[1];
		strcpy_s(x, 1, "");
		return x;
	}
}
//Descr: compara doua cheltuieli
//In: doua apartamente
//Out: true/false
bool Cheltuiala::compare(Cheltuiala& a) {
	return ((this->zi == a.zi) && (strcmp(this->tip, a.tip) == 0) && (this->price == a.price));
}
