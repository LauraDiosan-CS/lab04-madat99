
#include <iostream>
#include <cassert>
#include <cstring>
#include "Repo.h"
#include "Cheltuiala.h"
#include "TestR.h";
using namespace std;
void TestRepo() {
	Repo r;
	Cheltuiala*lc = new Cheltuiala[10];
	char aux[] = "Internet";
	Cheltuiala c2 = Cheltuiala(15,aux, 5);
	r.addElement(c2);
	char aux1[] = "Menaj";
	Cheltuiala c3 = Cheltuiala(16,aux1, 6);
	r.addElement(c3);
	lc = r.getAll();
	assert(strcmp((*lc).toString(), "15;aux;5;") == 1);
	
	cout << "Teste Repo trecute cu succes";


}