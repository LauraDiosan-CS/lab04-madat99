#include "ui.h"

UI::UI()
{
	this->ctrl = Service();
}

UI::UI(Service& c)
{
	this->ctrl = c;
}

UI::~UI()
{
	//cout << "destructor ui";
}

/*
Descr: afiseaza meniul
*/
void UI::printMenu()
{
	cout << endl;
	cout << "OPTIUNI: " << endl;
	cout << "1. Adauga cheltuiala" << endl;
	cout << "2. Elimina cheltuielile dintr-o zi" << endl;
	cout << "3. Elimina cheltuielile din zilele x - y" << endl;
	cout << "4. Eliminare dupa tip" << endl;
	cout << "5. Inlocuire pret cheltuiala" << endl;
	cout << "6. Afisare lista cheltuieli" << endl;
	cout << "7. Afisarea cheltuielilor dintr-o zi" << endl;
	cout << "8. Afisarea cheltuielilor cu valoare mai mare decat v" << endl;
	cout << "9. Afisarea cheltuielilor cu o anumita valoare" << endl;
	cout << "10. Suma totala a chetuielilor de acelasi tip" << endl;
	cout << "11. Cea mai valoroasa cheltuiala dintr-o zi" << endl;
	cout << "12. Sortare dupa tip" << endl;
	cout << "13. Filtrare dupa tip" << endl;
	cout << "14. Filtrare dupa valoare" << endl;
	//cout << "15. Undo" << endl;
	cout << "15. Iesire " << endl;
	cout << "Introduceti optiunea (prin numarul ei): " << endl;
}

/*
Descr: afiseaza lista de apartamente
*/
void UI::afiseaza() {
	ctrl.afisare(1, 0, 0, 0);
}

void UI::adauga() {
	char* tip = new char[20];
	int p; int zi;
	cin >> tip;
	cin >> p;
	cin >> zi;
	Cheltuiala c = Cheltuiala(zi, tip, p);
	ctrl.addC(zi, p, tip);
}

void UI::run()
{
	while (true)
	{
		printMenu();
		char* optiune = new char[30];
		cout << "Alegeti optiunea dorita: ";
		cin >> optiune;
		if (strcmp(optiune, "1") == 0)
		{
			int zi, p;
			char* tip = new char[4];
			cout << "Ziua Cheltuielii:-nr intre 1 si 31- ";  cin >> zi;
			cout << "Tip: "; cin >> tip;
			cout << "Pret: "; cin >> p;
			ctrl.addC(zi, p, tip);
		}
		else if (strcmp(optiune, "2") == 0)
		{
			int zi;
			cout << "Introduceti ziua: "; cin >> zi;
			ctrl.eliminare(zi, 0, NULL, 0, 1);
			//cout << "Lista modificata: ";
			//ctrl.afisare(1,0,0,0);
		}
		else if (strcmp(optiune, "3") == 0)
		{
			int st, fi;
			cout << "Introduceti start: ";
			cin >> st;
			cout << "Introduceti final: ";
			cin >> fi;
			//nu merge
			ctrl.eliminare(0, st, NULL, fi, 2);
		}
		else if (strcmp(optiune, "4") == 0)
		{
			char* tip = new char[20];
			cout << "Introduceti tipul: ";
			cin >> tip;
			ctrl.eliminare(0, 0, tip, 0, 3);
		}
		else if (strcmp(optiune, "5") == 0)
		{
			int zi, val;
			char* tip = new char[10];
			cout << "Introduceti ziua: ";
			cin >> zi;
			cout << "Introduceti tipul cheltuielii: ";
			cin >> tip;
			cout << "Introduceti valoarea cu care se inlocuieste pretul: ";
			cin >> val;
			ctrl.inlocuire_gaz(tip, zi, val);
		}
		else if (strcmp(optiune, "6") == 0)
		{
			ctrl.afisare(1, 0, 0, 0);
		}
		else if (strcmp(optiune, "7") == 0)
		{
			int zi;
			cout << "Introduceti ziua: ";
			cin >> zi;
			ctrl.afisare(3, zi, 0, 0);
		}
		else if (strcmp(optiune, "8") == 0)
		{
			int val;
			cout << "Introduceti limita: ";
			cin >> val;
			ctrl.afisare(4, 0, 0, val);
		}
		else if (strcmp(optiune, "9") == 0)
		{
			int s;
			cout << "Introduceti valoarea: ";
			cin >> s;
			ctrl.afisare(2, 0, s, 0);
		}
		else if (strcmp(optiune, "10") == 0)
		{
			char* tip = new char[20];
			cout << "Introduceti tipul: ";
			cin >> tip;
			int s = 0;
			ctrl.obtPropr(tip, 1, s, 0);
			cout << s << endl;
		}
		else if (strcmp(optiune, "11") == 0)
		{
			int zi;
			cout << "Introduceti ziua: ";
			cin >> zi;
			int s = 0;
			ctrl.obtPropr(NULL, 2, s, zi);
		}
		else if (strcmp(optiune, "12") == 0)
		{
			char* tip = new char[20];
			cout << "Introduceti tipul: ";
			cin >> tip;
			int s = 0;
			ctrl.obtPropr(tip, 3, s, 0);
		}
		else if (strcmp(optiune, "13") == 0)
		{
			char* tip = new char[20];
			cout << "Introduceti tipul: ";
			cin >> tip;
			ctrl.filtrare(tip, 0, 1);
		}
		else if (strcmp(optiune, "14") == 0)
		{
			int val;
			cout << "Introduceti valoarea: ";
			cin >> val;
			ctrl.filtrare(NULL, val, 2);
		}
		else if (strcmp(optiune, "16") == 0)
		{
			//To do undo
		}
		else if (strcmp(optiune, "15") == 0)
		{
			 cout << "LA REVEDERE!" << endl;
			return;
		}
		else
		{
			cout << "Comanda invalida!" << endl;
		}
	}
}