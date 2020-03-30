#pragma once
#include <vector>
#include <iostream>

using namespace std;

class Bilet;
class Kurs;

class Klient
{public:
	Klient();
	Klient(Kurs* k);
	Klient(Kurs* k, int l_biletow);
	void kup_bilet(Kurs* k);

	friend class Obsluga;
	friend istream& operator>>(istream& s, Klient& k);
	friend ostream& operator<<(ostream& s, Klient& k);

private:
	vector <Bilet*> bilety;
	int l_biletow;
};