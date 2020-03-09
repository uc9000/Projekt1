#include "Czas.h"
void Czas::format() { //ustawia prawidlowy format czasu (sek;min;godz). Ogolnie ogarnia syf.
	short unsigned int r, b;
	if (sek >= 60) {
		r = sek % 60;
		b = sek / 60;
		min += b;
		sek = r;
	}
	if (min >= 60) {
		r = min % 60;
		b = min / 60;
		godz += b;
		min = r;
	}
}

//wymuszone ustawienie wartosci bez ograniczen
void Czas::forceSetSek(int sek) {
	if (sek >= 0) {
		this->sek = (unsigned int)sek;
	}
	else {
		this->sek = 0;
	}
}

void Czas::forceSetMin(int min) {
	if (sek >= 0) {
		this->min = (unsigned int)min;
	}
	else {
		this->min = 0;
	}
}
Czas::Czas() { //domsylny konstruktor - wszystko ustawione na 0
	sek = 0;
	min = 0;
	godz = 0;
}
//reszta konstruktorow
Czas::Czas(int sek) {
	this->min = 0;
	this->godz = 0;
	if (sek >= 0) {
		this->sek = (unsigned int)sek;
		this->format();
	}
	else {
		this->sek = 0;
		std::cout << "Wprowadzono niepoprawne dane. Obiekt utworzono z zerowymi paremetrami" << std::endl;
	}

}

Czas::Czas(int sek, int min) {
	this->godz = 0;
	if (sek >= 0 && min >= 0) {
		this->sek = (unsigned int)sek;
		this->min = (unsigned int)min;
		this->format();
	}
	else {
		this->sek = 0;
		this->min = 0;
		std::cout << "Wprowadzono niepoprawne dane. Obiekt utworzono z zerowymi paremetrami" << std::endl;
	}
}

Czas::Czas(int sek, int min, int godz) {
	if (sek >= 0 && min >= 0 && godz >= 0) {
		this->sek = (unsigned int)sek;
		this->min = (unsigned int)min;
		this->godz = (unsigned int)godz;
		this->format();
	}
	else {
		this->sek = 0;
		this->min = 0;
		this->godz = 0;
		std::cerr << "Wprowadzono niepoprawne dane. Obiekt utworzono z zerowymi paremetrami" << std::endl;
	}
}

//akcesory:		
bool Czas::setSek(int sek) {
	if (sek >= 0 && sek < 60) {
		this->sek = (unsigned int)sek;
		return true;
	}
	else {
		std::cerr << "Error: Wprowadzono liczbe poza zakresem (0 - 59)" << std::endl << "Podaj wartosc jeszcze raz: " << std::endl;
		return false;
	}
}

unsigned int Czas::getSek() {
	return sek;
}

bool Czas::setMin(int min) {
	if (min >= 0 && min < 60) {
		this->min = (unsigned int)min;
		return true;
	}
	else {
		std::cerr << "Error: Wprowadzono liczbe poza zakresem (0 - 59)" << std::endl << "Podaj wartosc jeszcze raz: " << std::endl;
		return false;
	}
}

unsigned int Czas::getMin() {
	return min;
}

bool Czas::setGodz(int godz) {
	if (godz >= 0) {
		this->godz = (unsigned int)godz;
		return true;
	}
	else {
		std::cout << "Czas moze przyjmowac tylko wartosci dodatnie" << std::endl << "Podaj wartosc jeszcze raz: " << std::endl;
		return false;
	}
}

unsigned int Czas::getGodz() {
	return godz;
}

void Czas::setCzas(int sek, int min, int godz) {
	this->godz = godz;
	this->setMin(min);
	this->setSek(sek);
}

void Czas::setCzas(int sek) {
	this->forceSetSek(sek);
	this->format();
}

//inne fajne <s>funkcje</s> metody
void Czas::zero() {
	sek = 0;
	min = 0;
	godz = 0;
}

void Czas::printCzas() {
	this->format();
	std::cout << "Sekundy: " << getSek() << " Minuty: " << getMin() << " Godziny: " << getGodz() << std::endl;
}



Czas Czas::operator + (Czas z1) { //dodanie dwoch obiektow (czas + czas)
	Czas z2;
	z2.setGodz(z1.getGodz() + godz);
	z2.forceSetMin(z1.getMin() + min);
	z2.forceSetSek(z1.getSek() + sek);
	z2.format();
	return z2;
}

void Czas::operator += (Czas z1) {
	*this = *this + z1;
	//this->printCzas();
}

Czas Czas::operator + (int v) { //dodanie obiekt + int (czas + sekundy)
	Czas z1(*this);
	if (v < 0) {
		return z1;
	}
	z1.forceSetSek(this->getSek() + v);
	z1.format();
	return z1;
}

void Czas::operator += (int v) {
	if (v < 0) {
		return;
	}
	this->sek += v;
	this->format();
}

bool Czas::operator == (Czas z1) {
	if (this->sek == z1.sek && this->min == z1.min && this->godz == z1.godz) {
		return true;
	}
	return false;
}

bool Czas::operator > (Czas z1) {
	if (this->godz > z1.godz) {
		return true;
	}
	else if (this->godz < z1.godz) {
		return false;
	}
	if (this->min > z1.min) {
		return true;
	}
	else if (this->min < z1.min) {
		return false;
	}
	if (this->sek > z1.sek) {
		return true;
	}
	return false;
}

bool Czas::operator < (Czas z1) {
	return !(*this > z1);
}

bool Czas::operator <= (Czas z1) {
	if (*this < z1 || *this == z1) {
		return true;
	}
	return false;
}

bool Czas::operator >= (Czas z1) {
	if (*this > z1 || *this == z1) {
		return true;
	}
	return false;
}