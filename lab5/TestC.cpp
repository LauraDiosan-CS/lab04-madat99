#include "TestC.h"
#include "assert.h"

void tests() {
	Cheltuiala c1 = Cheltuiala();	//cheltuiala goala
							//Cheltuiala c1;
	
	assert(c1.getPrice() == 0);
	assert(strcmp(c1.toString(), "") == 0);

	char aux[] = "Internet";
	
	Cheltuiala c2 = Cheltuiala(aux, 10);	//o cheltuiala cu info
	
	assert(c2.getPrice() == 10);
	assert(strcmp(c2.toString(), "Internet;10;") == 1);

	Cheltuiala c3 = Cheltuiala(c2);	//c3 = o copie a cheltuielii c2
	
	assert(c3.getPrice() == 10);
	

	

	c3.setPrice(5);
	assert(c3.getPrice() == 5);
	assert(strcmp(c3.toString(), "Internet;5;") == 1);

	cout << "Teste trecute cu succes";

}

