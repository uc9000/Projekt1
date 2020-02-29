#include <iostream>
#include <vector> //Do klasy Obrabiarka
#include <stdexcept> //do zabezpieczen

class Czas {
	private:
		unsigned int sek, min, godz;
				
		void format(){ //ustawia prawidlowy format czasu (sek;min;godz). Ogolnie ogarnia syf.
			short unsigned int r, b;
			if (sek >= 60){
				r = sek % 60;
				b = sek / 60;
				min += b;
				sek = r;
			}
			if (min >= 60){
				r = min % 60;
				b = min / 60;
				godz += b;
				min = r;
			}
		}
		
		void forceSetSek(int sek){
			this->sek = (unsigned int)sek;
		}

		void forceSetMin(int min){
			this->min = (unsigned int)min;
		}

	public:		
		Czas(){ //domsylny konstruktor - wszystko ustawione na 0
			sek = 0;
			min = 0;
			godz = 0;
		}
		//reszta konstruktorow
		Czas(int sek){
			if(sek >= 0){
				this->sek = (unsigned int)sek;
				this->format();
			}
			else{				
				this->sek = 0;
				std::cout << "Wprowadzono niepoprawne dane. Obiekt utworzono z zerowymi paremetrami" << std::endl;
			}
		}
		
		Czas(int sek, int min){
			if(sek >= 0 && min >= 0){
				this->sek = (unsigned int)sek;
				this->min = (unsigned int)min;
				this->format();
			}
			else{
				this->sek = 0;
				this->min = 0;
				std::cout << "Wprowadzono niepoprawne dane. Obiekt utworzono z zerowymi paremetrami" << std::endl;
			}			
		}
		
		Czas(int sek, int min, int godz){
			if(sek >= 0 && min >= 0 && godz >= 0){
				this->sek = (unsigned int)sek;
				this->min = (unsigned int)min;
				this->godz = (unsigned int)godz;
				this->format();
			}
			else{
				this->sek = 0;
				this->min = 0;
				this->godz = 0;
				std::cout << "Wprowadzono niepoprawne dane. Obiekt utworzono z zerowymi paremetrami" << std::endl;
			}			
		}		

		//akcesory:		
		bool setSek(int sek) {
			if (sek >= 0 && sek < 60) {
				this->sek = (unsigned int)sek;
				return true;
			}
			else {
				std::cout << "Error: Wprowadzono liczbe poza zakresem (0 - 59)" << std::endl;
				return false;
			}			
		}

		unsigned int getSek() {
			return sek;
		}

		bool setMin(int min) {
			if (min >= 0 && min < 60) {
				this->min = (unsigned int)min;
				return true;
			}
			else {
				std::cout << "Error: Wprowadzono liczbe poza zakresem (0 - 59)" << std::endl;
				return false;
			}
		}

		unsigned int getMin() {
			return min;
		}

		bool setGodz(int godz) {
			if (godz >= 0) {
				this->godz = (unsigned int)godz;
				return true;
			}
			else {
				std::cout << "Czas moze przyjmowac tylko wartosci dodatnie" << std::endl;
				return false;
			}
		}

		unsigned int getGodz() {
			return godz;
		}

		void setCzas(int sek, int min, int godz){
			this->godz = godz;
			this->setMin(min);
			this->setSek(sek);
		}

		//inne fajne funkcje
		void zero(){
			sek = 0;
			min = 0;
			godz = 0;
		}

		void printCzas() {
			this->format();
			std::cout << "Sekundy: " << getSek() << " Minuty: " << getMin() << " Godziny: " << getGodz() << std::endl;
		}

		//przeciazenie operatorow
		Czas operator + (Czas z1){ //dodanie dwoch obiektow (czas + czas)
			Czas z2;
			z2.setGodz(z1.getGodz() + godz);
			z2.forceSetMin(z1.getMin() + min);
			z2.forceSetSek(z1.getSek() + sek);			
			z2.format();
			return z2;
		}

		void operator += (Czas z1){
			*this = *this + z1;
			//this->printCzas();
		}

		Czas operator + (int v){ //dodanie obiekt + int (czas + sekundy)
			Czas z1(*this);
			if (v < 0){
				return z1;
			}
			z1.forceSetSek(this->getSek() + v);
			z1.format();
			return z1;
		}

		void operator += (int v){
			if (v < 0){
				return;
			}
			this->sek += v;
			this->format();
		}

		bool operator == (Czas z1){
			if(sek == z1.getSek() && min == z1.getMin() && godz == z1.getGodz()){
				return true;
			}
			return false;
		}

		bool operator > (Czas z1){
			if(godz > z1.getGodz()){
				return true;
			}else if(godz < z1.getGodz()){
				return false;
			}
			if(min > z1.getMin()){
				return true;
			}else if(min < z1.getMin()){
				return false;
			}
			if(sek > z1.getSek()){
				return true;
			}
			return false;
		}

		bool operator < (Czas z1){
			return !(*this > z1);
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
};

class Obrabiarka{
	private:
	std::vector<Czas> list;

	public:		
		size_t getCount(){
			return list.size();
		}
		Czas getSum(){
			Czas suma;
			for(auto a : list){
				suma += a;
			}
			return suma;
		}

		void printSum(){
			std::cout << "Suma czasow obrabiarki: " << std::endl;
			Czas suma = this->getSum();
			suma.printCzas();
		}
		
		void printAll(){
			std::cout << "Lista wszystkich czasow: " << std::endl;
			for(auto a : list){
				a.printCzas();
			}
		}

		void push(Czas z){
			this->list.push_back(z);
		}

		void push(int sek, int min, int godz){
			Czas z;
			z.setCzas(sek, min, godz);
			this->list.push_back(z);
		}

		void setAt(Czas z, int i){
			try{
				this->list.at(i) = z;
			}
			catch(const std::out_of_range& e){
				std::cerr << "Error: Wprowadzenie danych poza dostepna pamiecia: " << e.what() << std::endl;
			}
		}

		Czas getAt(int i){
			try{
				return this->list.at(i);
			}
			catch(const std::out_of_range& e){
				std::cerr << "Error: Dane poza dostepna pamiecia: " << e.what() << std::endl;
				Czas z(0,0,0);
				return z;
			}
		}

		void printAt(int i){
			try{
				this->list.at(i).printCzas();
			}
			catch(const std::out_of_range& e){
				std::cerr << "Error: Tu nic nima: " << e.what() << std::endl;
			}
		}
};

int main() {
	using namespace std;
	//test klasy czas
	Czas z1;
	Czas z2(2312, 61, 2);
	z1.setGodz(5);
	z1.setMin(59);
	z1.setSek(3);
	z1.printCzas();
	z2.printCzas();
	z1 = z1 + z2;
	z1.printCzas();
	z1 += 125;
	z1.printCzas();
	if (z1 > z2){
		cout << "z1 wiekszy" << endl;
	}
	if (z2 < z1){
		cout << "z1 wiekszy" << endl;
	}
	//test klasy obrabiarka
	Obrabiarka o1;
	o1.push(z1);
	o1.push(z2);
	z1.setCzas(13, 31, 1);
	o1.push(z1);
	z1.setCzas(14, 1, 0);
	o1.push(z1);
	o1.push(59, 59, 2);
	cout << "Ilosc procesow: " << o1.getCount() << endl;
	o1.printAll();
	o1.printSum();
	o1.printAt(100);
	z2 = o1.getAt(101);
	o1.printAt(3);
	return 0;
}