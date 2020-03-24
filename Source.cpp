#include <iostream>
#include "Cheltuiala.h"
#include "Repo.h"
#include "Service.h"
#include "TestC.h"
#include "TestR.h"
#include "TestService.h"
#include "Ui.h"
using namespace std;

int main(){

	//tests();
	//TestRepo();

	//cout << " start main ..." << endl;

	//teste();
	//teste2();
	//testService();
	Repo r;
	Service c;
	c = Service(r);
	char* tip = new char[4];
	strcpy_s(tip, 4, "gaz");
	Cheltuiala ch = Cheltuiala(12, tip, 150);
	char* x = new char[10];
	strcpy_s(x, 9, "internet");
	Cheltuiala ap1 = Cheltuiala(11, x, 70);
	c.addC(12, 150, tip);
	c.addC(11, 70, x);
	UI ui;
	ui = UI(c);
	
	ui.run();
	
	system("pause");
	return 0;
	
}
