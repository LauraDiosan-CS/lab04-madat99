#pragma once
#ifndef Service_H
#define Service_H
#include "Repo.h"
#include "Cheltuiala.h"
#include <iostream>
using namespace std;

class Service {
private:
	Repo repo;
public:
	Service();
	Service(Repo& repo);
	Service(const Service& c);
	~Service();
	Service& operator=(const Service& c);
	Repo getRepo();
	Cheltuiala* getAllC();
	Cheltuiala& getC(int p);
	int getSizeC();
	
	void obtPropr(char* tip, int ok, int& suma, int ap);
	void addC(int ap, int p, char* tip);
	void stergere(int ap, int p, char* tip);
	void afisare(int ok, int val, int suma, int comp);
	void inlocuire_gaz(char* tip, int val1, int val2);
	void filtrare(char* tip, int val, int ok);
	void setLista(Cheltuiala* c);
	void inlocuire(int ap, int p, char* tip, int ap2, int p2, char* tip2);
	void eliminare(int , int st, char* tip, int fi, int ok);
	void update(Cheltuiala& c, char* tip, int zi, int p);
	
	char* toString();
	
};

#endif
