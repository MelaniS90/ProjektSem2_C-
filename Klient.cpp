#include "Klient.h"
#include "Bilet.h"
#include "Kursy.h"
#include <vector>
#include <iostream>

using namespace std;

Klient::Klient(){
	#ifdef _DEBUG
		cout << "utworzono obiekt Klient" << endl;
	#endif

}

Klient::Klient(Kurs *k)
{
	this->l_biletow = 1;
	this->kup_bilet(k);
}

Klient::Klient(Kurs *k, int l_biletow)
{
	this->l_biletow = l_biletow;
	for(int i=0;i<l_biletow;i++)
		this->kup_bilet(k);
}

void Klient::kup_bilet(Kurs* k)
{
	//Bilet* bilety = new Bilet[l_biletow];
	//for (int i = 0; i < l_biletow; l_biletow++)
	//{
	//	bilety[i]=Bilet(k);
	//}
	Bilet* b = new Bilet(k);
	bilety.push_back(b);
}

istream& operator>>(istream& s, Klient& k)
{
	string dane;
	s >> dane;
	return s;
}

ostream& operator<<(ostream& s, Klient& k)
{
	s << k.l_biletow;
	return s;
}