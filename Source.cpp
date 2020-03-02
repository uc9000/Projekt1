#include <iostream> //Do klasy Czas
#include <vector> //Do klasy Obrabiarka
#include <stdexcept> //do zabezpieczen w klasie Obrabiarka

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
		
		//wymuszone ustawienie wartosci bez ograniczen
		void forceSetSek(int sek){
			if(sek >= 0){
				this->sek = (unsigned int)sek;
			}else{
				this->sek = 0;
			}			
		}

		void forceSetMin(int min){
			if(sek >= 0){
				this->min = (unsigned int)min;
			}else{
				this->min = 0;
			}			
		}

	public:		
		Czas(){ //domsylny konstruktor - wszystko ustawione na 0
			sek = 0;
			min = 0;
			godz = 0;
		}
		//reszta konstruktorow
		Czas(int sek){
			this->min = 0;
			this->godz = 0;
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
			this->godz = 0;
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
				std::cerr << "Wprowadzono niepoprawne dane. Obiekt utworzono z zerowymi paremetrami" << std::endl;
			}
		}

		//akcesory:		
		bool setSek(int sek) {
			if (sek >= 0 && sek < 60) {
				this->sek = (unsigned int)sek;
				return true;
			}
			else {
				std::cerr << "Error: Wprowadzono liczbe poza zakresem (0 - 59)" << std::endl;
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
				std::cerr << "Error: Wprowadzono liczbe poza zakresem (0 - 59)" << std::endl;
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

		void setCzas(int sek){
			this->forceSetSek(sek);
			this->format();
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
			if(this->sek == z1.sek && this->min == z1.min && this->godz == z1.godz){
				return true;
			}
			return false;
		}

		bool operator > (Czas z1){
			if(this->godz > z1.godz){
				return true;
			}else if(this->godz < z1.godz){
				return false;
			}
			if(this->min > z1.min){
				return true;
			}else if(this->min < z1.min){
				return false;
			}
			if(this->sek > z1.sek){
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
		Obrabiarka(const Obrabiarka& o){ //kontruktor kopiujacy
			this->list = o.list;
		}
		
		Obrabiarka(){
		}
		
		~Obrabiarka(){		
			list.clear(); //usuwa obiekty z vectora
		}
		
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

		Czas getAt(int i){
			try{
				return this->list.at(i);
			}
			catch(const std::out_of_range& e){
				std::cerr << "Error: Dane poza dostepna pamiecia: " << e.what() << std::endl;
				Czas z = Czas(0,0,0);
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

		void printSum(){
			std::cout << "Suma czasow obrabiarki: " << std::endl;
			Czas suma = this->getSum();
			suma.printCzas();
		}
		
		void printAll(){			
			if(this->list.size() == 0){
				std::cout << "Lista jest pusta." << std::endl;
				return;
			}
			std::cout << "Lista wszystkich czasow: " << std::endl;
			for(auto a : list){
				a.printCzas();
			}
		}

		void push(Czas z){
			this->list.push_back(z);
		}

		void pop(){
			if(this->list.size() > 1){
				this->list.pop_back();
			}		
		}

		void push(int sek, int min, int godz){
			Czas z = Czas(sek, min, godz);
			this->list.push_back(z);
		}

		void push(int sek){
			Czas z = Czas(sek);
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

		void clear(){
			this->list.clear();
		}		

		void cpy(Obrabiarka o, int n){
			this->clear();
			for (int i = 0; i < n; i++){
				this->push(o.getAt(i));
			}
		}

		Obrabiarka getLimited(Czas z){
			Obrabiarka o;		
			for (int i = 0; (o.getSum() < z) && (i < (int)this->list.size()); i++){				
				o.push(this->getAt(i));
			}
			if(z < o.getSum()){
				o.pop();
			}
			return o;
		}

		Obrabiarka getLimited(int sek, int min, int godz){
			Czas z = Czas(sek, min, godz);
			return getLimited(z);
		}

		void operator = (Obrabiarka o){
			this->list = o.list;
		}
};

int main() {
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
	o3.push(34,23,5);	
	cout << "Obiekt o3: " << endl;
	o3.printAll();
	z1.setCzas(23, 45, 13);
	o2 = o3.getLimited(z1);
	cout << "z1: " << endl;
	z1.printCzas();
	cout << "o2 = o3 ograniczone do z1:" << endl;
	o2.printAll();
	return 0;
}