#pragma once
#ifndef UI_H
#define UI_H
#include "Service.h"
class UI {
private:
	Service ctrl;
	void printMenu();
	void adauga();
	void afiseaza();
public:
	UI();
	~UI();
	UI(Service& c);
	void run();
};


#endif