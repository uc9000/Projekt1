#ifndef OBRABIARKA_H
#define OBRABIARKA_H
#include "Czas.h"
#include <vector> //Do klasy Obrabiarka
#include <stdexcept> //do zabezpieczen w klasie Obrabiarka

class Obrabiarka {
private:
	std::vector<Czas> list;

public:
	Obrabiarka(const Obrabiarka& o);
	Obrabiarka();
	~Obrabiarka();
	size_t getCount();
	Czas getSum();
	Czas getAt(int i);
	void printAt(int i);
	void printSum();
	void printAll();
	void push(Czas z);
	void pop();
	void push(int sek, int min, int godz);
	void push(int sek);
	void setAt(Czas z, int i);
	void clear();
	void cpy(Obrabiarka o, int n);
	Obrabiarka getLimited(Czas z);
	Obrabiarka getLimited(int sek, int min, int godz);
	void operator = (Obrabiarka o) {
		this->list = o.list;
	}
};

#endif