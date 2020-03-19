#include "Obrabiarka.h"

Obrabiarka::Obrabiarka(const Obrabiarka& o) { //kontruktor kopiujacy
	this->list = o.list;
}

Obrabiarka::Obrabiarka() {
}

Obrabiarka::~Obrabiarka() {
	list.clear(); //usuwa obiekty z vectora
}

size_t Obrabiarka::getCount() {
	return list.size();
}

Czas Obrabiarka::getSum() {
	Czas suma;
	for (auto a : list) {
		suma += a;
	}
	return suma;
}

Czas Obrabiarka::getAt(int i) {
	try {
		return this->list.at(i);
	}
	catch (const std::out_of_range & e) {
		std::cerr << "Error: Dane poza dostepna pamiecia: " << e.what() << std::endl;
		Czas z = Czas(0, 0, 0);
		return z;
	}
}

void Obrabiarka::printAt(int i) {
	try {
		this->list.at(i).printCzas();
	}
	catch (const std::out_of_range & e) {
		std::cerr << "Error: Tu nic nima: " << e.what() << std::endl;
	}
}

void Obrabiarka::printSum() {
	std::cout << "Suma czasow obrabiarki: " << std::endl;
	Czas suma = this->getSum();
	suma.printCzas();
}

void Obrabiarka::printAll() {
	if (this->list.size() == 0) {
		std::cout << "Lista jest pusta." << std::endl;
		return;
	}
	std::cout << "Lista czasow: " << std::endl;
	for (auto a : list) {
		a.printCzas();
	}
}

void Obrabiarka::push(Czas z) {
	this->list.push_back(z);
}

void Obrabiarka::pop() {
	if (this->list.size() > 1) {
		this->list.pop_back();
	}
}

void Obrabiarka::push(int sek, int min, int godz) {
	Czas z = Czas(sek, min, godz);
	this->list.push_back(z);
}

void Obrabiarka::push(int sek) {
	Czas z = Czas(sek);
	this->list.push_back(z);
}

void Obrabiarka::setAt(Czas z, int i) {
	try {
		this->list.at(i) = z;
	}
	catch (const std::out_of_range & e) {
		std::cerr << "Error: Wprowadzenie danych poza dostepna pamiecia: " << e.what() << std::endl;
	}
}

void Obrabiarka::clear() {
	this->list.clear();
}

void Obrabiarka::cpy(Obrabiarka o, int n) {
	if (n <= 0) {
		std::cerr << "Warning: Nalezy podac conajmniej 1 czas" << std::endl
			<< "Nie skopiowana zadnego czasu!" << std::endl;
	}
	if (n >= (int)o.getCount()) {
		std::cerr << "Warning: Zadano wiecej czasow niz jest dostepnych na liscie. " << std::endl
			<< "Zostana skopiowane wszystkie dostepne czasy" << std::endl;
	}
	this->clear();
	for (int i = 0; i < n && i < (int)o.getCount(); i++) {
		this->push(o.getAt(i));
	}
}

Obrabiarka Obrabiarka::getLimited(Czas z) {
	Obrabiarka o;
	for (int i = 0; (o.getSum() < z) && (i < (int)this->list.size()); i++) {
		o.push(this->getAt(i));
	}
	if (z < o.getSum()) {
		o.pop();
	}
	return o;
}

Obrabiarka Obrabiarka::getLimited(int sek, int min, int godz) {
	Czas z = Czas(sek, min, godz);
	return getLimited(z);
}