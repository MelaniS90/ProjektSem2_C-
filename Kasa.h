#pragma once
/******Drugi projekt*******/
#include "Obsluga.h"


class Kasa: public Obsluga
{
public:
	Kasa() { Obsluga::mozliwoscZwrotu = true; };
	

private:
	void DrukujBilet();//zapis do pliku
};

