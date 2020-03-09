#ifndef CZAS_H
#define CZAS_H
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
	Czas operator + (Czas z1);
	void operator += (Czas z1);
	Czas operator + (int v);
	void operator += (int v);
	bool operator == (Czas z1);
	bool operator > (Czas z1);
	bool operator < (Czas z1);
	bool operator <= (Czas z1);
	bool operator >= (Czas z1);
};
#endif