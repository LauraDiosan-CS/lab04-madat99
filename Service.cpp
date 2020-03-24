#include "Repo.h"
#include "Service.h"
#include <cstring>
#include <iostream>

Service::Service()
{
	//cout << "constructor fara parametrii controller" << endl;
	this->repo = Repo();
}

Service::Service(Repo& r)
{
	//cout << "constructor cu parametrii controller" << endl;
	this->repo = r;
}

Service::Service(const Service& c)
{
	//cout << "constructor de copiere controller" << endl;
	this->repo = c.repo;
}

Service::~Service()
{
	//cout << "destructor controller" << endl;
}

Service& Service::operator=(const Service& c)
{
	if (this != &c) this->repo = c.repo;
	return *this;
}

Repo Service::getRepo()
{
	return this->repo;
}

/*
Descr: calculeaza suma totala in functie de tip
calculeaza cea mai valoroasa cheltuiala a apartamentului ap
sorteaza in functie de tip
Input: tip, ok (in functie ce cerinta), suma
Output: in functie de cerinta (suma, )
*/
void Service::obtPropr(char* tip, int ok, int& suma, int ap)
{
	Cheltuiala* ch = new Cheltuiala[this->repo.getSize()];
	ch = this->repo.getAll();
	if (ok == 1)
	{
		int sumT = 0;
		for (int i = 0; i < this->repo.getSize(); i++)
		{
			if (strcmp(ch[i].getTip(), tip) == 0)
			{
				sumT = sumT + ch[i].getPrice();
			}
		}
		//cout << "suma este: " << sumT;
		suma = sumT;
	}
	else if (ok == 2)
	{
		int max = 0;
		for (int i = 0; i < this->repo.getSize(); i++)
		{
			if (ch[i].getZi() == ap && ch[i].getPrice() > max)
			{
				max = ch[i].getPrice();
			}
		}
		cout << "cea mai valoroasa cheltuiala a apartamentului " << ap << " este: " << max;
	}
	else if (ok == 3)
	{
		Cheltuiala* rez = new Cheltuiala[this->repo.getSize()];
		int n = 0;
		for (int i = 0; i < this->repo.getSize(); i++)
		{
			if (strcmp(repo.getCheltuiala(i).getTip(), tip) == 0)
			{
				cout << repo.getCheltuiala(i).toString() << endl;
				rez[n] = repo.getCheltuiala(i);
				n++;
			}
		}
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (rez[i].getPrice() < rez[j].getPrice())
				{
					Cheltuiala aux;
					aux = rez[i];
					rez[i] = rez[j];
					rez[j] = aux;
				}
			}
		}
		for (int i = 0; i < n; i++)
		{
			cout << rez[i].toString() << " ";
		}
	}
}

char* Service::toString()
{
	char* ap = new char[this->repo.getSize()];
	ap = this->repo.toString();
	return ap;
}

Cheltuiala* Service::getAllC()
{
	return this->repo.getAll();
}

Cheltuiala& Service::getC(int pos) {
	//if ((pos >= 0) && (pos < this->numar))
	return this->repo.getCheltuiala(pos);
}

void Service::addC(int zi, int p, char* tip)
{
	Cheltuiala c = Cheltuiala(zi, tip, p);
	this->repo.addElement(c);
}

void Service::stergere(int zi, int p, char* tip)
{
	Cheltuiala ch= Cheltuiala(zi, tip, p);
	int poz = repo.cautaPosZi(zi);
	repo.eliminare(poz);
}
/*
Descr: afiseaza lista, cheltuielile mai mari de 100,
toate cheltuielile unui apartament,
cheltuielile egale cu o suma data
Input:
Output:
*/
void Service::afisare(int ok, int val, int suma, int comp)
{
	Cheltuiala* ch = new Cheltuiala[this->repo.getSize()];
	ch = this->repo.getAll();
	if (ok == 1)
	{
		for (int i = 0; i < this->repo.getSize(); i++)
		{
			cout << ch[i].toString() << " ";
		}
		cout << endl;
	}
	else if (ok == 2)
	{
		for (int i = 0; i <= this->repo.getSize(); i++)
		{
			if (ch[i].getPrice() == suma)
			{
				cout << ch[i].toString() << " ";
			}
		}
	}
	else if (ok == 3)
	{
		for (int i = 0; i < this->repo.getSize(); i++)
		{
			if (ch[i].getZi() == val)
			{
				cout << ch[i].toString() << " ";
			}
		}
	}
	else if (ok == 4)
	{
		for (int i = 0; i < this->repo.getSize(); i++)
		{
			if (ch[i].getPrice() > comp)
			{
				cout << ch[i].toString() << " ";
			}
		}
	}
}

/*
Descr: elimina cheltuielile unui apartament
elimina cheltuielile apartamentelor de la start la final
elimina chetuielile dupa tip
Input: apartament, start, final, tip, ok(optiunea)
Output: rezultatul in functie de cerinta
*/
void Service::eliminare(int ap, int st, char* tip, int fi, int ok)
{
	Cheltuiala* ch = new Cheltuiala[this->repo.getSize()];
	ch = this->repo.getAll();
	if (ok == 1)
	{
		int i = 0;
		while (i < this->repo.getSize())
		{
			if (this->repo.getCheltuiala(i).getZi() == ap)
			{
				repo.eliminare(i);
			}
			else
			{
				i++;
			}
		}
	}
	else if (ok == 2)
	{
		int i = 0;
		while (i < this->repo.getSize())
		{
			if (this->repo.getCheltuiala(i).getZi() >= st && this->repo.getCheltuiala(i).getZi() <= fi)
			{
				repo.eliminare(i);
			}
			else
			{
				i++;
			}
		}
	}
	else if (ok == 3)
	{
		int i = 0;
		while (i < this->repo.getSize())
		{
			if (strcmp(this->repo.getCheltuiala(i).getTip(), tip) == 0)
			{
				repo.eliminare(i);
			}
			else
			{
				i++;
			}
		}
	}
}

void Service::inlocuire(int zi, int p, char* tip, int zi2, int p2, char* tip2)
{
Cheltuiala c = Cheltuiala(zi, tip, p);
Cheltuiala c2 = Cheltuiala(zi2, tip2, p2);
this->repo.update(c, c2);
}


/*
Descr: inlocuirea pretului unei cheltuieli in functie de tip si ziua cheltuielii
Input: tipul dupa care se face inlocuirea si numarul apartamentului
Output: -
*/
void Service::inlocuire_gaz(char* tip, int v, int n)
{
	Cheltuiala* ch = new Cheltuiala[this->repo.getSize()];
	ch = this->repo.getAll();
	for (int i = 0; i < this->repo.getSize(); i++)
	{
		if (strcmp(ch[i].getTip(), tip) == 0 && ch[i].getZi() == v)
		{
			ch[i].setPrice(n);
		}
	}
}

/*
Descr: filtreaza lista
eliminand cheltuielile dupa un anumit tip
eliminand cheltuielile mai mari decat o valoare
Input: tipul, valoarea, ok(id cerinta)
Output: -
*/
void Service::filtrare(char* tip, int val, int ok)
{
	if (ok == 1)
	{
		int i = 0;
		while (i < this->repo.getSize())
		{
			if (strcmp(this->repo.getCheltuiala(i).getTip(), tip) != 0)
			{
				repo.eliminare(i);
			}
			else
			{
				i++;
			}
		}
	}
	else if (ok == 2)
	{
		int i = 0;
		while (i < this->repo.getSize())
		{
			if (this->repo.getCheltuiala(i).getPrice() >= val)
			{
				repo.eliminare(i);
			}
			else
			{
				i++;
			}
		}
	}
}

void Service::setLista(Cheltuiala* c)
{
	this->repo.setLista(c);
}

int Service::getSizeC()
{
	return this->repo.getSize();
}



void Service::update(Cheltuiala& c, char* tip, int zi2, int p)
{
	Cheltuiala c2 = Cheltuiala(zi2, tip, p);
	repo.update(c, c2);
}