#pragma once
#ifndef Cheltuiala_H
#define Cheltuiala_H

#include <iostream>
using namespace std;

const int MAX_Cheltuieli = 10;

class Cheltuiala {
private:
	char* tip;
	int price;
public:
	Cheltuiala();
	Cheltuiala(char* tip, int p);
	Cheltuiala(const Cheltuiala &c);
	~Cheltuiala();

	//Descr: acces pt tipul unei cheltuieli
	//In: o cheltuiala  
	//Out: tipul
	char* const getTip() const {
		//return tip;
		return this->tip;
	}

	int getPrice();
	void setPrice(int p);
	char* toString();
	
};

#endif


