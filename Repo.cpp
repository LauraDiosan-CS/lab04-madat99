#include "Cheltuiala.h"
#include <string>
#include "Repo.h"

//Descr: create repo 
//In: -
//Out: an instance of repo
Repo::Repo() {
	
	
	this->nrc = 0;
	this->lc = new Cheltuiala[MAX_CHELTUIELI];
}

Repo::Repo(int nrC, Cheltuiala* c) {
	
	this->nrc = nrC;
	this->lc = new Cheltuiala[nrc];
	for (int i = 0; i < this->nrc; i++)
		this->lc[i] = c[i];
	
}

/*
Descr: creeaza un repo utilizand informatii de la alt repo
In: un repo(r)
Out: o instanta de Repo cu informatii de la r
*/
Repo::Repo(const Repo &r) {
	
	this->nrc = r.nrc;

	if (this->lc)
		delete[]this->lc;
	this->lc = new Cheltuiala[this->nrc];
	for (int i = 0; i < this->nrc; i++)
		this->lc[i] = r.lc[i];
	
}

Repo::~Repo() {
	if (this->lc != NULL) {
		
		delete[] this->lc;
		this->lc = NULL;
	}
}

/*
Descr: creeeaza un nou repo(egal cu cel dat r)
In: un repo(r)
Out: un nou repo(egal cu r)
*/
Repo& Repo::operator=(const Repo& r) {
	if (this != &r)
	{
		this->nrc = r.nrc;
		
		if (this->lc)
			delete[]this->lc;
		this->lc = new Cheltuiala[this->nrc];
		for (int i = 0; i < this->nrc; i++)
			this->lc[i] = r.lc[i];
	}
	return *this;
}

//adauga o cheltuiala in repo

void Repo::addElement(Cheltuiala el) {

	this->lc[this->nrc] = el;
	this->nrc++;
	
}

/*
Descr: acceseaza un apartament(de la o pozitie)
In : un repo si o pozitie
Out : apartamentul de la pozitia respectiva
*/
Cheltuiala & Repo::getCheltuiala(int pos) {
	//if ((pos >= 0) && (pos < this->numar))
	return this->lc[pos];
}


/*
Descr: converteste un repo la un string
In: un repo
Out: stringul corespunzator
*/

char* Repo::toString() {
	int lungimea = this->nrc * (MAX_CHELTUIELI + 1) + 6;
	char* s = new char[lungimea];
	char* aux = new char[5];
	_itoa_s(this->nrc, aux, 5, 10);
	strcpy_s(s, 1, "");
	for (int i = 0; i < this->nrc; i++) {
		strcat_s(s, 50, this->lc[i].toString());
	}
	return s;
}

/*
Descr: returneaza lista de cheltuieli
Input: -
Output: lista de cheltuieli
*/
Cheltuiala* Repo::getAll()
{
	return this->lc;
}

	int Repo::getSize()
	{
		return this->nrc;
	}


	/*
Descr: afiseaza o lista
Input: -
Output: afisare
*/
	void Repo::afisareLista()
	{
		Cheltuiala* c = new Cheltuiala[this->nrc];
		c = this->getAll();
		for (int i = 0; i < this->nrc; i++)
			cout << c[i].toString();
	}

	/*
	Descr: cauta o cheltuiala dupa pret
	Input: pretul dupa care se face cautarea
	Output: pozitia cheltuielii
	*/
	int Repo::cautaPosPret(int pret) {
		int pozc = -1;
		Cheltuiala* chelt = new Cheltuiala[this->nrc];
		chelt = this->getAll();
		for (int i = 0; i < this->nrc; i++) {
			if (chelt[i].getPrice() == pret) {
				pozc = i;
			}
		}
		return pozc;
	}

	/*
	Descr: cauta o cheltuiala dupa zi 
	Input: numarul dupa care se face cautarea
	Output: pozitia cheltuielii
	*/

	int Repo::cautaPosZi(int zi) {
		int pozc = -1;
		Cheltuiala* chelt = new Cheltuiala[this->nrc];
		chelt = this->getAll();
		for (int i = 0; i < this->nrc; i++) {
			if (chelt[i].getZi() == zi) {
				pozc = i;
			}
		}
		return pozc;
	}

	/*
	Descr: cauta o cheltuiala dupa tip
	Input: tipul dupa care se face cautarea
	Output: pozitia cheltuielii
	*/
	int Repo::cautaPosTip(char* tip) {
		int pozc = -1;
		Cheltuiala* chelt = new Cheltuiala[this->nrc];
		chelt = this->getAll();
		for (int i = 0; i < this->nrc; i++) {
			if (strcmp(chelt[i].getTip(), tip) == 0) {
				pozc = i;
			}
		}
		return pozc;
	}

	/*
	Descr: modifica pretul unei cheltuieli
	Input: pretul actual si cel cu care se inlocuieste
	Output: -
	*/
	void Repo::updatePret(int pret1, int pret2) {
		int rez = -1;
		Cheltuiala* chelt = new Cheltuiala[this->nrc];
		chelt = this->getAll();
		rez = this->cautaPosPret(pret1);
		chelt[rez].setPrice(pret2);
	}

	/*
	Descr: modifica tipul unei cheltuieli
	Input: tipul actual si cel cu care se inlocuieste
	Output: -
	*/
	void Repo::updateTip(char* tip1, char* tip2) {
		int rez = -1;
		Cheltuiala* chelt = new Cheltuiala[this->nrc];
		chelt = this->getAll();
		rez = this->cautaPosTip(tip1);
		chelt[rez].setTip(tip2);
	}

	/*
	Descr: modifica ziua unei cheltuieli
	Input: numarul actual si cel cu care se inlocuieste
	Output: -
	*/
	void Repo::updateZi(int ap1, int ap2) {
		int rez = -1;
		Cheltuiala* chelt = new Cheltuiala[this->nrc];
		chelt = this->getAll();
		rez = this->cautaPosZi(ap1);
		chelt[rez].setZi(ap2);
	}

	void Repo::setLista(Cheltuiala* c)
	{
		this->lc = c;
	}

	/*
	Descr:
	*/
	void Repo::update(Cheltuiala& c, Cheltuiala& c2)
	{
		int ok = 1;
		Cheltuiala* chelt = new Cheltuiala[this->nrc];
		chelt = this->getAll();
		for (int i = 0; i < this->nrc; i++)
		{
			if (strcmp(chelt[i].toString(), c.toString()) != 0)
			{
				ok = 0;
				this->lc[i] =c2;
			}
		}
		if (ok == 1)
		{
			cout << "nu exista cheltuiala" << endl;
		}
	}

	/*
	Descr: elimina o cheltuiala dupa pozitia din lista
	Input: pozitia de pe care se elimina
	Output: lista modificata
	*/
	void Repo::eliminare(int poz)
	{
		Cheltuiala* chelt = new Cheltuiala[this->nrc];
		chelt = this->getAll();
		for (int i = poz; i < this->nrc - 1; i++) {
			chelt[i] = chelt[i + 1];
		}
		this->nrc--;
	}