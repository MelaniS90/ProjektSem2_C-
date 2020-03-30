#include "Bilet.h"
#include "Kursy.h"
#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

Bilet::Bilet(){
	#ifdef _DEBUG
		cout << "utworzono obiekt Bilet" << endl;
	#endif
}

Bilet::~Bilet()
{
	delete k;
}

Bilet::Bilet(Kurs* k)
{
	this->k = k;
	this->miejscowka = rand() % k->l_miejsc;
}

istream& operator>>(istream& s, Bilet& b)
{
	string dane;
	s >> dane;
	return s;
}

ostream& operator<<(ostream& s, Bilet& b)
{	s << b.k->data;
	s << b.k->start;
	s << b.k->koniec;
	s << b.miejscowka;
	return s;
}