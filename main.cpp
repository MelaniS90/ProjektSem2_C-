#include <cstdio>
#include <iostream>
#include <fstream>
#include "Obsluga.h"
#include "Bilet.h"
#include "Klient.h"
#include "Kursy.h"

using namespace std;


int main()
{	
	Kurs* k1=new Kurs(12, 100,"Warszawa", "Gdansk");
	Kurs* k2=new Kurs(34, 78, "Krakow", "Warszawa");

	Obsluga kasa;
	kasa.zaladuj_kursy(k1);
	kasa.zaladuj_kursy(k2);


	/*************************************************************************************/
	/*Zapis Obiektu kasa do pliku*/
	/*************************************************************************************/
	cout << kasa;
	ofstream file;
	file.open("test.txt");
	file << kasa;
	file.close();

	/****************************************************************************************/
	/*Odczyt z pliku*/
	/*****************************************************************************************/
	Obsluga obsl;

	ifstream file1;
	file1.open("test.txt");
	file1 >> obsl;
	file1.close();

	cout << obsl;

	/******************************************************************************************/
	/*Wyszukiwanie polaczenia*/
	/******************************************************************************************/
	cout<< *kasa.szukaj_polaczenia("Warszawa", "Gdansk");
	cout << *kasa.szukaj_polaczenia("Krakow", "Szczecin");


	/******************************************************************************************/
	/*Sprzedarz biletow*/
	/******************************************************************************************/
	cout << *k2;
	Klient k;

	kasa.obsluz_klienta(k2,4,&k);
	//kasa.obsluz_klienta(k2,1);
	//kasa.obsluz_klienta(k2,1);

	cout << *k2;


	system("pause");
	return 0;
}