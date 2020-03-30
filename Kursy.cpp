#include "Kursy.h"
#include <iostream>

using namespace std;


Kurs::Kurs(){
	#ifdef _DEBUG
		cout << "utworzono obiekt Kurs" << endl;
	#endif
}

istream& operator>>(istream &s, Kurs &k)
{
	string dane;
	s >> dane;
	return s;
}

ostream& operator<<(ostream &s, Kurs &k)
{
	if (&k != nullptr)
	{
		s << k.data;
		s << " ";
		s << k.l_miejsc;
		s << " ";
		s << k.start;
		s << " ";
		s << k.koniec;
		s << " ";
		s << k.l_miejsc-k.zajete_miejsca;
		s << endl;
	}
	return s;
}
