#pragma once
#include <string>

using namespace std;


class Kurs
{public:
	Kurs();
	Kurs(int data, int l_miejsc, string start, string koniec) : data(data), l_miejsc(l_miejsc), start(start), koniec(koniec) {};
	Kurs(const Kurs& k);

	int data; //na razie int
	int l_miejsc; //w pociagu danego kursu
	int zajete_miejsca=0;
	string start;
	string koniec;

	friend class Bilet;
	friend istream& operator>>(istream& s, Kurs& k);
	friend ostream& operator<<(ostream& s, Kurs& k);

};