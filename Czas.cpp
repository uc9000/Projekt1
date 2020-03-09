#include "Czas.h"
#pragma once
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
    //przeciazenie operatorow
    Czas operator + (Czas c1){ //dodanie dwoch obiektow (czas + czas)
        Czas c2;
        c2.godziny = c2.godziny + c1.godziny;
        c2.minuty = c2.minuty + c1.minuty;
        c2.sekundy = c2.sekundy + c1.sekundy;
        if(c2.sekundy >= 60){
            c2.minuty += sekundy / 60;
            c2.sekundy = sekundy % 60;
        }
        if(c2.minuty >= 60){
            c2.godziny += minuty / 60;
            c2.minuty = minuty % 60;
        }
        return c2;
    }

    void operator += (Czas c1){
        *this = *this + c1;
    }

    Czas operator + (int x){ //dodanie obiekt + int (czas + sekundy)
        Czas c1 = Czas(*this);
        if (x < 0){
            return c1;
        }
        c1.sekundy += x;        
        if(c1.sekundy >= 60){
            c1.minuty += sekundy / 60;
            c1.sekundy = sekundy % 60;
        }
        if(c1.minuty >= 60){
            c1.godziny += minuty / 60;
            c1.minuty = minuty % 60;
        }
        return c1;
    }

    void operator += (int x){
        *this = *this + x;
    }

    bool operator == (Czas c1){
        if(sekundy == c1.sekundy && minuty == c1.minuty && godziny == c1.godziny){
            return true;
        }
        return false;
    }

    bool operator > (Czas c1){
        if(godziny > c1.godziny){
            return true;
        }else if(godziny < c1.godziny){
            return false;
        }
        if(minuty > c1.minuty){
            return true;
        }else if(minuty < c1.minuty){
            return false;
        }
        if(sekundy > c1.sekundy){
            return true;
        }
        return false;
    }

    bool operator <= (Czas z1){
        if (*this < z1 || *this == z1){
            return true;
        }
        return false;
    }

    bool operator >= (Czas z1){
        if (*this > z1 || *this == z1){
            return true;
        }
        return false;
    }

    bool operator < (Czas z1){
        return !(*this >= z1);
    }
};