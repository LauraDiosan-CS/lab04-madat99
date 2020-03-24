#pragma once
#ifndef Cheltuiala_H
#define Cheltuiala_H

#include <iostream>
using namespace std;

const int MAX_Cheltuieli = 100;

class Cheltuiala {
private:
	int zi;
	char* tip;
	int price;
public:
	Cheltuiala();
	Cheltuiala(int zi, char* tip, int p);
	Cheltuiala(const Cheltuiala & c);
	
	~Cheltuiala();

	
	Cheltuiala& operator=(const Cheltuiala& c);

	
	char* getTip();
	int getZi();
	int getPrice();
	void setTip(char* t);
	void setPrice(int p);
	void setZi(int zi);
	char* toString();
	bool compare(Cheltuiala& ch);
	
};

#endif


