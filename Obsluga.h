#pragma once
#include <vector>
#include <iostream>
using namespace std;

class Klient;
class Kurs;


class Obsluga
{public:
	Obsluga();
	virtual ~Obsluga();

	void obsluz_klienta(Kurs* k,int l_biletow, Klient* klient);//zmiana !! Klient!!!
	void zaladuj_kursy(Kurs* k);
	bool czy_wolne_miejscce(Kurs* k);
	Kurs* szukaj_polaczenia(string start, string end);
	int policz_sprzedane();
	static int l_obslug;

	/********drugi projekt*********/
	void zwrotBiletu();
	/******************************/
	
	
	friend istream& operator>>(istream& s, Obsluga& o);
	friend ostream& operator<<(ostream& s, Obsluga& o);

protected:
	vector<Klient*> klienci;
	vector<Kurs*> kursy;


	/********drugi projekt*********/
	bool mozliwoscZwrotu=false;
};