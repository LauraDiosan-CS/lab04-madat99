#include "Cheltuiala.h"
#include <string>
#include "Repo.h"

//Descr: create repo 
//In: -
//Out: an instance of repo
Repo::Repo() {
	
	this->lc = NULL;
	this->nrc = 0;
	
}

Repo::Repo(int nrC, Cheltuiala* lc) {
	
	this->nrc = nrC;
	
}


Repo::Repo(const Repo &f) {
	
	this->nrc = f.nrc;
	
}

Repo::~Repo() {
	if (this->lc != NULL) {
		
		delete[] this->lc;
		this->lc = NULL;
	}
}

void Repo::addElement(Cheltuiala el) {

	this->lc[nrc] = el;
	this->nrc++;
	
}

Cheltuiala* Repo::getAll()
{
	return this->lc;
}

	int Repo::getSize()
	{
		return this->nrc;
	}