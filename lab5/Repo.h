#pragma once
#ifndef Repo_H
#define Repo_H
#include "Cheltuiala.h"

#include <iostream>
using namespace std;

const int MAX_CHELTUIELI = 100;

class Repo {
private:
	Cheltuiala* lc; //lista de cheltuieli
	int nrc; //nr de cheltuieli
public:
	Repo();
	Repo(int nrC, Cheltuiala*lc);
	Repo(const Repo &r);
	~Repo();
	
	void addElement(Cheltuiala el);
	Repo* getNrCheltuieli();
	Cheltuiala* getAll();
	int getSize();

};

#endif

