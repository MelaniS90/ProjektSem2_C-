#pragma once
#include <iostream>

using namespace std;

class Kurs;

class Bilet
{public:
	Bilet();
	~Bilet();
	Bilet(Kurs* k);
	friend istream& operator>>(istream& s, Bilet& b);
	friend ostream& operator<<(ostream& s, Bilet& b);
	
	Kurs* k;
	int miejscowka;
};