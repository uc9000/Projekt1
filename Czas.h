#pragma once
#include <iostream>
class Czas {
private:
	unsigned int sek, min, godz;
	void format();
	//wymuszone ustawienie wartosci bez ograniczen
	void forceSetSek(int sek);
	void forceSetMin(int min);

public:
	Czas();
	//reszta konstruktorow
	Czas(int sek);
	Czas(int sek, int min);
	Czas(int sek, int min, int godz);
	//akcesory:		
	bool setSek(int sek);
	unsigned int getSek();
	bool setMin(int min);
	unsigned int getMin();
	bool setGodz(int godz);
	unsigned int getGodz();
	void setCzas(int sek, int min, int godz);
	void setCzas(int sek);
	//inne fajne <s>funkcje</s> metody
	void zero();
	void printCzas();
	
	//przeciazenie operatorow

	Czas operator + (Czas z1) { //dodanie dwoch obiektow (czas + czas)
		Czas z2;
		z2.setGodz(z1.getGodz() + godz);
		z2.forceSetMin(z1.getMin() + min);
		z2.forceSetSek(z1.getSek() + sek);
		z2.format();
		return z2;
	}

	void operator += (Czas z1) {
		*this = *this + z1;
		//this->printCzas();
	}

	Czas operator + (int v) { //dodanie obiekt + int (czas + sekundy)
		Czas z1(*this);
		if (v < 0) {
			return z1;
		}
		z1.forceSetSek(this->getSek() + v);
		z1.format();
		return z1;
	}

	void operator += (int v) {
		if (v < 0) {
			return;
		}
		this->sek += v;
		this->format();
	}

	bool operator == (Czas z1) {
		if (this->sek == z1.sek && this->min == z1.min && this->godz == z1.godz) {
			return true;
		}
		return false;
	}

	bool operator > (Czas z1) {
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

	bool operator < (Czas z1) {
		return !(*this > z1);
	}

	bool operator <= (Czas z1) {
		if (*this < z1 || *this == z1) {
			return true;
		}
		return false;
	}

	bool operator >= (Czas z1) {
		if (*this > z1 || *this == z1) {
			return true;
		}
		return false;
	}
};