#include "Obsluga.h"
#include "Klient.h"
#include "Bilet.h"
#include "Kursy.h"
#include <iostream>
#include <string>

using namespace std;

int Obsluga::l_obslug = 0;

Obsluga::Obsluga() {
	#ifdef _DEBUG
		cout << "utworzono obiekt Obsluga" << endl;
	#endif
	l_obslug++;
}

Obsluga::~Obsluga(){}

void Obsluga::obsluz_klienta(Kurs* k,int l_biletow,Klient* klient)        //pamietaj o zmianie! Klient!!!
{
	if (czy_wolne_miejscce(k) && l_biletow <= (k->l_miejsc - k->zajete_miejsca)) {
		klienci.push_back(klient);
		for (int i = 0;i < l_biletow;i++)
			klient->kup_bilet(k);
		k->zajete_miejsca = k->zajete_miejsca + 1 * l_biletow;
	}
}

void Obsluga::zaladuj_kursy(Kurs* k)
{
	kursy.push_back(k);
}

bool Obsluga::czy_wolne_miejscce(Kurs* k)
{
	if (k->zajete_miejsca < k->l_miejsc)
		return true;
	else
		return false;
}

int Obsluga::policz_sprzedane()
{
	int sprzedane_bilety=0;
	for (Kurs* kurs : kursy)
		sprzedane_bilety += kurs->zajete_miejsca;
	return sprzedane_bilety;
}

Kurs* Obsluga::szukaj_polaczenia(string start, string end)
{
	int iter = 0;
	int index=-1;
	for (Kurs* kurs : kursy)
	{	
		if (kurs->start == start && kurs->koniec==end)
			index = iter;
		iter++;
	}
	if (index != -1)
		return this->kursy[index];
	else
		return nullptr;
}

istream& operator>>(istream &s, Obsluga &o)
{	
	string start, koniec;
	int l_kursow,l_sprzedane, data, l_miejsc;
	s >> o.l_obslug;
	s >> l_sprzedane;
	s >> l_kursow;
	for (int i = 0; i < l_kursow; i++)
	{
		s >> data;
		s >> l_miejsc;
		s >> start;
		s >> koniec;
		Kurs* k = new Kurs(data, l_miejsc, start, koniec);
		o.kursy.push_back(k);
	}
	return s;
}

ostream& operator<<(ostream &s, Obsluga &o)
{
	s << o.l_obslug;
	s << " ";
	s << o.policz_sprzedane();
	s << " ";
	s << o.kursy.size();
	s << endl;
	for (int i = 0; i < o.kursy.size(); i++)
		s << *o.kursy[i];
	

	s << endl;
	return s;
}
