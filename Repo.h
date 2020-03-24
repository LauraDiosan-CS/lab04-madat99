#pragma once
#ifndef Repo_H
#define Repo_H
#include "Cheltuiala.h"

#include <iostream>
using namespace std;

const int MAX_CHELTUIELI = 10;

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
	
	Cheltuiala* getAll();
	int getSize();
	void setSize(int numar);

	Repo& operator=(const Repo & r);
	
	void afisareLista();
	void setLista(Cheltuiala* c);
	int cautaPosPret(int p);
	int cautaPosZi(int c);
	int cautaPosTip(char* tip);
	void update(Cheltuiala& c, Cheltuiala& c2);
	void updatePret(int p, int newp);
	void updateTip(char* t, char* newt);
	void updateZi(int zi, int newzi);
	void eliminare(int poz);
	Cheltuiala& getCheltuiala(int poz);
	
	char* toString();
	

};

#endif

