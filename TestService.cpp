#include "TestService.h"
#include <iostream>
#include <cassert>
#include <cstring>
using namespace std;
void testService()
{
	cout << "teste service" << endl;
	Repo r;
	Service c = Service(r);
	//assert(strcmp(c.getRepo().toString(), "") == 0);
	char* tip = new char[4];
	strcpy_s(tip, 4, "gaz");
	Cheltuiala ch = Cheltuiala(12, tip, 150);
	char* x = new char[10];
	strcpy_s(x, 10, "internet");
	Cheltuiala ch1 = Cheltuiala(11, x, 70);
	c.addC(12, 150, tip);
	c.addC(11, 70, x);
	assert(c.getSizeC() == 2);
	c.eliminare(11, 1, tip, 1, 1);
	
	char* s = new char[4];
	strcpy_s(s, 4, "apa");
	Cheltuiala ch2 = Cheltuiala(13, s, 100);
	c.addC(13, 100, s);
	//c.eliminare(0, 0, NULL, 0, 3);
	//c.afisare(1, 0, 0, 0);
	//assert(strcmp(c.getRepo().toString(), "apa;13;100;") == 0);
	//c.inlocuire_gaz(s, 13, 2251);
	//cout<<c.getApartamentC(1).toString();
	//assert(strcmp(c.getApartamentC(1).toString(), "apa;13;100;") == 0);
	cout << "testele controller merg...";
}