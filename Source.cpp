//include<iostream> //W klasie Czas
//#include <vector> //W klasie Obrabiarka
//#include <stdexcept> //do zabezpieczen w klasie Obrabiarka
#include "Obrabiarka.h"
#include <string>
#include <cctype>

//funkcje wejscia
long int dajInt() {
	using namespace std;
	const int sizeLimit = 5;
	string str;
	while (true) {
		cin >> str;
		if ((int)str.size() > sizeLimit) {
			cerr << "Liczba jest za dluga. Podaj liczbe calkowita: " << endl;
			continue;
		}
		for (int i = 0; i < (int)str.size(); i++) {
			if (!(isdigit(str[i]) || str[i] == '-')) {
				cerr << "Podaj liczbe calkowita: ";
				continue;
			}
		}
		break;
	}
	return stoi(str);
}

bool takCzyNie() {
	using namespace std;
	int q;
	while (true) {
		cout << "	1) Tak\n	2) Nie" << endl;
		q = dajInt();
		if (q == 1)
			return true;
		else if (q == 2)
			return false;
		else
			continue;
	}
	return false;
}

//testowanie metod, konstruktorow, operatorow itd. klas Czas i Obrabiarka
void test() {
	using namespace std;
	//test klasy czas
	Czas z1;
	Czas z2 = Czas(2312, 61, 2);
	z1.setGodz(5);
	z1.setMin(59);
	z1.setSek(3);
	z1.printCzas();
	z2.printCzas();
	z1 = z1 + z2;
	z1.printCzas();
	z1 += 125;
	z1.printCzas();
	if (z1 > z2) {
		cout << "z1 wiekszy" << endl;
	}
	if (z2 < z1) {
		cout << "z1 wiekszy" << endl;
	}
	//test klasy obrabiarka
	Obrabiarka o1;
	o1.push(z1);
	o1.push(z2);
	z1.setCzas(13, 31, 1);
	o1.push(z1); //push istniejacego obiektu klasy Czas
	o1.push(1342); //push w sekundach
	o1.push(59, 59, 2);//push w docelowym foracie czasu
	cout << "Ilosc procesow: " << o1.getCount() << endl;
	cout << "Obiekt o1: " << endl;
	o1.printAll();
	o1.printSum();
	o1.printAt(100);//sprawdzenie zabezpieczen
	z2 = o1.getAt(101);
	o1.printAt(3);
	cout << "Obiekt o2 utworzony na podstawie o1 " << endl;
	Obrabiarka o2 = Obrabiarka(o1); //test kopiujacego konstr.
	o2.printAll();
	o1.clear();
	cout << "Obiekt o1 po wyczyszczeniu: " << endl;
	o1.printAll();
	cout << "Obiekt o2: " << endl;
	o2.printAll();
	Obrabiarka o3;
	cout << "Utworzenie o3 przy pomocy operatora = : " << endl;
	o3 = o2; //test operatora przypisania
	o3.printAll();
	cout << "o1 : " << endl;
	o1.printAll();
	cout << "o1 po skopiowaniu n elementow z o3: " << endl;
	o1.cpy(o3, 3);
	o1.printAll();
	o3.push(34, 23, 5);
	cout << "Obiekt o3: " << endl;
	o3.printAll();
	z1.setCzas(23, 45, 13);
	o2 = o3.getLimited(z1);
	cout << "z1: " << endl;
	z1.printCzas();
	cout << "o2 = o3 ograniczone do z1:" << endl;
	o2.printAll();
	//return 0;
}

void test2() {
	using namespace std;
	Obrabiarka o;
	Obrabiarka kopia;
	o.push(30, 1, 0);
	o.push(15, 30, 1);
	o.push(15, 45, 2);
	o.push(23, 54, 1);
	o.push(43, 21, 7);
	o.push(29, 1, 3);
	cout << "Lista czasow dodanych \"na sztywno\" : " << endl;
	o.printAll();
	cout << "Ile pierwszych czasow chcesz skopiowac? : ";
	kopia.cpy(o, dajInt());
	cout << "Skopiowana ";
	kopia.printAll();
	cout << "Koniec testu" << endl << endl;
}

void test3() {
	using namespace std;
	Czas z;
	Obrabiarka o;
	Obrabiarka kopia;
	o.push(30, 1, 0);
	o.push(15, 30, 1);
	o.push(15, 45, 2);
	o.push(23, 54, 1);
	o.push(43, 21, 7);
	o.push(29, 1, 3);
	cout << "Lista czasow dodanych \"na sztywno\" : " << endl;
	o.printAll();
	cout << "Suma tych czasow to : " << endl;
	o.printSum();
	cout << "Podaj wartosci czasu do ktorego ma byc ograniczona kopia: " << endl << "Ilosc sekund: ";
	while (!z.setSek(dajInt())) {}
	cout << "Ilosc minut: ";
	while (!z.setMin(dajInt())) {}
	cout << "Ilosc godzin: ";
	while (!z.setGodz(dajInt())) {}
	cout << "Wprowadzono czas o wartosci : ";
	z.printCzas();
	kopia = o.getLimited(z);
	cout << "Skopiowana lista czasow ograniczona do podanego czasu: " << endl;
	kopia.printAll();
	cout << "Suma tych czasow to : " << endl;
	kopia.printSum();
	cout << "Koniec testu." << endl << endl;
}

void menu() {
	using namespace std;
	int w = 0;
	while (w != -1) {
		switch (w) {
		case 0:
			cout << "Wybierz opcje: " << endl;
			cout << "1) Ogolny test podstawowych metod/operatorow klasy Czas i Obrabiarka." << endl;
			cout << "2) Test kopii obrabiarki (n pierwszych czasow)" << endl;
			cout << "3) Test kopii obrabiarki (ograniczone do podanego czasu) " << endl;
			cout << "4) Zakoncz " << endl;
			while (true) {
				w = dajInt();
				if (w >= 1 && w <= 4) {
					break;
				}
				cout << "Podaj liczbe od 1 do 4 : ";
				continue;
			}
			break;
		case 1:
			test();
			w = 0;
			break;
		case 2:
			test2();
			w = 0;
			break;
		case 3:
			test3();
			w = 0;
			break;
		case 4:
			cout << "Czy napewno chcesz zakonczyc program? " << endl;
			if (takCzyNie()) {
				w = -1;
				break;
			}
			w = 0;
			break;
		}
	}
}

int main() {
	menu();
	std::cout << "Koniec dzialania programu" << std::endl;
	return 0;
}