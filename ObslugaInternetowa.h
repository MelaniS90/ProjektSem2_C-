#pragma once
/******Drugi prjekt******/
#include "Obsluga.h"
#include <iostream>
#include <vector>

class Bilet;

using namespace std;

class ObslugaInternetowa: public Obsluga
{
public:
	ObslugaInternetowa() {};
	void Rezerwuj() {};
	void InformujOopoznieniach() {};
	void kupZarezerwowany() {};


private:
	vector <Bilet*> rezerwacja ;
	void usunRezerwacje() {};
	

};