#include <iostream>

class Czas {
	private:
		unsigned int sek, min, godz;
	public:			
		void format(){ //ustawia prawidlowy format czasu (sek;min;godz). Ogolnie ogarnia syf.
			short unsigned int r, b;
			if (sek >= 60){
				r = sek % 60;
				b = (sek - r) / 60;
				min += b;
				sek = r;
			}
			if (min >= 60){
				r = min % 60;
				b = (min - r) / 60;
				godz += b;
				min = r;
			}
		}

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
				std::cout << "Wprowadzono niepoprawne dane. Obiekt utworzono z zerowymi paremetrami" << std::endl;
				this->sek = 0;
			}
		}
		
		Czas(int sek, int min){
			if(sek >= 0 && min >= 0){
				this->sek = (unsigned int)sek;
				this->min = (unsigned int)min;
				this->format();
			}
			else{
				std::cout << "Wprowadzono niepoprawne dane. Obiekt utworzono z zerowymi paremetrami" << std::endl;
				this->sek = 0;
				this->min = 0;
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
				std::cout << "Wprowadzono niepoprawne dane. Obiekt utworzono z zerowymi paremetrami" << std::endl;
				this->sek = 0;
				this->min = 0;
				this->godz = 0;
			}			
		}		

		//akcesory:
		bool setSek(int sek) {
			if (sek >= 0) {
				this->sek = sek;
				this->format();
				return true;
			}
			else {
				std::cout << "Czas moze przyjmowac tylko wartosci dodatnie" << std::endl;
				return false;
			}			
		}

		unsigned int getSek() {
			return sek;
		}

		bool setMin(int min) {
			if (min >= 0) {
				this->min = min;
				this->format();
				return true;
			}
			else {
				std::cout << "Czas moze przyjmowac tylko wartosci dodatnie" << std::endl;
				return false;
			}
		}

		unsigned int getMin() {
			return min;
		}

		bool setGodz(int godz) {
			if (godz >= 0) {
				this->godz = godz;
				this->format();
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
			z2.setSek(z1.getSek() + sek);
			z2.setMin(z1.getMin() + min);
			z2.setGodz(z1.getGodz() + godz);
			z2.format();
			return z2;
		}

		void operator += (Czas z1){
			*this = *this + z1;
		}

		Czas operator + (int v){ //dodanie obiekt + int (czas + sekundy)
			Czas z1(*this);
			if (v < 0){
				return z1;
			}
			z1.setSek(z1.getSek() + v);
			z1.format();
			return z1;
		}

		void operator += (int v){
			if (v < 0){
				return;
			}
			this->setSek(this->getSek() + v);
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
			}else if(sek < z1.getSek()){
				return false;
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

int main() {
	using namespace std;
	Czas z1;
	Czas z2(2312, 61, 2);
	z1.setGodz(5);
	z1.setMin(71);
	z1.setSek(131);
	z1.printCzas();
	z2.printCzas();
	z1 += z2;
	z1.printCzas();
	z1 += 125;
	z1.printCzas();
	if (z1 > z2){
		cout << "z1 wiekszy" << endl;
	}
	if (z2 < z1){
		cout << "z1 wiekszy" << endl;
	}
}